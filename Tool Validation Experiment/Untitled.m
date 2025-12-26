x=1:1:6;
errorbar(x,fre1(1,:),fre1(2,:),fre1(3,:),'-*b','color',[.1 .1 .1],'LineWidth',1','MarkerSize',8); 
xlabel('Group 1');ylabel('FRE(mm)');
%设置坐标轴字体大小粗细，字体样式以及横纵轴范围
set(gca,'fontsize',10,'fontweight','bold','FontName','Times New Roman','XLim',[0,7],'YLim',[0.1,0.55]);
