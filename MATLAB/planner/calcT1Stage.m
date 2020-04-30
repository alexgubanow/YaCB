function [x, v, accelL] = calcT1Stage(initX, targetX, maxV, maxA, dt)
distToTrav = abs(targetX - initX);
i = 1;
v(i) = maxA * dt;
x(i) = initX;
while(abs(v(i) - maxV) > abs(maxA * dt)/2 && distToTrav > 0)
    i = i + 1;
    v(i) = v(i - 1) + maxA * dt;
    x(i) = x(i - 1) + v(i - 1) * dt + 1/2 * (maxA * dt^2);
    distToTrav = distToTrav - abs(v(i - 1)) * dt + 1/2*abs(maxA * dt^2);
end
accelL = abs(targetX - initX) - distToTrav;
end