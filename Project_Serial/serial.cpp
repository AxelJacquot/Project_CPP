#include "serial.h"
#include <QDebug>

Serial::Serial(QWidget *parent)
{
    m_serial=new QSerialPort(this);
    m_serial->setPortName("/dev/ttyACM0");
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if(!m_serial->open(QIODevice::ReadOnly)) {
        qDebug() <<QObject::tr("Je ne peux pas ouvrir le port série %1...").arg(m_serial->portName());
    }
    connect(    m_serial,static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
                this,&Serial::handleError);
    connect(m_serial,&QSerialPort::readyRead,this,&Serial::readData);
}

void Serial::handleError(QSerialPort::SerialPortError error)
{
    if(error==QSerialPort::ResourceError) {
        qDebug() <<QObject::tr("Erreur critique : %1").arg(m_serial->errorString());
    }
}

void Serial::readData()
{
    QByteArray buf=m_serial->readAll();
    qDebug() <<buf;
}

void Serial::writeData()
{
    const char *data = "Test";
    qint64 len = 4;
    m_serial->write(data, len);
}
