function [x, v, a, t] = calcT1Stage(initX, maxX, maxV, maxA, dt, endT)
a(1) = maxA;
v(1) = a(1) * dt;
x(1) = initX + v(1) * dt;
t(1) = endT;
i = 2;
while(v(i - 1) < maxV && x(i - 1) < maxX)
    a(i) = a(i - 1);
    v(i) = v(i - 1) + a(i) * dt;
    x(i) = x(i - 1) + v(i) * dt;
    t(i) = t(i - 1) + dt;
    i = i + 1;
end
a(end)=[];
v(end)=[];
x(end)=[];
t(end)=[];
end