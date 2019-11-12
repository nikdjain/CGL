#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
QImage image(300, 300, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 dda(150,0,150,300 );
  dda( 0,150,300,150);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    float tx,ty;
    tx=ui->textEdit_7->toPlainText().toFloat();
    ty=ui->textEdit_6->toPlainText().toFloat();
    float x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    Translate(tx,ty,x1,y1,x2,y2);
}
void MainWindow::Translate(float tx, float ty, float x1, float y1, float x2, float y2)
{
    float T[3][3],P[2][3],A[2][3]={0};
    T[0][0]=1;
    T[0][1]=0;
    T[0][2]=0;
    T[1][0]=0;
    T[1][1]=1;
    T[1][2]=0;
    T[2][0]=tx;
    T[2][1]=ty;
    T[2][2]=1;
    P[0][0]=x1;
    P[0][1]=y1;
    P[0][2]=1;
    P[1][0]=x2;
    P[1][1]=y2;
    P[1][2]=1;
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=2;j++)
        {
            A[i][j]=0;
            for(int k=0;k<=2;k++)
            {
                A[i][j]+=P[i][k]*T[k][j];
            }
        }
    }
 dda( A[0][0]+150,-A[0][1]+150,A[1][0]+150,-A[1][1]+150);
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

void MainWindow::on_pushButton_4_clicked()
{
    float x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
      dda(x1+150,-y1+150,x2+150,-y2+150);
}

void MainWindow::on_pushButton_3_clicked()
{
    float tx,ty;
    tx=ui->textEdit_7->toPlainText().toFloat();
    ty=ui->textEdit_6->toPlainText().toFloat();
    float x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    Scale(tx,ty,x1,y1,x2,y2);
}
void MainWindow::Scale(float sx, float sy, float x1, float y1, float x2, float y2)
{
    float T[3][3],P[2][3],A[2][3]={0};
    T[0][0]=sx;
    T[0][1]=0;
    T[0][2]=0;
    T[1][0]=0;
    T[1][1]=sy;
    T[1][2]=0;
    T[2][0]=0;
    T[2][1]=0;
    T[2][2]=1;
    P[0][0]=x1;
    P[0][1]=y1;
    P[0][2]=1;
    P[1][0]=x2;
    P[1][1]=y2;
    P[1][2]=1;
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=2;j++)
        {
            A[i][j]=0;
            for(int k=0;k<=2;k++)
            {
                A[i][j]+=P[i][k]*T[k][j];
            }
        }
    }
 dda( A[0][0]+150,-A[0][1]+150,A[1][0]+150,-A[1][1]+150);
}

void MainWindow::on_pushButton_2_clicked()
{
    float angle;
    angle=ui->textEdit_5->toPlainText().toFloat();
    float x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    Rotate(angle,x1,y1,x2,y2);
}
void MainWindow::Rotate(float angle,float x1, float y1, float x2, float y2)
{
    float T[3][3],P[2][3],A[2][3]={0};
    angle=angle*3.14/180;
    T[0][0]=cos(angle);
    T[0][1]=sin(angle);
    T[0][2]=0;
    T[1][0]=-sin(angle);
    T[1][1]=cos(angle);
    T[1][2]=0;
    T[2][0]=0;
    T[2][1]=0;
    T[2][2]=1;
    P[0][0]=x1;
    P[0][1]=y1;
    P[0][2]=1;
    P[1][0]=x2;
    P[1][1]=y2;
    P[1][2]=1;
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=2;j++)
        {
            A[i][j]=0;
            for(int k=0;k<=2;k++)
            {
                A[i][j]+=P[i][k]*T[k][j];
            }
        }
    }
 dda( A[0][0]+150,-A[0][1]+150,A[1][0]+150,-A[1][1]+150);
}
