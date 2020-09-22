#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cataloglist.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

/* Global Variables */
bool saved = 1;
cataloglist collection;


/* MainWindow Setup */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* BUTTONS */
void MainWindow::on_InfoButton_clicked()
{
    infowindow = new InfoDialog(this);
    infowindow->setFixedSize(650,450);
    infowindow->setWindowTitle("Information");
    infowindow->show();
}

void MainWindow::on_ExitButton_clicked()
{
    if(saved){
        clear_collection(&collection);
        QApplication::quit();
    }
    else
    {
        QMessageBox::StandardButton reply;
        QString exit_quest = "Would you like to exit before saving?";

        reply = QMessageBox::question(this, "Vinyl Cataloging Assistant", exit_quest, QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            clear_collection(&collection);
            QApplication::quit();
        }
    }

}

void MainWindow::on_AddButton_clicked()
{
    add_dialog add_window;

    add_window.setFixedSize(400,175);
    add_window.setWindowTitle("Add Entry");
    add_window.setWindowIcon(QIcon(":/AddIcon/IMG/AddIcon.png"));

    if(add_window.exec() == QDialog::Accepted){
        QString add_title, add_artist, add_grade, add_year, add_notes;

        //Acquire entry info and add to sorted list
        add_title = add_window.getTmp_title();
        add_artist = add_window.getTmp_artist();
        add_grade = add_window.getTmp_grade();
        add_year = add_window.getTmp_year();
        add_notes = add_window.getTmp_notes();

        if(add_title == nullptr || add_artist == nullptr || add_year.toInt() <= 0)
            QMessageBox::critical(this, "Error!", "Invalid title, artist, or year.");
        else
        {
            add_entry(&collection, add_title, add_artist, add_grade, add_notes, add_year.toInt());

            //Clear list widget and print updated sorted list
            ui->CatalogListWidget->clear();
            cataloglist * current = &collection;

            while ((*current) != nullptr){
                ui->CatalogListWidget->addItem((*current)->title);
                ui->CatalogListWidget->addItem((*current)->author);
                ui->CatalogListWidget->addItem(QString::number((*current)->year));
                ui->CatalogListWidget->addItem((*current)->grade);
                ui->CatalogListWidget->addItem((*current)->notes);
                ui->CatalogListWidget->addItem("\n");
                current = &((*current)->next);
            }
            saved = 0;
        }
    }
}

void MainWindow::on_RemoveButton_clicked()
{
    remove_dialog remove_window;

    remove_window.setFixedSize(400,175);
    remove_window.setWindowTitle("Remove Entry");
    remove_window.setWindowIcon(QIcon(":/RemIcon/IMG/RemIcon.png"));

    if(remove_window.exec() == QDialog::Accepted){
        QString rem_title, rem_year;

        //Acquire entry info and remove from sorted list
        rem_title = remove_window.getTmp_title();
        rem_year = remove_window.getTmp_year();
        if(remove_entry(&collection, rem_title, rem_year.toInt()) == 0)
            QMessageBox::critical(this, "Error!", "No such entry could be found.");
        else
        {
            //Clear list widget and print updated sorted list
            ui->CatalogListWidget->clear();
            cataloglist * current = &collection;

            while ((*current) != nullptr){
                ui->CatalogListWidget->addItem((*current)->title);
                ui->CatalogListWidget->addItem((*current)->author);
                ui->CatalogListWidget->addItem(QString::number((*current)->year));
                ui->CatalogListWidget->addItem((*current)->grade);
                ui->CatalogListWidget->addItem((*current)->notes);
                ui->CatalogListWidget->addItem("\n");
                current = &((*current)->next);
            }
            saved = 0;
        }
    }
}

void MainWindow::on_SaveButton_clicked()
{
    QString out_filename = QFileDialog::getSaveFileName(this, tr("Save"), "", tr("Catalog (*.txt);;All Files (*)"));

    if(out_filename.isEmpty())
        return;
    else
    {
        QFile out_file(out_filename);

        if(!out_file.open(QIODevice::WriteOnly | QFile::Text)){
            QMessageBox::critical(this, "Error!", "Unable to open file.");
            out_file.errorString();
            return;
        }

        //Print from memory to out_file through out_text stream.
        QTextStream out_text(&out_file);
        cataloglist * current = &collection;
        while((*current) != nullptr){
            out_text << (*current)->title << "\n";
            out_text << (*current)->author << "\n";
            out_text << (*current)->year << "\n";
            out_text << (*current)->grade << "\n";
            out_text << (*current)->notes << "\n";
            out_text << "\n";
            out_file.flush();
            current = &((*current)->next);
        }
        out_file.close();
    }
    saved = 1;
}

void MainWindow::on_ImportButton_clicked()
{
    QString in_filename = QFileDialog::getOpenFileName(this, tr("Import"), "", tr("Catalog (*.txt);;All Files (*)"));
    if(in_filename.isEmpty()){
        return;
    }
    else
    {
        QFile in_file(in_filename);
        QString in_title, in_author, in_year, in_grade, in_notes, newlinecatch;

        if(!in_file.open(QIODevice::ReadOnly | QFile::Text)){
            QMessageBox::critical(this, "Error!", "Unable to open file.");
            in_file.errorString();
            return;
        }

        //Read data from in_file into memory through in_text stream.
        QTextStream in_text(&in_file);
        clear_collection(&collection);
        while((in_title = in_text.readLine(0)) != nullptr){
            in_author = in_text.readLine(0);
            in_year = in_text.readLine(0);
            in_grade = in_text.readLine(0);
            in_notes = in_text.readLine(0);
            newlinecatch = in_text.readLine(0);
            add_entry(&collection, in_title, in_author, in_grade, in_notes, in_year.toInt());
        }
        in_file.close();

        //Print to main window
        ui->CatalogListWidget->clear();
        cataloglist * current = &collection;
        while ((*current) != nullptr){
            ui->CatalogListWidget->addItem((*current)->title);
            ui->CatalogListWidget->addItem((*current)->author);
            ui->CatalogListWidget->addItem(QString::number((*current)->year));
            ui->CatalogListWidget->addItem((*current)->grade);
            ui->CatalogListWidget->addItem((*current)->notes);
            ui->CatalogListWidget->addItem("\n");
            current = &((*current)->next);
        }
        saved = 1;
    }
}
