#include "bl.h"

namespace s21 {

// TranslateX
TranslateX::TranslateX() = default;   // TranslateX constructor
TranslateX::~TranslateX() = default;  // TranslateX destructor

// TranslateY
TranslateY::TranslateY() = default;   // TranslateY constructor
TranslateY::~TranslateY() = default;  // TranslateY destructor

// TranslateZ
TranslateZ::TranslateZ() = default;   // TranslateZ constructor
TranslateZ::~TranslateZ() = default;  // TranslateZ destructor

// Scale
Scale::Scale() = default;   // Scale constructor
Scale::~Scale() = default;  // Scale destructor

// RotateX
RotateX::RotateX() = default;   // RotateX constructor
RotateX::~RotateX() = default;  // RotateX destructor

// RotateY
RotateY::RotateY() = default;   // RotateY constructor
RotateY::~RotateY() = default;  // RotateY destructor

// RotateZ
RotateZ::RotateZ() = default;   // RotateZ constructor
RotateZ::~RotateZ() = default;  // RotateZ destructor

// ==================== Transformations ====================

/// @brief Scale the vertices of the model by a given factor.
/// @param model Pointer to the model whose vertices will be scaled.
/// @param factor The scaling factor. Values greater than 1 enlarge the model,
/// while values between 0 and 1 shrink it.
void Scale::transform(Model* model, double factor) {
  for (const auto& vertex : model->getVertexList()) {
    auto& mutableVertex = const_cast<Vertex&>(vertex);
    mutableVertex.set_x(vertex.x() * factor);
    mutableVertex.set_y(vertex.y() * factor);
    mutableVertex.set_z(vertex.z() * factor);
  }
}

/// @brief Rotate the vertices of the model around the X-axis.
/// @param model Pointer to the model whose vertices will be rotated.
/// @param angle The angle of rotation in degrees. Positive values rotate
/// counterclockwise.
void RotateX::transform(Model* model, double angle) {
  angle = angle * (M_PI / 180);
  for (const auto& vertex : model->getVertexList()) {
    auto& mutableVertex = const_cast<Vertex&>(vertex);
    double y = vertex.y();
    double z = vertex.z();
    mutableVertex.set_y(y * cos(angle) + z * sin(angle));
    mutableVertex.set_z(-y * sin(angle) + z * cos(angle));
  }
}

/// @brief Rotate the vertices of the model around the Y-axis.
/// @param model Pointer to the model whose vertices will be rotated.
/// @param angle The angle of rotation in degrees. Positive values rotate
/// counterclockwise.
void RotateY::transform(Model* model, double angle) {
  angle = angle * (M_PI / 180);
  for (const auto& vertex : model->getVertexList()) {
    auto& mutableVertex = const_cast<Vertex&>(vertex);
    double x = vertex.x();
    double z = vertex.z();
    mutableVertex.set_x(x * cos(angle) + z * sin(angle));
    mutableVertex.set_z(-x * sin(angle) + z * cos(angle));
  }
}

/// @brief Rotate the vertices of the model around the Z-axis.
/// @param model Pointer to the model whose vertices will be rotated.
/// @param angle The angle of rotation in degrees. Positive values rotate
/// counterclockwise.
void RotateZ::transform(Model* model, double angle) {
  angle = angle * (M_PI / 180);
  for (const auto& vertex : model->getVertexList()) {
    auto& mutableVertex = const_cast<Vertex&>(vertex);
    double x = vertex.x();
    double y = vertex.y();
    mutableVertex.set_x(x * cos(angle) + y * sin(angle));
    mutableVertex.set_y(-x * sin(angle) + y * cos(angle));
  }
}

/// @brief Translate the vertices of the model along the X-axis.
/// @param model Pointer to the model whose vertices will be translated.
/// @param value The translation distance along the X-axis.
void TranslateX::transform(Model* model, double value) {
  for (const auto& vertex : model->getVertexList()) {
    auto& mutableVertex = const_cast<Vertex&>(vertex);
    mutableVertex.set_x(vertex.x() + value);
  }
}

/// @brief Translate the vertices of the model along the Y-axis.
/// @param model Pointer to the model whose vertices will be translated.
/// @param value The translation distance along the Y-axis.
void TranslateY::transform(Model* model, double value) {
  for (const auto& vertex : model->getVertexList()) {
    auto& mutableVertex = const_cast<Vertex&>(vertex);
    mutableVertex.set_y(vertex.y() + value);
  }
}

/// @brief Translate the vertices of the model along the Z-axis.
/// @param model Pointer to the model whose vertices will be translated.
/// @param value The translation distance along the Z-axis.
void TranslateZ::transform(Model* model, double value) {
  for (const auto& vertex : model->getVertexList()) {
    auto& mutableVertex = const_cast<Vertex&>(vertex);
    mutableVertex.set_z(vertex.z() + value);
  }
}

}  // namespace s21
