#include "remove_dialog.h"
#include "ui_remove_dialog.h"

remove_dialog::remove_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remove_dialog)
{
    ui->setupUi(this);
}

remove_dialog::~remove_dialog()
{
    delete ui;
}

QString remove_dialog::getTmp_year() const
{
    return ui->year_line->text();
}

QString remove_dialog::getTmp_title() const
{
    return ui->title_line->text();
}
