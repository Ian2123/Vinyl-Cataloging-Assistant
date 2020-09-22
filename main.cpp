/*
 * Vinyl Cataloging Assistant
 *      by Ian M. Isely
 *
 * ----BACKGROUND----
 * I started creation of this program sometime in late May, 2020 and completed it
 * on July 2nd, 2020. I wanted to expand my knowledge into GUI programming while
 * also practicing with a language I know and love which is why I decided to
 * use Qt to create this. At the moment, Qt is a popular GUI programming framework
 * based on C++ which proved to be perfect in achieving my goal stated above.
 * In order to give myself some more motivation, other than to just learn Qt, I
 * thought long about what exactly I wanted to create and out of my love for the
 * record collecting hobby the idea for this program as you see it was born.
 * ------------------
 *
 * ----DESCRIPTION---
 * This program allows a user to add and remove entries to their record collection
 * which is displayed to them in a list. Entire collections can be saved to, and
 * imported from, their PC as a .txt file. The collection is stored in memory as
 * a sorted linked list which the definition of can be found in "cataloglist.h"
 * and traversed from there.
 * ------------------
*/
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication cataloger(argc, argv);
    MainWindow w;

    w.setWindowTitle("Vinyl Cataloging Assistant");
    w.setWindowIcon(QIcon(":/MWIcon/IMG/MWIcon.png"));
    w.resize(800,400);
    w.show();
    return cataloger.exec();
}
