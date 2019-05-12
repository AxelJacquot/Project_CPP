#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    init_port();
    ui->setupUi(this);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),this,SLOT(transmitCombo(int)));
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(transmitCAN()));
    connect(m_serial,SIGNAL(readyRead()),this,SLOT(readData()));
}

void MainWindow::init_port()
{
    m_serial=new QSerialPort(this);
    m_serial->setPortName("/dev/ttyUSB0");
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if(!m_serial->open(QIODevice::ReadWrite)) {
        qDebug() <<QObject::tr("Je ne peux pas ouvrir le port série %1...").arg(m_serial->portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::transmitCombo(int value)
{
    QByteArray byte;
    byte.clear();
    byte.append(value);
    m_serial->write(byte);
}

void MainWindow::transmitCAN()
{
    int value = 50;
    QByteArray byte;
    byte.clear();
    byte.append(value);
    m_serial->write(byte);

}

void MainWindow::readData()
{
     QByteArray buf=m_serial->readAll();

     QDataStream in(buf); //< Attach a read-only stream to it
     in.setByteOrder(QDataStream::LittleEndian); //< Set the proper byte order
     qint16 result_tmp; //< The result you want
     in >> result_tmp; //< Just read it from the stream

     double result = 0;
     result = 3.3 * (result_tmp/255);

    ui->lcdNumber->display(result);
}