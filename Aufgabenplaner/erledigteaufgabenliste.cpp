#include "erledigteaufgabenliste.h"
#include "ui_erledigteaufgabenliste.h"

erledigteAufgabenliste::erledigteAufgabenliste(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::erledigteAufgabenliste)
{
    ui->setupUi(this);
}

erledigteAufgabenliste::~erledigteAufgabenliste()
{
    delete ui;
}

void erledigteAufgabenliste::addTaskToList(const QString& text){
    ui->listWidgetErledigteAufgaben->addItem(text);
}
