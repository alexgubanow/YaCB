close all; clc; clear;
curr = 0;
dst = 10;
dt = 0.0001;
dir = sign(dst - curr);
distToTrav = sqrt(((dst / 2) - curr)^2);
[x1, v1, distToTrav] = calcT1Stage(curr, distToTrav, 2 * dir, 3 * dir, dt);
x = x1; v = v1;

if (distToTrav > 0)
    [x2, v2] = calcT2stage(x(end), v(end), x(end) + (distToTrav * dir), dt);
    x = [x x2]; v = [v v2];
end
hold on
figure(1);
v3 = fliplr(v1);
x3 = zeros(1, length(v3));
x3(1) = x(end) + v3(1) * dt;
for i=2:length(v3)
    x3(i) = x3(i - 1) + v3(i) * dt;
end
x = [x x3]; v = [v v3];
plot(v);
figure(2);
plot(x);
% figure(3);
% plot([t1 t3], [a1 fliplr(a1)]);




