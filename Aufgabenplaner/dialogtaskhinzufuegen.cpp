#include "dialogtaskhinzufuegen.h"
#include "ui_dialogtaskhinzufuegen.h"

DialogTaskHinzufuegen::DialogTaskHinzufuegen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTaskHinzufuegen)
{
    ui->setupUi(this);

    connect(ui->AufgabeSpeichernDialog, &QPushButton::clicked, this, &QDialog::accept); //
    connect(ui->AbbrechenDialog, &QPushButton::clicked, this, &QDialog::reject);
}

DialogTaskHinzufuegen::~DialogTaskHinzufuegen()
{
    delete ui;
}
