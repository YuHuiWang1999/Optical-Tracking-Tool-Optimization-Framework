#include "CalibrationApp.h"

CalibrationApp::CalibrationApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	initConnect();
	ReadstandardData();
	/*this->grabKeyboard();*/
}

CalibrationApp::~CalibrationApp()
{}

void CalibrationApp::initConnect()
{
	connect(ui.connect_ndi, &QPushButton::clicked, this, &CalibrationApp::registerTools);///连接NDI设备
	connect(ui.point_picker, &QPushButton::clicked, this, &CalibrationApp::startpointpick);///开启探针拾取
	connect(ui.US_picker, &QPushButton::clicked, this, &CalibrationApp::startUSpick);///开启超声拾取
	connect(ui.Seg_Reader, &QPushButton::clicked, this, &CalibrationApp::ReadSegData);///读取分割数据
	connect(ui.Do_calibration, &QPushButton::clicked, this, &CalibrationApp::Docalibration);///标定
	connect(ui.saveresult, &QPushButton::clicked, this, &CalibrationApp::DocaliResult);///标定
	connect(ui.Trans_Output, &QPushButton::clicked, this, &CalibrationApp::OutputTransData);///导出姿态数据
	connect(ui.Trans_Reader, &QPushButton::clicked, this, &CalibrationApp::ReadTransData);///读取姿态数据
	
	connect(ui.Do_cal, &QPushButton::clicked, this, &CalibrationApp::DoMediumcal);///打开介质计算界面

	connect(connectTimer, &QTimer::timeout, this, &CalibrationApp::getConnectData);///定时器获取数据
}
void CalibrationApp::keyPressEvent(QKeyEvent *ev)
{
	if (ev->key() == Qt::Key_F2)
	{
		qDebug() << "US F2 is pressed";
		if (isstartpick)
		{
			ispick = true;
		}
		if (isstartUS_collect)
		{
			isUS_collect = true;
		}
	}
}
void CalibrationApp::pointpick(vector<double> temp, vector<double> temp1)
{
	double probepick[3], posToM[3];
	vector<double> sp(3);
	probepick[0] = temp[4];
	probepick[1] = temp[5];
	probepick[2] = temp[6];
	vtkSmartPointer<vtkMatrix4x4> Matrix_MToworld = vtkSmartPointer<vtkMatrix4x4>::New();
	NDIDataToMat(temp1, Matrix_MToworld);
	Matrix_MToworld->Invert();
	PointSwith(Matrix_MToworld, probepick, posToM);
	sp[0] = posToM[0];
	sp[1] = posToM[1];
	sp[2] = posToM[2];
	PointToModel.push_back(sp);
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);
	for (int i = 0; i < 3; i++)
	{
		QString str = QString::number(posToM[i], 'f', 3);
		ui.tableWidget->setItem(row, i, new QTableWidgetItem(str));
	}
}
void CalibrationApp::NDIDataToMat(vector<double> temp, vtkMatrix4x4 * Matrix)
{
	Matrix3d  r;
	UQtoMat(temp[0], temp[1], temp[2], temp[3], r);
	Matrix->SetElement(0, 0, r(0, 0));
	Matrix->SetElement(0, 1, r(0, 1));
	Matrix->SetElement(0, 2, r(0, 2));
	Matrix->SetElement(0, 3, temp[4]);
	Matrix->SetElement(1, 0, r(1, 0));
	Matrix->SetElement(1, 1, r(1, 1));
	Matrix->SetElement(1, 2, r(1, 2));
	Matrix->SetElement(1, 3, temp[5]);
	Matrix->SetElement(2, 0, r(2, 0));
	Matrix->SetElement(2, 1, r(2, 1));
	Matrix->SetElement(2, 2, r(2, 2));
	Matrix->SetElement(2, 3, temp[6]);
	Matrix->SetElement(3, 0, 0);
	Matrix->SetElement(3, 1, 0);
	Matrix->SetElement(3, 2, 0);
	Matrix->SetElement(3, 3, 1);
}
void CalibrationApp::UQtoMat(double q0, double qx, double qy, double qz, Matrix3d & Matrix)
{
	Matrix(0, 0) = (q0 * q0) + (qx * qx) - (qy * qy) - (qz * qz);
	Matrix(0, 1) = 2 * ((qx * qy) - (q0 * qz));
	Matrix(0, 2) = 2 * ((qx * qz) + (q0 * qy));
	Matrix(1, 0) = 2 * ((qx * qy) + (q0 * qz));
	Matrix(1, 1) = (q0 * q0) - (qx * qx) + (qy * qy) - (qz * qz);
	Matrix(1, 2) = 2 * ((qy * qz) - (q0 * qx));
	Matrix(2, 0) = 2 * ((qx * qz) - (q0 * qy));
	Matrix(2, 1) = 2 * ((qy * qz) + (q0 * qx));
	Matrix(2, 2) = (q0 * q0) - (qx * qx) - (qy * qy) + (qz * qz);
}
void CalibrationApp::PointSwith(vtkMatrix4x4 * Matrix, double in[3], double out[3])
{
	double inchange[4], outchange[4];
	inchange[0] = in[0];
	inchange[1] = in[1];
	inchange[2] = in[2];
	inchange[3] = 1;
	Matrix->MultiplyPoint(inchange, outchange);
	out[0] = outchange[0];
	out[1] = outchange[1];
	out[2] = outchange[2];
}
void CalibrationApp::CollectUS(vector<double> temp, vector<double> temp1)
{
	USToWorld.push_back(temp);
	ModelToWorld.push_back(temp1);
	
	int row = ui.tableWidget_2->rowCount();
	ui.tableWidget_2->insertRow(row);
	for (int i = 0; i < 7; i++)
	{
		QString str = QString::number(temp[i], 'f', 3);
		ui.tableWidget_2->setItem(row, i, new QTableWidgetItem(str));
	}
}
void CalibrationApp::UQRegister(vector<vector<double>> source, vector<vector<double>> target, vtkMatrix4x4 * Matrix)
{
	double norm_s[3] = { 0 };
	double norm_t[3] = { 0 };
	double r[9];
	double t[3];
	for (int i = 0; i < source.size(); i++)
	{
		norm_s[0] = norm_s[0] + source[i][0];
		norm_s[1] = norm_s[1] + source[i][1];
		norm_s[2] = norm_s[2] + source[i][2];
		norm_t[0] = norm_t[0] + target[i][0];
		norm_t[1] = norm_t[1] + target[i][1];
		norm_t[2] = norm_t[2] + target[i][2];
	}
	double center_s[3], center_t[3];
	center_s[0] = norm_s[0] / source.size();
	center_s[1] = norm_s[1] / source.size();
	center_s[2] = norm_s[2] / source.size();
	center_t[0] = norm_t[0] / target.size();
	center_t[1] = norm_t[1] / target.size();
	center_t[2] = norm_t[2] / target.size();
	double sxx = 0;
	double sxy = 0;
	double sxz = 0;
	double syx = 0;
	double syy = 0;
	double syz = 0;
	double szx = 0;
	double szy = 0;
	double szz = 0;
	for (int i = 0; i < source.size(); i++)
	{
		double x_s = source[i][0] - center_s[0];
		double y_s = source[i][1] - center_s[1];
		double z_s = source[i][2] - center_s[2];
		double x_t = target[i][0] - center_t[0];
		double y_t = target[i][1] - center_t[1];
		double z_t = target[i][2] - center_t[2];
		sxx = sxx + x_s * x_t;
		sxy = sxy + x_s * y_t;
		sxz = sxz + x_s * z_t;
		syx = syx + y_s * x_t;
		syy = syy + y_s * y_t;
		syz = syz + y_s * z_t;
		szx = szx + z_s * x_t;
		szy = szy + z_s * y_t;
		szz = szz + z_s * z_t;
	}
	MatrixXd N(4, 4);
	N << sxx + syy + szz, syz - szy, szx - sxz, sxy - syx,
		syz - szy, sxx - syy - szz, sxy + syx, szx + sxz,
		szx - sxz, sxy + syx, -sxx + syy - szz, syz + szy,
		sxy - syx, szx + sxz, syz + szy, -sxx - syy + szz;
	EigenSolver<Matrix4d> es(N);
	MatrixXcd evecs = es.eigenvectors();//获取矩阵特征向量4*4，这里定义的MatrixXcd必须有c，表示获得的是complex复数矩阵
	MatrixXcd evals = es.eigenvalues();//获取矩阵特征值 4*1
	MatrixXd evalsReal;//注意这里定义的MatrixXd里没有c
	evalsReal = evals.real();//获取特征值实数部分
	MatrixXf::Index evalsMax;
	evalsReal.rowwise().sum().maxCoeff(&evalsMax);//得到最大特征值的位置
	double q0 = evecs.real()(0, evalsMax);
	double qx = evecs.real()(1, evalsMax);
	double qy = evecs.real()(2, evalsMax);
	double qz = evecs.real()(3, evalsMax);
	r[0] = (q0 * q0) + (qx * qx) - (qy * qy) - (qz * qz);
	r[1] = 2 * ((qx * qy) - (q0 * qz));
	r[2] = 2 * ((qx * qz) + (q0 * qy));
	r[3] = 2 * ((qx * qy) + (q0 * qz));
	r[4] = (q0 * q0) - (qx * qx) + (qy * qy) - (qz * qz);
	r[5] = 2 * ((qy * qz) - (q0 * qx));
	r[6] = 2 * ((qx * qz) - (q0 * qy));
	r[7] = 2 * ((qy * qz) + (q0 * qx));
	r[8] = (q0 * q0) - (qx * qx) - (qy * qy) + (qz * qz);
	MatrixXd R = Map<MatrixXd>(r, 3, 3);
	Vector3d P1, P2, T;
	P1 << center_s[0], center_s[1], center_s[2];
	P2 << center_t[0], center_t[1], center_t[2];
	T = P2 - (R.transpose()) * P1;
	Matrix->SetElement(0, 0, r[0]);
	Matrix->SetElement(0, 1, r[1]);
	Matrix->SetElement(0, 2, r[2]);
	Matrix->SetElement(0, 3, T(0));
	Matrix->SetElement(1, 0, r[3]);
	Matrix->SetElement(1, 1, r[4]);
	Matrix->SetElement(1, 2, r[5]);
	Matrix->SetElement(1, 3, T(1));
	Matrix->SetElement(2, 0, r[6]);
	Matrix->SetElement(2, 1, r[7]);
	Matrix->SetElement(2, 2, r[8]);
	Matrix->SetElement(2, 3, T(2));
	Matrix->SetElement(3, 0, 0);
	Matrix->SetElement(3, 1, 0);
	Matrix->SetElement(3, 2, 0);
	Matrix->SetElement(3, 3, 1);
}
void CalibrationApp::ReadstandardData()
{
	QString path = "./Ini_Data/PointinModelData.txt";
	ifstream fin(path.toUtf8().data(), ios::in);
	if (!fin) {
		printf("The file is not exist!");
		return;
	}
	vector<double> sp(3);
	while (!fin.eof())
	{
		fin >> sp[0] >> sp[1] >> sp[2];
		PointToModel.push_back(sp);
	}
	fin.close();
}
void CalibrationApp::startConnectTimer()
{
	std::cout << std::endl << "Entering tracking mode and collecting data..." << std::endl;
	ndi.onErrorPrintDebugMessage("capi.startTracking()", ndi.capi.startTracking());
	connectTimer->start(50);
}
void CalibrationApp::stopConnectTimer()
{
	connectTimer->stop();
	std::cout << std::endl << "Leaving tracking mode and returning to configuration mode..." << std::endl;
	ndi.onErrorPrintDebugMessage("capi.stopTracking()", ndi.capi.stopTracking());
}
void CalibrationApp::startpointpick()
{
	isstartUS_collect = false;
	ui.US_picker->setText(QStringLiteral("开启超声图像拾取"));
	if (isstartpick)
	{
		isstartpick = false;
		ui.point_picker->setText(QStringLiteral("开启模型点拾取"));
	}
	else
	{
		isstartpick = true;
		ui.point_picker->setText(QStringLiteral("结束模型点拾取"));
	}
}
void CalibrationApp::startUSpick()
{
	isstartpick = false;
	ui.point_picker->setText(QStringLiteral("开启模型点拾取"));
	if (isstartUS_collect)
	{
		isstartUS_collect = false;
		ui.US_picker->setText(QStringLiteral("开启超声图像拾取"));
	}
	else
	{
		isstartUS_collect = true;
		ui.US_picker->setText(QStringLiteral("结束超声图像拾取"));
	}
	ofstream PointToModelData("PointToModelData.txt");
	for (int i = 0; i < PointToModel.size(); i++)
	{
		PointToModelData << PointToModel[i][0] << " " << PointToModel[i][1] << " " << PointToModel[i][2] << '\n';
	}
	PointToModelData.close();
}
void CalibrationApp::OutputTransData()
{
	ofstream transdata("TransData.txt");
	for (int i = 0; i < USToWorld.size(); i++)
	{
		transdata << USToWorld[i][0] << " " << USToWorld[i][1] << " " << USToWorld[i][2] << " " << USToWorld[i][3] << " " << USToWorld[i][4] << " " << USToWorld[i][5] << " " << USToWorld[i][6] 
			<< ModelToWorld[i][0] << " " << ModelToWorld[i][1] << " " << ModelToWorld[i][2] << " " << ModelToWorld[i][3] << " " << ModelToWorld[i][4] << " " << ModelToWorld[i][5] << " " << ModelToWorld[i][6]<<'\n';
	}
	transdata.close();
}
void CalibrationApp::ReadTransData()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("导入数据"), "./", "*.txt");
	if (path == "") return;
	vector<vector<double> >source;

	ifstream fin(path.toUtf8().data(), ios::in);
	if (!fin) {
		printf("The file is not exist!");
		return;
	}
	vector<double> sp1(7);
	vector<double> sp2(7);
	while (!fin.eof())
	{
		fin >> sp1[0] >> sp1[1] >> sp1[2] >> sp1[3] >> sp1[4] >> sp1[5] >> sp1[6] >> sp2[0] >> sp2[1] >> sp2[2] >> sp2[3] >> sp2[4] >> sp2[5] >> sp2[6];
		USToWorld.push_back(sp1);
		ModelToWorld.push_back(sp2);
		int row = ui.tableWidget_2->rowCount();
		ui.tableWidget_2->insertRow(row);
		for (int i = 0; i < 7; i++)
		{
			QString str = QString::number(sp1[i], 'f', 3);
			ui.tableWidget_2->setItem(row, i, new QTableWidgetItem(str));
		}
	}
	fin.close();
}
void CalibrationApp::ReadSegData()
{
	QString projectPath = QFileDialog::getExistingDirectory(this, QStringLiteral("项目位置"), "./");
	if (projectPath == "") return;
	int size = USToWorld.size();
	///循环读取分割数据并转换
	/*std::ofstream segdata("./processdata/segdata.txt");*/
	for (int i = 0; i < size; i++)
	{
		if (USToWorld[i][0] > -1.00)///判断是否空值
		{
			string f = string((const char *)projectPath.toLocal8Bit());
			string file = "/";
			string  type = ".txt";
			string  inname;
			string  name = std::to_string(i);////////////////////注意图片索引
			inname = name + type;
			inname = file + inname;
			inname = f + inname;
			ifstream fin(inname, ios::in);
			if (!fin)
			{
				printf("The file is not exist!");
				return;
			}
			///////////计算图像点坐标并存储
			int pos_pixel[2];
			vector< vector<double> > FPToImage;
			FPToImage.clear();
			while (!fin.eof())
			{
				fin >> pos_pixel[0] >> pos_pixel[1];
				vector<double> sp(3);
				sp[0] = SIZE_PIXEL * pos_pixel[0];
				sp[1] = SIZE_PIXEL * pos_pixel[1];
				sp[2] = 0;
				
				FPToImage.push_back(sp);/////将单张位置存储
			}
			for (int i = 1; i < 4; i++)
			{
				pointToImage.push_back(FPToImage[i]);/////将中间三个位置存储
			}
			///利用像素位置计算交点位置并存储
			////计算间隔距离
			double d1 = sqrt((FPToImage[0][0] - FPToImage[1][0])*(FPToImage[0][0] - FPToImage[1][0]) + (FPToImage[0][1] - FPToImage[1][1])*(FPToImage[0][1] - FPToImage[1][1]));
			double d2 = sqrt((FPToImage[1][0] - FPToImage[2][0])*(FPToImage[1][0] - FPToImage[2][0]) + (FPToImage[1][1] - FPToImage[2][1])*(FPToImage[1][1] - FPToImage[2][1]));
			double d3 = sqrt((FPToImage[2][0] - FPToImage[3][0])*(FPToImage[2][0] - FPToImage[3][0]) + (FPToImage[2][1] - FPToImage[3][1])*(FPToImage[2][1] - FPToImage[3][1]));
			double d4 = sqrt((FPToImage[3][0] - FPToImage[4][0])*(FPToImage[3][0] - FPToImage[4][0]) + (FPToImage[3][1] - FPToImage[4][1])*(FPToImage[3][1] - FPToImage[4][1]));
			///计算交叉点位置
			//前
			//1--4//
			 //\                 point1=p1+(p5-p1)*d1/(d1+d2)
			  //\
			//2--5//             point2=p2+(p5-p2)*d3/(d3+d2)
			 //\
			  //\                point3=p2+(p6-p2)*d3/(d3+d4)
			//3--6//
			//后

			double point1[3], point2[3], point3[3];
			vector<double> sp(3);
			point1[0] = PointToModel[0][0] + (PointToModel[4][0] - PointToModel[0][0])*(d1 / (d1 + d2));
			point1[1] = PointToModel[0][1] + (PointToModel[4][1] - PointToModel[0][1])*(d1 / (d1 + d2));
			point1[2] = PointToModel[0][2] + (PointToModel[4][2] - PointToModel[0][2])*(d1 / (d1 + d2));
			point2[0] = PointToModel[1][0] + (PointToModel[4][0] - PointToModel[1][0])*(d3 / (d3 + d2));
			point2[1] = PointToModel[1][1] + (PointToModel[4][1] - PointToModel[1][1])*(d3 / (d3 + d2));
			point2[2] = PointToModel[1][2] + (PointToModel[4][2] - PointToModel[1][2])*(d3 / (d3 + d2));
			point3[0] = PointToModel[1][0] + (PointToModel[5][0] - PointToModel[1][0])*(d3 / (d3 + d4));
			point3[1] = PointToModel[1][1] + (PointToModel[5][1] - PointToModel[1][1])*(d3 / (d3 + d4));
			point3[2] = PointToModel[1][2] + (PointToModel[5][2] - PointToModel[1][2])*(d3 / (d3 + d4));
			////////将体模坐标系下坐标转换至US坐标系下
			vtkSmartPointer<vtkMatrix4x4> Matrix_ModelToworld = vtkSmartPointer<vtkMatrix4x4>::New();
			vtkSmartPointer<vtkMatrix4x4> Matrix_USToworld = vtkSmartPointer<vtkMatrix4x4>::New();
			vtkSmartPointer<vtkMatrix4x4> Matrix_ModelToUS = vtkSmartPointer<vtkMatrix4x4>::New();
			NDIDataToMat(USToWorld[i], Matrix_USToworld);
			NDIDataToMat(ModelToWorld[i], Matrix_ModelToworld);
			Matrix_USToworld->Invert();
			vtkMatrix4x4::Multiply4x4( Matrix_USToworld, Matrix_ModelToworld, Matrix_ModelToUS);
			PointSwith(Matrix_ModelToUS, point1, point1);
			PointSwith(Matrix_ModelToUS, point2, point2);
			PointSwith(Matrix_ModelToUS, point3, point3);
			sp[0] = point1[0];
			sp[1] = point1[1];
			sp[2] = point1[2];
			inspointToUS.push_back(sp);
			sp[0] = point2[0];
			sp[1] = point2[1];
			sp[2] = point2[2];
			inspointToUS.push_back(sp);
			sp[0] = point3[0];
			sp[1] = point3[1];
			sp[2] = point3[2];
			inspointToUS.push_back(sp);

			////存储交叉点位置

			fin.close();
		}
	}
	ui.pointnum->setText(QString::number(inspointToUS.size()));
}
void CalibrationApp::Docalibration()
{
	//计算标定矩阵
	UQRegister(pointToImage, inspointToUS, Matrix_ImageToUS);
	//将结果显示在table中
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			QString str = QString::number(Matrix_ImageToUS->GetElement(j, i), 'f', 4);
			ui.tableWidget_3->setItem(j, i, new QTableWidgetItem(str));
		}
	}
	//计算标定误差
	double esum = 0;
	for (int i = 0; i < pointToImage.size(); i++)
	{
		double imagepoint[3], swithpoint[3], realpoint[3];
		imagepoint[0] = pointToImage[i][0];
		imagepoint[1] = pointToImage[i][1];
		imagepoint[2] = pointToImage[i][2];
		PointSwith(Matrix_ImageToUS, imagepoint, swithpoint);
		realpoint[0] = inspointToUS[i][0];
		realpoint[1] = inspointToUS[i][1];
		realpoint[2] = inspointToUS[i][2];
		double error = sqrt((swithpoint[0] - realpoint[0])*(swithpoint[0] - realpoint[0]) +
			(swithpoint[1] - realpoint[1])*(swithpoint[1] - realpoint[1]) +
			(swithpoint[2] - realpoint[2])*(swithpoint[2] - realpoint[2]));
		esum = esum + error;
	}
	double aveerror = esum / pointToImage.size();
	ui.meanerror->setText(QString::number(aveerror));
}

void CalibrationApp::getConnectData()
{
	ndi.capi.getTrackingDataTX();
	std::vector<ToolData> toolData = ndi.apiSupportsBX2 ? ndi.capi.getTrackingDataBX2() : ndi.capi.getTrackingDataBX();
	vector<double> temp0;
	bool temp0Flag = false;
	//探针DRO
	if (0 == toolData[0].transform.status)
	{
		temp0.push_back(toolData[0].transform.q0);
		temp0.push_back(toolData[0].transform.qx);
		temp0.push_back(toolData[0].transform.qy);
		temp0.push_back(toolData[0].transform.qz);

		temp0.push_back(toolData[0].transform.tx);
		temp0.push_back(toolData[0].transform.ty);
		temp0.push_back(toolData[0].transform.tz);
		temp0.push_back(toolData[0].transform.error);
		temp0Flag = true;
		ui.probe_DRO->setStyleSheet("background-color: rgb(67, 198, 172)");
	}
	else
	{
		ui.probe_DRO->setStyleSheet("background-color: rgb(182, 0, 0)");
	}

	vector<double> temp1;
	bool temp1Flag = false;
	//超声固连DRO
	if (0 == toolData[1].transform.status)
	{
		temp1.push_back(toolData[1].transform.q0);
		temp1.push_back(toolData[1].transform.qx);
		temp1.push_back(toolData[1].transform.qy);
		temp1.push_back(toolData[1].transform.qz);

		temp1.push_back(toolData[1].transform.tx);
		temp1.push_back(toolData[1].transform.ty);
		temp1.push_back(toolData[1].transform.tz);
		temp1.push_back(toolData[1].transform.error);
		temp1Flag = true;
		ui.US_DRO->setStyleSheet("background-color: rgb(67, 198, 172)");
	}
	else
	{
		ui.US_DRO->setStyleSheet("background-color: rgb(182, 0, 0)");
	}

	vector<double> temp2;
	bool temp2Flag = false;
	//体模固连DRO
	if (0 == toolData[2].transform.status)
	{
		temp2.push_back(toolData[2].transform.q0);
		temp2.push_back(toolData[2].transform.qx);
		temp2.push_back(toolData[2].transform.qy);
		temp2.push_back(toolData[2].transform.qz);

		temp2.push_back(toolData[2].transform.tx);
		temp2.push_back(toolData[2].transform.ty);
		temp2.push_back(toolData[2].transform.tz);
		temp2.push_back(toolData[2].transform.error);
		temp2Flag = true;
		ui.M_DRO->setStyleSheet("background-color: rgb(67, 198, 172)");
	}
	else
	{
		ui.M_DRO->setStyleSheet("background-color: rgb(182, 0, 0)");
	}
	if (ispick)
	{
		if (temp0Flag && temp2Flag)
		{
			pointpick(temp0, temp2);
		}
		ispick = false;
	}
	if (isUS_collect)
	{
		if (temp1Flag && temp2Flag)
		{
			CollectUS(temp1, temp2);
		}
		else
		{
			vector <double> e(7, -2.00);
			ModelToWorld.push_back(e);
			USToWorld.push_back(e);
			int row = ui.tableWidget_2->rowCount();
			ui.tableWidget_2->insertRow(row);
			for (int i = 0; i < 7; i++)
			{
				QString str = QString::number(e[i], 'f', 3);
				ui.tableWidget_2->setItem(row, i, new QTableWidgetItem(str));
			}
		}
		isUS_collect = false;
	}
}
void CalibrationApp::registerTools()
{
	/*QMessageBox::information(this, "connect", "qqq");*/
	if (isConnect)
	{
		qDebug() << "connect successful ";
		return;
	}
	if (ndi.registerTools() == -1)
		qDebug() << "connect failed ";
	else
	{
		qDebug() << "connect successful ";
		isConnect = true;
		startConnectTimer();
		
	}
}
void CalibrationApp::DoMediumcal()
{
	/*this->releaseKeyboard();*/
	QtMedium *MediumWindow = new QtMedium;
	MediumWindow->show();

}

void CalibrationApp::DocaliResult()
{
	ofstream CalibrationResult("CalibrationResult.txt");
	for (int i = 0; i < 4; i++)
	{
		CalibrationResult << Matrix_ImageToUS->GetElement(i,0) << " " << Matrix_ImageToUS->GetElement(i, 1) << " " << Matrix_ImageToUS->GetElement(i, 2) << " " << Matrix_ImageToUS->GetElement(i, 3)<< '\n';
	}
	CalibrationResult.close();
	QMessageBox::information(this, "save", "Finish save");
}
