#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include<QtDebug>
#include<QColorDialog>

QColor color;
QRgb borcol;

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

    l=std::abs((int)(x2-x1))>std::abs((int)(y2-y1))?std::abs((int)(x2-x1)):std::abs((int)(y2-y1));
    dx=(x2-x1)/l;
    dy=(y2-y1)/l;

    x=x1+0.5f;
    y=y1+0.5f;
    do
    {
       img.setPixel(static_cast<int>(x),static_cast<int>(y),borcol);
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

void MainWindow::on_pushButton_clicked()
{
    QColor col1 = getCol();
    borcol=col1.rgb();
}
