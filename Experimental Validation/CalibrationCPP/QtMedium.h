#pragma once

#include <QWidget>
#include "ui_QtMedium.h"
#include <QMessageBox>
class QtMedium : public QWidget
{
	Q_OBJECT

public:
	QtMedium(QWidget *parent = nullptr);
	~QtMedium();
	void initConnect();
	double oldconcen;
private:
	Ui::QtMediumClass ui;
private slots:
	void GetalcoholVol();

};
