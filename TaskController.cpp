#include "TaskController.h"

TaskController::TaskController(TaskInterface* interface) : taskInterface(interface){}                             //Methoden für View

void TaskController::addAufgabe(const string& titel, const string& beschreibung, const string& faelligkeitsdatum) 
{
    int neuerIndex = taskInterface->getNextIndex();
    Task neueAufgabe(neuerIndex, titel, beschreibung, faelligkeitsdatum, false);                                  //neues Task Objekt erstellen
    taskInterface->addTask(neueAufgabe);                                                                          //Objekt in vector pushen
    taskInterface->saveAufgaben();                                                                                //Speichert direkt die Aufgaben nach jeder neuen
}

void TaskController::delAufgabe(int index) {
    taskInterface->deleteTask(index);                                                                             //Erase des Objekts im Vector an der Stelle index
    taskInterface->saveAufgaben();
}

void TaskController::markiereAufgabeAlsErledigt(int index) {
    taskInterface->markiereAufgabeAlsErledigt(index);                                                             //setzt automatisch Objekt an index auf true (istErledigt)
    taskInterface->saveAufgaben();
}

std::vector<Task>& TaskController::getTasks() {
    return taskInterface->getTasks();                                                                             //holt alle aktuellen Aufgaben (aus TaskManager)
}

void TaskController::save() {
    taskInterface->saveAufgaben();                                                                                //save Methode für View
}

void TaskController::load() {
    taskInterface->loadAufgaben();                                                                                //load Methode für View
}

void TaskController::editAufgabe(int index, const std::string& neuerTitel, const std::string& neueBeschreibung, const std::string& neuesFaelligkeitsdatum)
{
    taskInterface->editAufgabe(index, neuerTitel, neueBeschreibung, neuesFaelligkeitsdatum);                      //ermöglicht Eingabe neuer Titel, Beschreibung und Datum 
    taskInterface->saveAufgaben();
}
