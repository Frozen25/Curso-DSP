%{
Integrantes
=========================
Gladys Arias 
Alexis Gavriel
Cristian Rivera 
Andres Vargas (Autor del código del ejercicio_5)
Fecha: Marzo 15, 2019.

Descripción del algoritmo
=========================
algoritmo: The main functionality of the algorithm is to calculate values for the
equivalence between a continuous equation with time dependecy and for the discreet
mapping of this function with sampling frequency dependecy.
----------------------Variables-------------------------------------
A= Amplitude of the signal
fo= Frequency of the signal
fs = Sampling Frequency
Phase = The phase degree, it will be convert to radians in the code
t = specific time to evaluate
n = number of the sampling
----------------------Equations-------------------------------------
s(t) = Asin(2π*fo*t+phase)
s(n) = Asin(2π*(fo/fs)*n+phase)
%}
function ejercicio5()
      %---------------Input Menu Section----------------------------
    choice = yes_or_no ("Do you want to set your own values?\nIf not the preset demo will run");
    if(!choice)
      %---------------Run preset test-------------------------------
      getGraph(10,50,300,0,0.10,1);
      ejercicio5();
    else
      %---------------Input Values Section--------------------------
      amp = input ("Select Amplitude\n");
      fo = input ("Select Signal Frequency in Hz\n"); 
      fs = input ("Select Sampling Frequency in Hz\n");
      init = input ("Select Intial Time in Seconds\n");
      final = input ("Select Final Time in Seconds\n");
      phase = input ("Select Phase Degrees\n");
      getGraph(amp,fo,fs,init,final,phase);
      ejercicio5();
    endif
  
end
%---------------------Main Function--------------------
function getGraph(amp,fo,fs,init,final,phase)
  ts = (1/fs); %period of the sampling
  f= fo/fs; %normalized frequency
  ite =(final-init)/(ts); % max n int value
  n=0:ite; 
  t = linspace(init,final,1000);  %iterations for s(t)
  phaseShift = phase * pi/180; % In radians.
  st = amp*sin(2*pi*t*fo - phaseShift); % s(t) function
  sn = amp*(sin(2*pi*f*n+phaseShift)); % s(n) function
  %-----------------plot section-----------------------
  plot(t,st, 'LineWidth', 2);
  hold on
  stem(n*ts,sn);
  hold off
  %----------------Information Section-----------------
  title('Discreet Senosoid');
  xlabel('Time in secs');
  ylabel('Magnitude');
  legend('s(t)','s(n)');
  grid on;
  % Enlarge figure to full screen.
  set(gcf, 'units','normalized','outerposition',[0 0 1 1]);
endfunction

