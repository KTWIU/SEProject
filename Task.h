#include <iostream>
#pragma once
using namespace std;

class Task
{
public:
    Task(int index, const string& titel, const string& beschreibung, const string& faelligkeitsdatum, bool isterledigt);    //Standard Konstruktor
    ~Task();                                                                                                                //Destruktor

    //getter Methoden
    int getIndex() const; 
    string getTitel() const;
    string getBeschreibung() const;
    string getFaelligkeitsdatum() const;
    bool getIstErledigt() const;

    //setter Methoden
    void setIndex(const int);
    void setTitel(const string&);
    void setBeschreibung(const string&);
    void setFaelligkeitsdatum(const string&);
    void setIstErledigt(const bool);

private:
    //Attribute
    int index;
    string titel;
    string beschreibung;
    string faelligkeitsdatum;
    bool istErledigt;
};