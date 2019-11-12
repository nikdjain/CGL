#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
     void dda(float,float,float,float);
     int sign(int);
    void on_pushButton_2_clicked();
void dda1(float,float,float,float);
void on_pushButton_3_clicked();
 void dda2(float,float,float,float);
void on_pushButton_4_clicked();
void dda3(float,float,float,float);

void on_pushButton_5_clicked();
void dda4(float,float,float,float,float);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
