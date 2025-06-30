#include <QApplication>
#include <QWidget>


//TEST OB QT FUNKTIONIERT - CODE LÖSCHEN
int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Aufgaben-Tracker (Test)");
    window.resize(400, 200);
    window.show();

    return app.exec();
}