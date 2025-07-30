#include "TaskManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>


TaskManager::TaskManager() {}                           //Konstruktor

void TaskManager::addTask(const Task& task) {
    v_tasks.push_back(task);
}

void TaskManager::deleteTask(int index) {
    if (index >= 0 && index < v_tasks.size()) {
        v_tasks.erase(v_tasks.begin() + index);
    } else {
        cout << "Index error beim Versuch, die Aufgabe zu löschen!" << endl;
    }
}

void TaskManager::markiereAufgabeAlsErledigt(int index) {
    if (index >= 0 && index < v_tasks.size()) {
        v_tasks[index].setIstErledigt(true);
    } else {
        cout << "Index error beim Versuch, die Aufgabe als erledigt zu markieren!" << endl;
    }
}

vector<Task>& TaskManager::getTasks() {
    return v_tasks;
}

const vector<Task>& TaskManager::getTasks() const {
    return v_tasks;
}

void TaskManager::saveAufgaben() {
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

void TaskManager::loadAufgaben() {
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
    return v_tasks.size();
}

void TaskManager::editAufgabe(int index, const std::string& neuerTitel, const std::string& neueBeschreibung, const std::string& neuesFaelligkeitsdatum)
{
    if (index >= 0 && index < v_tasks.size())
    {
        v_tasks[index].setTitel(neuerTitel);
        v_tasks[index].setBeschreibung(neueBeschreibung);
        v_tasks[index].setFaelligkeitsdatum(neuesFaelligkeitsdatum);
    }
}