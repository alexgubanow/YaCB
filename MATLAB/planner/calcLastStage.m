function [x, v] = calcLastStage(prevX, nowX, initV, maxV, maxA, dt)
    dir = sign(nowX - prevX);
    origL = abs(nowX - prevX);
    accelL = origL / 2;
    distToTrav = origL;
    %if last velocity of prev segment is zero
    %we are or deaccel prev or at start point
    if(abs(initV) < abs(maxA * dt)/2)
        %how long we can accel
        %calc accel stage
        [x1, v1, accelL] = calcT1Stage(prevX, accelL, maxV * dir, maxA * dir, dt);
        x = x1; v = v1;
        distToTrav = distToTrav - accelL;
        
    end
    %calc deaccel if needed
    
        if(exist('v', 'var'))
            if(length(v) > 1)
                initV = v(end);
            end
        end
        initX = prevX;
        if(exist('x', 'var'))
            initX = x(end);
        end
        [x3, v3, deaccL] = calcT3Stage(initX, nowX, initV, 0-(maxA * dir), dt);
        distToTrav  = distToTrav - deaccL;
    if (distToTrav > 0)
        if(exist('v', 'var'))
            initV = v(end);
        end
        initX = prevX;
        if(exist('x', 'var'))
            initX = x(end);
        end        
        [x2, v2] = calcT2stage(initX, initV, distToTrav, dt);         
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
    if(exist('v3', 'var'))
            v = [v v3];
    end
    if(exist('x3', 'var'))
        x = [x x3];
    end    
end