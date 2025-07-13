#include "bl.h"

#include <sstream>

using namespace std;

namespace s21 {

// ==================== Model ====================

Model* Model::mdGet() {
  static Model ret;  // Для предотвращения утечек
  return &ret;
}

/// @brief Default constructor for the Model class, initializes the parser.
Model::Model() {
  parser_ = new Parser();
}

/// @brief Destructor for the Model class, cleans up the vertex and face
/// lists.
Model::~Model() {
  vertex_list_.clear();
  face_list_.clear();
  delete parser_;
}

/// @brief Get the list of vertices.
/// @return A constant reference to the vector of vertices.
const vector<Vertex>& Model::getVertexList() const {
  return vertex_list_;
}

/// @brief Get the list of faces.
/// @return A constant reference to the vector of faces.
const vector<Face>& Model::getFaceList() const {
  return face_list_;
}

/// @brief Clear all vertices and faces from the model.
void Model::cleanModel() {
  vertex_list_.clear();
  face_list_.clear();
}

/// @brief Add a vertex to the model.
/// @param v The vertex to be added.
inline void Model::addVertex(Vertex v) {
  vertex_list_.push_back(v);
}

/// @brief Add a face to the model.
/// @param f The face to be added.
inline void Model::addFace(Face f) {
  face_list_.push_back(f);
}

/// @brief Get the scale factor for the model.
/// @return The scale factor as a double.
double Model::getScaleFactor() {
  return scale_factor_;
}

/// @brief Get the current affine transformation.
/// @return A pointer to the current affine transformation.
Affine* Model::affine() {
  return affine_;
}

// ==================== Edges count ====================

/// @brief Count the number of unique edges in the model.
/// @return The number of unique edges.
int Model::getEdgeCount() {
  std::set<std::pair<int, int>> uniqueEdges;
  for (auto& face : face_list_) {
    auto indices = face.getFaceMembers();
    int sizeF = static_cast<int>(indices.size());
    for (int i = 0; i < sizeF; i++) {
      int i1 = indices[i];
      int i2 = indices[(i + 1) % sizeF];  // Следующая вершина
      if (i1 > i2) std::swap(i1, i2);
      uniqueEdges.insert(std::make_pair(i1, i2));
    }
  }
  return static_cast<int>(uniqueEdges.size());
}

/// @brief Parse an OBJ file and populate the model with vertices and faces.
/// @param filename The name of the OBJ file to parse.
/// @throw invalid_argument if no vertices or faces are loaded after
/// parsing.
void Model::parseObjFile(string filename) {
  ifstream file;
  file.open(filename);

  if (file.is_open()) {

    string str;
    double max_vertex_abs = 0.0;
    while (getline(file, str)) {
      // Проверяем первые два символа строки
      if (str.compare(0, 2, "v ") == 0) {
        parser_->parseVertex(this, str, &max_vertex_abs);
      } else if (str.compare(0, 2, "f ") == 0) {
        parser_->parseFace(this, str);
      }
    }

    scale_factor_ = 1.8 / max_vertex_abs;

    if (vertex_list_.empty()) {
      throw invalid_argument("Error: No vertices loaded.");
    }
    if (face_list_.empty()) {
      throw invalid_argument("Error: No faces loaded.");
    }

    file.close();
  }
}

// ==================== Parser methods ====================

/// @brief Parse a vertex from a string and add it to the model.
/// @param model Pointer to the Model object to which the vertex will be
/// added.
/// @param str The string containing the vertex data.
/// @param max_vertex_abs Pointer to a double that keeps track of the
/// maximum absolute vertex coordinate.
inline void Parser::parseVertex(Model* model, string str,
                                double* max_vertex_abs) {

  std::istringstream iss(str);
  std::string prefix;  // ожидаем 'v'
  iss >> prefix;       // Пропускаем 'v'

  double x = 0.0, y = 0.0, z = 0.0;
  if (iss >> x >> y >> z) {

    if (std::fabs(x) > *max_vertex_abs) *max_vertex_abs = std::fabs(x);
    if (std::fabs(y) > *max_vertex_abs) *max_vertex_abs = std::fabs(y);
    if (std::fabs(z) > *max_vertex_abs) *max_vertex_abs = std::fabs(z);

    Vertex v(x, y, z);
    model->addVertex(v);
  }
}

/// @brief Parse a face from a string and add it to the model.
/// @param model Pointer to the Model object to which the face will be
/// added.
/// @param str The string containing the face data.
inline void Parser::parseFace(Model* model, string str) {

  Face f;
  std::istringstream iss(str);
  std::string prefix;  // ожидаем 'f'
  iss >> prefix;       // Пропускаем 'f'

  while (!iss.eof()) {
    std::string segment;
    iss >> segment;
    if (!segment.empty()) {
      // Игнорируем возможные "\r"
      if (segment == "\r") continue;
      int p = std::atoi(segment.c_str());
      f.addIndex(p);
    }
  }

  if (!f.getFaceMembers().empty()) {
    model->addFace(f);
  }

}

// ==================== Affine usage ====================

/// @brief Apply the current affine transformation to the model with a
/// specified value.
/// @param value The value used for the affine transformation (e.g., scale
/// factor, angle).
inline void Model::useAffine(double value) {
  affine_->transform(this, value);
}

/// @brief Set the current affine transformation for the model.
/// @param a Pointer to an Affine object that will be set as the current
/// transformation.
inline void Model::setAffine(Affine* a) {
  affine_ = a;
}

// ==================== Vertex ====================

/// @brief Constructor for the Vertex class.
/// @param x The x-coordinate of the vertex.
/// @param y The y-coordinate of the vertex.
/// @param z The z-coordinate of the vertex.
Vertex::Vertex(double x, double y, double z) {
  x_ = x;
  y_ = y;
  z_ = z;
}

/// @brief Get the x-coordinate of the vertex.
/// @return The x-coordinate as a double.
double Vertex::x() const {
  return x_;
}

/// @brief Get the y-coordinate of the vertex.
/// @return The y-coordinate as a double.
double Vertex::y() const {
  return y_;
}

/// @brief Get the z-coordinate of the vertex.
/// @return The z-coordinate as a double.
double Vertex::z() const {
  return z_;
}

/// @brief Set the x-coordinate of the vertex.
/// @param x The new x-coordinate.
void Vertex::set_x(double x) {
  x_ = x;
}

/// @brief Set the x-coordinate of the vertex.
/// @param x The new x-coordinate.
void Vertex::set_y(double y) {
  y_ = y;
}

/// @brief Set the z-coordinate of the vertex.
/// @param z The new z-coordinate.
void Vertex::set_z(double z) {
  z_ = z;
}

// ==================== face ====================

/// @brief Get the list of vertex indices that make up the face.
/// @return A constant reference to the vector of vertex indices.
const vector<int> Face::getFaceMembers() const {
  return this->face_vertexes_;
}

/// @brief Add an index to the face's vertex list.
/// @param idx The index of the vertex to be added.
inline void Face::addIndex(int idx) {
  this->face_vertexes_.push_back(std::abs(idx));
}

// ==================== Action ====================

/// @brief Constructor for the Action class.
/// This constructor initializes the transformation objects for scaling and
/// rotation along the X, Y, and Z axes, as well as translation along the X,
/// Y, and Z axes.
Action::Action() {
  s_ = new Scale;
  rx_ = new RotateX;
  ry_ = new RotateY;
  rz_ = new RotateZ;
  tx_ = new TranslateX;
  ty_ = new TranslateY;
  tz_ = new TranslateZ;
}

/// @brief Destructor for the Action class.
/// This destructor cleans up the dynamically allocated transformation
/// objects to prevent memory leaks.
Action::~Action() {
  delete s_;
  delete rx_;
  delete ry_;
  delete rz_;
  delete tx_;
  delete ty_;
  delete tz_;
}

}  // namespace s21
