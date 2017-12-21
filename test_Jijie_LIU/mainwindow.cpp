#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //set the window
    this->setWindowTitle(tr("Test of Kiwix"));
    //set the name of the window
    this->resize(320, 200);
    //set the size of the window
    QPalette palette = this->palette();
    //use the palette to set the background color of the window
    palette.setColor(QPalette::Window, QColor(255, 255, 255));
    //set the color white
    this->setPalette(palette);
    //comfirm the color setting on the window

    //We can't add QHBoxLayout directly to the window, it should be added in the Qwidget
    //so I create a Qwidget to put QHBoxLayout into it, and set Qwidget at the middle of the window
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    //add Button
    mButton = new QPushButton("Read",this);
    //create the button named "Read"
    connect(mButton,SIGNAL (released()),this,SLOT(handleButton()));
    //connect the button with the function handleButton()

    //add the TextEdit to see the text we have read
    mText = new QTextEdit();
    //create the TextEdit
    mText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //we will not see scroll horizontal bar.
    mText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //we can see the scroll vertical bar.
    mText->show();

    //Use QVBoxlayout to put the button and the textedit together
    mBox = new QVBoxLayout(centralWidget);
    mBox->addWidget(mText);
    mBox->addWidget(mButton);
}

MainWindow::~MainWindow()
{

}

//When we click the button, we call this function, and then this function read the text.
void MainWindow::handleButton(){
    //I use a QFileDiaglog to choose a file to read
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::AnyFile);
    QString mFiles = fileDialog->getOpenFileName(this,tr("Open files"),"/Users/enzoliu");
    QFile file(mFiles);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QTextStream stream(&file);//put the file into a stream to read it
    QString line_in;//It stocks the words of each line
    int pos = 20;//The first place where we insert \n. We have 20 char before it, line_in[0 - 19]
    while( !stream.atEnd()){
        line_in = stream.readLine();
        while(pos < line_in.size()){
            line_in.insert(pos,"\n");
            pos += 21;//between two \n, we should have 20 char. So I add 21.
        }
        mText->append(line_in);//We add a line into mText to show it
        pos = 20;//set pos = 20 for the next line_in
    }
}
