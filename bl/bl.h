#ifndef BL_H
#define BL_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <regex>
#include <set>
#include <string>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>

using namespace std;

namespace s21 {
class Model;
class Vertex;
class Face;
class Parser;
class Affine;
class Action;

/// @enum Projection
/// @brief Enumeration to define type of projection for model.
typedef enum { Central = 0, Parallel } Projection;

/// @enum EdgeType
/// @brief Enumeration to define type of edges for model.
typedef enum { Solid = 0, Dashed } EdgeType;

/// @enum VertexType
/// @brief Enumeration to define type of vertexes for model.
typedef enum { None = 0, Circular, Squared } VertexType;

/// @class Changeable
/// @brief Abstract class containing rv for affine transformations and
/// prototypes of methods to perform operations with it
class Changeable {
 protected:
  Affine* affine_;

 public:
  virtual ~Changeable(){};  ///< Destructor for Changeable class.
  virtual void useAffine(double value) = 0;  ///< Apply an affine transformation
                                             ///< with the given value.
  virtual void setAffine(
      Affine* a) = 0;  ///< Set the affine transformation object to be used.
};

/**
 * @class Model
 * @brief Class Model is a Facade class for all the logic implemented in
 * classes Vertex, Face, Parser and Affine.
 *
 * This class encapsulates and divides responsibilities, as well as serves
 * as a Client for the Affine class, which implements Strategy patterns
 * for actions Rotate, Translate and Scale.
 */
class Model : Changeable {
 private:
  vector<Vertex> vertex_list_;  ///< List of vertices in the model.
  vector<Face> face_list_;      ///< List of faces in the model.
  Parser* parser_;              ///< Parser object for handling file input.
  double scale_factor_;         ///< Factor for scaling model.
  Model();                      ///< Constructor for Model class.
                                // static Model* md_;

 public:
  ~Model();  ///< Destructor for Model class.

  Model(const Model&) = delete;
  void operator=(const Model&) = delete;

  static Model* mdGet();

  // Get&Set
  const vector<Vertex>& getVertexList() const;  ///< Get the list of vertices.
  const vector<Face>& getFaceList() const;      ///< Get the list of faces.
  void cleanModel();                            ///< Clean/reset the model.
  void addVertex(Vertex v);                     ///< Add a vertex to the model.
  void addFace(Face f);                         ///< Add a face to the model.
  double getScaleFactor();  ///< Get the scale factor used in the model.
  Affine* affine();    ///< Get the affine transformation currently applied.
  int getEdgeCount();  ///< Get the count of edges in the model.

  // Parent's funcs
  void useAffine(double value) override;  ///< Apply an affine transformation
                                          ///< with a specified value.
  void setAffine(Affine* a) override;     ///< Set the affine transformation.

  // Funcs
  void parseObjFile(string filename);  ///< Parse an OBJ file to build the model.
};

/// @class Vertex
/// @brief Class Vertex describes the structure of one vertex.
class Vertex {
 private:
  double x_;  ///< X coordinate of the vertex.
  double y_;  ///< Y coordinate of the vertex.
  double z_;  ///< Z coordinate of the vertex.

 public:
  Vertex(double x, double y, double z);  ///< Constructor for Vertex class.

  // Get&Set
  double x() const;      ///< Get the X coordinate of the vertex.
  double y() const;      ///< Get the Y coordinate of the vertex.
  double z() const;      ///< Get the Z coordinate of the vertex.
  void set_x(double x);  ///< Set the X coordinate.
  void set_y(double y);  ///< Set the Y coordinate.
  void set_z(double z);  ///< Set the Z coordinate.
};

/// @class Face
/// @brief Class Vertex describes the structure of one face.
class Face {
 private:
  std::vector<int> face_vertexes_;  ///< Indices of vertices that form the face.

 public:
  const vector<int> getFaceMembers()
      const;               ///< Get the members (vertex indices) of the face.
  void addIndex(int idx);  ///< Add a vertex index to the face.
};

/// @class Parser
/// @brief Class Parser performs basic operations on lines in .obj file.
class Parser {
 public:
  void parseVertex(Model* model, string str,
                   double* max_vertex_abs);  ///< Parse a vertex string and
                                             ///< add it to the model.
  void parseFace(Model* model,
                 string str);  ///< Parse a face string and add it to the model.
};

/// @class Affine
/// @brief Abstract class for performing affine operations.
class Affine {
 public:
  Affine(){};           ///< Default constructor for the Affine class.
  virtual ~Affine(){};  ///< Virtual destructor for the Affine class.

  virtual void transform(Model* model,
                         double value) = 0;  ///< Apply transformation.
};

/// @class Scale
/// @brief Scale affine transformation.
class Scale : public Affine {
 public:
  Scale();            ///< Default constructor for Scale.
  ~Scale() override;  ///< Destructor for Scale.
  void transform(Model* model, double factor) override;
};

/// @class RotateX
class RotateX : public Affine {
 public:
  RotateX();            ///< Default constructor for RotateX.
  ~RotateX() override;  ///< Destructor for RotateX.
  void transform(Model* model, double angle) override;
};

/// @class RotateY
class RotateY : public Affine {
 public:
  RotateY();            ///< Default constructor for RotateY.
  ~RotateY() override;  ///< Destructor for RotateY.
  void transform(Model* model, double angle) override;
};

/// @class RotateZ
class RotateZ : public Affine {
 public:
  RotateZ();            ///< Default constructor for RotateZ.
  ~RotateZ() override;  ///< Destructor for RotateZ.
  void transform(Model* model, double angle) override;
};

/// @class TranslateX
class TranslateX : public Affine {
 public:
  TranslateX();            ///< Default constructor for TranslateX.
  ~TranslateX() override;  ///< Destructor for TranslateX.
  void transform(Model* model, double value) override;
};

/// @class TranslateY
class TranslateY : public Affine {
 public:
  TranslateY();            ///< Default constructor for TranslateY.
  ~TranslateY() override;  ///< Destructor for TranslateY.
  void transform(Model* model, double value) override;
};

/// @class TranslateZ
class TranslateZ : public Affine {
 public:
  TranslateZ();            ///< Default constructor for TranslateZ.
  ~TranslateZ() override;  ///< Destructor for TranslateZ.
  void transform(Model* model, double value) override;
};

/// @class Action
/// @brief Class action contains pointers to affine operations.
class Action {
 public:
  Scale* s_;        ///< Pointer to the Scale action.
  TranslateX* tx_;  ///< Pointer to the TranslateX action.
  TranslateY* ty_;  ///< Pointer to the TranslateY action.
  TranslateZ* tz_;  ///< Pointer to the TranslateZ action.
  RotateX* rx_;     ///< Pointer to the RotateX action.
  RotateY* ry_;     ///< Pointer to the RotateY action.
  RotateZ* rz_;     ///< Pointer to the RotateZ action.

  Action();   ///< Default constructor for the Action class.
  ~Action();  ///< Destructor for the Action class.
};
}  // namespace s21

#endif
