#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTranslator translator;
	translator.load(QLocale(), QLatin1String("challenge"), QLatin1String("_"), QLatin1String(":/locales/lang"));
	a.installTranslator(&translator);

	MainWindow w;
	w.show();
	return a.exec();
}
