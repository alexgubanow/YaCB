close all; clc; clear;
p1 = 0;
p2 = 10;
[x, v, a, t] = calcT1Stage(p1, p2, 2, 20, 0.0001, 0);
figure(1);
hold on
plot(t, v);
% figure(2);
% plot([t1 t3], [v1 fliplr(v1)]);
% figure(3);
% plot([t1 t3], [a1 fliplr(a1)]);

function [v, a] = calcT1T3Stage(maxX, maxV, maxA, dt)
a(1) = maxA;
v(1) = a(1) * dt;
i = 2;
while(v(i - 1) < maxV && x(i - 1) < maxX)
    a(i) = a(i - 1);
    v(i) = v(i - 1) + a(i) * dt;
    i = i + 1;
end
a(end)=[];
v(end)=[];
end


function [i, j] = findJointPoint(Xt1, Xt3)

i = 2;
j = 2;

while(Xt3(j) - Xt1(i) > 0)
    i = i + 1;
    j = j + 1;    
end
    i = i - 1; 
end