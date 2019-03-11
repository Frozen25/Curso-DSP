1;

#######################
#

function ejercicio3()
  n = 0:50;
  x1 = cos(pi*n/2);
  x2 = sin(pi*n/8);
  x3 = cos(pi*n/4 + pi/3);
  x4 = cos(2*n/pi);
  
  figure(1);
  subplot(2,2,1);
    plot(n,x1);
  subplot(2,2,2);
    plot(n,x2);
  subplot(2,2,3);
    plot(n,x3);
  subplot(2,2,4);
    plot(n,x4);
    
  %{
    x1: se puede apreciar que los puntos maximos se dan en 4 y 8, 
      por lo que se determina que el periodo T = 4
    x2: se puede apreciar que los puntos minimos ocurren en 12 y 28
      por lo que se puede concluir que el periodo es T = 16
    x3: se puede apreciar que los puntos maximos se dan en 7 y 15
      lo que sugiere que el periodo es T = 8
    x4: se puede apreciar que los puntos  maximos de funcion x4 varian.
    Estos puntos maximos no coinciden el uno con los siguientes.
  %}
  
  figure(2);
  
  y1 = x1+x2;
  y2 = x1+x2-x3;
  y3 = x1+x2-x3-2*x4;
  
  subplot(2,2,1);
    plot(n,y1);
  subplot(2,2,2);
    plot(n,y2);  
  subplot(2,2,3);
    plot(n,y3);

  %{
    y1: la funcion aparenta tener un periodo T = 16, ya que sus puntos
      maximos coinciden en 20 y 36
    y2: la funcion aparenta tener un periodo T = 16, ya que sus puntos
      minimos coinciden en 14 y 30
    y3: la funcion no aparenta tener un periodo definido, no se encuentran
      coincidencias entre puntos.
    
  %}
  
endfunction
