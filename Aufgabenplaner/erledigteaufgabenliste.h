#ifndef ERLEDIGTEAUFGABENLISTE_H
#define ERLEDIGTEAUFGABENLISTE_H

#include <QDialog>

namespace Ui {
class erledigteAufgabenliste;
}

class erledigteAufgabenliste : public QDialog
{
    Q_OBJECT

public:
    void addTaskToList(const QString& text);
    explicit erledigteAufgabenliste(QWidget *parent = nullptr);
    Ui::erledigteAufgabenliste *getUi() {return ui; }
    ~erledigteAufgabenliste();

private:
    Ui::erledigteAufgabenliste *ui;
};

#endif // ERLEDIGTEAUFGABENLISTE_H
