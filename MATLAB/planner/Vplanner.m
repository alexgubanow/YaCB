function [x,v,a] = Vplanner(wpts, maxV, maxA, dt)
for p = 2 : length(wpts) - 1
    initV = 0;
    if(exist('v', 'var'))
        initV = v(end);
    end
    [xS, vS] = calcStages(wpts(p - 1), wpts(p), wpts(p + 1), initV, maxV, maxA, dt);
    if(exist('x', 'var') == 0)
        x = xS; v = vS;
    else
        x = [x xS]; v = [v vS];
    end  
end

end

function [x, v] = calcStages(prevX, nowX, nextX, initV, maxV, maxA, dt)
    dir = sign(nowX - prevX);
    nextDir = sign(nextX - nowX);
    distToTrav = sqrt(((nowX) - prevX)^2);
    if(dir ~= nextDir)
        distToTrav = sqrt(((nowX / 2) - prevX)^2);
    end
    %if last velocity of prev segment is zero
    %we are or deaccel prev or at start point
    if(initV == 0)
        %how long we can accel
        %calc accel stage
        [x1, v1, distToTrav] = calcT1Stage(prevX, distToTrav, maxV * dir, maxA * dir, dt);
        x = x1; v = v1;
    end
    if (distToTrav > 0)
        if(exist('v', 'var'))
            initV = v(end);
        end
        initX = prevX;
        if(exist('x', 'var'))
            initX = x(end);
        end        
        [x2, v2] = calcT2stage(initX, initV, initX + (distToTrav * dir), dt);         
        if(exist('v', 'var'))
            v = [v v2];
        else
            v = v2;
        end
        if(exist('x', 'var'))
            x = [x x2];
        else
            x = x2;
        end
    end
    
    %calc deaccel if needed
    if(dir ~= nextDir)
        if(exist('v', 'var'))
            initV = v(end);
        end
        initX = prevX;
        if(exist('x', 'var'))
            initX = x(end);
        end
        [x3, v3] = calcT3Stage(initX, initV, nowX, 0-(maxA * dir), dt);
        if(exist('v', 'var'))
            v = [v v3];
        else
            v = v3;
        end
        if(exist('x', 'var'))
            x = [x x3];
        else
            x = x3;
        end
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













