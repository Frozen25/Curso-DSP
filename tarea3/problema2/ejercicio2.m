%{
Integrantes
=========================
Gladys Arias (Autora del código del ejercicio_4)
Alexis Gavriel
Cristian Rivera 
Andres Vargas
Fecha: Mayo 19, 2019.

Descripción del algoritmo
=========================
algoritmo: 
%}
function b= ejercicio2 ()
  n=[0:1:200];
  a=0.8;
  y0=0;#y(-1)=0
  fi=[1/4,1/5,1/10,1/20];
  c=0;
  %Ecuacion de diferencias
  %y(n)=(1-a)x(n)-ay(n-1)
  for i=fi,
    c=c+1;
    xi=sin(2*pi*i*n); %Calculo de X_i
    y=filter([1-a],[1,a],xi);
    figure 1
    title('yi(n)')
    subplot (4, 1, c)
    plot(n,y);
    xlabel ("N");
    ylabel ("Yi(t)");
    
    [h,w]=freqz([1-a],[1,a],n,"whole");
    %Ploteo de la senal modulada tanto en frecuencia como en magniud 
    figure 2
    freqz_plot(w,h);
  endfor

endfunction
