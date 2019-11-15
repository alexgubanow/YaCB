close all; clc; clear;
maxV = 6;
maxA = 1;
curr = 0;
dst = 18;
dt = 0.0001;
dir = sign(dst - curr);
[x, v, accelL] = calcT1Stage(curr, dst, maxV * dir, maxA * dir, dt);
%x = rot90(x, 2);
v = fliplr(v);
accelL
x(end - 2)
x(end - 1)
x(end)
v(end - 2)
v(end - 1)
v(end)
%hold on
figure(1);
plot(v);
figure(2);
plot(x);



