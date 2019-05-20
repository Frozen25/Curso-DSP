function notchFilter()
  t= -100:1:100; % fs=300Hz
  x = 2+cos(50*(t)+0.5)+sin(60*(t)-1/4);
  figure(1);
  plot(t,x);
  grid on;
  fs=300;f0=60;
  b0=1; 
  b1=-2*cos(2*pi*f0/fs);
  b2=1;
  r=0.96;
  a0=1;
  a1=-2*r*cos(2*pi*f0/fs)
  a2=r*r;
  b=[b2,b1,b0];
  a=[a2,a1,a0];
  [h,w]=freqz(b,a);
  hf=abs(h);
  figure(2);
  freqz_plot(w*fs/(2*pi),h);
  title(' Response');
  xlabel('Freguency in Hz');
  figure(3);
  zplane(b,a);legend('zero','plot');
  grid on;
  y = filter(b,a,x);
  figure(4)
  plot(t,y);
  grid on;
endfunction
