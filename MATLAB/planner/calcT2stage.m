function [x,v] = calcT2stage(initX, initV, distToTrav, dt)
v(1) = initV;
x(1) = initX;
% distToTrav = distToTrav - abs(v(1)) * dt;
i = 2;
while(distToTrav > 0)
    v(i) = initV;
    x(i) = x(i - 1) + initV * dt;
    distToTrav = distToTrav - abs(initV) * dt;
    i = i + 1;
end
end