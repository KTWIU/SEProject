#ifndef TASKINTERFACE_H
#define TASKINTERFACE_H

class TaskInterface                         //abstrakte Klasse, damit nicht überschrieben werden kann bzw. keine Instanz erstellt werden kann
{
    public:
        virtual void saveAufgaben() = 0;    //pure virtual function
        virtual void loadAufgaben() = 0;
        virtual ~TaskInterface() = default;
};



#endif