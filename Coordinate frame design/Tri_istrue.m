function [flag,L]=Tri_istrue(A,B,C)
%判断三角形是否满足条件
% A,B,C三角形的三个顶点坐标
lAB=round(norm(A-B));
lAC=round(norm(A-C));
lBC=round(norm(B-C));
L=sort([lAB,lAC,lBC]);
ss=diff(L);
if sum([50>L,6>ss])
    flag=0;
else
    flag=1;
end
end