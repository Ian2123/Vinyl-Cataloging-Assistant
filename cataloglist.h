#ifndef CATALOGLIST_H
#define CATALOGLIST_H

#include <QString>

struct node
{
  QString title, author, grade, notes;
  int year;
  node *next;
};
typedef node * cataloglist;


void add_entry(cataloglist * qp, QString in_title, QString in_author, QString in_grade, QString in_notes, int in_year){
    node *n = new node;

    n->title = in_title;
    n->author = in_author;
    n->grade = in_grade;
    n->year = in_year;
    n->notes = in_notes;

    //Author Sort
    while(*qp != nullptr && in_author.compare((*qp)->author) < 0){
        qp = &((*qp)->next);
    }

    //Year Sort
    while(*qp != nullptr && (*qp)->year < in_year)
         qp = &((*qp)->next);

    n->next = *qp;
    *qp = n;
}


int remove_entry(cataloglist * qp, QString out_title, int out_year){
    node *n;

    while (*qp != nullptr && (QString::compare((*qp)->title, out_title) || (*qp)->year != out_year)){
        qp = &((*qp)->next);
    }

    if(*qp == nullptr) return 0;

    n = *qp;
    *qp = (*qp)->next;
    delete n;

    return 1;
}

void clear_collection(cataloglist * qp){
    node * next = *qp;

    while(*qp != nullptr){
        next = (*qp)->next;
        free(*qp);
        *qp = next;
    }
}

#endif // CATALOGLIST_H
