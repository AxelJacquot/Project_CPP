#include "param_led.h"

param_led::param_led( QWidget *parent) : QWidget(parent)
{
    box = new QHBoxLayout(this);
    this->setGeometry(0,0,200,50);
    this->setFixedHeight(50);

    label = new QLabel();
    label->setText("Choix Led");

    box->addWidget(label);

    combo = new QComboBox();
    combo->addItem("Aucune");
    combo->addItem("Rouge");
    combo->addItem("Orange");
    combo->addItem("Bleu");
    combo->addItem("Vert");
    combo->addItem("Toutes");
    combo->addItem("Vert + Orange");
    combo->addItem("Bleu + Rouge");

    box->addWidget(combo);

    connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(CurrentChanged(int)));
}

void param_led::CurrentChanged(int)
{

}

