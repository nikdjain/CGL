#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
#include<QDebug>
QImage image(300, 300, QImage:: Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_5_linkActivated(const QString &link)
{

}
void MainWindow::on_pushButton_clicked()
{
    float x1, y1, x2, y2;
    x1=ui->textEdit_4->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit->toPlainText().toFloat();
    y2=ui->textEdit_3->toPlainText().toFloat();
    dda(x1, y1, x2, y2);
}

void MainWindow:: dda(float x1, float y1, float x2, float y2)
{
    QRgb colour;
    colour=qRgb(0, 255, 0);
    float x, y, len, dx, dy;
    dx=abs( x2-x1);
    dy=abs(y2-y1);
    if(dx>=dy)
        len=dx;
    else
        len=dy;

    dx=dx/len;
    dy=dy/len;

    dx=sign(x2-x1)*dx;
    dy=sign(y2-y1)*dy;

    x=x1;
    y=y1;
    int i=1;
    while(i<=len)
    {
        image.setPixel(x, y, colour);
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label_5->setPixmap(QPixmap:: fromImage(image));
}

int MainWindow:: sign(int x)
{
    if(x>0)
        return 1;
    else
        return -1;
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1, y1, x2, y2;
    x1=ui->textEdit_4->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit->toPlainText().toFloat();
    y2=ui->textEdit_3->toPlainText().toFloat();
    bresenham(x1, y1, x2, y2);
}

void MainWindow:: bresenham(int x1, int y1, int x2, int y2)
{
    QRgb colour;
    colour=qRgb(255, 0, 0);
    int dx,dy,x,y,p, i=0;
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>=dy)
    {
        p=(2*dy-dx);   //initial decision parameter
        while(i<dx)
        {
            image.setPixel(x,y,colour);
            if(p<0)
                p+=(2*dy);  // p(i+1) = pi + 2dy - 2dx(y(i+1) - yi)
            else
            {
                p+=(2*(dy-dx));
                y=y+sign(y2-y1);
            }
            x=x+sign(x2-x1);
            i++;
        }
    }
    else
    {
        p=(2*dx-dy);
        while(i<dy)
        {
            image.setPixel(x,y,colour);
            if(p<0)
                p+=(2*dx);
            else
            {
                p+=(2*(dx-dy));
                x=x+sign(x2-x1);
            }
            y=y+sign(y2-y1);
            i++;
        }
    }
    ui->label_5->setPixmap(QPixmap:: fromImage(image));
}
