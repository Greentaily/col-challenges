#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_challenge1_button_calculate_clicked()
{
	Sphere sphere;
	sphere.setRadius(this->ui->challenge1_input->value());
	sphere.randomizeColors();
	qreal volume = sphere.getVolume();
	QPixmap pic = sphere.getPixmap(this->ui->challenge1_graphics_view->width(),
								   this->ui->challenge1_graphics_view->height());
	this->ui->challenge1_result->setValue(volume);
	this->ui->challenge1_graphics_view->clear();
	this->ui->challenge1_graphics_view->setPixmap(pic);
}

void MainWindow::on_challenge2_button_count_clicked()
{
	QString text = this->ui->challenge2_input->toPlainText()
												.toLower()
												.simplified()
												.replace(" ", "");
	//qDebug() << text.split(QString(), Qt::SkipEmptyParts) [](int value) {return;};
	QMap<QChar, int> map;
	int max = 0;
	QStringList result;
	foreach (QChar c, text)
	{
		map.insert(c, map.value(c) + 1);
		max = qMax(max, map.value(c));
	}
	foreach (QChar c, map.keys()) if (map.value(c) == max) result << c;
	if (result.isEmpty()) this->ui->challenge2_result->clear();
	else this->ui->challenge2_result->setText(result.join(" "));
}

void MainWindow::on_challenge3_button_generate_clicked()
{
	this->v.clear();
	this->v.squeeze();
	QStringList strings;
	for (int i = 0; i < QRandomGenerator::system()->bounded(4, 8); ++i)
	{
		int gen = QRandomGenerator::system()->bounded(-1000, 1000);
		this->v << gen;
		strings << QString::number(gen);
	}
	this->ui->challenge3_input->setText(strings.join(" | "));
}

void MainWindow::on_challenge3_button_sort_clicked()
{
	QStringList strings;
	for (int i = 0; i < this->v.count() - 1; ++i)
	{
		int min = i;
		for (int k = i + 1; k < this->v.count(); ++k)
		{
			if (this->v.at(k) < this->v.at(min)) min = k;
		}
		v.swapItemsAt(min, i);
		QStringList step;
		foreach (int j, this->v) step << QString::number(j);
		strings << QString::number(i + 1) + ":\n" + step.join(" | ");
	}
	this->ui->challenge3_result->clear();
	this->ui->challenge3_result->appendPlainText(strings.join("\n\n"));
}
