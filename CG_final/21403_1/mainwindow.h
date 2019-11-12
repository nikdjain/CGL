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
    void on_label_5_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void dda(float, float, float, float);

    int sign(int);

    void on_pushButton_2_clicked();

    void bresenham(int, int, int, int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
