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
algoritmo: The main functionality of the algorithm is to calculate the convolution
between two discrete time signals.
----------------------Variables-------------------------------------
x= First discrete time signal x(n) 
nx= Array of the same size than x that describes the shift of the first sample
h = Second discrete time signal h(n) 
nh = Array of the same size than h that describes the shift of the first sample
----------------------Equations-------------------------------------
y(n) = sum from -infinite to infinite of (x(n)*h(n-k)) 
%}
function result = convolution (x,nx,h,nh)
  if(numel(x)!=numel(nx)|| numel(h)!=numel(nh))
    printf("The length of arrays does not match:\n");
    return;
  endif
  x = centerSignal(x,nx);
  h = centerSignal(h,nh);
  result = convSignals(x,h);
endfunction
  