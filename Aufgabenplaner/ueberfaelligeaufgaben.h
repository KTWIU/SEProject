#ifndef UEBERFAELLIGEAUFGABEN_H
#define UEBERFAELLIGEAUFGABEN_H
#include <QDialog>

namespace Ui {
class ueberfaelligeAufgaben;
}

class ueberfaelligeAufgaben : public QDialog                        //Klasse für den Dialog der überfälligen Aufgaben
{
    Q_OBJECT

public:
    void addTaskToList(const QString& text);                        //Methode: Fügt Aufgabe in die Liste der erledigten Aufgaben (nachdem Datum überschritten)
    explicit ueberfaelligeAufgaben(QWidget *parent = nullptr);      //Konstruktor
    ~ueberfaelligeAufgaben();                                       //Destruktor

private:
    Ui::ueberfaelligeAufgaben *ui;
};

#endif // UEBERFAELLIGEAUFGABEN_H
