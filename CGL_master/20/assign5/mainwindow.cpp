#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include<math.h>
#include<QColorDialog>
QColor col,c;
QImage image(300, 300, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start=true;
    j=0;
    //a[20]=0;
   // b[20]=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dda(float x1,float y1,float x2,float y2)
{
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
            image.setPixel(x,y,col.rgb());
            x=x+dx*sign(x2-x1);
            y=y+dy*sign(y2-y1);
            i++;
        }
            ui->label->setPixmap(QPixmap::fromImage(image));
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
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start==true)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[j]=p;
        b[j]=q;
        if(ev->button()==Qt::RightButton)
        {
            dda(a[0],b[0],a[j-1],b[j-1]);
            start=false;
        }
        else
        {
            if(j>0)
            {
                dda(a[j-1],b[j-1],a[j],b[j]);
            }
        }
        j++;
    }
}
void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
    int q=ev->pos().y();
    seedfill(p,q);
    ui->label->setPixmap(QPixmap::fromImage(image));

}
void MainWindow::seedfill(int x, int y)
{
    QRgb curr=image.pixel(x,y);
    if(curr!=(col.rgb())&&curr!=(c.rgb()))
    {
        image.setPixel(x,y,c.rgb());
        seedfill(x+1,y);
        seedfill(x-1,y);
        seedfill(x,y+1);
        seedfill(x,y-1);
    }
}

void MainWindow::on_pushButton_clicked()
{
    col=QColorDialog::getColor();
}

void MainWindow::on_pushButton_2_clicked()
{
    c=QColorDialog::getColor();
}
