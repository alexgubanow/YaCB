close all; clc; clear;
wpts = rand([3,100])*100;
t = 0:1:length(wpts)-1;
%[x, v, a, tvec, pp] = trapveltraj(wpts, 501,'PeakVelocity',5,'Acceleration',300);
[x, v, a, tvec, pp] = trapveltraj(wpts, length(wpts));
%subplot(2,1,1)
figure(1)
hold on
plot(t,wpts, 'r*')
plot(tvec, x)
xlabel('t')
ylabel('Positions')
legend('Xr','Yr','Zr','X','Y','Z')
%subplot(2,1,2)
figure(2)
plot(tvec, v)
xlabel('t')
ylabel('Velocities')
legend('X','Y', 'Z')
figure(3)
plot(tvec, a)
xlabel('t')
ylabel('Accel')
legend('X','Y', 'Z')