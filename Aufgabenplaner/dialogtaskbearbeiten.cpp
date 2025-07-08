#include "dialogtaskbearbeiten.h"
#include "ui_dialogtaskbearbeiten.h"

DialogTaskBearbeiten::DialogTaskBearbeiten(QWidget *parent)                             //Konstruktor um Task zu bearbeiten
    : QDialog(parent)
    , ui(new Ui::DialogTaskBearbeiten)
{
    ui->setupUi(this);

    connect(ui->AufgabeSpeichernDialog, &QPushButton::clicked, this, &QDialog::accept); //Slot für Button "Aufgabe Speichern" auf Dialog
    connect(ui->AbbrechenDialog, &QPushButton::clicked, this, &QDialog::reject);        //Slot für Button "Abbrechen" auf Dialog
}

DialogTaskBearbeiten::~DialogTaskBearbeiten()                                           //Destruktor
{
    delete ui;
}

void DialogTaskBearbeiten::setTitel(const QString& titel)                               //Setter Methode für Titel
{
    ui->titel->setText(titel);                                                          //schreibt Text des bisherigen Titels in das Eingabefeld
}

void DialogTaskBearbeiten::setBeschreibung(const QString& beschreibung)                 //Setter Methode für Beschreibung
{
    ui->beschreibung->setPlainText(beschreibung);                                       //schreibt Text der bisherigen Beschreibung in das Eingabefeld
}

void DialogTaskBearbeiten::setFaelligkeitsdatum(const QDate& faelligkeitsdatum)         //Setter Methode für Datum
{
    ui->faelligkeitsdatum->setDate(faelligkeitsdatum);                                  //Schreibt bsiher eingestelltes Datum in das Datumsfeld
}
