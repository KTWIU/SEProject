#include "TaskManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>


TaskManager::TaskManager() {}                                                               //Konstruktor des TaskManagers

void TaskManager::addTask(const Task& task) {                                               //Fügt neue Aufgabe zur Aufgabenliste hinzu
    v_tasks.push_back(task);
}

void TaskManager::deleteTask(int index) {                                                   //Löscht eine Aufgabe an der angegebenen Indexposition
    if (index >= 0 && index < v_tasks.size()) {
        v_tasks.erase(v_tasks.begin() + index);
    } else {
        cout << "Index error beim Versuch, die Aufgabe zu löschen!" << endl;
    }
}

void TaskManager::markiereAufgabeAlsErledigt(int index) {                                   //Markiert Aufgabe als erledigt (istErledigt Attribut = true)
    if (index >= 0 && index < v_tasks.size()) {
        v_tasks[index].setIstErledigt(true);
    } else {
        cout << "Index error beim Versuch, die Aufgabe als erledigt zu markieren!" << endl;
    }
}

vector<Task>& TaskManager::getTasks() {                                                     //gibt (nicht const) Vektor aller Aufgaben zurück
    return v_tasks;
}

const vector<Task>& TaskManager::getTasks() const {                                         //gibt einen const Vektor aller Aufgaben zurück
    return v_tasks;
}

void TaskManager::saveAufgaben() {                                                          //speichern aller AUfgaben in die CSV Datei (Persistenzschicht)
    ofstream TasksFile("TasksFile.csv");
    if (TasksFile.is_open()) {
        TasksFile << "Index;Titel;Beschreibung;Faelligkeitsdatum;Erledigt;" << endl;
        for (const auto& t : v_tasks) {
            TasksFile << t.getIndex() << ";" << t.getTitel() << ";" << t.getBeschreibung()
                      << ";" << t.getFaelligkeitsdatum() << ";" << t.getIstErledigt() << ";" << endl;
        }
    } else {
        cout << "Datei konnte nicht für das Speichern geöffnet werden!" << endl;
    }
    TasksFile.close();
}

void TaskManager::loadAufgaben() {                                                          //Aufgaben aus der csv-Datei lesen und AUfgabenliste befüllen
    v_tasks.clear();
    string line;
    ifstream TasksFile("TasksFile.csv");
    if (TasksFile.is_open()) {
        getline(TasksFile, line); // Header überspringen
        while (getline(TasksFile, line)) {
            stringstream ss(line);
            string tempIndex, titel, beschreibung, faelligkeitsdatum, tempIstErledigt;
            getline(ss, tempIndex, ';');
            getline(ss, titel, ';');
            getline(ss, beschreibung, ';');
            getline(ss, faelligkeitsdatum, ';');
            getline(ss, tempIstErledigt, ';');
            int index = stoi(tempIndex);
            bool istErledigt = (tempIstErledigt == "1" || tempIstErledigt == "true");
            v_tasks.emplace_back(index, titel, beschreibung, faelligkeitsdatum, istErledigt);
        }
    } else {
        cout << "Datei konnte beim Laden nicht geöffnet werden!" << endl;
    }
    TasksFile.close();
}

int TaskManager::getNextIndex() {
    return v_tasks.size();                                                                              //Tatsächlicher Index der auch nach Löschen von Aufgaben stimmt
}
                                                                                                        //Attribute einer vorhandenen AUfgabe bearbeiten
void TaskManager::editAufgabe(int index, const std::string& neuerTitel, const std::string& neueBeschreibung, const std::string& neuesFaelligkeitsdatum)
{
    if (index >= 0 && index < v_tasks.size())
    {
        v_tasks[index].setTitel(neuerTitel);
        v_tasks[index].setBeschreibung(neueBeschreibung);
        v_tasks[index].setFaelligkeitsdatum(neuesFaelligkeitsdatum);
    }
}