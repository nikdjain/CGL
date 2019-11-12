#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include<QtDebug>
#include<QColorDialog>

QColor color;
QRgb col=qRgb(255,0,0);
QRgb borcol=qRgb(255,255,255);

static QImage img(400,400,QImage::Format_RGB888);

int ver,a[5],b[5];
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


void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
     int q=ev->pos().y();
     //qDebug()<<p<<" "<<q;
     QRgb old=qRgb(0,0,0);
     seedfill(p,q,old,col);
     ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::seedfill(int x,int y,QRgb old,QRgb col)
{
    QRgb curr=img.pixel(x,y);
    if(curr==old)
    {
        img.setPixel(x,y,col);
        seedfill(x,y+1,old,col);
        seedfill(x-1,y,old,col);
        seedfill(x,y-1,old,col);
        seedfill(x+1,y,old,col);
    }
}

QColor MainWindow::getCol()
{
    color= QColorDialog::getColor();
    return color;
}

void MainWindow::on_pushButton_clicked()
{
    QColor col1 = getCol();
    col=col1.rgb();
}
