#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
QImage image(300, 300, QImage::Format_RGB888);

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

void MainWindow::on_pushButton_3_clicked()
{
    float x1,x2,y1,y2;
    x1=ui->textEdit_3->toPlainText().toFloat();
    y1=ui->textEdit_5->toPlainText().toFloat();
    x2=ui->textEdit_7->toPlainText().toFloat();
    y2=ui->textEdit_6->toPlainText().toFloat();
    dda(x1,y1,x2,y2);
}
void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    QRgb value;
    value=qRgb(0,255,0);
    float dx,dy,step,x,y;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>=dy)
    {
        step=dx;
    }
    else
    {
        step=dy;
    }
    dx=dx/step;
    dy=dy/step;
    x=x1;
    y=y1;
    int i=1;
    while(i<=step)
    {
        image.setPixel(x,y,value);
        x=x+dx*sign(x2-x1);
        y=y+dy*sign(y2-y1);
        i++;
    }
        ui->label_8->setPixmap(QPixmap::fromImage(image));
}
int MainWindow::sign(int p)
{
    if(p<0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void MainWindow::on_pushButton_clicked()
{
    int xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_4->toPlainText().toInt();
    ddacircle(xc,yc,r);
}
void MainWindow::ddacircle(int xc, int yc, int r)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    int xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_4->toPlainText().toInt();
    Bresenhamcircle(xc,yc,r);
}
void MainWindow::Bresenhamcircle(int xc, int yc, int r)
{
    QRgb value;
    value=qRgb(0,255,0);
    int x,y,d;
    x=0;
    y=r;
    d=3-2*r;
    while(x<=y)
    {
        image.setPixel(xc+x,yc+y,value);
        image.setPixel(xc+x,yc-y,value);
        image.setPixel(xc-x,yc+y,value);
        image.setPixel(xc-x,yc-y,value);
        image.setPixel(xc+y,yc+x,value);
        image.setPixel(xc-y,yc+x,value);
        image.setPixel(xc+y,yc-x,value);
        image.setPixel(xc-y,yc-x,value);
        if(d<0)
            d=d+4*x+6;
        else
        {
            d=d+4*(x-y)+10;
            y--;
        }
                x++;
    }
        ui->label_8->setPixmap(QPixmap::fromImage(image));
}

