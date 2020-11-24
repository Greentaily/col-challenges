#ifndef SPHERE_H
#define SPHERE_H

#include <QPixmap>
#include <QPainter>
#include <QtMath>
#include <QRandomGenerator>

/**
 * Class that represents sphere and handles all relevant functions.
 */
class Sphere
{
public:
	Sphere(QColor color_a = QColorConstants::White, QColor color_b = QColorConstants::Black);

	/**
	 * @brief Set the color A for the sphere.
	 * @details Set the top left / focal color of the gradient
	 *			used to draw the sphere and the background.
	 * @param color The new color.
	 * @note Color A is supposed to be the lighter shade.
	 *
	 */
	void setColorA(QColor color) {this->_color_a = color;}
	/**
	 * @brief Set the color B for the sphere.
	 * @details Set the bottom right / center color of the gradient
	 *			used to draw the sphere and the background.
	 * @param color The new color.
	 * @note Color B is supposed to be the darker shade.
	 */
	void setColorB(QColor color) {this->_color_b = color;}
	/**
	 * Set the radius of the sphere.
	 * @param radius Radius of the sphere.
	 * @note This method will also calculate and set the volume of the sphere.
	 */
	void setRadius(qreal radius);
	/**
	 * Get the radius of the sphere.
	 * @return Radius of the sphere.
	 */
	qreal getRadius() {return this->_radius;}
	/**
	 * Get the volume of the sphere.
	 * @return Volume of the sphere.
	 */
	qreal getVolume() {return this->_volume;}

	/**
	 * Generate and set new random colors for the surface of the sphere.
	 * @note Color values are generated in range {25, 255}.
	 */
	void randomizeColors();

	/**
	 * @brief Get complete pixmap of the sphere.
	 * @details Create and return pixmap of specified dimensions
	 *			that contains center-aligned gradient representation
	 *			of the sphere, its volume and scales for radius and diameter.
	 * @param width Width of the requested pixmap.
	 * @param height Height of the requested pixmap.
	 * @return Pixmap of specified dimensions.
	 */
	QPixmap getPixmap(int width = 200, int height = 200);


private:
	void drawBackground(QPainter& painter, int width, int height);
	void drawSphere(QPainter& painter, qreal diameter, QRectF box);
	void drawText(QPainter& painter, qreal diameter, QRectF box);

	qreal _radius = 0;
	qreal _volume = 0;
	QColor _color_a;
	QColor _color_b;

};

#endif // SPHERE_H
