#include "add_dialog.h"
#include "ui_add_dialog.h"

add_dialog::add_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_dialog)
{
    ui->setupUi(this);

}

add_dialog::~add_dialog()
{
    delete ui;
}

QString add_dialog::getTmp_notes() const
{
    return ui->line_notes->text();
}

QString add_dialog::getTmp_year() const
{
    return ui->line_year->text();
}

QString add_dialog::getTmp_grade() const
{
    return ui->line_grade->text();
}

QString add_dialog::getTmp_artist() const
{
    return ui->line_artist->text();
}

QString add_dialog::getTmp_title() const
{
    return ui->line_title->text();
}
