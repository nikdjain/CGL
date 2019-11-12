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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int a[10][4],b[10][4];
    float cm[1][3],rm[1][3],rom[3][3];
    int var;
    QRgb color;


private slots:
    void on_pushButton_clicked();
    void Multiply(float t1[1][3],float t2[3][3]);
    int sign(int);
    void bresenhams(int,int,int,int);
    void Initialise();
    void Rotate(float,float);
    void mouseDoubleClickEvent(QMouseEvent*);
    void seedfill(int,int);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
