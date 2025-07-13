#include <QApplication>
#include <iostream>

#include "ocolus.h"

using namespace s21;

/** @mainpage 3DViewer
 *
 * A wireframe model is a model of an object in 3D graphics, which is a set of
 * vertices and edges that defines the shape of the displayed polyhedral object
 * in three-dimensional space.
 *
 * .Obj file is a geometry definition file format first developed by Wavefront
 * Technologies. The file format is open and accepted by many 3D graphics
 * application vendors.
 *
 * The .obj file format is a simple data format that represents only
 * three-dimensional geometry, specifically the position of each vertex, the UV
 * of each texture coordinate vertex, vertex normals and the faces that define
 * each polygon as a list of vertices and texture vertices. Obj coordinates have
 * no units, but Obj files can contain scale information in a readable comment
 * line.
 *
 * An affine transformation is a mapping in a plane or in space onto itself, in
 * which parallel lines become parallel lines, intersecting lines become
 * intersecting lines, and oblique lines become oblique lines. A transformation
 * in a plane is called affine if it is mutually unambiguous and the image of
 * any line is a line. A transformation (mapping) is called mutually unambiguous
 * (bijective) if it transforms different points into different points, and each
 * point is transformed into a point. In algebraic terms, an affine
 * transformation is a transformation of the form f(x) = M x + v, where M is
 * some invertible matrix and v is some value.
 *
 * Properties of affine transformations:
 *
 * A composition of affine transformations is an affine transformation too
 *
 * The inverse of an affine transformation is an affine transformation too
 *
 * The ratio of areas is conserved.
 *
 * The ratio of lengths of line segments is conserved.
 */

/** @brief Entrypoint
 *
 * Main fuction that starts 3DViewer.
 *
 * Initializes QT Application, creates MainWindow Ocolus with all ui elements.
 *
 * It needs no arguments (though can be given if nesessery)
 *
 * @return Result of application work (standart error-code)
 *
 */

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Ocolus ocolus;
  ocolus.show();

  return app.exec();
}
