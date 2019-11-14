close all; clc; clear;
maxV = 2;
maxA = 1;
curr = 10;
dst = 0;
dt = 0.0001;
dir = sign(dst - curr);

[x1, v1, distToTrav] = calcT1Stage(curr, (dst / 2), maxV * dir, maxA * dir, dt);
x = x1; v = v1;

if (distToTrav > 0)
    [x2, v2] = calcT2stage(x(end), v(end), distToTrav, dt);
    x = [x x2]; v = [v v2];
end
[x3, v3] = calcT3Stage(x(end), v(end), dst, maxA * dir, dt);
x = [x x3]; v = [v v3];
hold on
figure(1);
% v3 = fliplr(v1);
% x3 = zeros(1, length(v3));
% x3(1) = x(end) + v3(1) * dt;
% for i=2:length(v3)
%     x3(i) = x3(i - 1) + v3(i) * dt;
% end
% x = [x x3]; v = [v v3];
plot(v);
figure(2);
plot(x);
% figure(3);
% plot([t1 t3], [a1 fliplr(a1)]);




