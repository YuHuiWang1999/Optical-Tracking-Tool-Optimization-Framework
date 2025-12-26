function [flag,L]=Qua_istrue(Qua)
%判断四边形是否满足条件
% Qua 四边形的四个顶点坐标
[L,~]=Qua_get(Qua);
ss=diff(L);
if sum([50>L,5.1>ss, 130<L])
    flag=0;
else
    flag=1;
end
end