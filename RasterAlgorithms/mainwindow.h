#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPoint>
#include <QActionGroup>

enum Algorithm{
    STEP_BY_STEP,
    BRESENHAM,
    DDA,
    BRESENHAM_CIRCLE
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void rerender();

    void changeAlgorithm(int index);

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent*);
    void drawGraph();

    QActionGroup algorithms;
    Algorithm algorithm;

    QVector<QPoint> StepByStepLine(double x0, double y0, double x1, double y1);
    QVector<QPoint> BresenhamLine(double x0, double y0, double x1, double y1);
    QVector<QPoint> DDALine(double x0, double y0, double x1, double y1);
    QVector<QPoint> BresenhamCircle(double x0, double y0,double R);
};
#endif // MAINWINDOW_H
