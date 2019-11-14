close all; clc; clear;
%wpts = rand([3,100])*100;
wpts = [0, 10, 20, 10];
dt = 0.0001;
%[x, v, a, tvec, pp] = trapveltraj(wpts, 501,'PeakVelocity',5,'Acceleration',300);
[x, v] = Vplanner(wpts, 2, 3, dt);
t = 0:length(x)/(length(wpts)-1):length(x);
%subplot(2,1,1)
figure(1)
hold on
%%plot(t,wpts(1:end - 1), 'r*')
plot(x)
xlabel('t')
ylabel('Positions')
legend('Xr','Yr','Zr','X','Y','Z')
%subplot(2,1,2)
figure(2)
plot(v)
xlabel('t')
ylabel('Velocities')
legend('X','Y', 'Z')