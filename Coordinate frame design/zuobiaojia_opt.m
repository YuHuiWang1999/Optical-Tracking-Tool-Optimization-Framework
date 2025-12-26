% 优选
P = readmatrix('ABCDzuobiao.txt');
[x,y]=size(P);
if 2~=y
    error("导入文件维数有误");
end
n=x/4;
d=zeros(1,n);
for i=1:n
    j=i*4-3;
    k=j+3;
    M=P((j:k),:);
    %     plot(M(:,1),M(:,2),'o','LineWidth',2,'MarkerSize',10);
    %     xlim([-10,150]);
    %     ylim([-10,150]);
    %     hold on
    %     plot(M(L,1),M(L,2),'LineWidth',2);
    %     hold off
    %     drawnow
    [Qua_s,~]=Qua_get(M');
    d(i)=Qua_s(6)-Qua_s(1);
end
L=[1,2,3,4,1,3,2,4];
ind1=[2,3,4,3,4,4];
ind2=[1,1,1,2,2,3];
[d1,index]=sort(d);

fileID1 = fopen('ABCD.txt','w');
fclose(fileID1);

N=20;  %提取前N组
for m=1:N
    i=index(m);
    j=i*4-3;
    k=j+3;
    M=P((j:k),:);
    [Qua_s,~]=Qua_get(M',0);
    str1=['(',num2str(M(3,1)),', ',num2str(M(3,2)),')'];
    str2=['(',num2str(M(4,1)),', ',num2str(M(4,2)),')'];
    str={str1,str2};
    title(['第',num2str(m),'个，共',num2str(N),'个']);
    text((M([3,4],1)+2),M([3,4],2),str);
    xlim([-10,150]);
    ylim([-10,150]);
    hold on
    plot(M(L,1),M(L,2),'LineWidth',2);
    map=(M(ind1,:)+M(ind2,:))/2;
    S=num2cell(Qua_s);
    text(map(:,1),map(:,2),S);
    hold off
    % drawnow
    print('myzuobiaojia','-dpsc2','-append');
    close(figure(gcf))
    fileID1 = fopen('ABCD.txt','a');
    fprintf(fileID1,'第%2d个，共%2d个\r\n',m,N);
    fprintf(fileID1,'%3.2f %3.2f\r\n',M');
    fprintf(fileID1,' AB\tAC\t AD\t BC\t BD\t CD\r\n');
    fprintf(fileID1,'%3d\t%3d\t%3d\t%3d\t%3d\t%3d\r\n\r\n',Qua_s);
    fclose(fileID1);
    % pause;
end
