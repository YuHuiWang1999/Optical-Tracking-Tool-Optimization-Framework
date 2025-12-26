% 从结果中排除
P = readmatrix('ABCDzuobiao.txt');
[x,y]=size(P);
if 2~=y
    error("导入文件维数有误");
end
n=x/4; %个数

exist Qua_old var;
if ans==0
    Qua_old=[];
end
[nn,~]=size(Qua_old);
n_ex=nn/2;
fileID1 = fopen('ABCDzuobiao.txt','w');
fclose(fileID1);

num=0;%满足条件的坐标架个数
for i=1:n
    j=i*4-3;
    k=j+3;
    M=P((j:k),:);
    flag1=1;
    for j=1:n_ex
        flag2 = Qua_isnolike(M',Qua_old([2*j-1,2*j],:));
        flag1=flag1*flag2;
        if ~(flag1)
            break
        end
    end
    if flag1
        fileID1 = fopen('ABCDzuobiao.txt','a');
        fprintf(fileID1,'%3.2f %3.2f\r\n',zuobiao);
        fclose(fileID1);
        num=num+1;
    end
end