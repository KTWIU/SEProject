#include "TaskController.h"

TaskController::TaskController(TaskInterface* interface) : taskInterface(interface){}

void TaskController::addAufgabe(const string& titel, const string& beschreibung, const string& faelligkeitsdatum)
{
    int neuerIndex = taskInterface->getNextIndex();
    Task neueAufgabe(neuerIndex, titel, beschreibung, faelligkeitsdatum, false);
    taskInterface->addTask(neueAufgabe);
    taskInterface->saveAufgaben();
}

void TaskController::delAufgabe(int index) {
    std::vector<Task>& tasks = taskInterface->getTasks();
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        taskInterface->saveAufgaben();
    }
}

void TaskController::markiereAufgabeAlsErledigt(int index) {
    auto& tasks = taskInterface->getTasks();
    if (index >= 0 && index < tasks.size()) {
        tasks.at(index).setIstErledigt(true);
        taskInterface->saveAufgaben();
    }
}

std::vector<Task>& TaskController::getTasks() {
    return taskInterface->getTasks();
}

void TaskController::save() {
    taskInterface->saveAufgaben();
}

void TaskController::load() {
    taskInterface->loadAufgaben();
}

void TaskController::editAufgabe(int index, const std::string& neuerTitel, const std::string& neueBeschreibung, const std::string& neuesFaelligkeitsdatum)
{
    taskInterface->editAufgabe(index, neuerTitel, neueBeschreibung, neuesFaelligkeitsdatum);
    taskInterface->saveAufgaben();
}
