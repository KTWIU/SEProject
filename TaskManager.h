#include <iostream>
#include <vector>
#include "Task.h"
#include "TaskInterface.h"
#pragma once
using namespace std;


class TaskManager : public TaskInterface                               //TaskManager erbt aus der abstrakten Basisklasse
{
public:
    TaskManager();                                                      //Konstruktor

                                                                        //Vorgeschriebenen Methoden aus Interface werden implementiert
    void addTask(const Task& task) override;
    void deleteTask(int index) override;
    void editAufgabe(int index, const string& neuerTitel, const string& neueBeschreibung, const std::string& neuesFaelligkeitsdatum) override;
    void markiereAufgabeAlsErledigt(int index) override;
    const vector<Task>& getTasks() const;                               //Referenz auf alle Aufgaben für die Anzeige in der GUI 
    vector<Task>& getTasks();                                           //nicht const getTasks Funktion z.B. zum ändern von Aufgaben
    void saveAufgaben() override;                                       //Speichern mit TaskInterface
    void loadAufgaben() override;                                       //Laden mit Taskinterface
    int getNextIndex() override;

private:
    vector<Task> v_tasks;
};