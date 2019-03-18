%{
Integrantes
=========================
Gladys Arias (Autora del código del ejercicio_4)
Alexis Gavriel
Cristian Rivera 
Andres Vargas
Fecha: Marzo 15, 2019.

Descripción del algoritmo
=========================
algoritmo: La funcion toma una Señal X1[n] y X2[n] las plotean
%}
function d=ejercicio_2()
  t=[0:1/18:2];
  n=[0:1:36];
  x1=exp(cos(40*pi*t/9)); #Funcion en el tiempo T
  x2=exp(cos(40*pi*n/9)); # Funcion discreta con n muestras
 
#impresion de las graficas
  xlabel ("t");
  ylabel ("X1(t)"); 
  title ("Plot for continus time")
  subplot (2, 1, 1)
  plot (t,x1, "-;X1(t);r", "linewidth",2);
  subplot (2, 1, 2)
  stem (n,x2,"-;X2(n);","linewidth",2);
  end
