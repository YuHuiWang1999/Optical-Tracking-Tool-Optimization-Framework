function [flag]=Qua_isnolike(Qua1,Qua2,opt)
% 判断两个四边形是否满足不相似约束
% Qua 四边形的四个顶点坐标
% opt是否输出不满足约束的信息，默认0

% [~,Tri_s1]=Qua_get(Qua1,0);
% [~,Tri_s2]=Qua_get(Qua2,0);
% for x=1:4
%     for y=1:4
%         ss=abs(Tri_s1(x,:)-Tri_s2(y,:));
%         if ~sum(6<ss)
%             flag=0;
%             return
%         end
%     end
% end
% flag=1;
if 3>nargin
    opt=0;
end

index1=[1,1,1,2,2,3];
index2=[2,3,4,3,4,4]; %以lAB,lAC,lAD,lBC,lBD,lCD为顺序的向量表示
S_v1=Qua1(:,index2)-Qua1(:,index1);
S_v2=Qua2(:,index2)-Qua2(:,index1);
S_n1=sum(S_v1.^2).^(1/2);
S_n2=sum(S_v2.^2).^(1/2);  %以lAB,lAC,lAD,lBC,lBD,lCD为顺序的线段长
[X_S1,Y_S2] = meshgrid(S_n1,S_n2);
d=abs(X_S1-Y_S2); %六条线段所有组合的长度差 6*6矩阵
[X_v1,Y_v2] = meshgrid(1:6);
index_v1=X_v1(d<5); %记录相似边的对应位置
index_v2=Y_v2(d<5);
n=length(index_v1); %计算相似边组合的个数
if 1<n
    like_S_v1=S_v1(:,index_v1); %提取相似边的向量
    like_S_n1=S_n1(index_v1); %计算相似边的长度
    like_S_v2=S_v2(:,index_v2);
    like_S_n2=S_n2(index_v2); 
    
    index1=zeros(1,n*(n-1)/2);
    index2=zeros(1,n*(n-1)/2);
    i=1;
    %完成所有相似边两两夹角的排列组合
    for j=1:n-1
        for k=j+1:n
            index1(i)=j;
            index2(i)=k;
            i=i+1;
        end
    end
    alpha1 = acosd(round(dot(like_S_v1(:,index1),like_S_v1(:,index2))./(like_S_n1(index1).*like_S_n1(index2)),6)); %计算相似边组合的夹角
    alpha2 = acosd(round(dot(like_S_v2(:,index1),like_S_v2(:,index2))./(like_S_n2(index1).*like_S_n2(index2)),6));
    alpha1(alpha1>90)=180-alpha1(alpha1>90); %替换为锐角
    alpha2(alpha2>90)=180-alpha2(alpha2>90);
    delta=abs(alpha2-alpha1); % 夹角的差
    con_delta=delta(2.1>delta); % 提取不满足条件的夹角差
    num=length(con_delta); % 不满足条件的个数
    if opt
        con_alpha1=alpha1(2.1>delta); % 提取不满足条件的相似边
        con_alpha2=alpha2(2.1>delta);
        q11=S_n1(index_v1(index1(2.1>delta)));
        q12=S_n1(index_v1(index2(2.1>delta)));
        q21=S_n2(index_v2(index1(2.1>delta)));
        q22=S_n2(index_v2(index2(2.1>delta)));
        % 输出不满足约束的边
        for nn=1:num
            shuchu1 = '第 %d 组：\n';
            shuchu2 = '第一个四边形中 %.2f 边和 %.2f 边的夹角 %.4f 与第二个四边形中 %.2f 边和 %.2f 边的夹角 %.4f 不满足约束，相差 %.4f 度\n';
            fprintf(shuchu1,nn);
            fprintf(shuchu2,q11(nn),q12(nn),con_alpha1(nn),q21(nn),q22(nn),con_alpha2(nn),con_delta(nn));
        end
    end
    if num
        flag=0;
    else
        flag=1;
    end
else
    flag=1;
end

end
