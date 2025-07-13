/********************************************************************************
** Form generated from reading UI file 'ocolus.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OCOLUS_H
#define UI_OCOLUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TestOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Ocolus
{
public:
    TestOpenGLWidget *openGLWidget;
    QPushButton *OpenFileButton;
    QLabel *name_header;
    QLabel *filename;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *projection_type_label;
    QRadioButton *parallel_radioButton;
    QRadioButton *central_radioButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *edge_type_label;
    QRadioButton *e_solid_radioButton;
    QRadioButton *e_dashed_radioButton;
    QLabel *e_thickness_label;
    QSlider *e_thickness_Slider;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *v_type_label;
    QRadioButton *v_none_radioButton;
    QRadioButton *v_circular_radioButton;
    QRadioButton *v_squared_radioButton;
    QLabel *vertex_size_label;
    QSlider *v_size_Slider;
    QPushButton *showButton;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *vertexes_header;
    QLabel *num_of_v;
    QLabel *edges_label;
    QLabel *num_of_e;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *tr_x;
    QSlider *translateXSlider;
    QLabel *tr_y;
    QSlider *translateYSlider;
    QLabel *tr_z;
    QSlider *translateZSlider;
    QLabel *sc;
    QSlider *scaleSlider;
    QLabel *rt_x;
    QSlider *rotateXSlider;
    QLabel *rt_y;
    QSlider *rotateYSlider;
    QLabel *rt_z;
    QSlider *rotateZSlider;
    QPushButton *e_color_Button;
    QPushButton *v_color_Button;
    QPushButton *bg_color_Button;
    QPushButton *setDefault_Button;
    QPushButton *saveScreenshotButton;
    QPushButton *recordGifButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Ocolus)
    {
        if (Ocolus->objectName().isEmpty())
            Ocolus->setObjectName("Ocolus");
        Ocolus->resize(1191, 635);
        Ocolus->setMouseTracking(false);
        Ocolus->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: dark-gray;"));
        openGLWidget = new TestOpenGLWidget(Ocolus);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(10, 10, 800, 600));
        openGLWidget->setMouseTracking(false);
        openGLWidget->setStyleSheet(QString::fromUtf8(""));
        OpenFileButton = new QPushButton(Ocolus);
        OpenFileButton->setObjectName("OpenFileButton");
        OpenFileButton->setGeometry(QRect(1010, 120, 166, 31));
        OpenFileButton->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    min-width: 10em;\n"
"    padding: 6px;"));
        name_header = new QLabel(Ocolus);
        name_header->setObjectName("name_header");
        name_header->setGeometry(QRect(850, 20, 71, 16));
        filename = new QLabel(Ocolus);
        filename->setObjectName("filename");
        filename->setGeometry(QRect(850, 50, 141, 31));
        filename->setStyleSheet(QString::fromUtf8("color: white;"));
        verticalLayoutWidget = new QWidget(Ocolus);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(1040, 190, 111, 97));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        projection_type_label = new QLabel(verticalLayoutWidget);
        projection_type_label->setObjectName("projection_type_label");
        projection_type_label->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout->addWidget(projection_type_label);

        parallel_radioButton = new QRadioButton(verticalLayoutWidget);
        parallel_radioButton->setObjectName("parallel_radioButton");
        parallel_radioButton->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout->addWidget(parallel_radioButton);

        central_radioButton = new QRadioButton(verticalLayoutWidget);
        central_radioButton->setObjectName("central_radioButton");
        central_radioButton->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout->addWidget(central_radioButton);

        verticalLayoutWidget_2 = new QWidget(Ocolus);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(850, 470, 141, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        edge_type_label = new QLabel(verticalLayoutWidget_2);
        edge_type_label->setObjectName("edge_type_label");

        verticalLayout_2->addWidget(edge_type_label);

        e_solid_radioButton = new QRadioButton(verticalLayoutWidget_2);
        e_solid_radioButton->setObjectName("e_solid_radioButton");
        e_solid_radioButton->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout_2->addWidget(e_solid_radioButton);

        e_dashed_radioButton = new QRadioButton(verticalLayoutWidget_2);
        e_dashed_radioButton->setObjectName("e_dashed_radioButton");
        e_dashed_radioButton->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout_2->addWidget(e_dashed_radioButton);

        e_thickness_label = new QLabel(verticalLayoutWidget_2);
        e_thickness_label->setObjectName("e_thickness_label");

        verticalLayout_2->addWidget(e_thickness_label);

        e_thickness_Slider = new QSlider(verticalLayoutWidget_2);
        e_thickness_Slider->setObjectName("e_thickness_Slider");
        e_thickness_Slider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        e_thickness_Slider->setMinimum(2);
        e_thickness_Slider->setMaximum(50);
        e_thickness_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(e_thickness_Slider);

        verticalLayoutWidget_3 = new QWidget(Ocolus);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(1010, 470, 151, 145));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        v_type_label = new QLabel(verticalLayoutWidget_3);
        v_type_label->setObjectName("v_type_label");

        verticalLayout_3->addWidget(v_type_label);

        v_none_radioButton = new QRadioButton(verticalLayoutWidget_3);
        v_none_radioButton->setObjectName("v_none_radioButton");
        v_none_radioButton->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout_3->addWidget(v_none_radioButton);

        v_circular_radioButton = new QRadioButton(verticalLayoutWidget_3);
        v_circular_radioButton->setObjectName("v_circular_radioButton");
        v_circular_radioButton->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout_3->addWidget(v_circular_radioButton);

        v_squared_radioButton = new QRadioButton(verticalLayoutWidget_3);
        v_squared_radioButton->setObjectName("v_squared_radioButton");
        v_squared_radioButton->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));

        verticalLayout_3->addWidget(v_squared_radioButton);

        vertex_size_label = new QLabel(verticalLayoutWidget_3);
        vertex_size_label->setObjectName("vertex_size_label");
        vertex_size_label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(vertex_size_label);

        v_size_Slider = new QSlider(verticalLayoutWidget_3);
        v_size_Slider->setObjectName("v_size_Slider");
        v_size_Slider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        v_size_Slider->setMinimum(5);
        v_size_Slider->setMaximum(50);
        v_size_Slider->setValue(5);
        v_size_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(v_size_Slider);

        showButton = new QPushButton(Ocolus);
        showButton->setObjectName("showButton");
        showButton->setGeometry(QRect(1010, 160, 166, 31));
        showButton->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    min-width: 10em;\n"
"    padding: 6px;"));
        verticalLayoutWidget_4 = new QWidget(Ocolus);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(1029, 20, 131, 81));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        vertexes_header = new QLabel(verticalLayoutWidget_4);
        vertexes_header->setObjectName("vertexes_header");

        verticalLayout_5->addWidget(vertexes_header);

        num_of_v = new QLabel(verticalLayoutWidget_4);
        num_of_v->setObjectName("num_of_v");
        num_of_v->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_5->addWidget(num_of_v);

        edges_label = new QLabel(verticalLayoutWidget_4);
        edges_label->setObjectName("edges_label");

        verticalLayout_5->addWidget(edges_label);

        num_of_e = new QLabel(verticalLayoutWidget_4);
        num_of_e->setObjectName("num_of_e");
        num_of_e->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_5->addWidget(num_of_e);

        verticalLayoutWidget_5 = new QWidget(Ocolus);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(840, 110, 160, 341));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        tr_x = new QLabel(verticalLayoutWidget_5);
        tr_x->setObjectName("tr_x");

        verticalLayout_6->addWidget(tr_x);

        translateXSlider = new QSlider(verticalLayoutWidget_5);
        translateXSlider->setObjectName("translateXSlider");
        translateXSlider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        translateXSlider->setMinimum(-100);
        translateXSlider->setMaximum(100);
        translateXSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(translateXSlider);

        tr_y = new QLabel(verticalLayoutWidget_5);
        tr_y->setObjectName("tr_y");

        verticalLayout_6->addWidget(tr_y);

        translateYSlider = new QSlider(verticalLayoutWidget_5);
        translateYSlider->setObjectName("translateYSlider");
        translateYSlider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        translateYSlider->setMinimum(-100);
        translateYSlider->setMaximum(100);
        translateYSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(translateYSlider);

        tr_z = new QLabel(verticalLayoutWidget_5);
        tr_z->setObjectName("tr_z");

        verticalLayout_6->addWidget(tr_z);

        translateZSlider = new QSlider(verticalLayoutWidget_5);
        translateZSlider->setObjectName("translateZSlider");
        translateZSlider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        translateZSlider->setMinimum(-100);
        translateZSlider->setMaximum(100);
        translateZSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(translateZSlider);

        sc = new QLabel(verticalLayoutWidget_5);
        sc->setObjectName("sc");

        verticalLayout_6->addWidget(sc);

        scaleSlider = new QSlider(verticalLayoutWidget_5);
        scaleSlider->setObjectName("scaleSlider");
        scaleSlider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        scaleSlider->setMinimum(-100);
        scaleSlider->setMaximum(100);
        scaleSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(scaleSlider);

        rt_x = new QLabel(verticalLayoutWidget_5);
        rt_x->setObjectName("rt_x");

        verticalLayout_6->addWidget(rt_x);

        rotateXSlider = new QSlider(verticalLayoutWidget_5);
        rotateXSlider->setObjectName("rotateXSlider");
        rotateXSlider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        rotateXSlider->setMinimum(-360);
        rotateXSlider->setMaximum(360);
        rotateXSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(rotateXSlider);

        rt_y = new QLabel(verticalLayoutWidget_5);
        rt_y->setObjectName("rt_y");

        verticalLayout_6->addWidget(rt_y);

        rotateYSlider = new QSlider(verticalLayoutWidget_5);
        rotateYSlider->setObjectName("rotateYSlider");
        rotateYSlider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        rotateYSlider->setMinimum(-360);
        rotateYSlider->setMaximum(360);
        rotateYSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(rotateYSlider);

        rt_z = new QLabel(verticalLayoutWidget_5);
        rt_z->setObjectName("rt_z");

        verticalLayout_6->addWidget(rt_z);

        rotateZSlider = new QSlider(verticalLayoutWidget_5);
        rotateZSlider->setObjectName("rotateZSlider");
        rotateZSlider->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        rotateZSlider->setMinimum(-360);
        rotateZSlider->setMaximum(360);
        rotateZSlider->setSingleStep(1);
        rotateZSlider->setValue(0);
        rotateZSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(rotateZSlider);

        e_color_Button = new QPushButton(Ocolus);
        e_color_Button->setObjectName("e_color_Button");
        e_color_Button->setGeometry(QRect(1010, 300, 166, 31));
        e_color_Button->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    min-width: 10em;\n"
"    padding: 6px;"));
        v_color_Button = new QPushButton(Ocolus);
        v_color_Button->setObjectName("v_color_Button");
        v_color_Button->setGeometry(QRect(1010, 340, 166, 31));
        v_color_Button->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    min-width: 10em;\n"
"    padding: 6px;"));
        bg_color_Button = new QPushButton(Ocolus);
        bg_color_Button->setObjectName("bg_color_Button");
        bg_color_Button->setGeometry(QRect(1010, 380, 166, 31));
        bg_color_Button->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    min-width: 10em;\n"
"    padding: 6px;"));
        setDefault_Button = new QPushButton(Ocolus);
        setDefault_Button->setObjectName("setDefault_Button");
        setDefault_Button->setGeometry(QRect(1010, 420, 166, 31));
        setDefault_Button->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    min-width: 10em;\n"
"    padding: 6px;"));
        saveScreenshotButton = new QPushButton(Ocolus);
        saveScreenshotButton->setObjectName("saveScreenshotButton");
        saveScreenshotButton->setGeometry(QRect(670, 540, 61, 61));
        saveScreenshotButton->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    padding: 6px;"));
        recordGifButton = new QPushButton(Ocolus);
        recordGifButton->setObjectName("recordGifButton");
        recordGifButton->setGeometry(QRect(740, 540, 61, 61));
        recordGifButton->setStyleSheet(QString::fromUtf8("    background-color: gray;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"    font: bold 12px;\n"
"    padding: 6px;"));
        label = new QLabel(Ocolus);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 821, 621));
        label->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        label_2 = new QLabel(Ocolus);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(840, 460, 331, 161));
        label_2->setStyleSheet(QString::fromUtf8("background-color: dark-gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        label_3 = new QLabel(Ocolus);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1030, 190, 131, 101));
        label_3->setStyleSheet(QString::fromUtf8("background-color: dark-gray;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: white;"));
        label_3->raise();
        label_2->raise();
        label->raise();
        openGLWidget->raise();
        OpenFileButton->raise();
        name_header->raise();
        filename->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        verticalLayoutWidget_3->raise();
        showButton->raise();
        verticalLayoutWidget_4->raise();
        verticalLayoutWidget_5->raise();
        e_color_Button->raise();
        v_color_Button->raise();
        bg_color_Button->raise();
        setDefault_Button->raise();
        saveScreenshotButton->raise();
        recordGifButton->raise();

        retranslateUi(Ocolus);

        QMetaObject::connectSlotsByName(Ocolus);
    } // setupUi

    void retranslateUi(QWidget *Ocolus)
    {
        Ocolus->setWindowTitle(QCoreApplication::translate("Ocolus", "Ocolus", nullptr));
        OpenFileButton->setText(QCoreApplication::translate("Ocolus", "Open File", nullptr));
        name_header->setText(QCoreApplication::translate("Ocolus", "Filename:", nullptr));
        filename->setText(QString());
        projection_type_label->setText(QCoreApplication::translate("Ocolus", "Projection Type:", nullptr));
        parallel_radioButton->setText(QCoreApplication::translate("Ocolus", "Parallel", nullptr));
        central_radioButton->setText(QCoreApplication::translate("Ocolus", "Central", nullptr));
        edge_type_label->setText(QCoreApplication::translate("Ocolus", "Edge Type:", nullptr));
        e_solid_radioButton->setText(QCoreApplication::translate("Ocolus", "Solid", nullptr));
        e_dashed_radioButton->setText(QCoreApplication::translate("Ocolus", "Dashed", nullptr));
        e_thickness_label->setText(QCoreApplication::translate("Ocolus", "Edge thickness:", nullptr));
        v_type_label->setText(QCoreApplication::translate("Ocolus", "Vertex Type:", nullptr));
        v_none_radioButton->setText(QCoreApplication::translate("Ocolus", "None", nullptr));
        v_circular_radioButton->setText(QCoreApplication::translate("Ocolus", "Circular", nullptr));
        v_squared_radioButton->setText(QCoreApplication::translate("Ocolus", "Squared", nullptr));
        vertex_size_label->setText(QCoreApplication::translate("Ocolus", "Vertex Size", nullptr));
        showButton->setText(QCoreApplication::translate("Ocolus", "Show", nullptr));
        vertexes_header->setText(QCoreApplication::translate("Ocolus", "Vertexes:", nullptr));
        num_of_v->setText(QString());
        edges_label->setText(QCoreApplication::translate("Ocolus", "Edges:", nullptr));
        num_of_e->setText(QString());
        tr_x->setText(QCoreApplication::translate("Ocolus", "Translate X", nullptr));
        tr_y->setText(QCoreApplication::translate("Ocolus", "Translate Y", nullptr));
        tr_z->setText(QCoreApplication::translate("Ocolus", "Translate Z", nullptr));
        sc->setText(QCoreApplication::translate("Ocolus", "Scale", nullptr));
        rt_x->setText(QCoreApplication::translate("Ocolus", "Rotate X", nullptr));
        rt_y->setText(QCoreApplication::translate("Ocolus", "Rotate Y", nullptr));
        rt_z->setText(QCoreApplication::translate("Ocolus", "Rotate Z", nullptr));
        e_color_Button->setText(QCoreApplication::translate("Ocolus", "Edge Color", nullptr));
        v_color_Button->setText(QCoreApplication::translate("Ocolus", "Vertex Color", nullptr));
        bg_color_Button->setText(QCoreApplication::translate("Ocolus", "BG Color", nullptr));
        setDefault_Button->setText(QCoreApplication::translate("Ocolus", "Set Default", nullptr));
        saveScreenshotButton->setText(QCoreApplication::translate("Ocolus", "Screen", nullptr));
        recordGifButton->setText(QCoreApplication::translate("Ocolus", "Gif", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ocolus: public Ui_Ocolus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OCOLUS_H
