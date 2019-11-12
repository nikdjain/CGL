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

void MainWindow::on_pushButton_clicked()
{
    float x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
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
        //delay(100);
    }
   // closegraph();
        ui->label->setPixmap(QPixmap::fromImage(image));
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

void MainWindow::on_pushButton_2_clicked()
{
    int x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    Bresenham(x1,y1,x2,y2);
}
void MainWindow::Bresenham(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(0,255,0);
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int p;
    int x,y;
    x=x1;
    y=y1;
    if(dx>=dy)
    {
        p= 2*dy-dx;
        int i=0;
        while(i<dx)
        {
            image.setPixel(x,y,value);
                if(p<0)
                {
                    x=x+1*sign(x2-x1);
                    p=p+2*dy;
                }
                else
                {
                    x=x+1*sign(x2-x1);
                    y=y+1*sign(y2-y1);
                    p=p+2*dy-2*dx;
                }
                i++;
        }
    }
    else
    {
        p= 2*dx-dy;
        int i=0;
        while(i<dy)
        {
            image.setPixel(x,y,value);
                if(p<0)
                {
                    y=y+1*sign(y2-y1);
                    p=p+2*dx;
                }
                else
                {
                    x=x+1*sign(x2-x1);
                    y=y+1*sign(y2-y1);
                    p=p+2*dx-2*dy;
                }
                i++;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}
