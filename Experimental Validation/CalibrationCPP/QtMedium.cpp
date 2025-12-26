#include "QtMedium.h"

QtMedium::QtMedium(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initConnect();

	oldconcen = 95.0;
}

QtMedium::~QtMedium()
{}

void QtMedium::initConnect()
{
	connect(ui.Do_acohol, &QPushButton::clicked, this, &QtMedium::GetalcoholVol);///打开介质计算界面
}
void QtMedium::GetalcoholVol()
{
	QString str1 = ui.water_vol->text();
	QString str2 = ui.concentration->text();
	double w_vol = str1.toDouble();
	double concen = str2.toDouble();
	double alcohol_vol = (w_vol*concen) / (oldconcen - concen);
	ui.label_water_3->setText(QString::number(alcohol_vol));
	double vol = w_vol + alcohol_vol;
	if (vol < 1300 || vol > 1560)
	{
		QMessageBox::warning(this, "", QStringLiteral("注意总体积在合理区域外！"), QStringLiteral("确认"));
	}
}
