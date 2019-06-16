function prueba()
  
  for i = [-0.2:0.1:0.96]    
    fs=300;f0=60;
    b0=1; 
    b1=-2*cos(2*pi*f0/fs);
    b2=1;
    r=0.96;
    a0=1;
    a1=-2*i*cos(2*pi*f0/fs)
    a2=i*i;
    b=[b2,b1,b0];
    a=[a2,a1,a0];
    [h,w]=freqz(b,a);
    hf=abs(h);
    
    freqz_plot(w*fs/(2*pi),h);
    hold on
    title(' Response');
    xlabel('Freguency in Hz');
    
  endfor
  hold off
endfunction