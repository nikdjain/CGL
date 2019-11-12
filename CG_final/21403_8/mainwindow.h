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
    QRgb colour;
    int a[10][4];
    int b[10][4];
    float cm[1][3];
    float rom[3][3];
    float rm[1][3];
    int var;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void Multiply(float t1[1][3],float t2[3][3]);
    void Rotate(float x1, float y1);
    void bresenham(int x1, int y1, int x2, int y2);
    int sign(int);
    void Initialise();
    void mousePressEvent(QMouseEvent *ev);
    void seedfill(int, int);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
