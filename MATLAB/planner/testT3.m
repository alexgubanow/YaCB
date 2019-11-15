close all; clc; clear;
maxV = 6;
maxA = 1;
curr = 100;
dst = 0;
dt = 0.00001;
[x, v] = calcT3Stage(curr, dst, maxV * dir,  0-(maxA * dir), dt);
x(end - 2)
x(end - 1)
x(end)
v(end - 2)
v(end - 1)
v(end)
figure(1);
plot(v);
figure(2);
plot(x);



