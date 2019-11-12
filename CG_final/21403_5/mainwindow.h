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
    bool start;
    int var;
    int a[20], b[20];
    QColor colour;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent*);
    void dda_line(float, float, float, float);
    int sign(int);
    void mouseDoubleClickEvent(QMouseEvent*);
    void seedfill(int, int);
};

#endif // MAINWINDOW_H
