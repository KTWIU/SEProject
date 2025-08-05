#pragma once
#include <string>
#include <vector>
#include "Task.h"

class TaskControllerInterface {
public:
    virtual void addAufgabe(const std::string& titel, const std::string& beschreibung, const std::string& faelligkeitsdatum) = 0;
    virtual void delAufgabe(int index) = 0;
    virtual void editAufgabe(int index, const std::string& neuerTitel, const std::string& neueBeschreibung, const std::string& neuesFaelligkeitsdatum) = 0;
    virtual void markiereAufgabeAlsErledigt(int index) = 0;
    virtual std::vector<Task>& getTasks() = 0;
    virtual void save() = 0;
    virtual void load() = 0;
    virtual ~TaskControllerInterface() = default;
};
