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
    float a[20][2];
    void DDA(float,float,float,float);
    int sign(float);
    void mousePressEvent(QMouseEvent *);
    bool k;
    int j;
    int* outcode(float x,float y);
    void CSA(float x1,float y1,float x2,float y2);
private slots:
    //void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
