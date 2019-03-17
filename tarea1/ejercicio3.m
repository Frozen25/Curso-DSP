1;
%{
Integrantes
=========================
Gladys Arias 
Alexis Gavriel (Autor del código del ejercicio 3)
Cristian Rivera 
Andres Vargas
Fecha: Marzo 15, 2019.

Descripción del algoritmo
=========================
algoritmo: La funcion grafica las señales x1, x2, x3, x4 en una figura:
  x1 = cos(pi*n/2);
  x2 = sin(pi*n/8);
  x3 = cos(pi*n/4 + pi/3);
  x4 = cos(2*n/pi);

además grafica las funciones y1, y2, y3 en otra figura:
  y1 = x1 + x2;
  y2 = x1 + x2 - x3;
  y3 = x1 + x2 - x3 - 2*x4;

  ** Todas las gráficas se hacen con 50 muestras (n = 50)
%}
#######################
#

function ejercicio3()
  n = 0:50;

  % Crea cada funcion x1, x2, x3, x4
  x1 = cos(pi*n/2);
  x2 = sin(pi*n/8);
  x3 = cos(pi*n/4 + pi/3);
  x4 = cos(2*n/pi);
  
  % Genera una figura en donde se muestran las 4 fuciones x1, x2, x3, x4
  figure(1);
  subplot(2,2,1);
    stem(n,x1);
    title (sprintf ("x1"));
  subplot(2,2,2);
    stem(n,x2);
    title (sprintf ("x2"));
  subplot(2,2,3);
    stem(n,x3);
    title (sprintf ("x3"));
  subplot(2,2,4);
    stem(n,x4);
    title (sprintf ("x4"));
    
  %{
    Análisis de las funciones x1, x2, x3, x4
    x1: se puede apreciar que los puntos maximos se dan en 4 y 8, 
      por lo que se determina que el periodo T = 4
    x2: se puede apreciar que los puntos minimos ocurren en 12 y 28
      por lo que se puede concluir que el periodo es T = 16
    x3: se puede apreciar que los puntos maximos se dan en 7 y 15
      lo que sugiere que el periodo es T = 8
    x4: se puede apreciar que los puntos  maximos de funcion x4 varian.
    Estos puntos maximos no coinciden el uno con los siguientes.
  %}
  

  % Se crea otra figura en donde se mostrarán las figuras y1, y2, y3
  figure(2);
  
  y1 = x1+x2;
  y2 = x1+x2-x3;
  y3 = x1+x2-x3-2*x4;
  
  subplot(2,2,1);
    stem(n,y1);
    title (sprintf ("y1"));
  subplot(2,2,2);
    stem(n,y2);
    title (sprintf ("y2"));
  subplot(2,2,3);
    stem(n,y3);
    title (sprintf ("y3"));

  %{
    Análisis de las funciones y1, y2, y3
    y1: la funcion aparenta tener un periodo T = 16, ya que sus puntos
      maximos coinciden en 20 y 36
    y2: la funcion aparenta tener un periodo T = 16, ya que sus puntos
      minimos coinciden en 14 y 30
    y3: la funcion no aparenta tener un periodo definido, no se encuentran
      coincidencias entre puntos.
    
  %}
  
endfunction
