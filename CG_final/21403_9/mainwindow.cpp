#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QColorDialog"
#include "math.h"
#include "qdebug.h"
QImage image(400,400,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(image));
    k=0;
    j=0;
    int i;
    for(i=0;i<20;i++)
    {
        a[i][0]=0;
        a[i][1]=0;
    }
    DDA(100,100,300,100);
    DDA(300,100,300,300);
    DDA(300,300,100,300);
    DDA(100,300,100,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::DDA(float x1,float y1,float x2,float y2)
{
    QRgb value=qRgb(250,0,0);
    float dx=abs(x2-x1);
    float dy=abs(y2-y1);
    float step;
    if(dx>dy)
        step=dx;
    else
        step=dy;
    dx=dx/step;
    dy=dy/step;
    float x=x1;
    float y=y1;
    float i=1;
    while(i<=step)
    {
        image.setPixel(x,y,value);
        x=x+dx*(sign(x2-x1));
        y=y+dy*(sign(y2-y1));
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}
int MainWindow::sign(float t)
{
    if(t<0)
        return -1;
    else
        return 1;
}
void MainWindow::mousePressEvent(QMouseEvent *eve)
{
    int p=eve->pos().x();
    int q=eve->pos().y();
    if(k==0)
    {
        a[j][0]=p;
        a[j][1]=q;
        qDebug()<<a[j][0]<<a[j][1];
        k=1;
    }
    else
    {
        j++;
        a[j][0]=p;
        a[j][1]=q;
        qDebug()<<a[j][0]<<a[j][1];

     DDA(a[j-1][0],a[j-1][1],a[j][0],a[j][1]);
     CSA(a[j-1][0],a[j-1][1],a[j][0],a[j][1]);
    }

}

int* MainWindow::outcode(float x,float y)
{
    int lf=100;
    int ab=100;
    int rg=300;
    int bt=300;
    int a[4];
    if(x<lf && y<ab)
       {
        a[0]=1;
        a[1]=0;
        a[2]=0;
        a[3]=1;
        }
    if(x<lf && y>100 && y<300)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=1;
    }
    if(x<lf && y>bt)
    {
        a[0]=0;
        a[1]=1;
        a[2]=0;
        a[3]=1;
    }
    if(x>lf && x<rg && y<ab)
    {
        a[0]=1;
        a[1]=0;
        a[2]=0;
        a[3]=0;
    }
    if(x>lf && x<rg && y>ab && y<bt)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=0;
    }
    if(x>lf && x<rg && y>bt)
    {
        a[0]=0;
        a[1]=1;
        a[2]=0;
        a[3]=0;
    }
    if(x>rg && y<ab)
    {
        a[0]=1;
        a[1]=0;
        a[2]=1;
        a[3]=0;
    }
    if(x>rg && y>ab && y<bt)
    {
        a[0]=0;
        a[1]=0;
        a[2]=1;
        a[3]=0;
    }
    if(x>rg && y>bt)
    {
        a[0]=0;
        a[1]=1;
        a[2]=1;
        a[3]=0;
    }
    return (a);
}

void MainWindow::CSA(float x1,float y1,float x2,float y2)
{
    int* a=outcode(x1,y1);
    int* b=outcode(x2,y2);
    int i;
    int c[4];
    for(i=0;i<4;i++)
    {
        c[i]=(a[i]&b[i]);
    }
    qDebug()<<c[0]<<c[1]<<c[2]<<c[3];
}
