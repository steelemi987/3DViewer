#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../bl/bl.h"

namespace s21 {

/// @class Controller
/// @brief Class is responsible  for any operation with model.
class Controller {
 private:
  Model* model_;  ///< Pointer to the model.

 public:
  Controller();   ///< Class constructor.
  ~Controller();  ///< Class destructor.

  // Get&Set
  vector<Vertex>& getVertexes()
      const;                       ///< Returns list(vector type) of vertexes.
  vector<Face>& getFaces() const;  ///< Returns list(vector type) of faces.
  int getVertexNum();              ///< Gets number of vertexes.
  int getEdgeNum();                ///< Gets number of edges.

  // Data
  void parseModel(string filename);   ///< Calls model parsing.
  void normalizeModel(Scale* scale);  ///< Makes model normalized for viewport.

  // Affine
  void transform(Affine* affineType,
                 double value);  ///< Calls affine transformation.
};
}  // namespace s21

#endif  // !CONTROLLER_H
