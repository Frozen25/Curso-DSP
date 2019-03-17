function d=ejercicio_4(x)
  m=input('Ingrese el numero de muestras');
  m=m-1;
  n=-m:m;
  #========se crea un vector de [-n:n], con valores X[n]; n<0=0
  X=[zeros(1,m),x];
  #========se crea un vector de [-n:n], para X[-n]
  x1=fliplr(X);
  #=========logica de parte par
  Xp=X/2+x1/2;
  #=========logica de parte impar
  Xi=X/2-x1/2;
  xt=Xp+Xi;
  #=========plot de las Señal
  subplot (4, 1, 1)
  stem(n,X,"filled");
  xlabel ("n");
  ylabel ("X(n)");
  title (" Señal original")
  subplot (4, 1, 2)
  stem(n,Xp,"filled","r");
  xlabel ("n");
  ylabel ("Xp(n)");
  title (" Señal Par")
  subplot (4, 1, 3)
  stem(n,Xi,"g");
  xlabel ("n");
  ylabel ("Xi(n)");
  title (" Señal Impar")
  subplot (4, 1, 4)
  stem(n,xt,"c");
  xlabel ("n");
  ylabel ("X(n)");
  title (" Xp(n)+Xi(n)")
  end