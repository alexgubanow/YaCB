close all; clc; clear;
maxV = 3;
curr = 0;
dst = 1000;
dt = 0.00001;
[x2, v2] = calcT2stage(curr, maxV, dst, dt);
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


