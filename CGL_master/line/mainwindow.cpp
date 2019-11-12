#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
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
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
dda(x1,y1,x2,y2);


}
void MainWindow::dda(float X1,float Y1,float X2,float Y2)
{
    QRgb value=qRgb(0,255,0);
   float dx=abs(X2-X1);
   float dy=abs(Y2-Y1);
   float step;
   if(dx>dy)
       step=dx;
   else
       step=dy;
   dx=dx/step;
   dy=dy/step;
   float x=X1;
   float y=Y1;
   float i=1;
   while(i<=step)
   {
     image.setPixel(x,y,value);
     x=x+dx*sign(X2-X1);
     y=y+dy*sign(Y2-Y1);
     i++;

   }

   ui->label->setPixmap(QPixmap::fromImage(image));
}
int MainWindow::sign(int p)
{
    if(p<0)
    {return -1;}
    else
    {
        return 1;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    dda1(x1,y1,x2,y2);

}
void MainWindow::dda1(float X1,float Y1,float X2,float Y2)
{
    QRgb value=qRgb(0,255,0);
   float dx=abs(X2-X1);
   float dy=abs(Y2-Y1);
   float step;
   if(dx>dy)
       step=dx;
   else
       step=dy;
   dx=dx/step;
   dy=dy/step;
   float x=X1;
   float y=Y1;
   float i=1;
   while(i<=step)
   {  if(int(x)%4==0)
     image.setPixel(x,y,value);
     x=x+dx*sign(X2-X1);
     y=y+dy*sign(Y2-Y1);
     i++;
   }

   ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_3_clicked()
{
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    dda2(x1,y1,x2,y2);
}
void MainWindow::dda2(float X1,float Y1,float X2,float Y2)
{
    QRgb value=qRgb(0,255,0);
   float dx=abs(X2-X1);
   float dy=abs(Y2-Y1);
   float step;
   if(dx>dy)
       step=dx;
   else
       step=dy;
   dx=dx/step;
   dy=dy/step;
   float x=X1;
   float y=Y1;
   float i=1;
   while(i<=step)
   {if(int(x)%4!=0)
     image.setPixel(x,y,value);
     x=x+dx*sign(X2-X1);
     y=y+dy*sign(Y2-Y1);
     i++;
   }

   ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_4_clicked()
{
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    dda3(x1,y1,x2,y2);
}
void MainWindow::dda3(float X1,float Y1,float X2,float Y2)
{
    QRgb value=qRgb(0,255,0);
   float dx=abs(X2-X1);
   float dy=abs(Y2-Y1);
   float step;
   if(dx>dy)
       step=dx;
   else
       step=dy;
   dx=dx/step;
   dy=dy/step;
   float x=X1;
   float y=Y1;
   float i=1;
   while(i<=step)
       {
       if(int(i)%8==0)
       {
       if(int(x)%4==0)
     image.setPixel(x,y,value);
     x=x+dx*sign(X2-X1);
     y=y+dy*sign(Y2-Y1);
     i++;
       }
  else
       {
           if(int(x)%4!=0)
         image.setPixel(x,y,value);
         x=x+dx*sign(X2-X1);
         y=y+dy*sign(Y2-Y1);
         i++;
       }

       }




   ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_pushButton_5_clicked()
{
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    float w=ui->textEdit_4->toPlainText().toFloat();
    dda4(x1,y1,x2,y2,w);
}
void MainWindow::dda4(float X1,float Y1,float X2,float Y2,float w)
{
    QRgb value=qRgb(0,255,0);
   float dx=abs(X2-X1);
   float dy=abs(Y2-Y1);
   float step;
   if(dx>dy)
       step=dx;
   else
       step=dy;
   dx=dx/step;
   dy=dy/step;
   float x=X1;
   float y=Y1;
   float i=1;
   int j;
   while(i<=step)
   {  if(X1==X2)
       {for(j=1;j<=w;j++)
     image.setPixel(x+j,y,value);}
       else if(Y1==Y2)
              {for(j=1;j<=w;j++)
            image.setPixel(x,y+j,value);}
       else
       for(j=1;j<=w;j++)
     image.setPixel(x+j,y,value);
     x=x+dx*sign(X2-X1);
     y=y+dy*sign(Y2-Y1);
     i++;
   }

   ui->label->setPixmap(QPixmap::fromImage(image));
}

