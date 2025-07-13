#include "controller.h"

using namespace std;

namespace s21 {

/// @brief Constructor for the Controller class.
/// Initializes a new Model instance.
Controller::Controller() { model_ = Model::mdGet(); }

/// @brief Destructor for the Controller class.
/// Cleans up the dynamically allocated Model instance.
Controller::~Controller() {}

/// @brief Retrieves the list of vertices from the managed Model.
/// @return A reference to the vector of Vertex objects.
vector<Vertex>& Controller::getVertexes() const {
  return const_cast<vector<Vertex>&>(model_->getVertexList());
}

/// @brief Retrieves the list of faces from the managed Model.
/// @return A reference to the vector of Face objects.
vector<Face>& Controller::getFaces() const {
  return const_cast<vector<Face>&>(model_->getFaceList());
}

/// @brief Parses an OBJ file to populate the Model with data.
/// @param filename The path to the OBJ file to be parsed.
void Controller::parseModel(string filename) {
  model_->cleanModel();
  model_->parseObjFile(filename);
}

/// @brief Retrieves the number of vertices in the Model.
/// @return The number of vertices.
int Controller::getVertexNum() { return model_->getVertexList().size(); }

/// @brief Retrieves the number of edges in the Model.
/// @return The number of edges, or 0 if the model does not exist.
int Controller::getEdgeNum() {
  if (model_) return model_->getEdgeCount();
  return 0;
}

/// @brief Normalizes the model using a given scaling factor.
/// @param scale Pointer to a Scale object representing the type of operation.
void Controller::normalizeModel(Scale* scale) {
  model_->setAffine(scale);
  model_->useAffine(model_->getScaleFactor());
}

/// @brief Applies a transformation to the model using the specified affine type
/// and value.
/// @param affineType Pointer to an Affine object representing the type of
/// transformation.
/// @param value The value to be used in the transformation.
void Controller::transform(Affine* affineType, double value) {
  model_->setAffine(affineType);
  model_->useAffine(value);
}
}  // namespace s21
