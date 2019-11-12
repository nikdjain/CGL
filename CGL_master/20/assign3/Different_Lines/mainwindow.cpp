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
        ui->label_6->setPixmap(QPixmap::fromImage(image));
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
    float x1,x2,y1,y2;
        x1=ui->textEdit->toPlainText().toFloat();
        y1=ui->textEdit_2->toPlainText().toFloat();
        x2=ui->textEdit_3->toPlainText().toFloat();
        y2=ui->textEdit_4->toPlainText().toFloat();
        Dotted_dda(x1,y1,x2,y2);
}
void MainWindow::Dotted_dda(float x1, float y1, float x2, float y2)
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
        if(i%3==0)
        image.setPixel(x,y,value);
        x=x+dx*sign(x2-x1);
        y=y+dy*sign(y2-y1);
        i++;
        //delay(100);
    }
   // closegraph();
        ui->label_6->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_3_clicked()
{
    float x1,x2,y1,y2;
        x1=ui->textEdit->toPlainText().toFloat();
        y1=ui->textEdit_2->toPlainText().toFloat();
        x2=ui->textEdit_3->toPlainText().toFloat();
        y2=ui->textEdit_4->toPlainText().toFloat();
        Dash_dda(x1,y1,x2,y2);
}
void MainWindow::Dash_dda(float x1, float y1, float x2, float y2)
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
        if(i%4!=0)
        image.setPixel(x,y,value);
        x=x+dx*sign(x2-x1);
        y=y+dy*sign(y2-y1);
        i++;
        //delay(100);
    }
   // closegraph();
        ui->label_6->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_4_clicked()
{
    float x1,x2,y1,y2;
        x1=ui->textEdit->toPlainText().toFloat();
        y1=ui->textEdit_2->toPlainText().toFloat();
        x2=ui->textEdit_3->toPlainText().toFloat();
        y2=ui->textEdit_4->toPlainText().toFloat();
        Dotted_Dash_dda(x1,y1,x2,y2);
}
void MainWindow::Dotted_Dash_dda(float x1, float y1, float x2, float y2)
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
        if(i%4!=0)
        image.setPixel(x,y,value);
        else if(i%3==0)
        image.setPixel(x,y,value);
        x=x+dx*sign(x2-x1);
        y=y+dy*sign(y2-y1);
        i++;
        //delay(100);
    }
   // closegraph();
        ui->label_6->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_5_clicked()
{
    float x1,x2,y1,y2,w;
        x1=ui->textEdit->toPlainText().toFloat();
        y1=ui->textEdit_2->toPlainText().toFloat();
        x2=ui->textEdit_3->toPlainText().toFloat();
        y2=ui->textEdit_4->toPlainText().toFloat();
        w=ui->textEdit_5->toPlainText().toFloat();
        Thick_dda(x1,y1,x2,y2,w);
}
void MainWindow::Thick_dda(float x1, float y1, float x2, float y2,float w)
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
    float j;
    while(i<=step)
    {
        if(y1==y2||x1==x2)
            for(j=1;j<=w;j+=0.2)
             image.setPixel(x+j,y+j,value);
        else
            for(j=1;j<=w;j+=0.2)
             image.setPixel(x+j,y,value);
        x=x+dx*sign(x2-x1);
        y=y+dy*sign(y2-y1);
        i++;
        //delay(100);
    }
   // closegraph();
        ui->label_6->setPixmap(QPixmap::fromImage(image));
}

