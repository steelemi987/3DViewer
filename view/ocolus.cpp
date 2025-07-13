#include "ocolus.h"

#include "ui_ocolus.h"

namespace s21 {

/// @brief Constructor for Ocolus.
/// @param parent Optional parent widget for this window.
Ocolus::Ocolus(QWidget* parent) : QMainWindow(parent), ui(new Ui::Ocolus) {
  ui->setupUi(this);
  loadSettings();
}

/// @brief Destructor for Ocolus.
///
/// Cleans up the UI components and saves the current settings before
/// destruction.
Ocolus::~Ocolus() {
  ui->openGLWidget->settings()->setValue("Settings", true);
  delete ui;
}

/// @brief Resets all sliders to their default positions.
///
/// This method sets the positions of all translation, scale, and rotation
/// sliders to zero.
void Ocolus::dropSliders() {
  sliderPosition[TranslateX_s] = 0;
  sliderPosition[TranslateY_s] = 0;
  sliderPosition[TranslateZ_s] = 0;
  sliderPosition[Scale_s] = 0;
  sliderPosition[RotateX_s] = 0;
  sliderPosition[RotateY_s] = 0;
  sliderPosition[RotateZ_s] = 0;
  this->ui->translateXSlider->setSliderPosition(0);
  this->ui->translateYSlider->setSliderPosition(0);
  this->ui->translateZSlider->setSliderPosition(0);
  this->ui->scaleSlider->setSliderPosition(0);
  this->ui->rotateXSlider->setSliderPosition(0);
  this->ui->rotateYSlider->setSliderPosition(0);
  this->ui->rotateZSlider->setSliderPosition(0);
}

/// @brief Resets the application settings to their default values.
///
/// This method sets the projection type, edge type, vertex type, background
/// color, vertex color, edge color, edge width, and vertex size to their
/// default values.
void Ocolus::setToDefault() {
  ui->openGLWidget->settings()->setValue("Settings", false);
  ui->parallel_radioButton->setChecked(true);
  ui->openGLWidget->settings()->setValue("projection_type", Parallel);
  ui->e_solid_radioButton->setChecked(true);
  ui->openGLWidget->settings()->setValue("edge_type", Solid);
  ui->v_none_radioButton->setChecked(true);
  ui->openGLWidget->settings()->setValue("vertex_type", None);
  QColor bg_color = Qt::black;
  QColor v_color = Qt::white;
  QColor e_color = Qt::white;
  ui->openGLWidget->settings()->setValue("bg_color", bg_color);
  ui->openGLWidget->settings()->setValue("vertex_color", v_color);
  ui->openGLWidget->settings()->setValue("edge_color", e_color);
  ui->openGLWidget->settings()->setValue("edge_width", 1);
  this->ui->e_thickness_Slider->setSliderPosition(1);
  ui->openGLWidget->settings()->setValue("vertex_size", 5);
  this->ui->v_size_Slider->setSliderPosition(5);
}

/// @brief Loads application settings from QSettings.
///
/// This method retrieves the saved settings and updates the UI components
/// accordingly. If no settings are found, it calls setToDefault() to initialize
/// the UI with default values.
void Ocolus::loadSettings() {
  if (ui->openGLWidget->settings()->value("Settings") == true) {
    switch (ui->openGLWidget->settings()->value("projection_type").toInt()) {
      case Central:
        ui->central_radioButton->setChecked(true);
        break;
      case Parallel:
        ui->parallel_radioButton->setChecked(true);
        break;
    }

    switch (ui->openGLWidget->settings()->value("edge_type").toInt()) {
      case Solid:
        ui->e_solid_radioButton->setChecked(true);
        break;
      case Dashed:
        ui->e_dashed_radioButton->setChecked(true);
        break;
    }

    switch (ui->openGLWidget->settings()->value("vertex_type").toInt()) {
      case None:
        ui->v_none_radioButton->setChecked(true);
        break;
      case Circular:
        ui->v_circular_radioButton->setChecked(true);
        break;
      case Squared:
        ui->v_squared_radioButton->setChecked(true);
        break;
    }
  } else {
    setToDefault();
  }
}

/// @brief Opens and processes an OBJ file.
/// @param filename The path to the OBJ file to be opened.
///
/// This method attempts to parse the specified OBJ file and updates the UI with
/// the filename, number of vertices, and number of edges. If an error occurs
/// during parsing, it displays an error message.
void Ocolus::openFile(QString filename) {
  if (filename.size() > 0) {
    try {
      this->ui->openGLWidget->parseObj(filename);
      QStringList l = filename.split("/");
      this->ui->filename->setText(l.last());
      this->ui->num_of_v->setNum(ui->openGLWidget->vertexNumber());
      this->ui->num_of_e->setNum(ui->openGLWidget->edgeNumber());
      dropSliders();
    } catch (invalid_argument) {
      ui->filename->setText("");
      ui->num_of_v->setText("");
      ui->openGLWidget->warning()->setWindowTitle("Error");
      ui->openGLWidget->warning()->setText(
          "Something went wrong while processing file. The file might be "
          "corrupted, or it's not an .obj file. Please, choose correct .obj "
          "file.");
      ui->openGLWidget->warning()->exec();
      ui->openGLWidget->update();
    }
  }
}

void Ocolus::on_OpenFileButton_clicked() {
  /// @brief Slot triggered when the "Open File" button is clicked.
  ///
  /// This method opens a file dialog to allow the user to select an OBJ file.
  /// If a valid file is selected, it calls openFile() to process it.
  QString filename = QFileDialog::getOpenFileName(
      this, tr("Open .obj file:"), "~/", tr("Obj Files (*.obj)"));
  openFile(filename);
}

void Ocolus::on_translateXSlider_valueChanged(int value) {
  /// @brief Slot triggered when the translate X slider value changes.
  ///
  /// This method updates the translation of the model along the X-axis based on
  /// the slider's value. It also calculates the difference from the previous
  /// position stored in sliderPosition.
  ///
  /// @param value The new value of the translate X slider.
  int pos = value;
  value -= sliderPosition[TranslateX_s];
  sliderPosition[TranslateX_s] = pos;

  if (ui->openGLWidget->is_controller()) {
    this->ui->openGLWidget->transformModel(ui->openGLWidget->action()->tx_,
                                           (double)value / 100);
    this->ui->openGLWidget->update();
  }
}

void Ocolus::on_translateYSlider_valueChanged(int value) {
  /// @brief Slot triggered when the translate Y slider value changes.
  ///
  /// This method updates the translation of the model along the Y-axis based on
  /// the slider's value, similar to the translate X slider.
  ///
  /// @param value The new value of the translate Y slider.
  int pos = value;
  value -= sliderPosition[TranslateY_s];
  sliderPosition[TranslateY_s] = pos;

  if (ui->openGLWidget->is_controller()) {
    this->ui->openGLWidget->transformModel(ui->openGLWidget->action()->ty_,
                                           (double)value / 100);
    this->ui->openGLWidget->update();
  }
}

void Ocolus::on_translateZSlider_valueChanged(int value) {
  /// @brief Slot triggered when the translate Z slider value changes.
  ///
  /// This method updates the translation of the model along the Z-axis based on
  /// the slider's value, similar to the translate X and Y sliders.
  ///
  /// @param value The new value of the translate Z slider.
  int pos = value;
  value -= sliderPosition[TranslateZ_s];
  sliderPosition[TranslateZ_s] = pos;

  if (ui->openGLWidget->is_controller()) {
    this->ui->openGLWidget->transformModel(ui->openGLWidget->action()->tz_,
                                           (double)value / 100);
    this->ui->openGLWidget->update();
  }
}

void Ocolus::on_scaleSlider_valueChanged(int value) {
  /// @brief Slot triggered when the scale slider value changes.
  ///
  /// This method updates the scale of the model based on the slider's value.
  /// The value is adjusted to provide a scaling factor.
  ///
  /// @param value The new value of the scale slider.
  int pos = value;
  value -= sliderPosition[Scale_s];
  sliderPosition[Scale_s] = pos;

  if (ui->openGLWidget->is_controller()) {
    this->ui->openGLWidget->transformModel(ui->openGLWidget->action()->s_,
                                           1 + ((double)value / 10));
    this->ui->openGLWidget->update();
  }
}

void Ocolus::on_rotateXSlider_valueChanged(int value) {
  /// @brief Slot triggered when the rotate X slider value changes.
  ///
  /// This method updates the rotation of the model around the X-axis based on
  /// the slider's value.
  ///
  /// @param value The new value of the rotate X slider.
  int pos = value;
  value -= sliderPosition[RotateX_s];
  sliderPosition[RotateX_s] = pos;

  if (ui->openGLWidget->is_controller()) {
    this->ui->openGLWidget->transformModel(ui->openGLWidget->action()->rx_,
                                           (double)value);
    this->ui->openGLWidget->update();
  }
}

void Ocolus::on_rotateYSlider_valueChanged(int value) {
  /// @brief Slot triggered when the rotate Y slider value changes.
  ///
  /// This method updates the rotation of the model around the Y-axis based on
  /// the slider's value.
  ///
  /// @param value The new value of the rotate Y slider.
  int pos = value;
  value -= sliderPosition[RotateY_s];
  sliderPosition[RotateY_s] = pos;

  if (ui->openGLWidget->is_controller()) {
    this->ui->openGLWidget->transformModel(ui->openGLWidget->action()->ry_,
                                           (double)value);
    this->ui->openGLWidget->update();
  }
}

void Ocolus::on_rotateZSlider_valueChanged(int value) {
  /// @brief Slot triggered when the rotate Z slider value changes.
  ///
  /// This method updates the rotation of the model around the Z-axis based on
  /// the slider's value.
  ///
  /// @param value The new value of the rotate Z slider.
  int pos = value;
  value -= sliderPosition[RotateZ_s];
  sliderPosition[RotateZ_s] = pos;

  if (ui->openGLWidget->is_controller()) {
    this->ui->openGLWidget->transformModel(ui->openGLWidget->action()->rz_,
                                           (double)value);
    this->ui->openGLWidget->update();
  }
}

void Ocolus::on_central_radioButton_clicked() {
  /// @brief Slot triggered when the "Central" radio button is clicked.
  ///
  /// This method sets the projection type to Central in the OpenGL widget
  /// settings and triggers an update to reflect the change in the rendering.
  ui->openGLWidget->settings()->setValue("projection_type", Central);
  ui->openGLWidget->update();
}

void Ocolus::on_parallel_radioButton_clicked() {
  /// @brief Slot triggered when the "Parallel" radio button is clicked.
  ///
  /// This method sets the projection type to Parallel in the OpenGL widget
  /// settings and triggers an update to reflect the change in the rendering.
  ui->openGLWidget->settings()->setValue("projection_type", Parallel);
  ui->openGLWidget->update();
}

void Ocolus::on_e_solid_radioButton_clicked() {
  /// @brief Slot triggered when the "Solid" edge type radio button is clicked.
  ///
  /// This method sets the edge type to Solid in the OpenGL widget settings
  /// and triggers an update to reflect the change in the rendering.
  ui->openGLWidget->settings()->setValue("edge_type", Solid);
  ui->openGLWidget->update();
}

void Ocolus::on_e_dashed_radioButton_clicked() {
  /// @brief Slot triggered when the "Dashed" edge type radio button is clicked.
  ///
  /// This method sets the edge type to Dashed in the OpenGL widget settings
  /// and triggers an update to reflect the change in the rendering.
  ui->openGLWidget->settings()->setValue("edge_type", Dashed);
  ui->openGLWidget->update();
}

void Ocolus::on_v_none_radioButton_clicked() {
  /// @brief Slot triggered when the "None" vertex type radio button is clicked.
  ///
  /// This method sets the vertex type to None in the OpenGL widget settings
  /// and triggers an update to reflect the change in the rendering.
  ui->openGLWidget->settings()->setValue("vertex_type", None);
  ui->openGLWidget->update();
}

void Ocolus::on_v_circular_radioButton_clicked() {
  /// @brief Slot triggered when the "Circular" vertex type radio button is
  /// clicked.
  ///
  /// This method sets the vertex type to Circular in the OpenGL widget settings
  /// and triggers an update to reflect the change in the rendering.
  ui->openGLWidget->settings()->setValue("vertex_type", Circular);
  ui->openGLWidget->update();
}

void Ocolus::on_v_squared_radioButton_clicked() {
  /// @brief Slot triggered when the "Squared" vertex type radio button is
  /// clicked.
  ///
  /// This method sets the vertex type to Squared in the OpenGL widget settings
  /// and triggers an update to reflect the change in the rendering.
  ui->openGLWidget->settings()->setValue("vertex_type", Squared);
  ui->openGLWidget->update();
}

void Ocolus::on_e_color_Button_clicked() {
  /// @brief Slot triggered when the "Choose Edge Color" button is clicked.
  ///
  /// This method opens a color dialog to select a new edge color. If a valid
  /// color is selected, it updates the edge color setting in the OpenGL widget
  /// and triggers an update to reflect the change in the rendering.
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose Edge Color");
  if (color.isValid()) {
    ui->openGLWidget->settings()->setValue("edge_color", color);
    ui->openGLWidget->update();
  }
}

void Ocolus::on_v_color_Button_clicked() {
  /// @brief Slot triggered when the "Choose Vertex Color" button is clicked.
  ///
  /// This method opens a color dialog to select a new vertex color. If a valid
  /// color is selected, it updates the vertex color setting in the OpenGL
  /// widget and triggers an update to reflect the change in the rendering.
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose Vertex Color");
  if (color.isValid()) {
    ui->openGLWidget->settings()->setValue("vertex_color", color);
    ui->openGLWidget->update();
  }
}

void Ocolus::on_bg_color_Button_clicked() {
  /// @brief Slot triggered when the "Choose Background Color" button is
  /// clicked.
  ///
  /// This method opens a color dialog to select a new background color. If a
  /// valid color is selected, it updates the background color setting in the
  /// OpenGL widget and triggers an update to reflect the change in the
  /// rendering.
  QColor color =
      QColorDialog::getColor(Qt::white, this, "Choose Background Color");
  if (color.isValid()) {
    ui->openGLWidget->settings()->setValue("bg_color", color);
    ui->openGLWidget->update();
  }
}

void Ocolus::on_e_thickness_Slider_valueChanged(int value) {
  /// @brief Slot triggered when the edge thickness slider value changes.
  ///
  /// This method updates the edge width setting in the OpenGL widget based
  /// on the new value from the slider and triggers an update to reflect
  /// the change in the rendering.
  ui->openGLWidget->settings()->setValue("edge_width", value);
  ui->openGLWidget->update();
}

void Ocolus::on_v_size_Slider_valueChanged(int value) {
  /// @brief Slot triggered when the vertex size slider value changes.
  ///
  /// This method updates the vertex size setting in the OpenGL widget based
  /// on the new value from the slider and triggers an update to reflect
  /// the change in the rendering.
  ui->openGLWidget->settings()->setValue("vertex_size", value);
  ui->openGLWidget->update();
}

void Ocolus::on_setDefault_Button_clicked() {
  /// @brief Slot triggered when the "Set Default" button is clicked.
  ///
  /// This method resets all settings to their default values by calling
  /// setToDefault() and triggers an update to reflect the changes in the
  /// rendering.
  setToDefault();
  this->ui->openGLWidget->update();
}

/// @brief Slot triggered when the "Show" button is clicked.
///
/// This method sends the parsed model to viewport
void Ocolus::on_showButton_clicked() { ui->openGLWidget->update(); }

/// @brief Slot triggered when the "Save Screenshot" button is clicked.
///
/// This method captures and saves screenshot of viewport.
void Ocolus::on_saveScreenshotButton_clicked() {
  QString filePath = QFileDialog::getSaveFileName(
      this, tr("Save Screenshot"), "", tr("Images (*.bmp *.jpg *.jpeg *.png)"));
  if (filePath.isEmpty()) return;
  QImage screenshot = ui->openGLWidget->grabFramebuffer();

  if (!screenshot.save(filePath)) {
    QMessageBox::warning(this, "Error", "Could not save screenshot.");
  } else {
    QMessageBox::information(this, "Saved", "Screenshot saved successfully!");
  }
}

/// @brief Slot triggered when the "Record Gif" button is clicked.
///
/// This method starts recording of a gif-image.
void Ocolus::on_recordGifButton_clicked() {
  // куда сохранять результат
  outputGifPath_ = QFileDialog::getSaveFileName(this, tr("Save GIF"), "",
                                                tr("GIF Files (*.gif)"));
  if (outputGifPath_.isEmpty()) return;

  frames_.clear();  // сбрасываем список кадров
  currentFrame_ = 0;
  totalFrames_ = 10 * 5;  // 10 fps × 5 s = 50 кадров

  // запускаем таймер на 100 мс
  recordTimer_ = new QTimer(this);
  connect(recordTimer_, &QTimer::timeout, this, &Ocolus::captureGifFrame);
  recordTimer_->start(100);

  QMessageBox::information(this, "Recording", "GIF recording started (5s) ...");
}

/// @brief Captures an image from viewport.
///
/// This method captures an image from viewport and calls makeGif() func to make
/// a gif of all the captured images.
void Ocolus::captureGifFrame() {
  QImage frame = ui->openGLWidget->grabFramebuffer();

  frame = frame.scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation);

  frames_.push_back(frame);

  currentFrame_++;
  if (currentFrame_ >= totalFrames_) {
    recordTimer_->stop();
    delete recordTimer_;
    recordTimer_ = nullptr;

    makeGif();
  }
}

/// @brief Makes a gif.
///
/// This method resets makes a gif of the captured images and saves it into file
/// system.
void Ocolus::makeGif() {
  if (frames_.empty()) return;

  QGifImage gif;
  gif.setDefaultDelay(100);  // 100 мс между кадрами => 10 fps

  for (auto& img : frames_) {
    gif.addFrame(img);
  }

  bool ok = gif.save(outputGifPath_);
  if (!ok) {
    QMessageBox::warning(this, "Error", "Could not save GIF.");
  } else {
    QMessageBox::information(this, "Done", "GIF saved successfully!");
  }

  QMessageBox::information(this, "Info", "GIF creation done!");
}

}  // namespace s21
