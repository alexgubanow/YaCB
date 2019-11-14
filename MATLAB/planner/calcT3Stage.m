function [x, v] = calcT3Stage(initX, initV, targetX, maxA, dt)
distToTrav = sqrt((targetX - initX)^2);
v(1) = initV + maxA * dt;
x(1) = initX + v(1) * dt;
i = 2;
while(abs(v(i - 1)) > 0 && distToTrav > 0)
    v(i) = v(i - 1) + maxA * dt;
    x(i) = x(i - 1) + v(i) * dt;
    distToTrav = distToTrav - abs(v(i)) * dt;
    i = i + 1;
end
v(end)=[];
x(end)=[];
end