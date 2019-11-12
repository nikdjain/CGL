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
    void on_dda_button_clicked();

    void on_bres_button_clicked();

    void dda_algo(int, int, int);

    void dda_line_algo(float, float, float , float);

    void bres_algo(int, int, int);

    void drawCircle(int, int, int, int);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
