#include "bankdialog.h"
#include "ui_bankdialog.h"

BankDialog::BankDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankDialog)
{
    ui->setupUi(this);
}

BankDialog::~BankDialog()
{
    delete ui;
}

int BankDialog::getAlap()
{
    return ui->comboBox->currentText().toInt() ;
}

int BankDialog::getKamat()
{
    return ui->comboBox_2->currentText().toInt() ;
}

int BankDialog::getEv()
{
    return ui->spinBox->value() ;
}
