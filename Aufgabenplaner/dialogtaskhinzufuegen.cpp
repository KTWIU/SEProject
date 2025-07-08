#include "dialogtaskhinzufuegen.h"
#include "ui_dialogtaskhinzufuegen.h"

DialogTaskHinzufuegen::DialogTaskHinzufuegen(QWidget *parent)                           //Konstruktor
    : QDialog(parent)
    , ui(new Ui::DialogTaskHinzufuegen)
{
    ui->setupUi(this);

    connect(ui->AufgabeSpeichernDialog, &QPushButton::clicked, this, &QDialog::accept); //Slot für Button "Aufgabe Speichern" auf Dialog
    connect(ui->AbbrechenDialog, &QPushButton::clicked, this, &QDialog::reject);        //Slot für Button "Abbrechen" auf Dialog
}

DialogTaskHinzufuegen::~DialogTaskHinzufuegen()                                         //Destruktor
{
    delete ui;
}
