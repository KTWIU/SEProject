#include "TaskFactory.h"


Task TaskFactory::createTask(int index, const std::string& titel, const std::string& beschreibung, //Erstellt ein Task-Objekt mit allen Attributen
                             const std::string& faelligkeitsdatum, bool istErledigt) {
    return Task(index, titel, beschreibung, faelligkeitsdatum, istErledigt);
}