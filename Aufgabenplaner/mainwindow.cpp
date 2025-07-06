#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogtaskhinzufuegen.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}


void MainWindow::on_pBAufgabeHinzufuegen_clicked()
{
    DialogTaskHinzufuegen dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Werte holen und Aufgabe hinzufügen
        QString titel = dialog.findChild<QLineEdit*>("titel")->text();
        QDate faelligkeitsdatum = dialog.findChild<QDateEdit*>("faelligkeitsdatum")->date();
        QString beschreibung = dialog.findChild<QTextEdit*>("beschreibung")->toPlainText();
        // Hier Aufgabenliste etc. erweitern!
    }
}

