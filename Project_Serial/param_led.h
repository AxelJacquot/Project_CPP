#ifndef PARAM_LED_H
#define PARAM_LED_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>

class param_led : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* box;
    QLabel* label;
    QComboBox* combo;
    QPushButton* button;
public:
    explicit param_led(QWidget *parent = nullptr);

signals:

public slots:
    void CurrentChanged(int);
};

#endif // PARAM_LED_H
