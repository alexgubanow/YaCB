function [x, v, distToTrav] = calcT1Stage(initX, distToTrav, maxV, maxA, dt)
aT1 = maxA;
v(1) = aT1 * dt;
x(1) = initX + v(1) * dt;
i = 2;
while(v(i - 1) < maxV && distToTrav > 0)
    v(i) = v(i - 1) + aT1 * dt;
    x(i) = x(i - 1) + v(i) * dt;
    distToTrav = distToTrav - v(i) * dt;
    i = i + 1;
end
v(end)=[];
x(end)=[];
end