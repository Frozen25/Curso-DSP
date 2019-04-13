%{
Integrantes
=========================
Gladys Arias 
Alexis Gavriel
Cristian Rivera 
Andres Vargas (Autor del código del ejercicio_5)
Fecha: Abril 11, 2019.

Descripción del algoritmo
=========================
algoritmo: The main functionality of the algorithm is to calculate the correlation
between two discrete time signals, this assuming that the first sample is always in
time 0.
----------------------Variables-------------------------------------
x= First discrete time signal x(n) 
h = Second discrete time signal h(n) 
----------------------Equations-------------------------------------
y(n) = sum from -infinite to infinite of (x(n)*h(n-k)) 
%}
function result = convSignals(x,h)
  lx = numel(x);
  lh = numel(h);
  iterations = lx+lh-1;
  y = zeros(1,iterations);
  for i = 1:iterations
    for j = 1:i
      if(le(j,lx) && le(abs((i+1)-j),lh))
        y(i) = y(i)+(x(j)*h((i+1)-j));
      endif
    end
  end
  result = y;
  #disp('Convolution: '),disp(y);
endfunction
