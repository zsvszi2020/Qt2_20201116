#include "widget.h"
#include "ui_widget.h"
#include "bankdialog.h"
#include <QDebug>
#include <math.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    createUI();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createUI()
{
    ui->tableWidget->setColumnCount(2)  ;
    ui->tableWidget->setRowCount(10)    ;
    QStringList header                  ;
    header << "Év" << "Hozam"           ;
    ui->tableWidget->setHorizontalHeaderLabels(header) ;
}


void Widget::on_pushButton_clicked()
{
      BankDialog dialog ;
      dialog.setModal(true) ;
      if (dialog.exec()==QDialog::Accepted)
      {
          int alap = dialog.getAlap() ;
          int kamat = dialog.getKamat() ;
          int ev = dialog.getEv() ;

          for (int i = 1; i <= ev ; i++)
          {
              ui->tableWidget->setItem(i-1,0,new QTableWidgetItem(QString::number(i)+" év")) ;
                       float hozam = alap * pow((kamat+100.0)/100.0,i) ;
              ui->tableWidget->setItem(i-1,1,new QTableWidgetItem(QString::number(hozam)+" Ft")) ;
          }
      }
}
