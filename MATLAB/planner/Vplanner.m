function [x,v,a] = Vplanner(wpts, maxV, maxA, dt)
segV = zeros(length(wpts) - 1,1);

for p = 2 : length(wpts) - 1    
    T2stageStart = x(p - 1);
    %if last velocity of prev segment is zero
    %we are or deaccel prev or at start point
    if(segV(p - 1) == 0)
        %calc accel stage
        [xT1, vT1, aT1, endI] = calcAccelStage(wpts(p - 1), maxV, maxA, dt);
        x = [x xT1]; v = [v vT1]; a = [a aT1];
        T2stageStart = p - 1 + endI;
    end
    %how long we could keep curr velocity
    if(x(T2stageStart) < wpts(p))
        %fill zero accel stage
        [xT2,vT2,aT2] = calcT2stage(x(T2stageStart), v(T2stageStart), wpts(p), dt);
        x = [x xT2]; v = [v vT2]; a = [a aT2];
    end
    %calc deaccel if needed
    if()
    end
end

end


function [x, v, a, endI] = calcAccelStage(initX, maxX, maxV, maxA, dt)
a(1) = maxA;
v(1) = a(1) * dt;
x(1) = initX + v(1) * dt;
i = 2;
while(v(i - 1) < maxV && x(i - 1) < maxX)
    a(i) = a(i - 1);
    v(i) = v(i - 1) + a(i) * dt;
    x(i) = x(i - 1) + v(i) * dt;
    i = i + 1;
end
endI = i - 1;
end

function [x,v,a] = calcT2stage(initX,initV, maxX,dt)
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













