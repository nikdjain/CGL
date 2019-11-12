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
    float cm[3][3], tm[3][3], rom[3][3], rm[3][3], im[3][3], rx[3][3], ry[3][3], rxy[3][3], ftm[3][3];
    QRgb red, green, blue;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void dda_line(float, float, float, float, QRgb);
    int sign(int);
    void Multiply(float t1[2][3],float t2[3][3]);
    void Translate(float, float);
    void Rotate(float);
    void Initialise();
    void RX();
    void RY();
    void RXY();
    void SetTM(float t[3][3]);
    void SetCoordinate(float, float, float, float);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
