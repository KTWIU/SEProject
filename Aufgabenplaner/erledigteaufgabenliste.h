#ifndef ERLEDIGTEAUFGABENLISTE_H
#define ERLEDIGTEAUFGABENLISTE_H

#include <QDialog>

namespace Ui {
class erledigteAufgabenliste;
}

class erledigteAufgabenliste : public QDialog                       //Dialogfenster der erledigten Aufgaben
{
    Q_OBJECT

public:
    void addTaskToList(const QString& text);                        //Methode um Aufgaben in die Liste einzufügen
    explicit erledigteAufgabenliste(QWidget *parent = nullptr);     //Kosntruktor
    Ui::erledigteAufgabenliste *getUi() {return ui; }
    ~erledigteAufgabenliste();                                      //Destruktor

private:
    Ui::erledigteAufgabenliste *ui;
};

#endif // ERLEDIGTEAUFGABENLISTE_H
