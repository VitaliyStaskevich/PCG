/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *colorPicker;
    QVBoxLayout *verticalLayout_2;
    QLabel *Picture;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *V_Edit;
    QSlider *H_Slider;
    QSlider *S_Slider;
    QLineEdit *S_Edit;
    QSlider *V_Slider;
    QLineEdit *H_Edit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QSlider *X_Slider;
    QSlider *Y_Slider;
    QSlider *Z_Slider;
    QLineEdit *X_Edit;
    QLineEdit *Y_Edit;
    QLineEdit *Z_Edit;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QSlider *B_Slider;
    QSlider *L_Slider;
    QSlider *A_Slider;
    QLineEdit *L_Edit;
    QLineEdit *A_Edit;
    QLineEdit *B_Edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        colorPicker = new QPushButton(centralwidget);
        colorPicker->setObjectName(QString::fromUtf8("colorPicker"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorPicker->sizePolicy().hasHeightForWidth());
        colorPicker->setSizePolicy(sizePolicy);
        colorPicker->setMinimumSize(QSize(250, 50));

        verticalLayout_4->addWidget(colorPicker);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Picture = new QLabel(centralwidget);
        Picture->setObjectName(QString::fromUtf8("Picture"));

        verticalLayout_2->addWidget(Picture);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        V_Edit = new QLineEdit(groupBox);
        V_Edit->setObjectName(QString::fromUtf8("V_Edit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(V_Edit->sizePolicy().hasHeightForWidth());
        V_Edit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(V_Edit, 2, 0, 1, 1);

        H_Slider = new QSlider(groupBox);
        H_Slider->setObjectName(QString::fromUtf8("H_Slider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(H_Slider->sizePolicy().hasHeightForWidth());
        H_Slider->setSizePolicy(sizePolicy2);
        H_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(H_Slider, 0, 1, 1, 1);

        S_Slider = new QSlider(groupBox);
        S_Slider->setObjectName(QString::fromUtf8("S_Slider"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(S_Slider->sizePolicy().hasHeightForWidth());
        S_Slider->setSizePolicy(sizePolicy3);
        S_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(S_Slider, 1, 1, 1, 1);

        S_Edit = new QLineEdit(groupBox);
        S_Edit->setObjectName(QString::fromUtf8("S_Edit"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(S_Edit->sizePolicy().hasHeightForWidth());
        S_Edit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(S_Edit, 1, 0, 1, 1);

        V_Slider = new QSlider(groupBox);
        V_Slider->setObjectName(QString::fromUtf8("V_Slider"));
        sizePolicy3.setHeightForWidth(V_Slider->sizePolicy().hasHeightForWidth());
        V_Slider->setSizePolicy(sizePolicy3);
        V_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(V_Slider, 2, 1, 1, 1);

        H_Edit = new QLineEdit(groupBox);
        H_Edit->setObjectName(QString::fromUtf8("H_Edit"));
        sizePolicy4.setHeightForWidth(H_Edit->sizePolicy().hasHeightForWidth());
        H_Edit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(H_Edit, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        X_Slider = new QSlider(groupBox_2);
        X_Slider->setObjectName(QString::fromUtf8("X_Slider"));
        sizePolicy2.setHeightForWidth(X_Slider->sizePolicy().hasHeightForWidth());
        X_Slider->setSizePolicy(sizePolicy2);
        X_Slider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(X_Slider, 0, 1, 1, 1);

        Y_Slider = new QSlider(groupBox_2);
        Y_Slider->setObjectName(QString::fromUtf8("Y_Slider"));
        sizePolicy3.setHeightForWidth(Y_Slider->sizePolicy().hasHeightForWidth());
        Y_Slider->setSizePolicy(sizePolicy3);
        Y_Slider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(Y_Slider, 1, 1, 1, 1);

        Z_Slider = new QSlider(groupBox_2);
        Z_Slider->setObjectName(QString::fromUtf8("Z_Slider"));
        sizePolicy3.setHeightForWidth(Z_Slider->sizePolicy().hasHeightForWidth());
        Z_Slider->setSizePolicy(sizePolicy3);
        Z_Slider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(Z_Slider, 2, 1, 1, 1);

        X_Edit = new QLineEdit(groupBox_2);
        X_Edit->setObjectName(QString::fromUtf8("X_Edit"));
        sizePolicy1.setHeightForWidth(X_Edit->sizePolicy().hasHeightForWidth());
        X_Edit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(X_Edit, 0, 0, 1, 1);

        Y_Edit = new QLineEdit(groupBox_2);
        Y_Edit->setObjectName(QString::fromUtf8("Y_Edit"));
        sizePolicy1.setHeightForWidth(Y_Edit->sizePolicy().hasHeightForWidth());
        Y_Edit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(Y_Edit, 1, 0, 1, 1);

        Z_Edit = new QLineEdit(groupBox_2);
        Z_Edit->setObjectName(QString::fromUtf8("Z_Edit"));
        sizePolicy1.setHeightForWidth(Z_Edit->sizePolicy().hasHeightForWidth());
        Z_Edit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(Z_Edit, 2, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        B_Slider = new QSlider(groupBox_3);
        B_Slider->setObjectName(QString::fromUtf8("B_Slider"));
        sizePolicy3.setHeightForWidth(B_Slider->sizePolicy().hasHeightForWidth());
        B_Slider->setSizePolicy(sizePolicy3);
        B_Slider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(B_Slider, 2, 1, 1, 1);

        L_Slider = new QSlider(groupBox_3);
        L_Slider->setObjectName(QString::fromUtf8("L_Slider"));
        sizePolicy2.setHeightForWidth(L_Slider->sizePolicy().hasHeightForWidth());
        L_Slider->setSizePolicy(sizePolicy2);
        L_Slider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(L_Slider, 0, 1, 1, 1);

        A_Slider = new QSlider(groupBox_3);
        A_Slider->setObjectName(QString::fromUtf8("A_Slider"));
        sizePolicy3.setHeightForWidth(A_Slider->sizePolicy().hasHeightForWidth());
        A_Slider->setSizePolicy(sizePolicy3);
        A_Slider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(A_Slider, 1, 1, 1, 1);

        L_Edit = new QLineEdit(groupBox_3);
        L_Edit->setObjectName(QString::fromUtf8("L_Edit"));
        sizePolicy1.setHeightForWidth(L_Edit->sizePolicy().hasHeightForWidth());
        L_Edit->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(L_Edit, 0, 0, 1, 1);

        A_Edit = new QLineEdit(groupBox_3);
        A_Edit->setObjectName(QString::fromUtf8("A_Edit"));
        sizePolicy1.setHeightForWidth(A_Edit->sizePolicy().hasHeightForWidth());
        A_Edit->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(A_Edit, 1, 0, 1, 1);

        B_Edit = new QLineEdit(groupBox_3);
        B_Edit->setObjectName(QString::fromUtf8("B_Edit"));
        sizePolicy1.setHeightForWidth(B_Edit->sizePolicy().hasHeightForWidth());
        B_Edit->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(B_Edit, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        colorPicker->setText(QCoreApplication::translate("MainWindow", "Choose a color", nullptr));
        Picture->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "HSV", nullptr));
        V_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        S_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        H_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        H_Edit->setPlaceholderText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        X_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Y_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Z_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "LAB", nullptr));
        L_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B_Edit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
