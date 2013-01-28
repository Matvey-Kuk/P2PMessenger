#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Класс главного окна с консолью и списком пиров.

#include <boxwithwires.h>
#include <globalcondition.h>

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

    //Обновление по таймеру
    void up();

private:
    Ui::MainWindow *ui;

    //Временно здесь, впоследствии в messengerConnectionProvider
    BoxWithWires* boxWithWires;

    //Таймер обновления состояния
    QTimer upTimer;
};

#endif // MAINWINDOW_H
