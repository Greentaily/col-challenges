#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>

#include "sphere.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_challenge1_button_calculate_clicked();

	void on_challenge2_button_count_clicked();

	void on_challenge3_button_generate_clicked();

	void on_challenge3_button_sort_clicked();

private:
	Ui::MainWindow* ui;
	QVector<int> v;
};
#endif // MAINWINDOW_H
