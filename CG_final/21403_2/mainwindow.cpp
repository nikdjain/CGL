#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>
#include<math.h>
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

void MainWindow::on_pushButton_clicked()
{
    float x1, y1, x2, y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    dda(x1, y1, x2, y2);
}

int MainWindow:: sign(int x)
{
    if(x>0)
        return 1;
    else
        return -1;
}

void MainWindow:: dda(float x1, float y1, float x2, float y2)
{
    QRgb colour;
    colour=qRgb(255, 0, 0);
    float x, y, len, dx, dy;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>=dy)
    {len=dx;}
    else
    {len=dy;}
    dx=dx/len;
    dy=dy/len;
    dx=sign(x2-x1)*dx;
    dy=sign(y2-y1)*dy;
    x=x1+0.5;
    y=y1+0.5;
    int i=1;
    while(i<=len)
    {
        image.setPixel(x, y, colour);
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label->setPixmap(QPixmap:: fromImage(image));
}


void MainWindow::on_pushButton_2_clicked()
{
    int x1, y1, r;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_5->toPlainText().toInt();
    circle(x1, y1, r);
}

void MainWindow:: circle(int xc,int yc,int r)
{
    QRgb colour;
    colour=qRgb(0, 255, 0);
    int x, y, d;
    x=0;
    y=r;
    d=3-2*r;
    while(x<=y)
    {
        x++;
        if(d>0)
        {
            y--;
            d=d+4*(x-y)+10;
        }
        else
        {

            d=d+4*x+6;
        }
        image.setPixel(xc+x, yc+y, colour);
        image.setPixel(xc+x, yc-y, colour);
        image.setPixel(xc-x, yc+y, colour);
        image.setPixel(xc-x, yc-y, colour);
        image.setPixel(xc+y, yc+x, colour);
        image.setPixel(xc+y, yc-x, colour);
        image.setPixel(xc-y, yc+x, colour);
        image.setPixel(xc-y, yc-x, colour);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_3_clicked()
{
    int x1, y1, r;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_5->toPlainText().toInt();
    dda_circle(x1, y1, r);
}

void MainWindow:: dda_circle(int xc, int yc, int r)
{
    QRgb colour;
    colour=qRgb(0, 0, 255);
   float xc1,xc2,yc1,yc2,eps,sx,sy;
   int val,i;
   xc1=r;
   yc1=0;
   sx=xc1;
   sy=yc1;
   i=0;
   do
   {
       val=pow(2,i);
       i++;
   }while(val<r);
   eps = 1/pow(2,i-1);
   do
   {
       xc2 = xc1 + yc1*eps;
       yc2 = yc1 - eps*xc2;
       image.setPixel(xc+xc2,yc-yc2,colour);
       xc1=xc2;
       yc1=yc2;
   }while((yc1-sy)<eps || (sx-xc1)>eps);
   ui->label->setPixmap(QPixmap::fromImage(image));
}
