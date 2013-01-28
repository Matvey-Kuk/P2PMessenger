#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    boxWithWires=new BoxWithWires(this);

    upTimer.setInterval(1*1000);
    QObject::connect(&upTimer, SIGNAL(timeout()), this,SLOT(up()));
    upTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    boxWithWires->createConnection(ui->lineEdit->text().section(':',0,0),ui->lineEdit->text().section(':',1,1).toInt());
}

void MainWindow::up(){
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Server port:"+QString::number(GlobalCondition::serverPort));
    for(int i=0; i<boxWithWires->coutConnections(); i++){
        ui->plainTextEdit->appendPlainText(boxWithWires->getConnection(i)->getIp()+":"+QString::number(boxWithWires->getConnection(i)->getPort()));
    }
}
