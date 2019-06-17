function LowPassFilter(audio)
  info = audioinfo(audio);
  [y,fs] = audioread(audio);
  disp ("The value of pi is:"), disp (info);
  player = audioplayer (y, fs);
  soundsc (y, fs);
 endfunction