#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>
QImage image(300, 300, QImage:: Format_RGB888);
MainWindow::MainWindow(QWidget *parent):
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

int MainWindow:: sign(int x)
{
    if(x<0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}


//Dotted
void MainWindow::on_pushButton_2_clicked()
{
    float x1, y1, x2, y2;
    int count=0;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
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
       if(count%5==0)
       {
           image.setPixel(x, y, colour);
       }
       count++;
       x=x+dx;
       y=y+dy;
       i++;
    }
    ui->label->setPixmap(QPixmap:: fromImage(image));
}


//Dashed
void MainWindow::on_pushButton_3_clicked()
{
    float x1, y1, x2, y2;
    int count=0;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
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
       if(count%10< 7)
       {
           image.setPixel(x, y, colour);
       }
       count++;
       x=x+dx;
       y=y+dy;
       i++;
    }
    ui->label->setPixmap(QPixmap:: fromImage(image));
}

void MainWindow::on_pushButton_4_clicked()
{
    float x1, y1, x2, y2;
    int count=0;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
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
       int compare=count%15;
       if(compare<7 || (compare>9 && compare<12))
       {
           image.setPixel(x, y, colour);
       }
       count++;
       x=x+dx;
       y=y+dy;
       i++;
    }
    ui->label->setPixmap(QPixmap:: fromImage(image));
}

void MainWindow::on_pushButton_5_clicked()
{
    float x1, y1, x2, y2;
    int width;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    width=ui->textEdit_5->toPlainText().toInt();
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
       if(x1==x2)
       {
           for(int j=0; j<width/2; j++)
           {
               image.setPixel(x+j, y, colour);
               image.setPixel(x-j, y, colour);
           }
       }
       else
       {
           for(int j=0; j<width/2; j++)
           {
               image.setPixel(x, y+j, colour);
               image.setPixel(x, y-j, colour);
           }
       }
       x=x+dx;
       y=y+dy;
       i++;
    }
    ui->label->setPixmap(QPixmap:: fromImage(image));
}
