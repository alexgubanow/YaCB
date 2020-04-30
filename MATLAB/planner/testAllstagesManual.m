close all; clc; clear;
maxV = 6;
maxA = 1;
curr = 60;
dst = 0;
dt = 0.00001;
dir = sign(dst - curr);
origL = abs(dst - curr);
distToTrav = origL;
[x1, v1, accL] = calcT1Stage(curr, (origL / 2), maxV * dir, maxA * dir, dt);
x = x1; v = v1;
distToTrav = distToTrav - accL;
[x3, v3, deaccL] = calcT3Stage(curr, dst, v(end), 0-(maxA * dir), dt);
distToTrav  = distToTrav - deaccL;
if (distToTrav > 0)
    [x2, v2] = calcT2stage(x(end), v(end), distToTrav, dt);
    x = [x x2]; v = [v v2];
end
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



