


%{

a
En general las señales x(n) y y(n) son parecidas. 
Entre sus diferencias están:
y(n) contiene ruido 
Está retrasada en el tiempo por un factor D. 

Al realizar la autocorrelación con un factor de K = 0 se obtiene el valor máximo de la autocorrelación.
Debido a ello, se puede inducir que si se realiza la correlación entre x(n) y y(n) en un factor K tal que D = -K se obtiene:
y(t) = ax(t -td + tk) + v(t)
y(t) = ax(t) + v(t)


%}


function problema3()

	n = 0:199;

	%% se crea el vector original x(n) como señal del emisor

	x_original = [1,1,1,1,1,-1,-1,1,1,-1,1,-1,1];

	%% se agrega padding a la señal para que tenga un tamaño de 200
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

	%----  b

	% ryx = correlation( y,n,x_original , 0:12 );
	
	ryx = correlation( y,n,x , n );
	ryx = ryx(201:260);



	figure(1);
	subplot(3,1,1);	  
	  stem(x);
	  title (sprintf ("x(n)"));
	subplot(3,1,2);
	  stem(y);
	  title (sprintf ("y(n), variance = 0.01"));
	subplot(3,1,3);
	  stem(ryx);
	  title(sprintf ("ryx, correlation yx"));

	%---- c

	


%{
	PUNTO C CORRELACIÓN
	calcule y dibuje la correlación cruzada
	rxy(n) utilizando la funcion desarrollada en el ejercicio2 para 0 <= n <= 59.
	utilice la grafica para estimar el valor del retardo.


	variables a utilizar: x , y
	si puede utilizar x_original es más eficiente
%} 



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

	ry2x = correlation( y_2,n,x , n );
	ry2x = ry2x(201:260);

	ry3x = correlation( y_3,n,x , n );
	ry3x = ry3x(201:260);

	figure(2);
	subplot(2,2,1);	 
	  stem(y_2);
	  title (sprintf ("y(n), variance = 0.1"));
	subplot(2,2,2);
	  stem(y_3);
	  title (sprintf ("y(n), variance = 1"));


% PUNTO C, variables: x, y_2   y    x, y_3
% si puede utilizar x_original es más eficiente



%---------------------------------------------------
%---- e
	x2_original = [-1,-1,-1,+1,+1,+1,+1,-1,+1,-1,+1,+1,-1,-1,+1];

	x2 = [x2_original,zeros(1,185)];
	x2_padded = [D,x2_original,zeros(1,165)];

	%% se genera la señal del receptor, igual a la señal emitida retrasada por 20 y con ruido
	y_x2 = (0.9.*x2_padded )+ v;

	figure(3);	
	subplot(2,1,1);	 
	  stem(x2);
	  title (sprintf ("x2(n), 4 register adder"));
	subplot(2,1,2);
	  stem(y_x2);
	  title (sprintf ("y2(n)"));



% PUNTO C, variables: x2, y_x2  
% si puede utilizar x_original es más eficiente

%---------------------------------------------------
%---- f
	register7 = zeros(1,7);
	register7(1) = 1;


	x3 = zeros(1,127);

	first = 0;
	last = 0;

	for i = 1:127
		first = register7(1);
		register7 = shift(register7,1);
		last = register7(1);
		x3(i) = last;
		register7(1) = xor(first, last);
	endfor

	x3_padded = [x3,zeros(1,73)];
	y_x3 = (0.9.*[D,x3,zeros(1,53)] )+ v;

	figure(3);	
	subplot(2,1,1);	 
	  stem(x3_padded);
	  title (sprintf ("x3(n), 7 register adder"));
	subplot(2,1,2);
	  stem(y_x3);
	  title (sprintf ("y3(n)"));





endfunction
