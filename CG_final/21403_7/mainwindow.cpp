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
            rom[i][j]=0;
            rx[i][j]=0;
            ry[i][j]=0;
            rxy[i][j]=0;
            cm[i][i]=0;
        }
    }
    im[0][0]=1;
    im[1][1]=1;
    im[2][2]=1;
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
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            rm[i][j]=0;
        }
    }
}

void MainWindow:: Multiply(float t1[2][3], float t2[3][3])
{
    for(int i=0; i<3; i++)
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

void MainWindow:: SetTM(float t[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            ftm[i][j]=t[i][j];
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

void MainWindow:: SetCoordinate(float x1, float y1, float x2, float y2)
{
    cm[0][0]=x1;
    cm[0][1]=y1;
    cm[0][2]=1;
    cm[1][0]=x2;
    cm[1][1]=y2;
    cm[1][2]=1;
}

void MainWindow:: Translate(float tx, float ty)
{
    tm[0][0]=1;
    tm[1][1]=1;
    tm[2][0]=tx;
    tm[2][1]=ty;
    tm[2][2]=1;
}

void MainWindow:: Rotate(float theta)
{
    const float mul=3.1415/180;
    rom[0][0]=cos(theta*mul);
    rom[0][1]=-sin(theta*mul);
    rom[1][0]=sin(theta*mul);
    rom[1][1]=cos(theta*mul);
    rom[2][2]=1;
}

void MainWindow:: RX()
{
    rx[0][0]=1;
    rx[1][1]=-1;
    rx[2][2]=1;
}

void MainWindow:: RY()
{
    ry[0][0]=-1;
    ry[1][1]=1;
    ry[2][2]=1;
}

void MainWindow:: RXY()
{
    rxy[0][1]=1;
    rxy[1][0]=1;
    rxy[2][2]=1;
}
void MainWindow::on_pushButton_clicked()
{
    float x1, y1, x2, y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
    Initialise();
    SetCoordinate(x1, y1, x2, y2);
    RX();
    Multiply(cm, rx);
    dda_line(rm[0][0]+150, rm[0][1]+150, rm[1][0]+150, rm[1][1]+150, red);
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1, y1, x2, y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
    Initialise();
    SetCoordinate(x1, y1, x2, y2);
    RY();
    Multiply(cm, ry);
    dda_line(rm[0][0]+150, rm[0][1]+150, rm[1][0]+150, rm[1][1]+150, red);
}

void MainWindow::on_pushButton_3_clicked()
{
    float x1, y1, x2, y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
    Initialise();
    SetCoordinate(x1, y1, x2, y2);
    RXY();
    Multiply(cm, rxy);
    dda_line(rm[0][0]+150, rm[0][1]+150, rm[1][0]+150, rm[1][1]+150, red);
}

void MainWindow::on_pushButton_4_clicked()
{
    float x1, y1, x2, y2, x, y, theta;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    x=ui->textEdit_5->toPlainText().toFloat();
    y=ui->textEdit_6->toPlainText().toFloat();
    theta=ui->textEdit_7->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
    Initialise();
    Translate(-x, -y);
    SetCoordinate(x1, y1, x2, y2);
    Multiply(cm, tm);
    SetTM(rm);
    Initialise();
    Rotate(theta);
    Multiply(ftm, rom);
    SetTM(rm);
    Initialise();
    Translate(x, y);
    Multiply(ftm, tm);
    dda_line(rm[0][0]+150, rm[0][1]+150, rm[1][0]+150, rm[1][1]+150, red);
}

void MainWindow::on_pushButton_5_clicked()
{
    float x1, y1, x2, y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    dda_line(0, 150, 300, 150, blue);
    dda_line(150, 0, 150, 300, blue);
    dda_line(x1+150, y1+150, x2+150, y2+150, green);
}
