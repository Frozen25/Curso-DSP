function d=ejercicio_1()
  t=[0:1/18:2];
  n=[0:1:36];
  x1=exp(cos(40*pi*t/9));
  x2=exp(cos(40*pi*n/9));
  #plot(t,x1, "-;X1(t);r", "linewidth",2,x2,"-b;X2(n);","linewidth",2);

  xlabel ("t");
  ylabel ("X1(t)");
  title ("Plot for continus time")
  subplot (2, 1, 1)
  plot (t,x1, "-;X1(t);r", "linewidth",2);
  subplot (2, 1, 2)
  stem (n,x2,"-;X2(n);","linewidth",2);
  end