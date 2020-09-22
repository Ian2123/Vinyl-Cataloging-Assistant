#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "infodialog.h"
#include "add_dialog.h"
#include "remove_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_InfoButton_clicked();

    void on_ExitButton_clicked();

    void on_AddButton_clicked();

    void on_RemoveButton_clicked();

    void on_SaveButton_clicked();

    void on_ImportButton_clicked();

private:
    Ui::MainWindow *ui;
    InfoDialog *infowindow;
};
#endif // MAINWINDOW_H
