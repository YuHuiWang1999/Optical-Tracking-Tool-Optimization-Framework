% O1=quat2dcm([]);
% O2=quat2dcn([]);

h1=15.939;
theta1=60;
%安装参数
l=150;
theta2=0;
h2=13.439+14;
d=1;
    %安装孔位
g1=9;
g2=12;
if 3==abs(g2-g1) || 51~=abs(g2-g1)
    theta3=10*(g1+g2)/3;
else
    error("安装孔位错误");
end
%T= zuobiaojia(h1,h2,theta1,theta2,theta3,l,d);

T1=P(0,0,-h1)*RY(-theta1)*RZ(theta2)*P(0,0,-d*h2)*P(-l,0,0)*RX(-90*(d-1))*RZ(-theta3);


function TX= RX(alpha)
% 绕X轴旋转alpha
TX=[1,          0,           0,0;
    0,cosd(alpha),-sind(alpha),0;
    0,sind(alpha), cosd(alpha),0;
    0,          0,           0,1];
end

function TY= RY(beta)
% 绕Y轴旋转beta
TY=[ cosd(beta),0,sind(beta),0;
              0,1,         0,0;
    -sind(beta),0,cosd(beta),0;
    0,          0,         0,1];
end

function TZ= RZ(gamma)
% 绕Z轴旋转gamma
TZ=[cosd(gamma),-sind(gamma),0,0;
    sind(gamma), cosd(gamma),0,0;
              0,        0,   1,0;
              0,        0,   0,1];
end

function TP= P(a,b,c)
% 平移(a,b,c)
TP=[1,0,0,a;
    0,1,0,b;
    0,0,1,c;
    0,0,0,1];
end