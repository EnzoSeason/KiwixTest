#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QTextBrowser>
#include <QFile>
#include <QDebug>
#include<QString>
#include<QHBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void handleButton();
private:
    QPushButton *mButton;
    QTextBrowser *mText;
    QHBoxLayout *mBox;
};

#endif // MAINWINDOW_H
