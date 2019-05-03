#ifndef SERIAL_H
#define SERIAL_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QList>

class Serial : public QWidget
{
    Q_OBJECT
public:
    explicit Serial(QWidget *parent = nullptr);

private:
    QSerialPort *m_serial;

signals:

public slots:
    void handleError(QSerialPort::SerialPortError error);
    void readData();
    void writeData();
};

#endif // SERIAL_H
