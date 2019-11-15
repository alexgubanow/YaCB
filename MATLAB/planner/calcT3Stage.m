function [x, v, deaccelL] = calcT3Stage(initX, targetX, initV, maxA, dt)
dir = sign(targetX - initX);
deaccelL = 0;
i = 1;
v(i) = initV + maxA * dt;
x(i) = initV * dt + 1/2*(maxA * dt^2);
while(abs(v(i)) > abs(maxA * dt)/2)
    i = i + 1;
    v(i) = v(i - 1) + maxA * dt;
    x(i) = x(i - 1) + v(i - 1) * dt + 1/2*(maxA * dt^2);
    deaccelL = deaccelL + abs(v(i - 1)) * dt + 1/2*abs(maxA * dt^2);
end
x = x + targetX;
x = x - deaccelL * dir;
end