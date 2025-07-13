#ifndef OCOLUS_H
#define OCOLUS_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QWidget>

#include "../qtgifimage/qgifimage.h"
#include "TestOpenGLWidget.h"

using namespace s21;

QT_BEGIN_NAMESPACE
namespace Ui {
class Ocolus;
}
QT_END_NAMESPACE

namespace s21 {

/// @class Ocolus
/// @brief Ocolus is a subclass of QMainWindow that serves as the main
/// application window for the OpenGL rendering application.
///
/// This class manages the user interface components, handles user interactions,
/// and manages application settings. It includes methods for loading settings,
/// resetting sliders, and opening OBJ files for rendering.
class Ocolus : public QMainWindow {
  Q_OBJECT
 private:
  /// @enum Slider
  /// @brief Enumeration to define slider types for transformations.
  typedef enum {
    TranslateX_s = 0,  ///< Slider for translating along the X-axis.
    TranslateY_s,      ///< Slider for translating along the Y-axis.
    TranslateZ_s,      ///< Slider for translating along the Z-axis.
    Scale_s,           ///< Slider for scaling the model.
    RotateX_s,         ///< Slider for rotating around the X-axis.
    RotateY_s,         ///< Slider for rotating around the Y-axis.
    RotateZ_s          ///< Slider for rotating around the Z-axis.
  } Slider;

  Ui::Ocolus* ui;  ///< Pointer to the UI components for the application.
  std::map<Slider, int>
      sliderPosition;  ///< Map to store the current positions of each slider.
  QString outputGifPath_;       ///< Output path for gif-image
  int currentFrame_;            ///< Current frame of Viewport
  int totalFrames_;             ///< Number of recorded frames
  QTimer* recordTimer_;         ///< Timer for gif-image
  std::vector<QImage> frames_;  ///< All the captured frames

 public:
  /// @brief Constructor for the Ocolus class.
  /// @param parent Pointer to the parent widget (if any).
  Ocolus(QWidget* parent = nullptr);

  /// @brief Destructor for the Ocolus class.
  ~Ocolus();

  /// @brief Drops (clears) the slider settings to their initial state.
  void dropSliders();

  /// @brief Updates the position of a specified slider.
  /// @param s The slider to be updated.
  /// @param value Pointer to the new value of the slider.
  void updateSliderPosition(Slider s, int* value);

  /// @brief Resets all settings to their default values.
  void setToDefault();

  /// @brief Loads settings from a configuration file or similar source.
  void loadSettings();

  /// @brief Opens a file with the specified filename.
  /// @param filename The name of the file to be opened.
  void openFile(QString filename);

  /// @brief Captures the current frame of Viewport.
  void captureGifFrame();

  /// @brief Makes a gif from captured frames.
  void makeGif();

 private slots:
  /// @brief Slot connected to the Open File button click event.
  void on_OpenFileButton_clicked();

  /// @brief Slot connected to the value change event of the translate X slider.
  /// @param value New value of the translate X slider.
  void on_translateXSlider_valueChanged(int value);

  /// @brief Slot connected to the value change event of the translate Y slider.
  /// @param value New value of the translate Y slider.
  void on_translateYSlider_valueChanged(int value);

  /// @brief Slot connected to the value change event of the translate Z slider.
  /// @param value New value of the translate Z slider.
  void on_translateZSlider_valueChanged(int value);

  /// @brief Slot connected to the value change event of the scale slider.
  /// @param value New value of the scale slider.
  void on_scaleSlider_valueChanged(int value);

  /// @brief Slot connected to the value change event of the rotate X slider.
  /// @param value New value of the rotate X slider.
  void on_rotateXSlider_valueChanged(int value);

  /// @brief Slot connected to the value change event of the rotate Y slider.
  /// @param value New value of the rotate Y slider.
  void on_rotateYSlider_valueChanged(int value);

  /// @brief Slot connected to the value change event of the rotate Z slider.
  /// @param value New value of the rotate Z slider.
  void on_rotateZSlider_valueChanged(int value);

  /// @brief Slot connected to the central radio button selection event.
  void on_central_radioButton_clicked();

  /// @brief Slot connected to the parallel radio button selection event.
  void on_parallel_radioButton_clicked();

  /// @brief Slot connected to the solid edge radio button selection event.
  void on_e_solid_radioButton_clicked();

  /// @brief Slot connected to the dashed edge radio button selection event.
  void on_e_dashed_radioButton_clicked();

  /// @brief Slot connected to the none vertex radio button selection event.
  void on_v_none_radioButton_clicked();

  /// @brief Slot connected to the circular vertex radio button selection event.
  void on_v_circular_radioButton_clicked();

  /// @brief Slot connected to the squared vertex radio button selection event.
  void on_v_squared_radioButton_clicked();

  /// @brief Slot connected to the edge color button click event.
  void on_e_color_Button_clicked();

  /// @brief Slot connected to the vertex color button click event.
  void on_v_color_Button_clicked();

  /// @brief Slot connected to the background color button click event.
  void on_bg_color_Button_clicked();

  /// @brief Slot connected to the value change event of the edge thickness
  /// slider.
  /// @param value New value of the edge thickness slider.
  void on_e_thickness_Slider_valueChanged(int value);

  /// @brief Slot connected to the value change event of the vertex size slider.
  /// @param value New value of the vertex size slider.
  void on_v_size_Slider_valueChanged(int value);

  /// @brief Slot connected to the Set Default button click event.
  void on_setDefault_Button_clicked();

  /// @brief Slot connected to the Show button click event.
  void on_showButton_clicked();

  /// @brief Slot connected to the Save Screenshot button click event.
  void on_saveScreenshotButton_clicked();

  /// @brief Slot connected to the Record Gif button click event.
  void on_recordGifButton_clicked();
};
}  // namespace s21
#endif  // OCOLUS_H
