function [x,v,a] = Vplanner(wpts, maxV, maxA, dt)
for p = 2 : length(wpts) - 1
    direction = sign(wpts(p) - wpts(p - 1));
    if(direction == 0)
        %in future need to provide sync between axes, by delaying some
        %some counts of zero move stage will be > 0
        [xZero, vZero, aZero] = zeroMovStage(wpts(p - 1), 0);
        x = [x xZero]; v = [v vZero]; a = [a aZero];
    else
        initV = 0;
        if(exist('v', 'var'))
            initV = v(end);
        end        
        [xS, vS] = calcStages(wpts(p - 1), wpts(p), wpts(p + 1), initV, maxV * direction, maxA * direction, dt);
        if(exist('x', 'var') == 0)
            x = xS; v = vS;
        else
            x = [x xS]; v = [v vS];
        end  
    end    
end

%     directionLast = sign(wpts(end) - wpts(end - 1));
%     if(direction == 0)
%         %in future need to provide sync between axes, by delaying some
%         %some counts of zero move stage will be > 0
%         [xZero, vZero, aZero] = zeroMovStage(wpts(end - 1), 0);
%         x = [x xZero]; v = [v vZero]; a = [a aZero];
%     else
%         initV = 0;
%         if(exist('v', 'var'))
%             initV = v(end);
%         end        
%         [xS, vS] = calcLastStage(wpts(end - 1), wpts(end), initV, maxV * direction, maxA * direction, dt);
%         if(exist('x', 'var') == 0)
%             x = xS; v = vS;
%         else
%             x = [x xS]; v = [v vS];
%         end  
%     end

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
        v3 = fliplr(v1);
        x3 = zeros(1, length(v3));
        x3(1) = x(end) + v3(1) * dt;
        for i=2:length(v3)
            x3(i) = x3(i - 1) + v3(i) * dt;
        end
        x = [x x3]; v = [v v3];
    end
end

function [x, v] = calcLastStage(prevX, nowX, initV, maxV, maxA, dt)
    dir = sign(nowX - prevX);
    distToTrav = sqrt(((nowX / 2) - prevX)^2);
    %if last velocity of prev segment is zero
    %we are or deaccel prev or at start point
    if(initV == 0)
        %how long we can accel
        %calc accel stage
        [x1, v1, distToTrav] = calcT1Stage(prevX, distToTrav, maxV * dir, maxA * dir, dt);
        x = x1; v = v1;
    end
    if (distToTrav > 0)
        [x2, v2] = calcT2stage(x1(end), v1(end), x1(end) + (distToTrav * dir), dt);
        x = [x x2]; v = [v v2];
    end
    v3 = fliplr(v1);
    x3 = zeros(1, length(v3));
    x3(1) = x(end) + v3(1) * dt;
    for i=2:length(v3)
        x3(i) = x3(i - 1) + v3(i) * dt;
    end
    x = [x x3]; v = [v v3];
end


function [x,v,a] = zeroMovStage(initX, counts)
a = zeros(counts, 1);
v = zeros(counts, 1);
x = zeros(counts, 1);
for i = 1:counts
    x(i) = initX;
end
end













