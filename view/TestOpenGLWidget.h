#ifndef TESTOPENGLWIDGET_H
#define TESTOPENGLWIDGET_H

#include <QMessageBox>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QTimer>
#include <QWheelEvent>

#include "../controller/controller.h"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

namespace s21 {

/// @class TestOpenGLWidget
/// @brief TestOpenGLWidget is a subclass of QOpenGLWidget that handles OpenGL
/// rendering and user interactions.
///
/// This class is responsible for rendering 3D models, processing user input
/// through mouse events, and managing the interaction with the underlying
/// Controller that maintains the model's state. It includes methods for parsing
/// OBJ files, transforming models, and obtaining model properties like vertex
/// and edge counts.
class TestOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 private:
  Controller* controller_;       ///< Pointer to the Controller managing the
                                 ///< underlying model.
  QPoint cursor_;                ///< Current cursor position during user interactions.
  Action* action_;               ///< Pointer to an Action object related to user operations.
  QSettings* settings_;          ///< Pointer to QSettings for managing application settings.
  QMessageBox* warning_;         ///< Pointer to a QMessageBox for displaying warnings.

  // ------------------ NEW FIELDS for VBO optimization ------------------
  bool buffers_built_ = false;   ///< Flag to indicate VBO/EBO are built.
  GLuint vao_;                   ///< Vertex Array Object for edges
  GLuint vbo_;                   ///< Vertex Buffer Object (all vertex coords)
  GLuint eboEdges_;              ///< Index Buffer (for edges lines)

  std::vector<float> verticesCPU_;     ///< CPU array of vertex coordinates (x,y,z).
  std::vector<unsigned int> edgesCPU_; ///< CPU array of indices for edges (lines).
  size_t n_vertices_ = 0;       ///< How many vertices total
  size_t n_edges_indices_ = 0;  ///< How many indices total in edges

  void buildGPUData();          ///< Builds VBO/EBO from the controller data.

 public:
  /// @brief Constructor for TestOpenGLWidget.
  /// @param parent Optional parent widget for this widget.
  explicit TestOpenGLWidget(QWidget* parent = nullptr);

  /// @brief Destructor for TestOpenGLWidget.
  ~TestOpenGLWidget();

  /// @brief Parses an OBJ file and prepares it for rendering.
  /// @param filename Path to the OBJ file to be parsed.
  void parseObj(QString filename);

  /// @brief Applies a transformation to the model.
  /// @param affineType Pointer to an Affine object that defines the type of
  /// transformation.
  /// @param value The value to be used for the transformation.
  void transformModel(Affine* affineType, double value);

  /// @brief Gets the number of vertices in the model.
  /// @return The count of vertices.
  int vertexNumber();

  /// @brief Gets the number of edges in the model.
  /// @return The count of edges.
  int edgeNumber();

  /// @brief Checks if a controller is set.
  /// @return true if a controller exists, false otherwise.
  bool is_controller();

  /// @brief Gets the associated Action object.
  /// @return Pointer to the Action object.
  Action* action();

  /// @brief Gets the QSettings instance used for storing application settings.
  /// @return Pointer to the QSettings.
  QSettings* settings();

  /// @brief Gets the QMessageBox instance used for displaying warnings.
  /// @return Pointer to the QMessageBox.
  QMessageBox* warning();

  // Mouse events
  /// @brief Handles mouse press events.
  /// @param e The mouse event data.
  void mousePressEvent(QMouseEvent* e) override;

  /// @brief Handles mouse move events.
  /// @param e The mouse event data.
  void mouseMoveEvent(QMouseEvent* e) override;

  /// @brief Handles mouse wheel events.
  /// @param e The wheel event data.
  void wheelEvent(QWheelEvent* e) override;

 protected:
  /// @brief Initializes OpenGL settings.
  void initializeGL() override;  // OpenGL initialization

  /// @brief Resizes the OpenGL viewport when the widget is resized.
  /// @param w New width of the widget.
  /// @param h New height of the widget.
  void resizeGL(int w, int h) override;  // Handle widget resize

  /// @brief Renders OpenGL content.
  void paintGL() override;  // Rendering

  /// @brief Initializes projection parameters for rendering.
  void initProjection();

  /// @brief Renders the edges of the model.
  void printEdges();

  /// @brief Renders the vertices of the model.
  void printVertexes();
};

}  // namespace s21
#endif
