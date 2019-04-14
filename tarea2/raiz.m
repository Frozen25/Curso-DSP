

#Mediante el metodo de Newton-Raphson el algoritmo 
#consigue el valor de la n-esima raiz de un valor y
#como se logró esto?
#se sabe que x = y^(1/a)
#sabiendo que x^a - y = 0
#existe una funcion f(xn) tal que f(xn) = (xn)^a - y para la cual se puede
#buscar el cero.
#dado que el metodo de Newton-Raphson dice que
#X(n+1) = X(n) - f(xn)/f'(xn)
#f(n)/f'(n) = [(xn)^a - y]/[a(xn)^(a-1)]
#entonces la funcion resultante con la cual se itera sobre X para conseguir un
#valor muy cercano al final es: 
#X(n+1) = X(n) - [X(n)^a - y]/[aX(n)^(a-1)]

function raiz(y,a)
  #Inicia el vector donde se guardaran los resultados
  xn = zeros(1,2);
  #Se coloca a y como el primer valors
  xn(1) = y;
  #se genera X(2) = X(1) - (X(1).^a-y)/(a*X(1).^(a-1))
  xn(2) = xn(1) - (xn(1).^a-y)/(a*xn(1).^(a-1));
  #Se realiza el paso anterior hasta que 
  # |X(N-1) - X(N)| < 10^-7 (donde 10^-7 es el umbral)
  #para este caso el umbral 10^-7 da como resultado 7 digitos decimales
  #de precision.
  i = 2;
  while abs(xn(i-1) - xn(i)) > 10^-7 
    xn = [xn,xn(i) - (xn(i).^a-y)/(a*xn(i).^(a-1))];
    i++;
  endwhile
  #Se grafica la funcion resultante
  stem(xn, ".");
  #se usa el N-esimo valor calculado para mostrar el resultado
  title( strcat("Raiz(", num2str(y), ",", num2str(a),") = ", num2str(xn(i))));
  xlabel("n");
  ylabel("xn (Resultado Newton-Raphson)");
  axis("tic","tic");
  grid on;
endfunction;
  