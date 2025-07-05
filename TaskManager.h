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
    void listAufgaben();//Listet die Aufgaben auf
    void saveAufgaben(); //Speichern
    void loadAufgaben(); //Laden


private:
    vector<Task> v_tasks;
};