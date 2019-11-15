function [x,v] = Vplanner(wpts, maxV, maxA, dt)
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
    initV = 0;
    if(exist('v', 'var'))
        initV = v(end);
    end
    [xLs, vLs] = calcLastStage(wpts(end - 1), wpts(end), initV, maxV, maxA, dt);
    if(exist('x', 'var') == 0)
        x = xLs; v = vLs;
    else
        x = [x xLs]; v = [v vLs];
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













