/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ddaButton;
    QPushButton *bresButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *x1;
    QLineEdit *y1;
    QLineEdit *x2;
    QLineEdit *y2;
    QLabel *imageLabel;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *patternButton;
    QLineEdit *length;
    QLineEdit *height;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(873, 452);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ddaButton = new QPushButton(centralWidget);
        ddaButton->setObjectName(QStringLiteral("ddaButton"));
        ddaButton->setGeometry(QRect(130, 220, 97, 31));
        bresButton = new QPushButton(centralWidget);
        bresButton->setObjectName(QStringLiteral("bresButton"));
        bresButton->setGeometry(QRect(250, 220, 97, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(53, 40, 31, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 40, 31, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 110, 31, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 110, 31, 21));
        x1 = new QLineEdit(centralWidget);
        x1->setObjectName(QStringLiteral("x1"));
        x1->setGeometry(QRect(90, 30, 113, 33));
        y1 = new QLineEdit(centralWidget);
        y1->setObjectName(QStringLiteral("y1"));
        y1->setGeometry(QRect(310, 30, 113, 33));
        x2 = new QLineEdit(centralWidget);
        x2->setObjectName(QStringLiteral("x2"));
        x2->setGeometry(QRect(90, 110, 113, 33));
        y2 = new QLineEdit(centralWidget);
        y2->setObjectName(QStringLiteral("y2"));
        y2->setGeometry(QRect(310, 110, 113, 33));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(470, 30, 300, 300));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 300, 97, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 330, 97, 31));
        patternButton = new QPushButton(centralWidget);
        patternButton->setObjectName(QStringLiteral("patternButton"));
        patternButton->setGeometry(QRect(190, 270, 97, 31));
        length = new QLineEdit(centralWidget);
        length->setObjectName(QStringLiteral("length"));
        length->setGeometry(QRect(90, 170, 113, 33));
        height = new QLineEdit(centralWidget);
        height->setObjectName(QStringLiteral("height"));
        height->setGeometry(QRect(310, 170, 113, 33));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 180, 65, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 180, 65, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 873, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ddaButton->setText(QApplication::translate("MainWindow", "DDA", Q_NULLPTR));
        bresButton->setText(QApplication::translate("MainWindow", "Bresenham", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "X1 :", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Y1 :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "X2 :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Y2 :", Q_NULLPTR));
        x1->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        y1->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        imageLabel->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Clear Image", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Clear Values", Q_NULLPTR));
        patternButton->setText(QApplication::translate("MainWindow", "Pattern", Q_NULLPTR));
        length->setText(QApplication::translate("MainWindow", "200", Q_NULLPTR));
        height->setText(QApplication::translate("MainWindow", "200", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Length :", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Height :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
