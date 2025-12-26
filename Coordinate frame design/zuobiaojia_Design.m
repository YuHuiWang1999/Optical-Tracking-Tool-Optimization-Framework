% 坐标架设计
% 第一节线段长为50mm
% A(0,0)
% B(50,0)
% Qua_old 需要排除的四边形坐标，四列，每两行一个四边形的坐标数据
exist Qua_old var;
if ans==0
    Qua_old=[];
end
[nn,~]=size(Qua_old);
n=nn/2;

zuobiao=zeros(2,4); %存放MarkersABCD点的坐标
Qua_s=zeros(4,3); %存放四边形六个的线段长
num=0;%满足条件的坐标架个数
A=[0;0];
B=[50;0];
zuobiao(:,1:2)=[A,B];
fileID1 = fopen('ABCDzuobiao.txt','w');
fclose(fileID1);
fileID2 = fopen('Qua_s.txt','w');
fclose(fileID2);
for s2=55:70  %第二节线段长度
    for theta2=30:5:80 %第二节线段与第一节角度
        C=B+[s2*cosd(theta2);s2*sind(theta2)];
        [flag,~]=Tri_istrue(A,B,C);
        if ~flag
            continue
        end
        zuobiao(:,3)=C;
        for s3=55:75 %第三节线段长度
            % for theta_temp=[5:175,185:355] %第三节线段与第二节角度
            for theta_temp=[(270-theta2):5:330] %第三节线段与第二节角度
                theta3=theta2+theta_temp-180;
                D=C+[s3*cosd(theta3);s3*sind(theta3)];
                zuobiao(:,4)=D;
                % plot(zuobiao(1,:),zuobiao(2,:),'o');
                [flag,Qua_s]=Qua_istrue(zuobiao);
                if flag
                    flag1=1;
                    for j=1:n
                        flag2 = Qua_isnolike(zuobiao,Qua_old([2*j-1,2*j],:));
                        flag1=flag1*flag2;
                        if ~(flag1)
                            break
                        end
                    end
                    if flag1
                        fileID1 = fopen('ABCDzuobiao.txt','a');
                        fprintf(fileID1,'%3.2f %3.2f\r\n',zuobiao);
                        fclose(fileID1);
                        fileID2 = fopen('Qua_s.txt','a');
                        fprintf(fileID2,'%3d %3d %3d %3d %3d %3d\r\n',Qua_s');
                        fclose(fileID2);
                        num=num+1;
                    end
                end
            end
        end
    end
end