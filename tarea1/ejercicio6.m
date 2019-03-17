
%{
Integrantes:
Gladys Arias
Alexis Gavriel
Cristian Rivera (Autor del código del ejercicio)
Andres Vargas
Fecha: Marzo 15, 2019.
%}


%playtone: recibe el tono al cual se quiere reproducir el sonido (parametro tone) y reproduce este
%y luego sus armonicos.
%opcionalmente puede recibir el paramtro sampling_rate con el que se tiene la cantidad
%de muestras por segundo. Si el sampling_rate es menor a 44100 se toma 44100 por defecto
%finalmente si se quiere cambiar la duración de cada armonico solo debe cambiarse el paramemtro duration
%este esta medido en segundos, así que si se quiere que la duración sea de medio segundo
%por armonico entonces la duración debe ser 0.5
function playtone(tone, sampling_rate = 44100,duration = 5)
  %selecciona el valor maximo del sampling_rate
  %si es menor al doble del espectro audible se usa 44100 para las muestras
  sampling_rate = max(44100,sampling_rate);
  %calcula la cantidad de armonicos que hay disponibles en el espectro audible para ese tono
  %esto se calcula despejando de la formula: tone * 2^armonics <= sampling_rate/2
  %donde armonics representa la cantidad maxima de armonicos
  %como estos son enteros al despejar la fomula  se tiene que usar la funcion floor para obtener el
  %valor entero.
  armonics = floor(log2(sampling_rate./(2.*tone)));
  %obtiene un arreglo desde cero hasta la cantidad de segundos por la cantidad de armonicos
  %por la cantidad de muestras de sonido
  samples = 0:(sampling_rate*armonics*duration*length(tone));
  %genera la señal donde: tone .* 2.^floor(samples/sampling_rate/duration)
  %obtiene un vector donde con los valores correspondientes de cada armonico
  %ejemplo para 440 se tiene 440,880,1720...
  signal = sin(2*pi*samples/sampling_rate .* tone .* 2.^floor(samples/sampling_rate/duration/length(tone)));
  %se construye el objecto que va a ser objeto de reproducción
  player = audioplayer (signal, sampling_rate);
  %se reproduce el objeto
  play (player);
  %bucle vacio que espera hasta que se termine de reproducir la señal
  while(isplaying(player))
  endwhile
endfunction;
