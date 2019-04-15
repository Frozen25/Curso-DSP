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
  plotCorr(x,nx,h,nh,result,lres);
endfunction

function plotCorr(x,nx,h,nh,r,nr)
	figure('name','Discrete Time Correlation of two signals');
	subplot(3,1,1);	 
	  stem(nx,x);
	  title (sprintf ("x(n) Function"));
	subplot(3,1,2);
	  stem(nh,h);
	  title (sprintf ("h(n) Impulse Response"));
	subplot(3,1,3);
	  stem(nr,r);
	  title(sprintf ("Discrete Time Correlation Result"));
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
