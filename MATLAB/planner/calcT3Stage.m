function [x, v] = calcT3Stage(initX, initV, maxA, dt)
i = 1;
v(i) = initV + maxA * dt;
x(i) = initX - initV * dt + 1/2*(maxA * dt^2);
while(abs(v(i)) > abs(maxA * dt) / 2)    
    i = i + 1;
    v(i) = v(i - 1) + maxA * dt;
    x(i) = x(i - 1) + v(i - 1) * dt + 1/2*(maxA * dt^2);
end
end