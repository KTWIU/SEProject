#include <iostream>
#include <vector>
#include "Task.h"
#pragma once
using namespace std;


class TaskManager
{
public:
    TaskManager(); //Konstruktor

    //Methoden
    void addAufgabe(const Task&);  //Hinzufügen einer Aufgabe(button UI später)
    void delAufgabe(const int index);  //Löschen einer Aufgabe (button UI später)
    Task* findAufgabe(const int index); //findet über Index die Aufgabe und gibt Pointer auf entsprechende Aufgabe zurück
    const vector<Task>& getTasks() const; //Referenz auf alle Aufgaben für die Anzeige in der GUI 
    void saveAufgaben(); //Speichern
    void loadAufgaben(); //Laden
    void editAufgabe(const int index, string neuerTitel, string neueBeschreibung, string neuesFaelligkeitsdatum); //Bearbeiten von Aufgaben über QListWidget mit Doppelklick
    vector<Task>& getTasks(); //nicht const getTasks Funktion

private:
    vector<Task> v_tasks;
};