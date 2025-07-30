#ifndef TASKINTERFACE_H
#define TASKINTERFACE_H
#include "Task.h"

class TaskInterface                         //abstrakte Klasse, damit nicht überschrieben werden kann bzw. keine Instanz erstellt werden kann
{
    public:
        virtual void saveAufgaben() = 0;    //pure virtual function
        virtual void loadAufgaben() = 0;
        virtual void addTask(const Task& task) = 0;
        virtual void deleteTask(int index) = 0;                      
        virtual void editAufgabe(int index, const string& neuerTitel, const string& neueBeschreibung, const string& faelligkeitsdatum) = 0; 
        virtual void markiereAufgabeAlsErledigt(int index) = 0;      
        virtual int getNextIndex() = 0;
        virtual vector<Task>& getTasks() = 0;
        virtual ~TaskInterface() = default;
};



#endif