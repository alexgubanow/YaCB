function [x,v,a] = Vplanner(wpts, maxV, maxA, dt)
segV = zeros(length(wpts) - 1,1);

for p = 2 : length(wpts) - 1
    direction = sign(wpts(p) - wpts(p - 1));
    if(direction == 0)
        %in future need to provide sync between axes, by delaying some
        %some counts of zero move stage will be > 0
        [xZero, vZero, aZero] = zeroMovStage(wpts(p - 1), 0);
        x = [x xZero]; v = [v vZero]; a = [a aZero];
    else
        [xS, vS, aS] = calcStages(wpts(p - 1), wpts(p), wpts(p + 1), initV, maxV * direction, maxA * direction, dt);
        x = [x xS]; v = [v vS]; a = [a aS];
    end    
end

end

function [x, v, a] = calcStages(prevX, nowX, nextX, initV, maxV, maxA, dt)
    T2stageStart = prevX;
    accelSteps = 0;
    %if last velocity of prev segment is zero
    %we are or deaccel prev or at start point
    if(initV == 0)
        %how long we can accel
        %calc accel stage
        [xT1, vT1, aT1] = calcT1Stage(prevX, maxX, maxV, maxA, dt);
        x = [x xT1]; v = [v vT1]; a = [a aT1];
        T2stageStart = xT1(length(xT1));
        accelSteps = length(xT1);
    end
    nextDir = sign(wpts(p + 1) - wpts(p));
    %calc deaccel if needed
    T2stageEnd = nowX;
    xT3 = 0; vT3= 0; aT3 = 0;
    if(nextDir < 0)
        %find deaccel time, to make it in balance with accel
        deaccelCounts = 
        %calc deaccel
        [xT3, vT3, aT3] = calcT3Stage(nowX, maxV, maxA, dt);
        T2stageEnd = xT3(length(xT3));
    end
    %how long we could keep curr velocity
    if(T2stageStart < T2stageEnd)
        %fill zero accel stage
        [xT2,vT2,aT2] = calcT2stage(T2stageStart, v(T2stageStart), T2stageEnd, dt);
        x = [x xT2]; v = [v vT2]; a = [a aT2];
    end
    if(nextDir < 0)
        x = [x xT3]; v = [v vT3]; a = [a aT3];
    end
end




function [x,v,a] = calcT2stage(initX, initV, maxX, dt)
a(1) = 0;
v(1) = initV;
x(1) = initX + v(1) * dt;
i = 2;
while(x(i - 1) < maxX)
    a(i) = 0;
    v(i) = v(i - 1);
    x(i) = x(i - 1) + v(i) * dt;
    i = i + 1;
end
end

function [x,v,a] = zeroMovStage(initX, counts)
a = zeros(counts, 1);
v = zeros(counts, 1);
x = zeros(counts, 1);
for i = 1:counts
    x(i) = initX;
end
end













