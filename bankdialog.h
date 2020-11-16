#ifndef BANKDIALOG_H
#define BANKDIALOG_H

#include <QDialog>

namespace Ui {
class BankDialog;
}

class BankDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BankDialog(QWidget *parent = nullptr);
    ~BankDialog()   ;
    int getAlap()   ;
    int getKamat()  ;
    int getEv()     ;

private:
    Ui::BankDialog *ui;
};

#endif // BANKDIALOG_H
