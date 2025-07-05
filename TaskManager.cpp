#include "TaskManager.h"

//Konstruktor
TaskManager::TaskManager() {}

void TaskManager::addAufgabe(const Task& neueAufgabe) //fertiges Task Objekt (Titel, Beschreibung...) wird über UI übergeben
{
    int neuerIndex = v_tasks.size(); //Anzahl der Indizes wächst mit Größe des vectors
    Task task_neu(neuerIndex, neueAufgabe.getTitel(), neueAufgabe.getBeschreibung(), neueAufgabe.getFaelligkeitsdatum()); //neues Task Objekt erstellen und in vector einfügen
    v_tasks.push_back(task_neu);
};

void TaskManager::delAufgabe(const int Index)
{
    if(Index >= 0 && Index < v_tasks.size()) //Bedingung um Fehler zu vermeiden
    {
        v_tasks.erase(v_tasks.begin() + Index); //Aufgabe an Index x aus vector entfernen
    } else
    {
        cout << "Index error beim Löschen der Aufgabe";
    }
};

