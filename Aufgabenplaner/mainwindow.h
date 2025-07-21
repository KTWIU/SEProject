#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidget>
#include <QMainWindow>
#include <QVector>
#include "../TaskManager.h"           //Einbinden der eigenen Klasse zum verwalten der Aufgaben

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
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
    TaskManager taskManager;                                                    //Objekt zum verwalten der Aufgaben (Backend)
    QVector<int> guiToVectorIndex;                                              //Zuordnungsliste zwischen den QListWidget einträgen und tatsächlichen Aufgaben Indizes
    void refreshListWidget();                                                   //Funktion, die ListWidget und Mapping nach Aktion (z.B. bearbeiten...) aktualisiert/neu aufbaut
};

#endif // MAINWINDOW_H
