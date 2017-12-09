#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QTextEdit>
#include <QFile>
#include<QFileDialog>
#include <QDebug>
#include<QString>
#include<QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *centralWidget;
    QVBoxLayout *mBox;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void handleButton();
private:
    QPushButton *mButton;
    QTextEdit *mText;
};

#endif // MAINWINDOW_H
