function [x, v, distToTrav] = calcT1Stage(initX, targetX, maxV, maxA, dt)
distToTrav = abs(targetX - initX);
v(1) = maxA * dt;
x(1) = initX ;
%  distToTrav = distToTrav - abs(v(1)) * dt;
i = 2;
while(abs(v(i - 1)) <= abs(maxV) && distToTrav > 0)
    v(i) = v(i - 1) + maxA * dt;
    x(i) = x(i - 1) + v(i - 1) * dt + 1/2*(maxA * dt^2);
    distToTrav = distToTrav - abs(v(i - 1)) * dt + 1/2*(maxA * dt^2);
    i = i + 1;
end
distToTrav = distToTrav + abs(v(end - 1)) * dt + 1/2*(maxA * dt^2);
v(end)=[];
x(end)=[];
% v(end)=[];
% x(end)=[];
end