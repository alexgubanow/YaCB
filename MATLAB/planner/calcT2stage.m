function [x,v] = calcT2stage(initX, initV, maxX, dt)
v(1) = initV;
x(1) = initX + v(1) * dt;
distToTrav = maxX - initX;
i = 2;
while(distToTrav > 0)
    v(i) = v(i - 1);
    x(i) = x(i - 1) + v(i) * dt;
    distToTrav = distToTrav - v(i) * dt;
    i = i + 1;
end
end