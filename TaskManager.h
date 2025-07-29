#include <iostream>
#include <vector>
#include "Task.h"
#include "TaskInterface.h"
#pragma once
using namespace std;


class TaskManager : public TaskInterface 
{
public:
    TaskManager(); //Konstruktor

    //Methoden
    void addAufgabe(const Task&);  //Hinzufügen einer Aufgabe(button UI später)
    void delAufgabe(const int index);  //Löschen einer Aufgabe (button UI später)
    Task* findAufgabe(const int index); //findet über Index die Aufgabe und gibt Pointer auf entsprechende Aufgabe zurück
    const vector<Task>& getTasks() const; //Referenz auf alle Aufgaben für die Anzeige in der GUI 
    void editAufgabe(const int index, string neuerTitel, string neueBeschreibung, string neuesFaelligkeitsdatum); //Bearbeiten von Aufgaben über QListWidget mit Doppelklick
    vector<Task>& getTasks(); //nicht const getTasks Funktion

    void saveAufgaben() override; //Speichern mit TaskInterface
    void loadAufgaben() override; //Laden mit Taskinterface

private:
    vector<Task> v_tasks;
};