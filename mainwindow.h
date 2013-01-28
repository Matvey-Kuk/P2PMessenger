#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//����� �������� ���� � �������� � ������� �����.

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

    //���������� �� �������
    void up();

private:
    Ui::MainWindow *ui;

    //�������� �����, ������������ � messengerConnectionProvider
    BoxWithWires* boxWithWires;

    //������ ���������� ���������
    QTimer upTimer;
};

#endif // MAINWINDOW_H
