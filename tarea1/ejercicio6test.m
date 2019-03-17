%{
Integrantes
=========================
Gladys Arias
Alexis Gavriel
Cristian Rivera (Autor del código del ejercicio)
Andres Vargas
Fecha: Marzo 15, 2019.

Descripción del archivo
=========================
ejemplos de llamadas a la funcione playtone, esto mediante la llamada al archivo ejercicio6 como alias de la función playtone.

%}

%La 440 vs La 432 - La legendaria batalla entre sonidos

%reproduzca el tono 440 con 44100 de muestras por segundo y cada armonico de el tono
%440 se reproduce a 0.5 segundos
display('La 440Hz vs La 432Hz');
display('La 440Hz, a 44100Hz muestras por segundo, con duración 0.5s');
display('Presione alguna tecla para continuar');
pause();
ejercicio6(440,44100,0.5);

%reproduzca el tono 432 con 44100 de muestras por segundo y cada armonico de el tono
%432 se reproduce a 0.5 segundos
display('La 432Hz, a 44100Hz muestras por segundo, con duración 0.5s');
display('Presione alguna tecla para continuar');
pause();
ejercicio6(432,5,0.5);


%reproduzca el tono 440 con 44100 de muestras por segundo y cada armonico de el tono
%440 se reproduce a 5 segundos
display('La 440Hz, a 44100Hz muestras por segundo, con duración 5s');
display('Presione alguna tecla para continuar');
pause();
ejercicio6(440);

%reproduzca el tono 432 con 44100 de muestras por segundo y cada armonico de el tono
%432 se reproduce a 5 segundos
display('La 432Hz, a 44100Hz muestras por segundo, con duración 5s');
display('Presione alguna tecla para continuar');
pause();
ejercicio6(432);

