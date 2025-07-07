#include "TaskManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

//Konstruktor
TaskManager::TaskManager() {}

void TaskManager::addAufgabe(const Task& neueAufgabe) //fertiges Task Objekt (Titel, Beschreibung...) wird über UI übergeben
{
    int neuerIndex = v_tasks.size(); //Anzahl der Indizes wächst mit Größe des vectors
    Task task_neu(neuerIndex, neueAufgabe.getTitel(), neueAufgabe.getBeschreibung(), neueAufgabe.getFaelligkeitsdatum(), neueAufgabe.getIstErledigt()); //neues Task Objekt erstellen und in vector einfügen
    v_tasks.push_back(task_neu);
};

void TaskManager::delAufgabe(const int Index)
{
    if(Index >= 0 && Index < v_tasks.size()) //Bedingung um Fehler zu vermeiden
    {
        v_tasks.erase(v_tasks.begin() + Index); //Aufgabe an Index x aus vector entfernen
    } else
    {
        cout << "Index error beim Versuch, die Aufgabe zu löschen!";
    }
};

Task* TaskManager::findAufgabe(const int Index)
{
    if(Index >= 0 && Index < v_tasks.size()) //Bedingung um Fehler zu vermeiden
    {
        auto it = find_if(v_tasks.begin(), v_tasks.end(), [Index](const Task& t){return t.getIndex()==Index;}); //Sucht nach Eigenschaft(Index) mit Lambda, da find nur ganze Objekte findet
        if(it != v_tasks.end())
        {
            Task* pntr = &(*it); //pointer auf den Task
            return pntr;
        } else {
            cout << "Index Error: Index nicht gefunden!";
            return nullptr; //wenn kein Index gefunden, Rückgabe nullptr, da Rückgabewert erwartet
        }
    } else
    {
        cout << "Index Error: Index out of range!";
        return nullptr;
    }
};

const vector<Task>& TaskManager::getTasks() const
{
    return v_tasks; //Für auflisten der Aufgaben in GUI
};

void TaskManager::saveAufgaben() //Komplette Datei wird bbei Aufruf neu geschrieben, bei dieser Datenmenge jedoch egal!
{
    ofstream TasksFile("TasksFile.csv"); //Aufgaben als .csv speichern, wenn noch keine Datei vorhanden wird eine erstellt
    int v_size;
    v_size = v_tasks.size(); //größe der vectors, damit ich drüber iterieren kann (jede Aufgabe&Attribut)
    if(TasksFile.is_open())
    {
    TasksFile << "Index;Titel;Beschreibung;Faelligkeitsdatum;Erledigt;" << endl; //Header
    for(int i=0; i < v_size; i++)
        {
        int index = v_tasks[i].getIndex();
        string titel = v_tasks[i].getTitel();
        string beschreibung = v_tasks[i].getBeschreibung();
        string faelligkeitsdatum = v_tasks[i].getFaelligkeitsdatum();
        bool istErledigt = v_tasks[i].getIstErledigt();
        TasksFile << index << ";" << titel << ";" << beschreibung << ";" << faelligkeitsdatum << ";" << istErledigt << ";" << endl;
        }
    } else{
        cout << "Datei konnte beim speichern nicht geöffnet werden!";
    }
    TasksFile.close();
};

void TaskManager::loadAufgaben()
{
    string line;
    ifstream TasksFile("TasksFile.csv");
    if(TasksFile.is_open())
    {
    getline(TasksFile, line); //Erste Zeile (Header) kann verworfen werden
    while(getline(TasksFile, line))
        {
            stringstream ss(line);
            string tempIndex; //vorerst string - Ziel: INT
            string titel;
            string beschreibung;
            string faelligkeitsdatum;
            string tempIstErledigt; //vorerst string - Ziel: BOOL
            getline(ss, tempIndex, ';');
            getline(ss, titel, ';');
            getline(ss, beschreibung, ';');
            getline(ss, faelligkeitsdatum, ';');
            getline(ss, tempIstErledigt, ';');
            int index = stoi(tempIndex);
            bool istErledigt = (tempIstErledigt == "1"||tempIstErledigt == "true");
            v_tasks.push_back(Task(index, titel, beschreibung, faelligkeitsdatum, istErledigt)); //neuen Task mit eingelesenen Attributen erstellen und zum Vector hinzufügen
        } 
    } else{
        cout << "Datei konnte beim laden nicht geöffnet werden!";
    }
    TasksFile.close();
};

vector<Task>& TaskManager::getTasks()
{
    return v_tasks;
}