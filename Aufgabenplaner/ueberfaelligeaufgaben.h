#ifndef UEBERFAELLIGEAUFGABEN_H
#define UEBERFAELLIGEAUFGABEN_H

#include <QDialog>

namespace Ui {
class ueberfaelligeAufgaben;
}

class ueberfaelligeAufgaben : public QDialog
{
    Q_OBJECT

public:
    void addTaskToList(const QString& text);
    explicit ueberfaelligeAufgaben(QWidget *parent = nullptr);
    ~ueberfaelligeAufgaben();

private:
    Ui::ueberfaelligeAufgaben *ui;
};

#endif // UEBERFAELLIGEAUFGABEN_H
