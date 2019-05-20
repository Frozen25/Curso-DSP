figure (4);

%muestra la funcion de transferencia definida en el ejercicio 5
%esto para distintos valores de a
w = 0:0.01:2*pi;
h  = ((1) .- e.^(-i .* w ))./ (1 .- 0.1 .* e.^(-i .* w));
h2 = ((1) .- e.^(-i .* w ))./ (1 .- 0.2 .* e.^(-i .* w));
h3 = ((1) .- e.^(-i .* w ))./ (1 .- 0.4 .* e.^(-i .* w));
h4 = ((1) .- e.^(-i .* w ))./ (1 .- 0.6 .* e.^(-i .* w));
h5 = ((1) .- e.^(-i .* w ))./ (1 .- 0.8 .* e.^(-i .* w));
h6 = ((1) .- e.^(-i .* w ))./ (1 .- 0.9 .* e.^(-i .* w));
plot(w,abs(h));
set(gca,'XTick',0:pi/3:2*pi) 
set(gca,'XTickLabel',{'0','pi/3','2*pi/3','pi','4*pi/3','5*pi/3','2*pi'})

hold on;
plot(w,abs(h2));
hold on;
plot(w,abs(h3));
hold on;
plot(w,abs(h4));
hold on;
plot(w,abs(h5));
hold on;
plot(w,abs(h6));
hold off;


%muestra la funcion de transferencia para un filtro peine solicitado en el ejercicio 5
%(magnitud)
%esto para distintos valores de a
figure(5);
w = 0:0.01:2*pi;
h  = ((1/6) .- (1/6).* e.^(-i .* w * 6))./ (1 .- 0.1 .* e.^(-i .* w));
h2 = ((1/6) .- (1/6).* e.^(-i .* w * 6))./ (1 .- 0.2 .* e.^(-i .* w));
h3 = ((1/6) .- (1/6).* e.^(-i .* w * 6))./ (1 .- 0.4 .* e.^(-i .* w));
h4 = ((1/6) .- (1/6).* e.^(-i .* w * 6))./ (1 .- 0.6 .* e.^(-i .* w));
h5 = ((1/6) .- (1/6).* e.^(-i .* w * 6))./ (1 .- 0.8 .* e.^(-i .* w));
h6 = ((1/6) .- (1/6).* e.^(-i .* w * 6))./ (1 .- 0.9 .* e.^(-i .* w));
plot(w,abs(h));
set(gca,'XTick',0:pi/3:2*pi) 
set(gca,'XTickLabel',{'0','pi/3','2*pi/3','pi','4*pi/3','5*pi/3','2*pi'})

hold on;
plot(w,abs(h2));
hold on;
plot(w,abs(h3));
hold on;
plot(w,abs(h4));
hold on;
plot(w,abs(h5));
hold on;
plot(w,abs(h6));
hold off;


%muestra la funcion de transferencia para un filtro peine solicitado en el ejercicio 5
%(fase)
%esto para distintos valores de a
figure(6);

plot(w,rad2deg(arg(h)));
set(gca,'XTick',0:pi/3:2*pi) 
set(gca,'XTickLabel',{'0','pi/3','2*pi/3','pi','4*pi/3','5*pi/3','2*pi'})
hold on;
plot(w,rad2deg(arg(h2)));
hold on;
plot(w,rad2deg(arg(h3)));
hold on;

plot(w,rad2deg(arg(h4)));
hold on;
plot(w,rad2deg(arg(h5)));
hold on;
plot(w,rad2deg(arg(h6)));

hold off;





%muestra el diagrama de polos y veros para cada una de las funciones anteriormente creadas
%esto para distintos valores de a
pkg load signal;

figure(7);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.1]);
figure(8);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.2]);
figure(9);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.3]);
figure(10);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.4]);
figure(11);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.5]);
figure(12);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.6]);
figure(13);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.7]);
figure(14);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.5]);
figure(15);
zplane([1/6,0,0,0,0,0,-1/6],[1,-0.9]);




