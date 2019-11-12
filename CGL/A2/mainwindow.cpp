#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int sign(int x){
    if(x>0)
        return 1;
    else if(x<0)
        return -1;
    else
        return 0;
}

QImage image(300, 300, QImage::Format_RGB888);

void MainWindow::on_dda_button_clicked()
{
    int x = ui->x->text().toInt();
    int y = ui->y->text().toInt();
    int r = ui->rad->text().toInt();

    dda_algo(x, y, r);
}

void MainWindow::on_bres_button_clicked()
{
    int x = ui->x->text().toInt();
    int y = ui->y->text().toInt();
    int r = ui->rad->text().toInt();

    bres_algo(x, y, r);
}

void MainWindow::dda_algo(int x, int y, int rad)
{
      float xc1,xc2,yc1,yc2,eps,sx,sy;
      int val,i;
      xc1=rad;
      yc1=0;
      sx=xc1;
      sy=yc1;
      i=0;
      do{
          val=pow(2,i);
          i++;
          }while(val<rad);
      eps = 1/pow(2,i-1);
      do{
          xc2 = xc1 + yc1*eps;
          yc2 = yc1 - eps*xc2;

          image.setPixel(x+xc2, y-yc2, qRgb(255,255,255));

          xc1=xc2;
          yc1=yc2;
         }while((yc1-sy)<eps || (sx-xc1)>eps);

      ui->imageLabel->setPixmap(QPixmap::fromImage(image));
      ui->imageLabel->show();

}
void MainWindow::bres_algo(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    ui->imageLabel->show();
}

void MainWindow::drawCircle(int xc, int yc, int x, int y)
{
    image.setPixel(xc+x, yc+y, qRgb(255,255,255));
    image.setPixel(xc-x, yc+y, qRgb(255,255,255));
    image.setPixel(xc+x, yc-y, qRgb(255,255,255));
    image.setPixel(xc-x, yc-y, qRgb(255,255,255));

    image.setPixel(xc+y, yc+x, qRgb(255,255,255));
    image.setPixel(xc-y, yc+x, qRgb(255,255,255));
    image.setPixel(xc+y, yc-x, qRgb(255,255,255));
    image.setPixel(xc-y, yc-x, qRgb(255,255,255));

}

void MainWindow:: dda_line_algo(float x1, float y1, float x2, float y2)
{

    float len, dx, dy, x, y;

    if(abs(x2-x1) > abs(y2-y1)){
        len = abs(x2-x1);
    }else{
        len = abs(y2-y1);
    }

    dx= (x2-x1)/len;
    dy = (y2-y1)/len;

    x = x1 + 0.5*sign(dx);
    y = y1 + 0.5*sign(dy);

    int i=1;
    while(i<=len){
        image.setPixel(floor(x), floor(y), qRgb(255,255,255));
        x = x + dx;
        y = y + dy;
        i++;
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    ui->imageLabel->show();
}

void MainWindow::on_pushButton_clicked()
{
    int x = ui->x->text().toInt();
    int y = ui->y->text().toInt();
    int r = ui->rad->text().toInt();

    bres_algo(x, y, r);

    dda_line_algo(x, y-r, x+1.732*r/2, y+r/2);
    dda_line_algo(x, y-r, x-1.732*r/2, y+r/2);
    dda_line_algo(x+1.732*r/2, y+r/2, x-1.732*r/2, y+r/2);

    dda_algo(x, y, r/2);
}
