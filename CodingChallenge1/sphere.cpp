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
	this->_color_a = QColor(
						 QRandomGenerator::system()->bounded(25, 255),
						 QRandomGenerator::system()->bounded(25, 255),
						 QRandomGenerator::system()->bounded(25, 255));
}

QPixmap Sphere::getPixmap(int width, int height)
{
	QPixmap pixmap(width, height);
	QPainter painter(&pixmap);
	painter.setRenderHint(QPainter::Antialiasing);

	/* Diameter takes up 75% of the viewport space. */
	const qreal diameter = 0.75 * qMin(width, height);
	/* Bounding box for the sphere. */
	const QRectF box(
				(width - diameter) / 2.0,
				(height - diameter) / 2.0,
				diameter, diameter);

	this->drawBackground(painter, width, height);
	this->drawSphere(painter, diameter, box);
	this->drawText(painter, diameter, box);

	return pixmap;
}

void Sphere::drawBackground(QPainter& painter, int width, int height)
{
	QLinearGradient background(0, 0, 0, height);
	background.setColorAt(0, this->_color_a);
	background.setColorAt(1, this->_color_b);
	painter.fillRect(QRect(0, 0, width, height), QBrush(background));
}

void Sphere::drawSphere(QPainter& painter, qreal diameter, QRectF box)
{
	/* Coordinates for these two points are calculated based on the
	 * position of the center point of the bounding box. */

	/* Center of the gradient */
	QPointF point_a(box.center() *= 0.8);
	/* Focal point of the gradient */
	QPointF point_b(box.center().x() * 0.8, box.center().y() * 0.7);

	QRadialGradient sphere(point_a, diameter * 0.65, point_b, diameter * 0.05);

	sphere.setColorAt(0, this->_color_a);
	sphere.setColorAt(1, this->_color_b);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(sphere));

	painter.drawEllipse(box);
}

void Sphere::drawText(QPainter& painter, qreal diameter, QRectF box)
{
	const qreal half_r = diameter * 0.25;
	const qreal vertical = box.center().y();

	painter.setPen(Qt::SolidLine);

	/* Draw volume of the sphere */
	painter.drawText(box, Qt::AlignCenter, "V = " + QString::number(this->_volume, 'f'));
	/* Draw the radius value */
	painter.save();
	painter.translate(box.center());
	painter.rotate(270);
	painter.translate(-box.center().x() + half_r, - vertical - half_r * 2 - 20);
	painter.drawText(box, Qt::AlignCenter, "r = " + QString::number(this->_radius, 'f', 2));
	/* Draw the radius scale */
	painter.translate(0, 10);
	painter.drawLine(box.left() + half_r, vertical, box.right() - half_r, vertical);
	painter.drawLine(box.left() + half_r, vertical - 5, box.left() + half_r, vertical + 5);
	painter.drawLine(box.right() - half_r, vertical - 5, box.right() - half_r, vertical + 5);
	/* Draw the diameter value */
	painter.restore();
	painter.translate(0, -half_r * 2 - 20);
	painter.drawText(box, Qt::AlignCenter, "d = " + QString::number(this->_radius * 2, 'f', 2));
	/* Draw the diameter scale */
	painter.translate(0, 10);
	painter.drawLine(box.left(), vertical, box.right(), vertical);
	painter.drawLine(box.left(), vertical - 5, box.left(), vertical + 5);
	painter.drawLine(box.right(), vertical - 5, box.right(), vertical + 5);
}


