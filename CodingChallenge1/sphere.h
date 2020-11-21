#ifndef SPHERE_H
#define SPHERE_H

#include <QPixmap>
#include <QPainter>
#include <QtMath>


class Sphere
{
public:
	Sphere(QColor color_a = QColorConstants::White, QColor color_b = QColorConstants::Black);

	void setColorA(QColor color) {this->_color_a = color;}
	void setColorB(QColor color) {this->_color_b = color;}
	void setRadius(qreal radius);
	qreal getRadius() {return this->_radius;}
	qreal getVolume() {return this->_volume;}

	void randomizeColors();

	QPixmap getPixmap(int width = 200, int height = 200);


private:
	qreal _radius = 0;
	qreal _volume = 0;
	QColor _color_a;
	QColor _color_b;

};

#endif // SPHERE_H
