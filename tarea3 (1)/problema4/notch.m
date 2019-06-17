%{
Integrantes
=========================
Gladys Arias 
Alexis Gavriel
Cristian Rivera 
Andres Vargas (Autor del código del ejercicio_5)
Fecha: Mayo 19, 2019.

Descripción del algoritmo
=========================
algoritmo: The main functionality of the algorithm is filter the specific 
frequencies required, in this case the frequencies to avoid is 60Hz this 
is implemented using a notch filter with two poles and two ceros.
----------------------Variables-------------------------------------
fo=  cut frequency = 60Hz
fs = Sampling Frequency 300Hz
bn = Equation ceros
an = Equation poles
t = time variation

----------------------Equations-------------------------------------
h(z)= (1-2cos(wn)*z^-1+2cos(wn)*z^-2)/(1-2cos(wn)*z^-1+2rcos(wn)*r^2*z^-2)
x = 2+cos(50*(t)+0.5)+sin(60*(t)-1/4); X equation in degrees
%}
function notch()
  t = -100:1:100 ; 
  x = 2+cos(50*(t)+0.5)+sin(60*(t)-1/4);
  fs=300;f0=60;
  g1 = 0.97;
  b0=1; 
  b1=-2*cos(2*pi*f0/fs);
  b2=1;
  r=0.98;
  a0=1;
  a1=-2*r*cos(2*pi*f0/fs)
  a2=r*r;
  b=[b2*g1,b1*g1,b0*g1];
  a=[a2,a1,a0];
  [h,w]=freqz(b,a);
  hf=abs(h);
  y = filter(b,a,x);
  figure(1)
  zplane(b,a);legend('zero','plot'); 
  grid on
  #Plot frequency response equation
  figure(2);
  freqz_plot(w*fs/(2*pi),h);
  title(' Response');
  xlabel('Freguency in Hz');
  grid on;
  #Plot y(t) filtered equation
  figure(3)
  subplot (2, 1, 1);
  stem(t,x);
  title(' X(t) in value');
  xlabel('Time in seconds');
  ylabel('y(t) unfiltered value');
  subplot (2, 1, 2);
  stem(t,y);
  title(' Filtered Signal');
  xlabel('Time in seconds');
  ylabel('y(t) filtered value');
  grid on;
 endfunction