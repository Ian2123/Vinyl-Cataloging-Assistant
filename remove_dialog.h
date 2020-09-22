#ifndef REMOVE_DIALOG_H
#define REMOVE_DIALOG_H

#include <QDialog>

namespace Ui {
class remove_dialog;
}

class remove_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit remove_dialog(QWidget *parent = nullptr);
    ~remove_dialog();
    QString tmp_title, tmp_year;

    QString getTmp_title() const;

    QString getTmp_year() const;

private:
    Ui::remove_dialog *ui;
};

#endif // REMOVE_DIALOG_H
