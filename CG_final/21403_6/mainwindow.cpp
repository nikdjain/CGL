#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>
#include<QDebug>
#include<math.h>

QImage image(300, 300, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            tm[i][j]=0;
            sm[i][j]=0;
            rom[i][j]=0;
        }
    }
    red=qRgb(255, 0, 0);
    green=qRgb(0, 255, 0);
    blue=qRgb(0, 0, 255);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: Initialise()
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            rm[i][j]=0;
        }
    }
}

void MainWindow:: Multiply(float t1[2][3], float t2[3][3], float rm[2][3])
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                rm[i][j]+=t1[i][k]*t2[k][j];
            }
        }
    }
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

void MainWindow:: dda_line(float x1, float y1, float x2, float y2, QRgb colour)
{
    float x, y, dx, dy, len;
    int i=0;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx<dy)
    {
        len=dy;
    }
    else
    {
        len=dx;
    }
    dx=(dx/len)*sign(x2-x1);
    dy=(dy/len)*sign(y2-y1);
    x=x1;
    y=y1;
    while(i<len)
    {
        image.setPixel(x, y, colour);
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

//Translate
void MainWindow::on_pushButton_clicked()
{
    float x1, y1, x2, y2, tx, ty;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    tx=ui->textEdit_5->toPlainText().toFloat();
    ty=ui->textEdit_6->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
    Initialise();
    Translate(x1, y1, x2, y2, tx, ty);
    dda_line(rm[0][0]+150, rm[0][1]+150, rm[1][0]+150, rm[1][1]+150, red);
}

//Scale
void MainWindow::on_pushButton_2_clicked()
{
    float x1, y1, x2, y2, sx, sy;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    sx=ui->textEdit_5->toPlainText().toFloat();
    sy=ui->textEdit_6->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
    Initialise();
    Scale(x1, y1, x2, y2, sx, sy);
    dda_line(rm[0][0]+150, rm[0][1]+150, rm[1][0]+150, rm[1][1]+150, red);
}

//Rotata
void MainWindow::on_pushButton_3_clicked()
{
    float x1, y1, x2, y2, theta;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    theta=ui->textEdit_5->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
    Initialise();
    Rotate(x1, y1, x2, y2, theta);
    dda_line(rm[0][0]+150, rm[0][1]+150, rm[1][0]+150, rm[1][1]+150, red);
}

//Normal solid line
void MainWindow::on_pushButton_4_clicked()
{
    float x1, y1, x2, y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    Initialise();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
}

void MainWindow:: Translate(float x1, float y1, float x2, float y2, float tx, float ty)
{
    tm[0][0]=1;
    tm[1][1]=1;
    tm[2][0]=tx;
    tm[2][1]=ty;
    tm[2][2]=1;
    cm[0][0]=x1;
    cm[0][1]=y1;
    cm[0][2]=1;
    cm[1][0]=x2;
    cm[1][1]=y2;
    cm[1][2]=1;
    Multiply(cm, tm, rm);
}

void MainWindow:: Scale(float x1, float y1, float x2, float y2, float sx, float sy)
{
    sm[0][0]=sx;
    sm[1][1]=sy;
    sm[2][2]=1;
    cm[0][0]=x1;
    cm[0][1]=y1;
    cm[0][2]=1;
    cm[1][0]=x2;
    cm[1][1]=y2;
    cm[1][2]=1;
    Multiply(cm, sm, rm);
}

void MainWindow:: Rotate(float x1, float y1, float x2, float y2, float theta)
{
    const float mul=3.1415/180;
    rom[0][0]=cos(theta*mul);
    rom[0][1]=-sin(theta*mul);
    rom[1][0]=sin(theta*mul);
    rom[1][1]=cos(theta*mul);
    rom[2][2]=1;
    cm[0][0]=x1;
    cm[0][1]=y1;
    cm[0][2]=1;
    cm[1][0]=x2;
    cm[1][1]=y2;
    cm[1][2]=1;
    Multiply(cm, rom, rm);
}
