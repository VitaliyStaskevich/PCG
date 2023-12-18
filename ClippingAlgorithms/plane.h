#ifndef PLANE_H
#define PLANE_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <iostream>

class plane : public QWidget
{
public:
    plane(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*)
    {
        QPainter painter1(this);
        double h = this->height();
        double w = this->width();
        h/=2;
        w/=2;
        double hScale = 20;
        double wScale = 20;
        painter1.translate(w,h);
        QPainterPath text;
        QFont f ("Times", 10);
        f.setStyleStrategy(QFont::ForceOutline);
        painter1.setPen(QPen(Qt::black, 1));
        painter1.drawLine(-this->width()/2, 0, this->width()/2, 0);
        painter1.drawLine(0, -this->height()/2, 0, this->height()/2);
        painter1.setPen(QPen(Qt::black, 3));
        text.addText(0, 0, f, QString::number(0));
        for(int i = 1; i < this->width()/(wScale*2); i++)
        {
            painter1.setPen(QPen(Qt::black, 3));
            painter1.drawPoint(i*wScale, 0);
            text.addText(i*wScale, 12, f, QString::number(i));
            painter1.drawPoint(-i*wScale, 0);
            text.addText(-i*wScale, 12, f, QString::number(-i));
            painter1.setPen(QPen(Qt::black, 1));
            painter1.drawLine(-i*wScale, -this->height()/2, -i*wScale, this->height()/2);
            painter1.drawLine(i*wScale, -this->height()/2, i*wScale, this->height()/2);
        }
        for(int i = 1; i < this->height()/(hScale*2); i++)
        {
            painter1.setPen(QPen(Qt::black, 3));
            painter1.drawPoint(0, i*hScale);
            text.addText(0, -i*hScale, f, QString::number(i));
            painter1.drawPoint(0, -i*hScale);
            text.addText(0, i*hScale, f, QString::number(-i));
            painter1.setPen(QPen(Qt::black, 1));
            painter1.drawLine(-this->width()/2, -i*hScale, this->width()/2, -i*hScale);
            painter1.drawLine(-this->width()/2, i*hScale, this->width()/2, i*hScale);
        }


        painter1.setPen(QPen(Qt::red, 4));
        painter1.setBrush(Qt::NoBrush);
        for(int i = 0; i<segments.size(); i++){
            painter1.drawLine(segments[i].first.x()*20, -segments[i].first.y()*20, segments[i].second.x()*20, -segments[i].second.y()*20);
        }
        painter1.setPen(QPen(Qt::blue, 5));
        if(!Cirus)
        {
            painter1.drawLine(Xmax*20, -Ymax*20, Xmax*20, -Ymin*20);
            painter1.drawLine(Xmax*20, -Ymax*20, Xmin*20, -Ymax*20);
            painter1.drawLine(Xmin*20, -Ymin*20, Xmax*20, -Ymin*20);
            painter1.drawLine(Xmin*20, -Ymin*20, Xmin*20, -Ymax*20);
        }
        else
        {
            for(int i = 0; i<polygon.size();i++){
                painter1.drawLine(polygon[i].first.x()*20,-polygon[i].first.y()*20,polygon[i].second.x()*20,-polygon[i].second.y()*20);
            }
        }
        painter1.setPen(QPen(Qt::darkGreen, 4));
        for(int i = 0; i<clippedSegments.size(); i++){
            painter1.drawLine(clippedSegments[i].first.x()*20, -clippedSegments[i].first.y()*20, clippedSegments[i].second.x()*20, -clippedSegments[i].second.y()*20);
        }
        painter1.setPen(QPen(Qt::black, 1));
        painter1.setBrush(QBrush(Qt::black));
        painter1.drawPath(text);
    }





    std::string filePath ="C:/projects/lab5_PCG/input.txt";
    void readFile();
    void readFileCirus();
    bool Cirus = 0;
private:
    void clipSegments();
    bool liangBarskyClip(QPointF &P1, QPointF &P2);
    QPointF intersectionPoint(QPointF,QPointF);
    void ClipByCirus(QPair<QPointF,QPointF>);
    float getT(QPair<QPointF,QPointF>,QPair<QPointF,QPointF>, bool*);
    int getCode(QPointF);
    void doCirus();
    QVector<QPair<QPointF,QPointF>> segments;
    QVector<QPair<QPointF,QPointF>> clippedSegments;
    int Xmin, Xmax, Ymin, Ymax;
    float t_1, t_2;
    QVector<QPair<QPointF, QPointF>> polygon;
};

#endif // PLANE_H
