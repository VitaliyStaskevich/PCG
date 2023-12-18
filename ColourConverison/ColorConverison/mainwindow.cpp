
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->H_Slider->setRange(0,360);
    ui->S_Slider->setRange(0,100);
    ui->V_Slider->setRange(0,100);

    ui->X_Slider->setRange(0,100);
    ui->Y_Slider->setRange(0,100);
    ui->Z_Slider->setRange(0,100);

    ui->L_Slider->setRange(0,100);
    ui->A_Slider->setRange(0,255);
    ui->B_Slider->setRange(0,255);
    ui->Picture->setStyleSheet("QLabel { background-color : black; }");
    connect(ui->H_Slider, SIGNAL(sliderMoved(int)),this, SLOT(changeColor(int)));
    connect(ui->S_Slider, SIGNAL(sliderMoved(int)),this, SLOT(changeColor(int)));
    connect(ui->V_Slider, SIGNAL(sliderMoved(int)),this, SLOT(changeColor(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: changeColor(int v)
{
    qDebug() << v;
}
