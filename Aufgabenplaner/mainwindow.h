#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidget>
#include <QMainWindow>
#include <QVector>
#include "../TaskManager.h"           //Einbinden der eigenen Klasse zum verwalten der Aufgaben
#include "../TaskController.h"
#include "../ViewInterface.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public ViewInterface
{
    Q_OBJECT

public:
    void zeigeAufgaben(const std::vector<Task>& aufgaben) override;
    void zeigeFehlermeldung(const std::string& meldung) override;
    MainWindow(QWidget *parent = nullptr);                                      //Konstruktor des MainWindows
    ~MainWindow();                                                              //Destruktor

private slots:

    void on_pBAufgabeHinzufuegen_clicked();                                     //Slot auf den Button, mit dem eine Aufgabe hinzugefügt wird

    void on_pBAufgabeErledigt_clicked();                                        //Slot auf den Button, mit dem eine Aufgabe als erledigt markiert wird

    void on_pBErledigteA_clicked();                                             //Slot auf den Button, mit dem der Dialog/die Liste für die erledigten Aufgaben geöffnet wird

    void on_pBUeberfaelligeA_clicked();                                         //Slot auf den Button, mit dem der Dialog/die Liste der überfälligen Aufgaben geöfnet wird

    void on_pBAufgabeEntfernen_clicked();                                       //Slot auf den Button, mit dem eine ausgewählte Aufgabe entfernt werden kann

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);                //Slot der die Bearbeitung durch einen Doppelklick ermöglicht

private:
    Ui::MainWindow *ui;
    TaskManager taskManager;
    TaskController* taskController;
    QVector<int> guiToVectorIndex;                                              //Zuordnungsliste zwischen den QListWidget einträgen und tatsächlichen Aufgaben Indizes
};

#endif // MAINWINDOW_H
