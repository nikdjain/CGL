#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
#include<QtGui>
#include<QColorDialog>
#include<QMouseEvent>

QImage image(400,400,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    color=qRgb(255,255,255);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
                rom[i][j]=0;
        }
    }
    var=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Initialise()
{
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<3;j++)
        {
             cm[i][j]=0;
             rm[i][j]=0;
        }
    }
}
void MainWindow::Multiply(float t1[1][3],float t2[3][3])
{
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                rm[i][j] +=t1[i][k]*t2[k][j];
            }
        }
    }
}
int MainWindow::sign(int x)
{
    if(x>0)
        return 1;
    else
        return -1;
}
void MainWindow::bresenhams(int x1,int y1,int x2,int y2)
{
    int x,y,dx,dy,p,i=0;

    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
    {
        p = (2*dy)-dx;
            while(i<dx)
            {
                image.setPixel(x,y,color);
                if(p<0)
                {
                    p += 2*dy;
                }
                else
                {
                    p += 2*(dy-dx);
                    y += sign(y2-y1);
                }
                x += sign(x2-x1);
                i++;
            }
    }
    else
    {
        p = (2*dx)-dy;
            while(i<dy)
            {
                image.setPixel(x,y,color);
                if(p<0)
                {
                    p += 2*dx;
                }
                else
                {
                    p += 2*(dx-dy);
                    x += sign(x2-x1);
                }
                y += sign(y2-y1);
                i++;
            }
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}
void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    bresenhams(0,200,400,200);
    bresenhams(200,0,200,400);
    Initialise();
    a[var][0]=x1;
    a[var][1]=y1;
    Rotate(a[var][0],a[var][1]);

    b[var][0]=rm[0][0];
    b[var][1]=rm[0][1];

    a[var][2]=x2;
    a[var][3]=y2;
    Initialise();
    Rotate(a[var][2],a[var][3]);

    b[var][2]=rm[0][0];
    b[var][3]=rm[0][1];
    bresenhams(b[var][0]+200,b[var][1]+200,b[var][2]+200,b[var][3]+200);
    var++;
}
void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
    int q=ev->pos().y();
    seedfill(p, q);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow:: seedfill(int x, int y)
{
    QRgb curr=image.pixel(x,y);
    if(curr!=color)
    {
        image.setPixel(x,y,color);
        seedfill(x+1,y);
        seedfill(x-1,y);
        seedfill(x,y+1);
        seedfill(x,y-1);
    }
}
void MainWindow::Rotate(float x1,float y1)
{
    int theta=45;
    const float mul=3.14/180;
    rom[0][0]=cos(theta*mul);
    rom[0][1]=-sin(theta*mul);
    rom[1][0]=sin(theta*mul);
    rom[1][1]=cos(theta*mul);
    rom[2][2]=1;
    cm[0][0]=x1;
    cm[0][1]=y1;
    cm[0][2]=1;
    Multiply(cm,rom);
}
