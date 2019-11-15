close all; clc; clear;
maxV = 6;
maxA = 1;
curr = 0;
dst = 100;
dt = 0.00001;
dir = sign(dst - curr);
origL = abs(dst - curr);
[x1, v1] = calcT1Stage(curr, (origL / 2), maxV * dir, maxA * dir, dt);
x = x1; v = v1;
deacceDist = abs((origL / 2) - distToTrav);
distToTrav = origL;
if (distToTrav > 0)
    [x2, v2] = calcT2stage(x(end), v(end), origL - deacceDist*2, dt);
    x = [x x2]; v = [v v2];
end
[x3, v3] = calcT3Stage(x(end), v(end), 0-(maxA * dir), dt);
x = [x x3]; v = [v v3];
distToTrav
x(end - 1)
x(end)
v(end - 1)
v(end)
hold on
figure(1);
plot(v);
figure(2);
plot(x);



