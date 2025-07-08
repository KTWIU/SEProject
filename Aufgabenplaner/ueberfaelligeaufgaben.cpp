#include "ueberfaelligeaufgaben.h"
#include "ui_ueberfaelligeaufgaben.h"

ueberfaelligeAufgaben::ueberfaelligeAufgaben(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ueberfaelligeAufgaben)
{
    ui->setupUi(this);
}

ueberfaelligeAufgaben::~ueberfaelligeAufgaben()                         //Destruktor
{
    delete ui;
}

void ueberfaelligeAufgaben::addTaskToList(const QString& text)          //Methode für hinzufügen in ueberfällige Liste
{
    ui->listWidgetUeberfaellige->addItem(text);                         //text als neuer Eintrag in der Liste
}
