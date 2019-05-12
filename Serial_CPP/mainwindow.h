#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void init_port();
    ~MainWindow();

public slots:
    void transmitCombo(int);
    void transmitCAN(void);
    void readData();

private:
    Ui::MainWindow *ui;
    QSerialPort* m_serial;  //Objet de la communication série
};

#endif // MAINWINDOW_H
