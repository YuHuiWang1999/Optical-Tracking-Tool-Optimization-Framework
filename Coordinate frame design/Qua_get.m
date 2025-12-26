function [L,Tri_s]=Qua_get(Qua,option)
% 获取四边形的六条线段长和四个三角形的边长
% Qua 四边形的四个顶点坐标
% option 是否对结果排序，取值1、0；默认1
if nargin < 2
    option=1;
end
A=Qua(:,1);
B=Qua(:,2);
C=Qua(:,3);
D=Qua(:,4);
lAB=round(norm(A-B),3);
lAC=round(norm(A-C),3);
lAD=round(norm(A-D),3);
lBC=round(norm(B-C),3);
lBD=round(norm(B-D),3);
lCD=round(norm(C-D),3);
% lAB=round(norm(A-B));
% lAC=round(norm(A-C));
% lAD=round(norm(A-D));
% lBC=round(norm(B-C));
% lBD=round(norm(B-D));
% lCD=round(norm(C-D));
L=[lAB,lAC,lAD,lBC,lBD,lCD];
Tri_s=[lAB,lBC,lAC;lAB,lBD,lAD;lAC,lCD,lAD;lBC,lCD,lBD];
if option
    L=sort(L);
    Tri_s=sort(Tri_s,2);
end
end

   