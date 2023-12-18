#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),algorithms(this)
{
    ui->setupUi(this);

    algorithms.addAction(ui->a_StepByStep);
    algorithms.addAction(ui->a_Bresenham);
    algorithms.addAction(ui->a_DDA);
    algorithms.addAction(ui->a_circle);

    algorithms.setExclusionPolicy(QActionGroup::ExclusionPolicy::Exclusive);

    for(auto action: algorithms.actions())
    {
        action->setCheckable(true);
    }

    ui->a_StepByStep->setChecked(true);
    algorithm = STEP_BY_STEP;

    connect(ui->comboBox       , SIGNAL(currentIndexChanged(int)),this, SLOT(changeAlgorithm(int)));
    connect(ui->spinBox  , SIGNAL(editingFinished()), this, SLOT(rerender()));
    connect(ui->spinBox_2, SIGNAL(editingFinished()), this, SLOT(rerender()));
    connect(ui->spinBox_3, SIGNAL(editingFinished()), this, SLOT(rerender()));
    connect(ui->spinBox_4, SIGNAL(editingFinished()), this, SLOT(rerender()));
}




void MainWindow::changeAlgorithm(int index)
{
    algorithm = static_cast<Algorithm>(index);
    ui->spinBox_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_4->setText("x2");
    switch(index)
    {
        case 0:
        algorithm = STEP_BY_STEP;
        break;
        case 1:
        algorithm = DDA;
        break;
        case 2:
        algorithm = BRESENHAM;
        break;
        case 3:
        algorithm = BRESENHAM_CIRCLE;
        ui->spinBox_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_4->setText("R");
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::paintEvent(QPaintEvent *)
{

    double x0 = ui->spinBox->value(),x1 = ui->spinBox_3->value(),
        y0 = ui->spinBox_2->value(), y1=ui->spinBox_4->value();

    QPixmap pix(650,650);
    pix.fill(Qt::white);
    QPainter p(&pix);
    p.setBrush(Qt::black);

    int max = qMax(abs(x0),qMax(abs(x1),qMax(abs(y0),abs(y1))));
    int range = 10;

    while(range <= max)
    {
        range*=2;
    }


    double step = 0.9/20;
    double stp = 0.9/(2*range);

    p.drawLine(pix.width()*0.05,pix.height()/2,pix.width()*0.95,pix.height()/2);
    p.drawLine(pix.width()/2,pix.height()*0.95,pix.width()/2,pix.height()*0.05);

    for(int i = 0; i < 20;i++)
    {
        p.setPen(QPen(Qt::black,1));
        p.drawLine(pix.width()*(0.05+step*i),pix.height()*0.05,pix.width()*(0.05+step*i),pix.height()*0.95);
        p.drawLine(pix.width()*0.05,pix.height()*(0.05+step*i),pix.width()*0.95,pix.height()*(0.05+step*i));
        p.drawText(pix.width()*(0.04+step*i),pix.height()/1.90,QString::number(range/10*(i-10)));
        if(i!=10)
            p.drawText(pix.width()/2.10,pix.height()*(0.955-step*i),QString::number(range/10*(i-10)));

    }

    QVector<QPoint> line;

    switch(algorithm)
    {
    case STEP_BY_STEP:
        line = StepByStepLine(x0,y0,x1,y1);
        break;
    case BRESENHAM:
        line = BresenhamLine(x0,y0,x1,y1);
        break;
    case DDA:
        line = DDALine(x0,y0,x1,y1);
        break;
    case BRESENHAM_CIRCLE:
        line = BresenhamCircle(x0,y0,x1);
        break;
    }

    p.setPen(QPen(Qt::red,3));


       if(algorithm !=BRESENHAM_CIRCLE)
        for(int i = 1; i<line.size();i++)
        {
            p.drawLine(pix.width()*(0.5+stp*line[i-1].x()),pix.height()*(0.5-stp*line[i-1].y()),pix.width()*(0.5+stp*line[i].x()),pix.height()*(0.5-stp*line[i].y()));
        }
       else
       {
        p.setPen(QPen(Qt::red,30));
        for(int i = 0; i<line.size();i++)
        {
            p.drawPoint(pix.width()*(0.5+stp*line[i].x()),pix.height()*(0.5-stp*line[i].y()));
        }
       }


    ui->label->setPixmap(pix);

}

QVector<QPoint> MainWindow::StepByStepLine(double x0, double y0, double x1, double y1){
    bool steep = abs(y1-y0)>abs(x1-x0);

    if(steep)
    {
        std::swap(x0,y0);
        std::swap(x1,y1);
    }

    if(x0>x1)
    {
        std::swap(x0,x1);
        std::swap(y0,y1);
    }

    double k = (y1 -y0)/(x1 - x0);
    double b = (y0-k*x0);

    QVector<QPoint> line;

    for(int x = x0; x<= x1;x++)
    {
        int y = qRound(k*x+b);
        line.push_back(steep?QPoint(y,x):QPoint(x,y));
    }
    return line;
}



QVector<QPoint> MainWindow::BresenhamLine(double x0, double y0, double x1, double y1)
{
    bool steep = abs(y1-y0)>abs(x1-x0);
    if(steep)
    {
        std::swap(x0,y0);
        std::swap(x1,y1);
    }

    if(x0>x1)
    {
        std::swap(x0,x1);
        std::swap(y0,y1);
    }

    int dx = x1-x0;
    int dy = abs(y1-y0);
    int error = dx/2;
    int ystep = (y0<y1) ? 1:-1;
    int y = y0;

    QVector<QPoint> line;
    for(int x = x0; x<= x1;x++)
    {
        line.push_back(steep?QPoint(y,x):QPoint(x,y));
        error -= dy;
        if(error<0)
        {
            y+=ystep;
            error+=dx;
        }
    }
    return line;
}


QVector<QPoint> MainWindow::DDALine(double x0, double y0, double x1, double y1){
    bool inverse = abs(y1-y0)>abs(x1-x0);
    if(inverse)
    {
        std::swap(x0,y0);
        std::swap(x1,y1);
    }
    if(x0>x1)
    {
        std::swap(x0,x1);
        std::swap(y0,y1);
    }

    double dx = x1-x0;
    double dy = y1-y0;
    double y = y0;

    QVector<QPoint> line;
    line.push_back(inverse?QPoint(y0,x0):QPoint(x0,y0));

    for(int x = x0+1; x<= x1;x++)
    {
        y += dy/dx;
        line.push_back(inverse?QPoint(qRound(y),x):QPoint(x,qRound(y)));
    }

    return line;
}

QVector<QPoint> MainWindow::BresenhamCircle(double x0, double y0, double R){

    QVector<QPoint> circle;

    int x = R;
    int y = 0;
    int radiusError = 1 - x;
    while (x >= y) {
        circle.push_back(QPoint(x0 + x, y0 - y));
        circle.push_back(QPoint(x0 - x, y0 - y));
        circle.push_back(QPoint(x0 + x, y0 + y));
        circle.push_back(QPoint(x0 - x, y0 + y));
        circle.push_back(QPoint(x0 + y, y0 - x));
        circle.push_back(QPoint(x0 - y, y0 - x));
        circle.push_back(QPoint(x0 + y, y0 + x));
        circle.push_back(QPoint(x0 - y, y0 + x));

        y++;

        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        } else {
            x--;
            radiusError += 2 * (y - x) + 1;
        }
    }
    return circle;
}





void MainWindow::rerender()
{
    update();
}
