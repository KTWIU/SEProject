#ifndef TASKCONTROLLER_H
#define TASKCONTROLELR_H
#include <vector>
#include <string>
#include <Task.h>
#include <TaskInterface.h>

class TaskController
{
    private:
        TaskInterface* taskInterface;

    public:
        TaskController(TaskInterface* interface);
        void addAufgabe(const string& titel, const string& beschreibung, const string& faelligkeitsdatum);
    
};

#endif