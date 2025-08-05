#ifndef TASKCONTROLLER_H
#define TASKCONTROLELR_H
#include <vector>
#include <string>
#include "Task.h"
#include "TaskInterface.h"
#include "TaskControllerInterface.h"


class TaskController : public TaskControllerInterface
{
    private:
        TaskInterface* taskInterface;

    public:                                                             //Methoden für die View
        TaskController(TaskInterface* interface);
        void addAufgabe(const string& titel, const string& beschreibung, const string& faelligkeitsdatum);
        void delAufgabe(int index);
        void editAufgabe(int index, const std::string& neuerTitel, const std::string& neueBeschreibung, const std::string& neuesFaelligkeitsdatum);
        void markiereAufgabeAlsErledigt(int index);
        vector<Task>& getTasks();
        void save();
        void load();
    
};

#endif