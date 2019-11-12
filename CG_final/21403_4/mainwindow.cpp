#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
#include<QtGui>
#include<QMouseEvent>
#include<QColorDialog>

QImage image(300, 300, QImage:: Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start=true;
    var=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: mousePressEvent(QMouseEvent *ev)
{
    if(start==true)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[var]=p;
        b[var]=q;
        if(ev->button()==Qt::RightButton)
        {
            dda_line(a[0], b[0], a[var-1], b[var-1]);
            start=false;
        }
        else
        {
            if(var>0)
            {
                dda_line(a[var], b[var], a[var-1], b[var-1]);
            }
        }
        var++;
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

void MainWindow:: dda_line(float x1, float y1, float x2, float y2)
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
        image.setPixel(x, y, colour.rgb());
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_clicked()
{
    colour=QColorDialog::getColor();
}
