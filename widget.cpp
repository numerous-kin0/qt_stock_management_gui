#include "widget.h"
#include "./ui_widget.h"
#include <QString>
#include <QMessageBox>
#include "item.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_okButton_clicked()
{
    int value = ui->stockSpinBox->value();

    double value1 = ui->priceSpinBox->value();

    QString barcodeString = ui->barcodeLineEdit->text();

    QString descriptionString = ui->descriptionEdit->text();

    if (barcodeString.isEmpty())
    {
        QMessageBox::warning(nullptr,"Warning","Barcode is empty!");
    }
    else if (descriptionString.isEmpty())
    {
        QMessageBox::warning(nullptr,"Warning","Description is empty!");
    }
    else if (value == 0)
    {
         QMessageBox::warning(nullptr, "Warning", "Value for stock cannot be 0!");
    }
    else if (value1 == 0)
    {
          QMessageBox::warning(nullptr, "Warning", "Value for price cannot be 0!");
    }

    if (value != 0 && value1 != 0 && barcodeString != "" && descriptionString != "")
    {
          Item someItem(barcodeString, descriptionString, value, value1);
    }

}


void Widget::on_cancelButton_clicked()
{
    //QObject::connect(&cancelButton, &QPushButton::clicked, &widge, &QDialog::reject);

}

