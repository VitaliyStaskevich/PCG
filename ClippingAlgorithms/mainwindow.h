#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <plane.h>
#include <QGridLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void changeFile(){
        QString appDirPath = "C:/projects/lab5_PCG/";
        QString newFilePath = QFileDialog::getOpenFileName(this, "Open File", appDirPath, "Text Files (*.txt);;All Files (*)");
        p->filePath = newFilePath.toStdString();
        qDebug() << newFilePath;
        p->readFile();
        p->Cirus = 0;
    }
    void changeFileCirus()
    {

        QString appDirPath = "C:/projects/lab5_PCG/";
        QString newFilePath = QFileDialog::getOpenFileName(this, "Open File", appDirPath, "Text Files (*.txt);;All Files (*)");
        p->filePath = newFilePath.toStdString();
        qDebug() << newFilePath;
        p->readFileCirus();
        p->Cirus=1;
    }
private:
    plane* p = new plane();
    QGridLayout *l = new QGridLayout;
    Ui::MainWindow *ui;
    QPushButton *pbliangBarsk;
    QPushButton *pbCirus;
};
#endif // MAINWINDOW_H
