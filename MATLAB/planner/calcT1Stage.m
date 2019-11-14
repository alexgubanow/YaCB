function [x, v, distToTrav] = calcT1Stage(initX, targetX, maxV, maxA, dt)
distToTrav = sqrt((targetX - initX)^2);
v(1) = maxA * dt;
x(1) = initX + v(1) * dt;
i = 2;
while(abs(v(i - 1)) < abs(maxV) && distToTrav > 0)
    v(i) = v(i - 1) + maxA * dt;
    x(i) = x(i - 1) + v(i) * dt;
    distToTrav = distToTrav - abs(v(i)) * dt;
    i = i + 1;
end
v(end)=[];
x(end)=[];
end