#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/TaskManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pBAufgabeHinzufuegen_clicked();

    void on_pBAufgabeErledigt_clicked();

    void on_pBErledigteA_clicked();

    void on_pBUeberfaelligeA_clicked();

    void on_pBAufgabeEntfernen_clicked();

private:
    Ui::MainWindow *ui;
    TaskManager taskManager;
};

#endif // MAINWINDOW_H
