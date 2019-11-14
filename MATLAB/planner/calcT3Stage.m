function [x, v, distToTrav] = calcT3Stage(initX, initV, distToTrav, maxA, dt)
v(1) = initV + maxA * dt;
x(1) = initX - initV * dt + 1/2*(maxA * dt^2);
distToTrav = distToTrav - initV * dt + 1/2*(maxA * dt^2);
i = 2;
while(distToTrav > 0)
    v(i) = v(i - 1) + maxA * dt;
    x(i) = x(i - 1) + v(i - 1) * dt + 1/2*(maxA * dt^2);
    distToTrav = distToTrav - abs(v(i - 1)) * dt + 1/2*(maxA * dt^2);
    i = i + 1;
end
% v(end)=[];
% x(end)=[];
% v(end)=[];
% x(end)=[];
end