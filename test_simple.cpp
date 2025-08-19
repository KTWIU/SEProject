#include <gtest/gtest.h>
#include "TaskManager.h"
#include "Task.h"
#include "TaskFactory.h"

//T01 – TaskFactory erstellt korrekt initialisiertes Task-Objekt
TEST(UnitTest_TaskFactory, T01_CreateTaskReturnsCorrectAttributes) {
    //Testdaten definieren
    int index = 1;
    std::string titel = "Testtitel";
    std::string beschreibung = "Testbeschreibung";
    std::string faelligkeitsdatum = "2025-12-31";
    bool istErledigt = false;

    //Task über die Factory erzeugen
    Task task = TaskFactory::createTask(index, titel, beschreibung, faelligkeitsdatum, istErledigt);

    //Alle Attribute müssen den eingegebenen Werten entsprechen
    EXPECT_EQ(task.getIndex(), index);
    EXPECT_EQ(task.getTitel(), titel);
    EXPECT_EQ(task.getBeschreibung(), beschreibung);
    EXPECT_EQ(task.getFaelligkeitsdatum(), faelligkeitsdatum);
    EXPECT_EQ(task.getIstErledigt(), istErledigt);
}

//T02 – Hinzufügen vergrößert die Aufgabenliste um eins
TEST(UnitTest_TaskManagerFunktionen, T02_AddTaskIncreasesCount) {
    TaskManager manager;
    std::size_t size_before = manager.getTasks().size();

    //Eine neue Aufgabe erzeugen (Index entspricht size_before)
    Task neueAufgabe = TaskFactory::createTask(
        static_cast<int>(size_before), //static cast, da size_before ein size_t ist
        "Testaufgabe",
        "Beschreibung",
        "2025-12-31",
        false
    );

    //Aufgabe hinzufügen
    manager.addTask(neueAufgabe);

    //Aufgabenanzahl ist um 1 größer
    std::size_t size_after = manager.getTasks().size();
    EXPECT_EQ(size_after, size_before + 1);
}

//T03 – Entfernen einer Aufgabe verkleinert die Liste
TEST(UnitTest_TaskManagerFunktionen, T03_DeleteTaskReducesCount) {
    TaskManager manager;

    //Zwei Aufgaben hinzufügen
    manager.addTask(TaskFactory::createTask(0, "Aufgabe1", "Desc1", "2025-12-31", false));
    manager.addTask(TaskFactory::createTask(1, "Aufgabe2", "Desc2", "2025-12-31", false));

    std::size_t size_before = manager.getTasks().size();

    //Erste Aufgabe löschen
    manager.deleteTask(0);

    std::size_t size_after = manager.getTasks().size();

    //Liste ist um 1 Element kleiner
    EXPECT_EQ(size_after, size_before - 1);
}

//T04 – Bearbeiten ändert die Eigenschaften einer Aufgabe
TEST(UnitTest_TaskManagerFunktionen, T04_EditTaskChangesAttributes) {
    TaskManager manager;

    //Eine Aufgabe hinzufügen
    manager.addTask(TaskFactory::createTask(0, "AltTitel", "AltDesc", "2025-10-10", false));
    std::size_t size_before = manager.getTasks().size();

    //Neue Werte zum Bearbeiten
    std::string neuerTitel = "NeuTitel";
    std::string neueBeschreibung = "NeuDesc";
    std::string neuesDatum = "2025-12-31";

    //Aufgabe an Index 0 bearbeiten
    manager.editAufgabe(0, neuerTitel, neueBeschreibung, neuesDatum);

    //Aufgabe hat neue Werte
    const auto& tasks = manager.getTasks();
    ASSERT_EQ(tasks.size(), size_before); // Größe bleibt gleich
    EXPECT_EQ(tasks[0].getTitel(), neuerTitel);
    EXPECT_EQ(tasks[0].getBeschreibung(), neueBeschreibung);
    EXPECT_EQ(tasks[0].getFaelligkeitsdatum(), neuesDatum);
}

//T05 – Markieren einer Aufgabe als erledigt setzt Status auf true
TEST(UnitTest_TaskManagerFunktionen, T05_MarkTaskAsDone) {
    TaskManager manager;

    //Eine Aufgabe hinzufügen, die noch nicht erledigt ist
    manager.addTask(TaskFactory::createTask(0, "Beispiel", "Beschreibung", "2025-12-31", false));

    //Aufgabe an Index 0 als erledigt markieren
    manager.markiereAufgabeAlsErledigt(0);

    //Status 'istErledigt' ist jetzt true
    const auto& tasks = manager.getTasks();
    ASSERT_EQ(tasks.size(), 1u);
    EXPECT_TRUE(tasks[0].getIstErledigt());
}

// T06 – Speichern und Laden von Aufgaben über CSV-Datei
TEST(UnitTest_TaskManagerPersistenz, T06_SaveAndLoad) {
    //Ursprünglicher Manager mit zwei Aufgaben
    TaskManager manager;
    manager.addTask(TaskFactory::createTask(0, "Titel1", "Beschr1", "2025-12-31", false));
    manager.addTask(TaskFactory::createTask(1, "Titel2", "Beschr2", "2025-12-31", true));

    //Aufgaben in CSV-Datei speichern
    manager.saveAufgaben(); //schreibt alle Aufgaben in "TasksFile.csv"

    //Neuer Manager simuliert Programmneustart – lädt Aufgaben aus Datei
    TaskManager neuerManager;
    neuerManager.loadAufgaben(); //liest Aufgaben aus "TasksFile.csv" und füllt Liste

    //Anzahl der geladenen Aufgaben muss übereinstimmen
    const auto& loadedTasks = neuerManager.getTasks();
    ASSERT_EQ(loadedTasks.size(), 2u);

    //Überprüfung der Attribute der ersten Aufgabe
    EXPECT_EQ(loadedTasks[0].getIndex(), 0);
    EXPECT_EQ(loadedTasks[0].getTitel(), "Titel1");
    EXPECT_EQ(loadedTasks[0].getBeschreibung(), "Beschr1");
    EXPECT_EQ(loadedTasks[0].getFaelligkeitsdatum(), "2025-12-31");
    EXPECT_FALSE(loadedTasks[0].getIstErledigt());

    //Überprüfung der Attribute der zweiten Aufgabe
    EXPECT_EQ(loadedTasks[1].getIndex(), 1);
    EXPECT_EQ(loadedTasks[1].getTitel(), "Titel2");
    EXPECT_EQ(loadedTasks[1].getBeschreibung(), "Beschr2");
    EXPECT_EQ(loadedTasks[1].getFaelligkeitsdatum(), "2025-12-31");
    EXPECT_TRUE(loadedTasks[1].getIstErledigt());
}

//========================================================================
//MAIN
//========================================================================
int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




