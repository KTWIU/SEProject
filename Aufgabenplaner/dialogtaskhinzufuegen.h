#ifndef DIALOGTASKHINZUFUEGEN_H
#define DIALOGTASKHINZUFUEGEN_H
#include <QDialog>

namespace Ui {
class DialogTaskHinzufuegen;
}

class DialogTaskHinzufuegen : public QDialog                        //Dialogfenster zum hinzufügen einer neuen Aufgabe
{
    Q_OBJECT

public:
    explicit DialogTaskHinzufuegen(QWidget *parent = nullptr);      //Konstruktor
    ~DialogTaskHinzufuegen();                                       //Destruktor

private slots:

private:
    Ui::DialogTaskHinzufuegen *ui;
};

#endif // DIALOGTASKHINZUFUEGEN_H
