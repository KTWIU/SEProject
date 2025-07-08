#include "erledigteaufgabenliste.h"
#include "ui_erledigteaufgabenliste.h"

erledigteAufgabenliste::erledigteAufgabenliste(QWidget *parent)     //Konstruktor
    : QDialog(parent)
    , ui(new Ui::erledigteAufgabenliste)
{
    ui->setupUi(this);
}

erledigteAufgabenliste::~erledigteAufgabenliste()                   //Destruktor
{
    delete ui;
}

void erledigteAufgabenliste::addTaskToList(const QString& text){    //Methode: um erledigte Aufgabe aus Aufgabenliste in die Liste zu verschieben (Referenz um nicht jedes mal Kopieren zu müssen)
    ui->listWidgetErledigteAufgaben->addItem(text);                 //Zeigt text als neuen Eintrag in der Liste der erledigten Aufgaben an
}
