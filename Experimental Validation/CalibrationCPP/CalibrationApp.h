#pragma once

#include <QtWidgets/QMainWindow>
#include "QtMedium.h"
#include <QWidget>
#include <QDebug>
#include <QToolButton>
#include <QPushButton>
#include <QFileDialog>
#include <QPainter>
#include <QString>
#include <QKeyEvent>
#include <QMessageBox>
#include "ui_CalibrationApp.h"
#include <vtkSmartPointer.h>
#include <vtkMatrix4x4.h>
#include <QTimer>
#include "NdiApi.h"
#include <vector>
#include <math.h>
#include <Eigen/Dense>
#define RAD_TO_DEGREES        (180 / 3.1415926) 
#define SIZE_PIXEL        0.085378424430506
using namespace std;
using namespace Eigen;

class CalibrationApp : public QMainWindow
{
    Q_OBJECT

public:
    CalibrationApp(QWidget *parent = nullptr);
    ~CalibrationApp();

	void initConnect();
	NdiApi ndi;
	//记录模型点相对坐标
	vector< vector<double> > PointToModel;

	//记录超声数据姿态
	vector< vector<double> > USToWorld;
	vector< vector<double> > ModelToWorld;
	///记录图像坐标位置
	vector< vector<double> > pointToImage;
	///记录交叉点坐标位置
	vector< vector<double> > inspointToUS;
	///记录标定结果
	vtkSmartPointer<vtkMatrix4x4> Matrix_ImageToUS = vtkSmartPointer<vtkMatrix4x4>::New();
	//连接NDI界面的定时器
	QTimer* connectTimer = new QTimer(this);
	
	virtual void keyPressEvent(QKeyEvent *ev);
	void pointpick(vector<double> temp, vector<double> temp1);
	void NDIDataToMat(vector<double> temp, vtkMatrix4x4* Matrix);
	void UQtoMat(double q0, double qx, double qy, double qz, Matrix3d &Matrix);
	void PointSwith(vtkMatrix4x4* Matrix, double in[3], double out[3]);
	//记录超声图像
	void CollectUS(vector<double> temp, vector<double> temp1);
	void UQRegister(vector<vector<double> > source, vector<vector<double> > target, vtkMatrix4x4* Matrix);
	void ReadstandardData();
private:
    Ui::CalibrationAppClass ui;
	//判断NDI是否连接
	bool isConnect = false;
	//判断是否开始采点
	bool isstartpick = false;
	//判断是否采点
	bool ispick = false;
	//判断是否开始采集US
	bool isstartUS_collect = false;
	//判断是否采集US
	bool isUS_collect = false;
private slots:

	//连接NDI，同时注册工具
	void registerTools();
	//开始connectTimer
	void startConnectTimer();
	//结束connectTimer
	void stopConnectTimer();
	//获取connectTimer对应的数据
	void getConnectData();
	//开始点拾取
	void startpointpick();
	//开始图像拾取
	void startUSpick();
	//导出姿态数据
	void OutputTransData();
	//读取姿态数据
	void ReadTransData();
	//读取分割数据
	void ReadSegData();
	//计算标定结果
	void Docalibration();
	//辅助计算标定介质
	void DoMediumcal();
	//导出标定结果
	void DocaliResult();
};
