#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int money){
    this->money += money;
    ui->lcdNumber->display(this->money);
    if (this->money >= 100) {
        ui->pbCoffee->setEnabled(true);
        ui->pbCoffee->repaint();
    }
    if (this->money >= 150) {
        ui->pbTea->setEnabled(true);
        ui->pbTea->repaint();
    }
    if (this->money >= 200) {
        ui->pbCoke->setEnabled(true);
        ui->pbCoke->repaint();
    }
}

void Widget::on_pbCoffee_clicked()
{
    if (this->money-100 < 0) {
        ui->pbCoffee->setEnabled(false);
        ui->pbCoffee->repaint();
    }else
        changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    if (this->money-150 < 0) {
        ui->pbTea->setEnabled(false);
        ui->pbTea->repaint();
    }else
        changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    if (this->money-200 < 0) {
        ui->pbCoke->setEnabled(false);
        ui->pbCoke->repaint();
    }else
        changeMoney(-200);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    int tmp = money;
    int count[4] = {0, };

    while(tmp){
        if (tmp >= 500) {
            count[0]++;
            tmp -= 500;
        }
        else if (tmp >= 100) {
            count[1]++;
            tmp -= 100;
        }else if (tmp >= 50) {
            count[2]++;
            tmp -= 50;
        }else {
            count[3]++;
            tmp -= 10;
        }
    }
    this->money = 0;
    ui->lcdNumber->display(0);
    QString ret = QString("500 : %1\n100 : %2\n50 : %3\n10 : %4").arg(count[0]).arg(count[1]).arg(count[2]).arg(count[3]);
    msg.information(nullptr, "How much money was returned", ret);
}
