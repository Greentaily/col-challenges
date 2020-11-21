#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->_sphere_scene = new QGraphicsScene(this);
	this->ui->challenge1_graphics_view->setScene(_sphere_scene);
}

MainWindow::~MainWindow()
{
	delete _sphere_scene;
	delete ui;
}


void MainWindow::on_challenge1_button_calculate_clicked()
{
	Sphere sphere;
	sphere.setRadius(this->ui->challenge1_input->value());
	qreal volume = sphere.getVolume();
	QPixmap pic = sphere.getPixmap(this->ui->challenge1_graphics_view->width(),
								   this->ui->challenge1_graphics_view->height());

	this->ui->challenge1_result->setValue(volume);

	this->_sphere_scene->clear();
	this->_sphere_scene->addPixmap(pic);
}

void MainWindow::on_challenge2_button_count_clicked()
{

}

void MainWindow::on_challenge3_button_generate_clicked()
{

}

void MainWindow::on_challenge3_button_sort_clicked()
{

}
