close all; clc; clear;
maxV = 6;
maxA = 1;
curr = 100;
dst = 0;
dt = 0.0001;
dir = sign(dst - curr);
[x1, v1, distToTrav] = calcT1Stage(curr, dst, maxV * dir, maxA * dir, dt);
distToTrav
x1(end - 2)
x1(end - 1)
x1(end)
v1(end - 2)
v1(end - 1)
v1(end)
%hold on
% figure(1);
% plot(v);
% figure(2);
% plot(x);



