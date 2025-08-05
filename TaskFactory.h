#pragma once
#include "Task.h"
#include <string>

class TaskFactory 
{
public:
    
    static Task createTask(int index, const std::string& titel, const std::string& beschreibung, //Erstellt ein Task-Objekt mit allen Attributen
                           const std::string& faelligkeitsdatum, bool istErledigt);

};
