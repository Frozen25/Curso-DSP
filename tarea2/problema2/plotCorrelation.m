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
between two discrete time signals.
----------------------Variables-------------------------------------
x= First discrete time signal x(n) 
nx= Array of the same size than x that describes the shift of the first sample
h = Second discrete time signal h(n) 
nh = Array of the same size than h that describes the shift of the first sample
----------------------Equations-------------------------------------
y(n) = sum from -infinite to infinite of (x(n)*h(k-n)) 
%}
function result = plotCorrelation(x,nx,h,nh)
  if(numel(x)!=numel(nx)|| numel(h)!=numel(nh))
    printf("The length of arrays does not match:\n");
    return;
  endif
  lx = numel(x);
  lh = numel(h);
  sx = centerSignal(x,nx);
  sh = centerSignal(h,nh);
  sh = flip(sh);  
  result = convSignals(sx,sh);
  result = shiftCorr(nx,nh,result);
  lres= (-lh+1-(nh(1)):(numel(result)-lh)-(nh(1)));
  plotCorr(nx,x,'Function x(n)');
  plotCorr(nh,h,'Impulse Response');
  plotCorr(lres,result,'Discrete Correlation');
endfunction

function plotCorr(nf,f,t)
  figure
  hold on
  stem(nf,f);
  hold off 
    %----------------Information Section-----------------
  title(t);
  xlabel('Time in secs');
  ylabel('Magnitude');
  legend('s(t)','s(n)');
  grid on;
  % Enlarge figure to full screen.
  set(gcf, 'units','normalized','outerposition',[0 0 1 1]);
endfunction

function res = shiftCorr(nx,nh,corr)
  if(nx(1)>0)
    corr = corr(abs(nx(1))+1:numel(corr));
  else 
    corr = corr(1:numel(corr)-abs(nx(1)));
  endif
  if(nh(1)<0)
    corr = corr(abs(nh(1))+1:numel(corr));
  else
    corr = corr(1:numel(corr)-abs(nh(1)));
  endif    
  res = corr;
endfunction
