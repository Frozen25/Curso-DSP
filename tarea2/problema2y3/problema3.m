%{
Integrantes
=========================
Gladys Arias 
Alexis Gavriel (Autor del código del problema 3)
Cristian Rivera 
Andres Vargas 
Fecha: 12 de Abril 2019.

Descripción del algoritmo
=========================
Algoritmo: Dadas las señales X de un emisor, y las señales de un receptor Y, se calcula el retraso D
	a partir de la correlación de las señales
----------------------Variables-------------------------------------
x = Señal del emisor
n = Tamaño de muestras del receptor (200)
v = señal de ruido agregado
D = retraso en la señal (20)
y = Señal del receptor con ruido y retraso
ryx = correlación de y con x, inicializada en n = 1
--------------------------------------------------------------------
%}

%{
--- a
Las señales x(n) y y(n) son parecidas. 
Entre sus diferencias están:
y(n) contiene ruido 
Está retrasada en el tiempo por un factor D. 

Al realizar la autocorrelación con un factor de K = 0 se obtiene el valor máximo de la autocorrelación.
Debido a ello, se puede inducir que si se realiza la correlación entre x(n) y y(n) en un factor K 
	tal que D = K (en donde se alinearían la señal del emisor y receptor) se encontraría un pico en el 
	valor de correlación y la posición de este pico indicaría el retraso D.
%}


function problema3()

	% indice de muestras
	n = 0:199;

	%% se crea el vector original x(n) como señal del emisor

	x_original = [1,1,1,1,1,-1,-1,1,1,-1,1,-1,1];

	%% se agrega padding a la señal para que tenga un tamaño de 200 para graficar
	x = [x_original,zeros(1,187)];

	%% se crea un vector de ruido de tamaño 200 con valor medio igual a 0 y varianza de 0.01
	std = 0.1;
	% mean = 0;
	% v = std.*randn(1,200) + mean;

	v = std.*randn(1,200);

	%% se coloca un supuesto retraso de 20
	D = zeros(1,20);
	x_padded = [D,x_original,zeros(1,167)];

	%% se genera la señal del receptor, igual a la señal emitida retrasada por 20 y con ruido
	y = 0.9.*x_padded + v;

	
	%---- c
	ryx = correlation( y,n,x_original , 0:12 );
	
	% El vector de retorno empieza en n = 1, por lo que se debe desplazar por el tamaño de x
	ryx = ryx(14:73);


	% grafica la señal del emisor, receptor y la correlación
	figure('name','Variance = 0.01');
	subplot(3,1,1);	  
	  stem(x);
	  title (sprintf ("x(n) Emitter"));
	subplot(3,1,2);
	  stem(y);
	  title (sprintf ("y(n) Receiver"));
	subplot(3,1,3);
	  stem(ryx);
	  title(sprintf ("ryx Correlation yx"));




% ---------------------------------------------------
%---- d
	% sigma^2 = 0.1   sigma^2 = 1

	std_2 = sqrt(0.1);
	std_3 = 1;
	
	%% se crea un vector de ruido de tamaño 200 con valor medio igual a 0 y varianza de 1 y 0.1
	v_2 = std_2.*randn(1,200);
	v_3 = std_3.*randn(1,200);

	%% se genera la señal del receptor, igual a la señal emitida retrasada por 20 y con ruido
	y_2 = 0.9.* x_padded + v_2;
	y_3 = 0.9.* x_padded + v_3;


	ry2x = correlation( y_2,n,x_original , 0:12 );
	ry3x = correlation( y_3,n,x_original , 0:12 );		

	% El vector de retorno empieza en n = 1, por lo que se debe desplazar por el tamaño de x
	ry2x = ry2x(14:73);
	ry3x = ry3x(14:73);

	% grafica la señal del emisor, receptor y la correlación
	figure('name','Variance = 0.1');
	subplot(3,1,1);	 
	  stem(x);
	  title (sprintf ("x(n) Emitter"));
	subplot(3,1,2);	 
	  stem(y_2);
	  title (sprintf ("y(n) Receiver"));
	subplot(3,1,3);
	  stem(ry2x);
	  title(sprintf ("ryx Correlation yx"));

	% grafica la señal del emisor, receptor y la correlación
	figure('name','Variance = 1');
	subplot(3,1,1);	 
	  stem(x);
	  title (sprintf ("x(n) Emitter"));
	subplot(3,1,2);
	  stem(y_3);
	  title (sprintf ("y(n) Receiver"));
	subplot(3,1,3);
	  stem(ry3x);
	  title(sprintf ("ryx Correlation yx"));


%---------------------------------------------------
%---- e

	% señal de salida del registro de corrimiento de tamaño 4 con sumador-mod2
	x2_original = [-1,-1,-1,+1,+1,+1,+1,-1,+1,-1,+1,+1,-1,-1,+1];

	% utilizada para graficar
	x2 = [x2_original,zeros(1,185)];

	% se agrega el retraso D
	x2_padded = [D,x2_original,zeros(1,165)];

	%% se genera la señal del receptor, igual a la señal emitida retrasada por 20 y con ruido
	v = std.*randn(1,200);
	y_x2 = (0.9.*x2_padded )+ v;

	% calcula la crrelacion
	ryx2 = correlation( y_x2,n,x2_original , 0:14 );	

	% El vector de retorno empieza en n = 1, por lo que se debe desplazar por el tamaño de x	
	ryx2 = ryx2(16:75);

	% grafica la señal del emisor, receptor y la correlación
	figure('name','4 Register shift adder-mod2');
	subplot(3,1,1);	 
	  stem(x2);
	  title (sprintf ("x2(n) Emitter"));
	subplot(3,1,2);
	  stem(y_x2);
	  title (sprintf ("y2(n) Receiver"));
	subplot(3,1,3);
	  stem(ryx2);
	  title(sprintf ("ryx Correlation yx"));



%---------------------------------------------------
%---- f

	% registro de 7 etapas con el primer elemento 1
	register7 = zeros(1,7);
	register7(1) = 1;

	% inicialización de la señal de salida del registro de 7 etapas
	x3 = zeros(1,127);

	first = 0;
	last = 0;

	% genera el vector x
	% el nuevo elemento es igual al resultado de la suma-mod2 del primer y último elemento
	% este es ingresado al inicio y corre el resto de valores
	% el último elemento del registro sale y se guarda en x
	for i = 1:127
		first = register7(1);
		register7 = shift(register7,1);
		last = register7(1);
		x3(i) = last;
		register7(1) = xor(first, last);
	endfor

	% agrega padding para hacer el vector de tamaño 200 para graficar
	x3_padded = [x3,zeros(1,73)];

	% calcula el vector de ruido
	v = std.*randn(1,200);
	y_x3 = (0.9.*[D,x3,zeros(1,53)] )+ v;
 
	% calcula la correlación
	ryx3 = correlation( y_x3,n,x3 , 0:126 );	

	% El vector de retorno empieza en n = 1, por lo que se debe desplazar por el tamaño de x	
	ryx3 = ryx3(128:186);


	% grafica la señal del emisor, receptor y la correlación
	figure('name','7 Register shift adder-mod2');
	subplot(3,1,1);	 
	  stem(x3_padded);
	  title (sprintf ("x3(n) Emitter"));
	subplot(3,1,2);
	  stem(y_x3);
	  title (sprintf ("y3(n) Receiver"));
	subplot(3,1,3);
	  stem(ryx3);
	  title(sprintf ("ryx Correlation yx"));





endfunction
