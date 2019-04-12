1;

function ejercicio3()

	n = 0:199;

	x_original = [1,1,1,1,1,-1,-1,1,1,-1,1,-1,1];

	x = [x_original,zeros(1,187)];
	std = 0.1;
	% mean = 0;
	% v = std.*randn(1,200) + mean;

	v = std.*randn(1,200);

	D = zeros(1,20);

	x_padded = [D,x_original,zeros(1,167)];
	y = 0.9.*x_padded + v;
	figure(1);
	subplot(2,1,1);	  
	  stem(x_graph);
	  title (sprintf ("x(n)"));
	subplot(2,1,2);
	  stem(y);
	  title (sprintf ("y(n)"));


%{
	PUNTO C CORRELACIÓN
	calcule y dibuje la correlación cruzada
	rxy(n) utilizando la funcion desarrollada en el ejercicio2 para 0 <= n <= 59.
	utilice la grafica para estimar el valor del retardo.


	variables a utilizar: x , y
	si puede utilizar x_original es más eficiente
%} 



% ---------------------------------------------------
	% sigma^2 = 0.1   sigma^2 = 1

	std_2 = sqrt(0.1);
	std_3 = 1;
	
	v_2 = std_2.*randn(1,200);
	v_3 = std_3.*randn(1,200);

	y_2 = 0.9.*x_padded + v_2;
	y_3 = 0.9.*x_padded + v_3;

	figure(2);
	subplot(2,1,1);	 
	  stem(y_2);
	  title (sprintf ("y(n), variance = 0.1"));
	subplot(2,1,2);
	  stem(y_3);
	  title (sprintf ("y(n), variance = 1"));

% PUNTO C, variables: x, y_2   y    x, y_3
% si puede utilizar x_original es más eficiente



% ---------------------------------------------------

	x2_original = [-1,-1,-1,+1,+1,+1,+1,-1,+1,-1,+1,+1,-1,-1,+1];

	x2 = [x2_original,zeros(1,185)];
	x2_padded = [D,x2,zeros(1,165)];

	y_x2 = 0.9.*x2_padded + v;

	figure(3);
	subplot(2,1,1);	 
	  stem(x2);
	  title (sprintf ("x2(n)"));
	subplot(2,1,2);
	  stem(y_x2);
	  title (sprintf ("y2(n)"));



% PUNTO C, variables: x2, y_x2  
% si puede utilizar x_original es más eficiente



endfunction
