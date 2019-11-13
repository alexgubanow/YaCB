close all; clc; clear;
p1 = 0;
p2 = 1;
[x1, v1, a1, t1] = calcT1Stage(p1, p2, 200, 2000, 0.0001, 0);
[x3, ~, a3, t3] = calcT3Stage(p2, p1, 200, 2000, 0.0001, 0);
v3 = fliplr(v1);
figure(1);
hold on
plot([t1 t3], [v1 fliplr(v1)]);
[x1p, x3p] = findJointPoint(v1, fliplr(v1));
plot(t1(x1p), v1(x1p),'r*');
plot(t3(x3p), v3(x3p),'go');
% figure(2);
% plot([t1 t3], [v1 fliplr(v1)]);
% figure(3);
% plot([t1 t3], [a1 fliplr(a1)]);




function [i, j] = findJointPoint(Xt1, Xt3)

i = 2;
j = 2;

while(Xt3(j) - Xt1(i) > 0)
    i = i + 1;
    j = j + 1;    
end
    i = i - 1; 
end