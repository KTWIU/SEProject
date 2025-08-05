#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogtaskbearbeiten.h"
#include "dialogtaskhinzufuegen.h"
#include "erledigteaufgabenliste.h"
#include "ueberfaelligeaufgaben.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QTextEdit>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)                                                         //Konstruktor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    taskController = new TaskController(&taskManager);                                          //dem controller das Modell (taskManager) übergeben
    taskController->load();                                                                     //Aufgaben beim Starten der Anwendung laden 
    zeigeAufgaben(taskController->getTasks());;                                                                        //Aktualisieren von Mapping & ListWidget

    ui->listWidget->clear();                                                                    //sicherstellen, dass Anzeige-Liste leer ist (nur GUI, nicht gespeicherten Aufgaben)
    guiToVectorIndex.clear();                                                                   //Mapping leeren


    const auto& tasks = taskController->getTasks();                                             //alle gespeicherten Aufgaben holen 
    for (int i = 0; i < tasks.size(); ++i)                                                      //Schleife über alle Aufgaben
    {
        const Task& t = tasks[i];
        if(!t.getIstErledigt())                                                                 //nur die offenen Aufgaben im mainwindow zeigen
        {
            QDate faellig = QDate::fromString(QString::fromStdString(t.getFaelligkeitsdatum()), "yyyy-MM-dd");
            QString statusText = (faellig.isValid() && faellig < QDate::currentDate()) ? "Überfällig" : "Offen";
            QString itemText = QString::fromStdString(t.getTitel()) + " | "
                               + QString::fromStdString(t.getBeschreibung()) + " | "
                               + QString::fromStdString(t.getFaelligkeitsdatum()) + " | "
                               + statusText;
            ui->listWidget->addItem(itemText);                                                  //Attribute jedes Tasks schreiben
            guiToVectorIndex.append(i);                                                         //Mapping der noch nicht erledigten Aufgaben für List MainWindow (sonst würden auch erledigte
        }                                                                                           //Indizes angezeigt werden)
    }
}

MainWindow::~MainWindow()                                                                       //Destruktor
{
    taskController->save();                                                                    //speichern vor dem beenden der Anwendung
    delete ui;
}

void MainWindow::on_pBAufgabeHinzufuegen_clicked()                                              //Methode: Logik für das hinzufügen einer Aufgabe (=extra Dialog)
{
    DialogTaskHinzufuegen dialog(this);                                                         //Erstellt Dialogfenster, setzt MainWindow als Elternfenster (=this) damit darüber angezeigt
    if (dialog.exec() == QDialog::Accepted)                                                     //wenn Dialog ausgeführt ist
    {
        QString titel = dialog.findChild<QLineEdit*>("titel")->text();                          //liest Inhalt aus Eingabefeld im Dialog
        QDate faelligkeitsdatum = dialog.findChild<QDateEdit*>("faelligkeitsdatum")->date();    //liest Inhalt aus Eingabefeld im Dialog
        QString beschreibung = dialog.findChild<QTextEdit*>("beschreibung")->toPlainText();     //liest Inhalt aus Eingabefeld im Dialog

        if(titel.isEmpty())                                                                     //Eingabevalidierung für den Titel gemäß Anforderungsdokument
        {
            QMessageBox::warning(this, "Fehler", "Titel ist leer!");
            return;
        };
        if(faelligkeitsdatum < QDate::currentDate())                                            //Eingabevalidierung für Datum gemäß Anforderungsdokument
        {
            QMessageBox::warning(this, "Fehler", "Datum liegt in der Vergangenheit!");
            return;
        };

        taskController->addAufgabe(titel.toStdString(), beschreibung.toStdString(), faelligkeitsdatum.toString("yyyy-MM-dd").toStdString());

        zeigeAufgaben(taskController->getTasks());;

    }
}


void MainWindow::on_pBAufgabeErledigt_clicked()                                                 //Methode: Logik für Aufgabe erledigt
{
    int guiIndex = ui->listWidget->currentRow();                                                //holt aktuell in Liste ausgewählte Aufgabe
    if(guiIndex >= 0)
    {
        int realIndex = guiToVectorIndex.at(guiIndex);                                          //Mapping auf echten Vector-Index!
        taskController->markiereAufgabeAlsErledigt(realIndex);
        delete ui->listWidget->takeItem(guiIndex);                                              //Aus der Liste (MainWindow) entfernen
        zeigeAufgaben(taskController->getTasks());;
    }
}

void MainWindow::on_pBErledigteA_clicked()                                                      //Methode: Logik für Liste der erledigten Aufgabenm
{
    erledigteAufgabenliste dialog(this);                                                        //Dialogfenster erstellen
    const auto& tasks = taskController->getTasks();

    for(const Task& t : tasks) {                                                                //Iteriert über alle Element
        if (t.getIstErledigt()) {
            dialog.addTaskToList(QString::fromStdString(t.getTitel()));                         //wenn erledigt, wird Aufgabe in die erledigt Liste eingefügt
        }
    }
    dialog.exec();                                                                              //Dialogfenster öffnen
}


void MainWindow::on_pBUeberfaelligeA_clicked()                                                  //Methode: Logik für Liste der überfälligen Aufgaben
{
    ueberfaelligeAufgaben dialog(this);                                                         //Dialog erstellen
    const auto& tasks = taskController->getTasks();                                                //vector mit Tasks

    QDate today = QDate::currentDate();                                                         //aktuelles Datum

    for(const Task& t : tasks)                                                                  //iteriert über Aufgaben
    {
        QDate faellig = QDate::fromString(QString::fromStdString(t.getFaelligkeitsdatum()), "yyyy-MM-dd");//holt Attribut Faelligkeitsdatum
        if(!t.getIstErledigt() && faellig.isValid() && faellig < today)                         //prüft ob noch nicht erledigt, faellig und mindestens von gestern
        {
            dialog.addTaskToList(QString::fromStdString(t.getTitel()));                         //mit Methode in Liste ueberfaelliger Aufgaben einfügen
        }
    }
    dialog.exec();
}


void MainWindow::on_pBAufgabeEntfernen_clicked()                                                //Methode: Aufgabe entfernen (komplett löschen)
{
    QListWidgetItem* item = ui->listWidget->currentItem();                                      //Referenz auf ausgewählte Aufgabe in Liste
    if(item)
    {
        int guiIndex = ui->listWidget->currentRow();
        int realIndex = guiToVectorIndex.at(guiIndex);
        if(guiIndex >= 0)
        {
            taskController->delAufgabe(realIndex);
            zeigeAufgaben(taskController->getTasks());;
        }
    }
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)                         //Methode: bearbeiten einer Aufgabe in mainWindow
{
    int guiIndex = ui->listWidget->row(item);                                                   //holt ausgewählte Aufgabe aus Liste
    if (guiIndex < 0 || guiIndex >= guiToVectorIndex.size())
    {
        return;
    };

    int realIndex = guiToVectorIndex.at(guiIndex);                                              //Mapping
    const Task& t = taskController->getTasks().at(realIndex);                                   //ausgewählte Aufgabe mit tatsächlichen Index holen

    DialogTaskBearbeiten dialog(this);                                                          //Bearbeiten Dialog erstellen (this = mainwindow)
    dialog.setTitel(QString::fromStdString(t.getTitel()));                                      //bisherige Attribute holen
    dialog.setBeschreibung(QString::fromStdString(t.getBeschreibung()));
    dialog.setFaelligkeitsdatum(QDate::fromString(QString::fromStdString(t.getFaelligkeitsdatum()), "yyyy-MM-dd"));

    if (dialog.exec() == QDialog::Accepted)
    {
        QString neuerTitel = dialog.findChild<QLineEdit*>("titel")->text();                     //neuen Attribute im Eingabefeld schreiben
        QString neueBeschreibung = dialog.findChild<QTextEdit*>("beschreibung")->toPlainText(); //Zeiger auf das Widget (benötigt findChild)
        QDate neuesDatum = dialog.findChild<QDateEdit*>("faelligkeitsdatum")->date();
        
        taskController->editAufgabe(realIndex, neuerTitel.toStdString(), neueBeschreibung.toStdString(), neuesDatum.toString("yyyy-MM-dd").toStdString());

        zeigeAufgaben(taskController->getTasks());;
    }
}

void MainWindow::zeigeAufgaben(const std::vector<Task>& aufgaben)
{
    ui->listWidget->clear();
    guiToVectorIndex.clear();

    QDate today = QDate::currentDate();
    for (int i = 0; i < aufgaben.size(); ++i)
    {
        const Task& t = aufgaben[i];
        if(!t.getIstErledigt())
        {
            QDate faellig = QDate::fromString(QString::fromStdString(t.getFaelligkeitsdatum()), "yyyy-MM-dd");
            QString statusText = (faellig.isValid() && faellig < today) ? "Überfällig" : "Offen";
            QString itemText = QString::fromStdString(t.getTitel()) + " | "
                               + QString::fromStdString(t.getBeschreibung()) + " | "
                               + QString::fromStdString(t.getFaelligkeitsdatum()) + " | "
                               + statusText;
            ui->listWidget->addItem(itemText);
            guiToVectorIndex.append(i);
        }
    }
}

void MainWindow::zeigeFehlermeldung(const std::string& meldung)
{
    QMessageBox::warning(this, "Fehler", QString::fromStdString(meldung));
}
