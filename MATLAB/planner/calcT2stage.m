function [x,v] = calcT2stage(initX, initV, targetX, dt)
v(1) = initV;
x(1) = initX + v(1) * dt;
distToTrav = sqrt((targetX - initX)^2);
i = 2;
while(distToTrav > 0)
    v(i) = v(i - 1);
    x(i) = x(i - 1) + v(i) * dt;
    distToTrav = distToTrav - abs(v(i)) * dt;
    i = i + 1;
end
end