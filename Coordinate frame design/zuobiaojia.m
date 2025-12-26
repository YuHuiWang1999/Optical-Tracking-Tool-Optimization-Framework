function T= zuobiaojia(h1,h2,theta1,theta2,theta3,l,d)
% 坐标架坐标系到平台坐标系的齐次转换矩阵;单位：度
T=P(0,0,-h1)*RY(-theta1)*RZ(theta2)*P(0,0,-d*h2)*P(-l,0,0)*RX(90*(d+1))*RZ(-theta3);
end

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
