#include "Aufgabenplaner/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;                   //Erstellt Hauptfenster der Anwendung
    w.show();
    return a.exec();
}
