#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include<QtDebug>
#include<QColorDialog>
#include<cmath>

QColor color;
QRgb col=qRgb(255,0,0);
QRgb borcol=qRgb(255,255,255);

static QImage img(400,400,QImage::Format_RGB888);

int ver,a[10],b[10];
bool start;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ver=0;
   start=true;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(float x1,float y1,float x2,float y2)

{

    float x,y,dx,dy,l,i=1;
    QRgb value;
    value=qRgb(255,255,255);


    l=std::abs((int)(x2-x1))>std::abs((int)(y2-y1))?std::abs((int)(x2-x1)):std::abs((int)(y2-y1));
    dx=(x2-x1)/l;
    dy=(y2-y1)/l;

    x=x1+0.5f;
    y=y1+0.5f;
    do
    {
       img.setPixel(static_cast<int>(x),static_cast<int>(y),value);
       x = x + dx;
       y = y + dy;
       i++;
      }while(i <= l);

    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start==true)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[ver]=p;
        b[ver]=q;
        if(ev->button()==Qt::RightButton)
        {
            a[ver]=a[0];
            b[ver]=b[0];
            dda(a[0],b[0],a[ver-1],b[ver-1]);
            start=false;
        }
        else {
            if(ver>0)
            {
                    dda(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}

QColor MainWindow::getCol()
{
    color= QColorDialog::getColor();
    return color;
}

void MainWindow :: clearImage()
{
    for(int i=0; i<400; i++)
    {
        for(int j=0; j<400; j++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
}

void MainWindow::Translation()
{
    int newA[10], newB[10];

    int tx = ui->tx->text().toInt();
    int ty = ui->ty->text().toInt();

    for(int i=0; i<ver; i++)
    {
        newA[i]=a[i]+tx;
        newB[i]=b[i]-ty;
    }

    for(int i=0; i<ver-1; i++)
        dda(newA[i],newB[i],newA[i+1],newB[i+1]);

}

void MainWindow::Scaling()
{
    int newA[10], newB[10];

    int sx = ui->sx->text().toInt();
    int sy = ui->sy->text().toInt();

    for(int i=0; i<ver; i++)
    {
        newA[i]=a[i]-200;
        newB[i]=b[i]-185;
    }

    for(int i=0; i<ver; i++)
    {
        newA[i]=newA[i]*sx;
        newB[i]=newB[i]*sy;
    }

    for(int i=0; i<ver; i++)
    {
        newA[i]=newA[i]+200;
        newB[i]=newB[i]+185;
    }

    for(int i=0; i<ver-1; i++)
        dda(newA[i],newB[i],newA[i+1],newB[i+1]);

}

void MainWindow :: Rotation()
{
    int newA[10], newB[10];

    float angle = ui->theta->text().toFloat();
    angle = (angle*3.142*-1)/180;

    float cosVal = cos(angle);
    float sinVal = sin(angle);

    for(int i=0; i<ver; i++)
    {
        newA[i] = (a[i]-200)*cosVal - (b[i]-200)*sinVal;
        newB[i] = (a[i]-200)*sinVal + (b[i]-200)*cosVal;
    }

    for(int i=0; i<ver; i++)
    {
        newA[i]=newA[i]+200;
        newB[i]=newB[i]+200;
    }

    for(int i=0; i<ver-1; i++)
        dda(newA[i],newB[i],newA[i+1],newB[i+1]);

}

void MainWindow::on_pushButton_2_clicked()
{
    clearImage();

    Translation();
}

void MainWindow::on_pushButton_clicked()
{
    clearImage();

    Scaling();

}

void MainWindow::on_pushButton_3_clicked()
{
    clearImage();

    Rotation();
}
