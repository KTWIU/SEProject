#pragma once
#include <vector>
#include <string>
#include "Task.h"

class ViewInterface {
public:
    virtual void zeigeAufgaben(const std::vector<Task>& aufgaben) = 0;  //Methode zum Anzeigen aller Aufgaben
    virtual void zeigeFehlermeldung(const std::string& meldung) = 0;    //Methode zum Anzeigen einer Fehlermeldung

    virtual ~ViewInterface() = default;
};
