#include "sphere.h"


Sphere::Sphere(QColor color_a, QColor color_b)
	: _color_a(color_a),
	  _color_b(color_b)
{

}

void Sphere::setRadius(qreal radius)
{
	this->_radius = radius;
	this->_volume = (4.0/3.0) * M_PI * qPow(radius, 3);
}

void Sphere::randomizeColors()
{

}

QPixmap Sphere::getPixmap(int width, int height)
{
	const int size = qMin(width, height);
	const double diameter = 0.8 * size;

	QPixmap pixmap(width, height);
	QPainter painter(&pixmap);
	painter.setRenderHint(QPainter::Antialiasing);

	QLinearGradient background(0, 0, 0, height);
	background.setColorAt(0, this->_color_a);
	background.setColorAt(1, this->_color_b);
	QBrush brush_background(background);
	painter.fillRect(QRect(0, 0, width, height), brush_background);

	QPointF point_a(0.4 * size, 0.4 * size);
	QPointF point_b(0.45 * size, 0.45 * size);
	QRadialGradient sphere(point_a, size * 0.5, point_b, size * 0.1);
	sphere.setColorAt(0, this->_color_a);
	sphere.setColorAt(1, this->_color_b);
	QBrush brush_sphere(sphere);
	painter.setPen(Qt::NoPen);
	painter.setBrush(brush_sphere);
	painter.drawEllipse(QRectF((size - diameter) / 2, (size - diameter) / 2, diameter, diameter));

	return pixmap;
}
