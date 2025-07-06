#ifndef DIALOGTASKHINZUFUEGEN_H
#define DIALOGTASKHINZUFUEGEN_H

#include <QDialog>

namespace Ui {
class DialogTaskHinzufuegen;
}

class DialogTaskHinzufuegen : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTaskHinzufuegen(QWidget *parent = nullptr);
    ~DialogTaskHinzufuegen();

private:
    Ui::DialogTaskHinzufuegen *ui;
};

#endif // DIALOGTASKHINZUFUEGEN_H
