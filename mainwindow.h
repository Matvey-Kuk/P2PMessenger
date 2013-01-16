#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Класс главного окна с консолью и списком пиров.

#include <boxwithwires.h>

#include <QMainWindow>
#include <QString>

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    //Временно здесь, впоследствии в messengerConnectionProvider
    BoxWithWires* boxWithWires;
};

#endif // MAINWINDOW_H
