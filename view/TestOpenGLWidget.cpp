#include "TestOpenGLWidget.h"

#include <cmath>
#include <utility>

namespace s21 {

/**
 * @brief Constructs a TestOpenGLWidget with an optional parent.
 *
 * Initializes member variables and creates instances of QSettings and
 * QMessageBox.
 *
 * @param parent Pointer to the parent QWidget, if any.
 */
TestOpenGLWidget::TestOpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent),
      controller_(nullptr),
      action_(nullptr),
      buffers_built_(false),
      vao_(0),
      vbo_(0),
      eboEdges_(0),
      n_vertices_(0),
      n_edges_indices_(0) {
  settings_ = new QSettings("School21Sber", "3DViewer_v2.0_CPP", this);
  warning_ = new QMessageBox();
}

/**
 * @brief Destroys the TestOpenGLWidget and releases resources.
 *
 * Deletes allocated memory for the controller, action, settings, and warning
 * message box.
 */
TestOpenGLWidget::~TestOpenGLWidget() {
  makeCurrent();  // Make this context current before deleting GL objects
  if (vbo_) {
    glDeleteBuffers(1, &vbo_);
  }
  if (eboEdges_) {
    glDeleteBuffers(1, &eboEdges_);
  }
  if (vao_) {
    glDeleteVertexArrays(1, &vao_);
  }

  if (controller_ != nullptr) {
    delete controller_;
    delete action_;
  }
  delete settings_;
  delete warning_;
  doneCurrent();
}

/**
 * @brief Parses an OBJ file and normalizes the model.
 *
 * If the controller is not initialized, it creates a new instance of the
 * controller and action. It then calls the controller to parse the model and
 * normalize it.
 *
 * @param filename The path to the OBJ file to be parsed.
 */
void TestOpenGLWidget::parseObj(QString filename) {
  if (controller_ == nullptr) {
    controller_ = new s21::Controller();
    action_ = new Action();
  }

  std::string s_filename = filename.toStdString();
  controller_->parseModel(s_filename);
  controller_->normalizeModel(this->action()->s_);

  buffers_built_ = false; 
}

/**
 * @brief Internal: Build the GPU Buffers (VBO/EBO) from the controller data.
 */
void TestOpenGLWidget::buildGPUData() {
  if (!controller_) return;  // Safety check

  const auto& verts = controller_->getVertexes();
  n_vertices_ = verts.size();
  verticesCPU_.clear();
  verticesCPU_.reserve(n_vertices_ * 3);  // x,y,z

  for (auto& v : verts) {
    verticesCPU_.push_back(static_cast<float>(v.x()));
    verticesCPU_.push_back(static_cast<float>(v.y()));
    verticesCPU_.push_back(static_cast<float>(v.z()));
  }

  edgesCPU_.clear();
  const auto& faces = controller_->getFaces();
  for (auto& face : faces) {
    const auto& idxs = face.getFaceMembers();
    int sizeF = static_cast<int>(idxs.size());
    for (int i = 0; i < sizeF; i++) {
      // current -> next
      int i1 = idxs[i] - 1;
      int i2 = idxs[(i + 1) % sizeF] - 1;  
      edgesCPU_.push_back(static_cast<unsigned int>(i1));
      edgesCPU_.push_back(static_cast<unsigned int>(i2));
    }
  }
  n_edges_indices_ = edgesCPU_.size();

  if (!vao_) glGenVertexArrays(1, &vao_);
  if (!vbo_) glGenBuffers(1, &vbo_);
  if (!eboEdges_) glGenBuffers(1, &eboEdges_);

  glBindVertexArray(vao_);

  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER,
               verticesCPU_.size() * sizeof(float),
               verticesCPU_.data(),
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(
      0,              // layout location = 0
      3,              // x,y,z
      GL_FLOAT, 
      GL_FALSE, 
      3 * sizeof(float),
      (void*)0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboEdges_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               edgesCPU_.size() * sizeof(unsigned int),
               edgesCPU_.data(),
               GL_STATIC_DRAW);

  glBindVertexArray(0);

  
  buffers_built_ = true;
}

/**
 * @brief Applies a transformation to the model.
 *
 * Calls the transform method of the controller with the given affine type and
 * value.
 *
 * @param affineType Pointer to the affine transformation type.
 * @param value The transformation value to apply.
 */
void TestOpenGLWidget::transformModel(Affine* affineType, double value) {
  if (controller_) {
    controller_->transform(affineType, value);
    
    buffers_built_ = false;
  }
}

/**
 * @brief Retrieves the current number of vertices in the model.
 *
 * @return The number of vertices.
 */
int TestOpenGLWidget::vertexNumber() {
  return controller_ ? controller_->getVertexNum() : 0;
}

/**
 * @brief Retrieves the current number of edges in the model.
 *
 * @return The number of edges; returns 0 if the controller is not initialized.
 */
int TestOpenGLWidget::edgeNumber() {
  if (controller_) return controller_->getEdgeNum();
  return 0;
}

/**
 * @brief Retrieves the action object associated with this widget.
 *
 * @return Pointer to the action object.
 */
Action* TestOpenGLWidget::action() { 
  return action_; 
}

/**
 * @brief Retrieves the QSettings object associated with this widget.
 *
 * @return Pointer to the QSettings object.
 */
QSettings* TestOpenGLWidget::settings() {
  return settings_;
}

/**
 * @brief Retrieves the QMessageBox object for displaying warnings.
 *
 * @return Pointer to the QMessageBox object.
 */
QMessageBox* TestOpenGLWidget::warning() {
  return warning_;
}

/**
 * @brief Checks if the controller is initialized.
 *
 * @return True if the controller is initialized, false otherwise.
 */
bool TestOpenGLWidget::is_controller() {
  return (controller_ != nullptr);
}

/**
 * @brief Handles mouse press events.
 *
 * Stores the initial cursor position when the mouse is pressed.
 *
 * @param e Pointer to the QMouseEvent containing the details of the mouse
 * event.
 */
void TestOpenGLWidget::mousePressEvent(QMouseEvent* e) {
  cursor_ = e->position().toPoint();
}

/**
 * @brief Handles mouse move events to apply transformations to the model.
 *
 * If the left button is pressed, the model is translated based on the mouse
 * movement. If the right button is pressed, the model is rotated based on the
 * mouse movement.
 *
 * @param e Pointer to the QMouseEvent containing the details of the mouse
 * event.
 */
void TestOpenGLWidget::mouseMoveEvent(QMouseEvent* e) {
  QPoint p = e->position().toPoint();

  if (controller_) {
    QPoint delta = p - cursor_;
    
    if (delta.manhattanLength() > 2) {
      
      if (e->buttons() & Qt::LeftButton) {
        transformModel(action_->tx_, double(delta.x()) / 150.0);
        transformModel(action_->ty_, -double(delta.y()) / 150.0);
      }
      
      if (e->buttons() & Qt::RightButton) {
        transformModel(action_->ry_, -double(delta.x()));
        transformModel(action_->rx_, double(delta.y()));
      }
      update();
    }
  }
  cursor_ = p;
}

/**
 * @brief Handles the wheel event for zooming in and out.
 *
 * Scales the model based on the direction of the mouse wheel scroll.
 *
 * @param e Pointer to the QWheelEvent containing the details of the wheel
 * event.
 */
void TestOpenGLWidget::wheelEvent(QWheelEvent* e) {
  if (controller_) {
    double p = double(e->angleDelta().y()) / 120.0;
    if (p > 0) {
      transformModel(action_->s_, 1.1);
    } else if (p < 0) {
      transformModel(action_->s_, 0.9);
    }
    if (p != 0) {
      update();
    }
  }
}

/**
 * @brief Initializes OpenGL settings.
 *
 * This method sets the clear color for the background and enables depth
 * testing.
 */
void TestOpenGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // Background color
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}

/**
 * @brief Resizes the OpenGL viewport.
 *
 * Sets the viewport to match the current window dimensions.
 *
 * @param w New width of the window.
 * @param h New height of the window.
 */
void TestOpenGLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);  // Setting the viewport
}

/**
 * @brief Renders the OpenGL scene.
 *
 * This method clears the buffers and calls functions to
 * initialize the projection, and print edges and vertices.
 */
void TestOpenGLWidget::paintGL() {

  if (!buffers_built_) {
    buildGPUData();
  }

  QColor bg = settings_->value("bg_color").value<QColor>();
  glClearColor(bg.redF(), bg.greenF(), bg.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  initProjection();
  printEdges();
  printVertexes();
}

/**
 * @brief Initializes the projection matrix.
 *
 * This method sets up the projection matrix based on the
 * projection type retrieved from settings. It handles
 * both perspective and orthographic projections.
 */
void TestOpenGLWidget::initProjection() {
  Projection proj = (Projection)settings_->value("projection_type").toInt();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float aspect = float(width()) / float(height());
  if (proj == Central) {
    glFrustum(-aspect, aspect, -1.0f, 1.0f, 1.0f, 50.0f);
    glTranslatef(0.0f, 0.0f, -3.0f);
  } else {
    glOrtho(-2.0f * aspect, 2.0f * aspect, -2.0f, 2.0f, -10.0f, 10.0f);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

/**
 * @brief Renders the edges of the model.
 *
 * This method retrieves edge type, width, and color from settings,
 * and draws the edges of the model using modern glDrawElements.
 * Supports dashed and solid lines via line stipple (Compatibility).
 */
void TestOpenGLWidget::printEdges() {
  int edgeT = settings_->value("edge_type").toInt();
  int edgeW = settings_->value("edge_width").toInt();
  QColor edgeColor = settings_->value("edge_color").value<QColor>();

  glLineWidth(edgeW);

  if (edgeT == Dashed) {
    glEnable(GL_LINE_STIPPLE); 
    glLineStipple(1, 0x00FF);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glColor3f(edgeColor.redF(), edgeColor.greenF(), edgeColor.blueF());

  if (!controller_ || !buffers_built_ || n_vertices_ == 0) return;

  glBindVertexArray(vao_);

  glDrawElements(GL_LINES,
                 static_cast<GLsizei>(n_edges_indices_),
                 GL_UNSIGNED_INT,
                 nullptr);

  glBindVertexArray(0);
}

/**
 * @brief Renders the vertices of the model.
 *
 * This method retrieves vertex type, size, and color from settings and
 * draws the vertices using glDrawArrays(GL_POINTS).
 * Supports circular (smooth) and square point styles.
 */
void TestOpenGLWidget::printVertexes() {
  int vType = settings_->value("vertex_type").toInt();
  if (vType != None && controller_ && buffers_built_ && n_vertices_ > 0) {
    int vSize = settings_->value("vertex_size").toInt();
    QColor vColor = settings_->value("vertex_color").value<QColor>();

    glPointSize(vSize);

    if (vType == Circular) {
      glEnable(GL_POINT_SMOOTH);
    } else {
      glDisable(GL_POINT_SMOOTH);
    }
    glColor3f(vColor.redF(), vColor.greenF(), vColor.blueF());

    glBindVertexArray(vao_);

    glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(n_vertices_));

    glBindVertexArray(0);
  }
}

}  // namespace s21
