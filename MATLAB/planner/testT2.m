close all; clc; clear;
maxV = 6;
curr = 82;
dst = 18;
dt = 0.00001;
distToTrav = abs(dst - curr);
dir = sign(dst - curr);
[x2, v2] = calcT2stage(curr, maxV * dir, abs(dst - curr), dt);
x2(end - 2)
x2(end - 1)
x2(end)
v2(end - 2)
v2(end - 1)
v2(end)
%hold on
% figure(1);
% plot(v);
% figure(2);
% plot(x);


