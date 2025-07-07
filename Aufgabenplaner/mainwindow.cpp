#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogtaskhinzufuegen.h"
#include "erledigteaufgabenliste.h"
#include "ueberfaelligeaufgaben.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QTextEdit>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Aufgaben beim Starten der Anwendung laden
    taskManager.loadAufgaben();
    const auto& tasks = taskManager.getTasks();
    for(const Task& t : tasks)
    {
        if(!t.getIstErledigt()) //nur die offenen Aufgaben im mainwindow zeigen
        {
            QString itemText = QString::fromStdString(t.getTitel()) + " | "
                             + QString::fromStdString(t.getBeschreibung()) + " | "
                             + QString::fromStdString(t.getFaelligkeitsdatum()) + " | "
                               + "Offen";
            ui->listWidget->addItem(itemText);
        }
    }
}

MainWindow::~MainWindow()
{
    taskManager.saveAufgaben(); //speichern vor dem beenden der Anwendung
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}


void MainWindow::on_pBAufgabeHinzufuegen_clicked()
{
    DialogTaskHinzufuegen dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        //Eingabe auslesen
        QString titel = dialog.findChild<QLineEdit*>("titel")->text();
        QDate faelligkeitsdatum = dialog.findChild<QDateEdit*>("faelligkeitsdatum")->date();
        QString beschreibung = dialog.findChild<QTextEdit*>("beschreibung")->toPlainText();

        //Eingabevalidierung
        if(titel.isEmpty())
        {
            QMessageBox::warning(this, "Fehler", "Titel ist leer!");
            return;
        };
        if(faelligkeitsdatum < QDate::currentDate())
        {
            QMessageBox::warning(this, "Fehler", "Datum liegt in der Vergangenheit!");
            return;
        };

        //Aufgabe anlegen, index regelt TaskManager
        taskManager.addAufgabe(Task(0, titel.toStdString(), beschreibung.toStdString(), faelligkeitsdatum.toString("yyyy-MM-dd").toStdString(), false));

        //speichern, nachdem eine Aufgabe hinzugefügt wurde
        taskManager.saveAufgaben();

        //Updated das GUI mit der letzten hiinzugefügten Aufgabe
        const auto& tasks = taskManager.getTasks();
        const Task& t = tasks.back();
        QString itemText = QString::fromStdString(t.getTitel()) + " | "
                           + QString::fromStdString(t.getBeschreibung()) + " | "
                           + QString::fromStdString(t.getFaelligkeitsdatum()) + " | "
                           + (t.getIstErledigt() ? "Erledigt" : "Offen");
        ui->listWidget->addItem(itemText);
    }
}


void MainWindow::on_pBAufgabeErledigt_clicked()
{
    int idx = ui->listWidget->currentRow();
    if(idx >= 0)
    {
        //Im TaskManager als erledigt markieren
        taskManager.getTasks().at(idx).setIstErledigt(true);

        //Aus der Liste entfernen
        delete ui->listWidget->takeItem(idx);

        //Speichern nachdem eine Aufgabe erledigt
        taskManager.saveAufgaben();
    }
}

void MainWindow::on_pBErledigteA_clicked()
{
    erledigteAufgabenliste dialog(this);
    const auto& tasks = taskManager.getTasks();

    for(const Task& t : tasks) {
        if (t.getIstErledigt()) {
            dialog.addTaskToList(QString::fromStdString(t.getTitel()));
        }
    }
    dialog.exec();
}


void MainWindow::on_pBUeberfaelligeA_clicked()
{
    ueberfaelligeAufgaben dialog(this);
    const auto& tasks = taskManager.getTasks();

    QDate today = QDate::currentDate();

    for(const Task& t : tasks)
    {
        QDate faellig = QDate::fromString(QString::fromStdString(t.getFaelligkeitsdatum()), "yyyy-MM-dd");
        if(!t.getIstErledigt() && faellig.isValid() && faellig < today)
        {
            dialog.addTaskToList(QString::fromStdString(t.getTitel()));
        }
    }
    dialog.exec();
}


void MainWindow::on_pBAufgabeEntfernen_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if(item)
    {
        int idx = ui->listWidget->currentRow();
        if(idx >= 0)
        {
            delete ui->listWidget->takeItem(idx); //Aus der GUI entfernen

            taskManager.delAufgabe(idx); //Aus TaskManager-Vector entfernen (über Index)
            taskManager.saveAufgaben(); //nach Entfernen einer Aufgabe speichern
        }
    }
}

