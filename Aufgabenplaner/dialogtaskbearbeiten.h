#ifndef DIALOGTASKBEARBEITEN_H
#define DIALOGTASKBEARBEITEN_H                                  //Header Guard
#include <QDialog>                                              //Implementierung von Dialogfenster

namespace Ui {
class DialogTaskBearbeiten;
}

class DialogTaskBearbeiten : public QDialog                     //Dialogfenster zum bearbeiten der ausgewählten Aufgabe, erbt aus QDialog
{
    Q_OBJECT

public:
    explicit DialogTaskBearbeiten(QWidget *parent = nullptr);   //Konstruktor Dialogfenster
    ~DialogTaskBearbeiten();                                    //Destruktor, gibt Speicher frei


    void setTitel(const QString& titel);                        //Methode: um später bereits vorhandene Werte in die Felder des Dialogs zu laden
    void setBeschreibung(const QString& beschreibung);          //Methode: um später bereits vorhandene Werte in die Felder des Dialogs zu laden
    void setFaelligkeitsdatum(const QDate& faelligkeitsdatum);  //Methode: um später bereits vorhandene Werte in die Felder des Dialogs zu laden

private:
    Ui::DialogTaskBearbeiten *ui;
};

#endif // DIALOGTASKBEARBEITEN_H
