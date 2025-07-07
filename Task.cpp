#include "Task.h"

//Konstruktor
Task::Task(int i, const string& t, const string& b, const string& f, bool e)
: index(i), titel(t), beschreibung(b), faelligkeitsdatum(f), istErledigt(e)
{
    //Attribute bereits in Intialisierungsliste gesetzt
}

int Task::getIndex() const 
{
    return index; 
};

string Task::getTitel() const
{
    return titel;
};

string Task::getBeschreibung() const 
{
    return beschreibung;
};

string Task::getFaelligkeitsdatum() const
{
    return faelligkeitsdatum;
};

bool Task::getIstErledigt() const
{
    return istErledigt;
};

void Task::setIndex(const int neuerIndex)
{
    index = neuerIndex;
};

void Task::setTitel(const string& neuerTitel)
{
    titel = neuerTitel;
};

void Task::setBeschreibung(const string& neueBeschreibung)
{
    beschreibung = neueBeschreibung;
};

void Task::setFaelligkeitsdatum(const string& neuesFaelligkeitsdatum)
{
    faelligkeitsdatum = neuesFaelligkeitsdatum;
};

void Task::setIstErledigt(const bool neuesIstErledigt)
{
    istErledigt = neuesIstErledigt;
};

Task::~Task() {}