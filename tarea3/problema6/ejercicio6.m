function b = ejercicio6 (wo)
  n=[0:1:100];
  k=[1,2];
  %Señal de entrada 
  x=cos(wo*n);
  %Ecuacion de Diferencia que genera y1(n)=Asen(won), y2(n)=Acos(won)
  %Y_k(n)=((A2/A)*x(n)+((A1*sen(wo)-A2*cos(wo))/A)x(n-1))+y(n-1)
  i=sqrt(-1);
  A=0;
  for j=k, 
    A=A+1;   
    q=-1/i^A;
    A1=(1-(-1)^A);
    A2=(1+(-1)^A);
    if (A==1)
      y1=filter([A2/(2*q),(A1*i*sin(wo)/(2*q)-A2*cos(wo)/(2*q))],[1,-cos(wo)],x);
    elseif (A==2)
      y2= filter([A2/(2*q),(A1*i*sin(wo)/(2*q)-A2*cos(wo)/(2*q))],[1,-cos(wo)],x);
    endif
endfor
   
   plot(n,y1, "-;y1(t)=Asen(nwo) A=1;r", "linewidth",2,y2,"-b;y2(t)=Acos(nwo) A=1;","linewidth",2);
   title("señales ortogonales y1(n) y y2(n) wo=0.05");
   xlabel("n");
    
endfunction
