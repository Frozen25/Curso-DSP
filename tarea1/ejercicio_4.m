%{
Integrantes
=========================
Gladys Arias (Autora del código del ejercicio_4)
Alexis Gavriel
Cristian Rivera 
Andres Vargas
Fecha: Marzo 15, 2019.

Descripción del algoritmo
=========================
algoritmo: La funcion toma una Señal X[n] y la descompone en su componente
par Xp[n] y su componente impar Xi[n] para luego sumar ambas componentes
y reconstruir  la Señal original X[n]
%}
function d=ejercicio_4(x)
  m=input('Ingrese el numero de muestras');
  m=m-1;
  n=-m:m;
  %========se crea un vector de [-n:n], con valores X[n]; n<0=0
  X=[zeros(1,m),x];
  %========se crea un vector de [-n:n], para X[-n]
  x1=fliplr(X);
  %=========logica de parte par
  Xp=X/2+x1/2;
  %=========logica de parte impar
  Xi=X/2-x1/2;
  xt=Xp+Xi;
  %=========plot de las Señal
  %plot para la primera seccion de la figura corresponde a la Señal original.
  %se le otorga el color por default
  subplot (4, 1, 1)
  stem(n,X,"filled");
  %Etiquetado de los ejes para la grafica de la Señal original discreta
  xlabel ("n");
  ylabel ("X(n)");
  title (" Señal original")
  
  %plot para la segunda seccion de la figura corresponde a la Componente Par de la Señal
  %se le otorga el color rojo
  subplot (4, 1, 2)
  stem(n,Xp,"filled","r");
  %Etiquetado de los ejes para la grafica de la Componente Par de la Señal discreta
  xlabel ("n");
  ylabel ("Xp(n)");
  title (" Componente Par")
  
  
  %plot para la Tercer seccion de la figura corresponde a la Componente Impar de la Señal
  %se le otorga el color verde
  subplot (4, 1, 3)
  stem(n,Xi,"g");
  %Etiquetado de los ejes para la grafica de la Componente Impar de la Señal discreta
  xlabel ("n");
  ylabel ("Xi(n)");
  title (" Componente Impar")
  
  %plot para la cuarta seccion de la figura corresponde a la Señal reconstruida apartir de la
  %componente par mas la componente impar.
  %se le otorga el color cian.
  subplot (4, 1, 4)
  stem(n,xt,"c");
  %Etiquetado de los ejes para la grafica para de la Señal discreta reconstruida.
  xlabel ("n");
  ylabel ("X(n)");
  title (" Xp(n)+Xi(n)")
  end
