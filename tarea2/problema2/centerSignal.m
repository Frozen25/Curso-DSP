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
algoritmo: The main functionality of the algorithm is to shift the array with the 
corresponding amount of spaces to obtain a new shifted signal with the first 
sample in time 0.
----------------------Variables-------------------------------------
x= First discrete time signal x(n) 
nx= Array of the same size than x that describes the shift of the first sample
%}
function centered = centerSignal(x,nx)
  if(nx(1)>0)
    x = [zeros(1,nx(1)),x];
  else
    x = [x,zeros(1,abs(nx(1)))];
  endif
  centered = x;
endfunction
