#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>
#include<cmath>

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

void MainWindow::on_thickLine_clicked()
{
    int x1 = ui->x1->text().toInt();
    int y1 = ui->y1->text().toInt();
    int x2 = ui->x2->text().toInt();
    int y2 = ui->y2->text().toInt();
    int w = ui->width->text().toInt();

    float yz;

   if(abs(x2-x1) > abs(y2-y1) && (x2-x1)!=0){
        yz=((w-1)/2)*(sqrt((((x2-x1)*(x2-x1))+(y2-y1)*(y2-y1))))/abs(x2-x1);
        for(int i=yz; i>-yz; i--)
        {
            dda_algo(x1,y1+i,x2,y2+i);
            dda_algo(x1,y1-i,x2,y2-i);
        }
    }
    else{
        yz=((w-1)/2)*(sqrt((((x2-x1)*(x2-x1))+(y2-y1)*(y2-y1))))/abs(y2-y1);
        for(int i=yz; i>-yz; i--)
        {
            dda_algo(x1+i,y1,x2+i,y2);
            dda_algo(x1-i,y1,x2-i,y2);
        }
    }

}

void MainWindow:: dda_algo(float x1, float y1, float x2, float y2)
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

void MainWindow::on_dotted_clicked()
{
    int x1 = ui->x1->text().toInt();
    int y1 = ui->y1->text().toInt();
    int x2 = ui->x2->text().toInt();
    int y2 = ui->y2->text().toInt();

    int flag=0;
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

            if(flag==0 || flag==1)
            {
                image.setPixel(floor(x), floor(y), qRgb(255,255,255));
                flag=(flag+1)%4;
            }else
                flag=(flag+1)%4;

        x = x + dx;
        y = y + dy;
        i++;
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    ui->imageLabel->show();
}

void MainWindow::on_dashed_clicked()
{
    int x1 = ui->x1->text().toInt();
    int y1 = ui->y1->text().toInt();
    int x2 = ui->x2->text().toInt();
    int y2 = ui->y2->text().toInt();

    int flag=0;
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


            if(flag==0 || flag==1 || flag==2)
            {
            image.setPixel(floor(x), floor(y), qRgb(255,255,255));
            flag=(flag+1)%5;
            }else
            flag=(flag+1)%5;

        x = x + dx;
        y = y + dy;
        i++;
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    ui->imageLabel->show();

}

void MainWindow::on_pushButton_clicked()
{
    int x1 = ui->x1->text().toInt();
    int y1 = ui->y1->text().toInt();
    int x2 = ui->x2->text().toInt();
    int y2 = ui->y2->text().toInt();

    int flag=0;
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


            if(flag==0 || flag==1 || flag==2 || flag==5)
            {
            image.setPixel(floor(x), floor(y), qRgb(255,255,255));
            flag=(flag+1)%7;
            }else
            flag=(flag+1)%7;

        x = x + dx;
        y = y + dy;
        i++;
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    ui->imageLabel->show();

}
