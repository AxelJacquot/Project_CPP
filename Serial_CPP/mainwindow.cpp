#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    init_port();    //Initialisation de la communication série
    ui->setupUi(this);  //Création de l'interface
    //Connection du comboBox à la communication série pour la sélection des leds
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),this,SLOT(transmitCombo(int)));
    //Connection du Bouton CAN à la communication série pour la demande de la tension mesurée
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(transmitCAN()));
    //Connection permettant l'affichage des données reçues
    connect(m_serial,SIGNAL(readyRead()),this,SLOT(readData()));
}

void MainWindow::init_port()    //Fonction d'initialisation de la communication série
{
    m_serial=new QSerialPort(this);     //Création de l'objet communication série
    //Signifit que nous allons communiqué avec un appareil se trouvant à cette adresse
    m_serial->setPortName("/dev/ttyUSB0");
    m_serial->setBaudRate(QSerialPort::Baud115200); //Réglage de la vitesse de la communication
    m_serial->setDataBits(QSerialPort::Data8);  //Réglage de la taille de la donnée
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if(!m_serial->open(QIODevice::ReadWrite)) {     //Ouvre la communication série et test si elle est possible
        qDebug() <<QObject::tr("Je ne peux pas ouvrir le port série %1...").arg(m_serial->portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::transmitCombo(int value)   //Slot transmettant la ou les leds à allumer
{
    //Traitement de la donnée pour la mettre dans le bon format
    QByteArray byte;
    byte.clear();
    byte.append(value);

    m_serial->write(byte);//Envoie de la donnée
}

void MainWindow::transmitCAN()  //Slot transmettant la demande de la tension mesurée
{
    int value = 50;     //Correspond à la valeur se trouvant sur le programme de la STM32

    QByteArray byte;    //Traitement de la donnée pour la mettre dans le bon format
    byte.clear();
    byte.append(value);

    m_serial->write(byte);  //Envoie de la donnée
}

void MainWindow::readData() //Slot récupérant la donnée se trouvant sur le bus
{
     QByteArray buf=m_serial->readAll();    //Récupération de la donnée

     unsigned char result_tmp = buf[0];
     buf.clear();

     double result = 0;
     result = 3.3 * ((double)result_tmp/255);   //Calcul de la tension reçu

    ui->lcdNumber->display(result);     //Affichage de la tension reçu
}
