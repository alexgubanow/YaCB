close all; clc; clear;
curr = 0;
dst = 10;
dt = 0.0001;
dir = sign(dst - curr);
[x1, v1, distToTrav] = calcAcStage(curr, (dst / 2), 2 * dir, 3 * dir, dt);

if (distToTrav > 0)
    [x2, v2] = calcT2stage(x1(end), v1(end), x1(end) + (distToTrav * dir), dt);
end
hold on
figure(1);
v3 = fliplr(v1);
x3 = zeros(1, length(v3));
x = x1;
v = v1;
if(exist('x2', 'var') > 0)
    lastX = x2(end);
    x = [x1 x2];
    v = [v1 v2];
end
x3(1) = x(end) + v3(1) * dt;
for i=2:length(v3)
    x3(i) = x3(i - 1) + v3(i) * dt;
end
plot([v v3]);
figure(2);
plot([x x3]);
% figure(3);
% plot([t1 t3], [a1 fliplr(a1)]);

function [x, v, distToTrav] = calcAcStage(curr, dst, maxV, maxA, dt)
distToTrav = sqrt((dst - curr)^2);
aT1 = maxA;
v(1) = aT1 * dt;
x(1) = curr + v(1) * dt;
i = 2;
while(v(i - 1) < maxV && distToTrav > 0)
    v(i) = v(i - 1) + aT1 * dt;
    x(i) = x(i - 1) + v(i) * dt;
    distToTrav = distToTrav - v(i) * dt;
    i = i + 1;
end
v(end)=[];
x(end)=[];
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