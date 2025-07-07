#include "ueberfaelligeaufgaben.h"
#include "ui_ueberfaelligeaufgaben.h"

ueberfaelligeAufgaben::ueberfaelligeAufgaben(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ueberfaelligeAufgaben)
{
    ui->setupUi(this);
}

ueberfaelligeAufgaben::~ueberfaelligeAufgaben()
{
    delete ui;
}

void ueberfaelligeAufgaben::addTaskToList(const QString& text)
{
    ui->listWidgetUeberfaellige->addItem(text);
}
