#include "infodialog.h"
#include "ui_infodialog.h"
#include <QMessageBox>

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_QtInfoButton_clicked()
{
    QMessageBox::aboutQt(this, "Qt Information");
}
