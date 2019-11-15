close all; clc; clear;
%wpts = rand([3,100])*100;
wpts = [0, 100, 0];
dt = 0.00001;
%[x, v, a, tvec, pp] = trapveltraj(wpts, 501,'PeakVelocity',1,'Acceleration',0.1);
[x, v] = Vplanner(wpts, 6, 1, dt);
t = 0:length(x)/(length(wpts)-1):length(x);
%subplot(2,1,1)
figure(1)
hold on
%%plot(t,wpts(1:end - 1), 'r*')
plot(x)
xlabel('t')
ylabel('Positions')
% legend('Xr','Yr','Zr','X','Y','Z')
%subplot(2,1,2)
figure(2)
plot(v)
xlabel('t')
ylabel('Velocities')
% legend('X','Y', 'Z')