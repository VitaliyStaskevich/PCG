
#ifndef IMAGEINFOREADERAPP_H
#define IMAGEINFOREADERAPP_H

#include <QMainWindow>


#include <QFileInfo>
#include <QImage>
#include <QImageReader>
#include <QImageWriter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageInfoReaderApp; }
QT_END_NAMESPACE

class ImageInfoReaderApp : public QWidget
{
    Q_OBJECT
public:
    ImageInfoReaderApp()
    {
        setWindowTitle("Image Info Reader");
        setFixedSize(800, 400);

        chooseFolderButton = new QPushButton("Choose Folder", this);
        connect(chooseFolderButton, &QPushButton::clicked, this, &ImageInfoReaderApp::chooseFolder);

        imageInfoTable = new QTableWidget(this);
        imageInfoTable->setColumnCount(6);
        imageInfoTable->setHorizontalHeaderLabels(QStringList() << "File Name" << "Size (px)" << "Resolution (dpi)" << "Color Depth" << "Compression"<<"Extension");
        imageInfoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        clearButton = new QPushButton("Clear", this);
        connect(clearButton, &QPushButton::clicked, this, &ImageInfoReaderApp::ClearTable);
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(chooseFolderButton);
        layout->addWidget(imageInfoTable);
        layout->addWidget(clearButton);
    }

public slots:
    void chooseFolder() {
        QString folderPath = QFileDialog::getExistingDirectory(this, "Choose a folder with images");

        if (!folderPath.isEmpty()) {
            imageInfoTable->setRowCount(0);

            QDir folder(folderPath);
            QStringList filters;
            filters << "*.jpg" << "*.gif" << "*.tif" << "*.bmp" << "*.png" << "*.pcx";
            folder.setNameFilters(filters);

            foreach (QFileInfo fileInfo, folder.entryInfoList()) {
                QImageReader imageReader(fileInfo.filePath());


                if (!imageReader.format().isEmpty()) {
                    QImage image = imageReader.read();
                    int row = imageInfoTable->rowCount();
                    imageInfoTable->insertRow(row);
                    imageInfoTable->setItem(row, 0, new QTableWidgetItem(fileInfo.fileName()));
                    imageInfoTable->setItem(row, 1, new QTableWidgetItem(QString("%1x%2").arg(image.width()).arg(image.height())));
                    imageInfoTable->setItem(row, 2, new QTableWidgetItem(QString("%1x%2 dpi").arg(qRound(image.dotsPerMeterX()*0.0254)).arg(qRound(image.dotsPerMeterY()*0.0254))));
                    imageInfoTable->setItem(row, 3, new QTableWidgetItem(QString("%1 bits").arg(image.depth())));

                    QImageWriter imageWriter(fileInfo.filePath());
                    QString compression = imageWriter.supportedSubTypes().join(", ");
                    imageInfoTable->setItem(row, 4, new QTableWidgetItem(compression.isEmpty() ? "Not Compressed" : compression));
                    imageInfoTable ->setItem(row, 5, new QTableWidgetItem(QString(fileInfo.suffix())));
                }
            }
        }
    }
    void ClearTable()
    {
        imageInfoTable->clearContents();
        imageInfoTable->setRowCount(0);
    }

private:
    QPushButton *chooseFolderButton;
    QTableWidget *imageInfoTable;
    QPushButton *clearButton;
};

#endif // IMAGEINFOREADERAPP_H
