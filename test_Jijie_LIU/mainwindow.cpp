#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //set the window
    this->setWindowTitle(tr("Test of Kiwix"));
    //set the name of the window
    this->resize(600, 240);
    //set the size of the window
    QPalette palette = this->palette();
    //use the palette to set the background color of the window
    palette.setColor(QPalette::Window, QColor(255, 255, 255));
    //set the color white
    this->setPalette(palette);
    //comfirm the color setting

    //add Button
    mButton = new QPushButton("Read",this);
    //create the button named "Read"
    connect(mButton,SIGNAL (released()),this,SLOT(handleButton()));
    //connect the button with the function handleButton()

    //add the TextBrowser to see the text we have read
    mText = new QTextBrowser();
    //create the TextBrowser
    mText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //we will not see scroll horizontal bar.
    mText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //we can see the scroll vertical bar.
    mText->show();
}

MainWindow::~MainWindow()
{

}

//When we click the button, we call this function, and then this function read the text.
void MainWindow::handleButton(){
    QFile file("/Users/enzoliu/Desktop/test_Jijie_LIU/test.txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QTextStream stream(&file);
    QString line_in;
    while( !stream.atEnd()){
        line_in = stream.readLine();
        mText->append(line_in);
    }
}
