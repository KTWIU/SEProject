#include "dialogtaskhinzufuegen.h"
#include "ui_dialogtaskhinzufuegen.h"

DialogTaskHinzufuegen::DialogTaskHinzufuegen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTaskHinzufuegen)
{
    ui->setupUi(this);
}

DialogTaskHinzufuegen::~DialogTaskHinzufuegen()
{
    delete ui;
}
