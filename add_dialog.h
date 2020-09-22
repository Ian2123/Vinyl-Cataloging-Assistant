#ifndef ADD_DIALOG_H
#define ADD_DIALOG_H

#include <QDialog>

namespace Ui {
class add_dialog;
}

class add_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_dialog(QWidget *parent = nullptr);
    ~add_dialog();
    QString tmp_title, tmp_artist, tmp_grade, tmp_year, tmp_notes;

    QString getTmp_title() const;

    QString getTmp_artist() const;

    QString getTmp_grade() const;

    QString getTmp_year() const;

    QString getTmp_notes() const;

private slots:


private:
    Ui::add_dialog *ui;
};

#endif // ADD_DIALOG_H
