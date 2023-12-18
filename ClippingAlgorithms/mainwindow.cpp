#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pbliangBarsk = new QPushButton;
    pbliangBarsk->setText("Liang Barsk Algorithm");
    l->addWidget(pbliangBarsk,0,1,1,1);
    pbCirus = new QPushButton;
    pbCirus -> setText("Cirus Beck Algorithm");
    l->addWidget(pbCirus,1,1,1,1);
    ui->centralwidget->setLayout(l);
    connect(pbliangBarsk, SIGNAL(clicked()), this, SLOT(changeFile()));
    connect(pbCirus, SIGNAL(clicked()), this, SLOT(changeFileCirus()));
    p->hide();
    p = new plane();
    l->addWidget(p,0,0,12,1);
    p->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

