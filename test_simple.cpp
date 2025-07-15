#include <gtest/gtest.h>
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/TaskManager.h" 
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/TaskManager.cpp" 
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/Task.h" 
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/Task.cpp" 
#include <QString>
#include <QDate>

//========================================================================
//Unit-Test: Eingabevalidierung
//========================================================================
bool validateTitel(const QString &title) 
{
    return !title.isEmpty();
}

TEST(UnitTest_Eingabevalidierung, T01_CheckIfTitleExists) 
{
    QString title = "Mein Titel"; 
    EXPECT_TRUE(validateTitel(title));

    QString emptyTitle = "";                                    //Testet den Fall wenb kein Titel eingegeben wurde
    EXPECT_FALSE(validateTitel(emptyTitle));
}

bool validateDate(const QDate &faelligkeitsdatum)
{
    if(faelligkeitsdatum < QDate::currentDate()){
        return false;
    }else{
        return true;
    }
}

TEST(UnitTest_Eingabevalidierung, T02_CheckIfDateGreaterOrEqualToday)
{
    QDate gestern;
    gestern = QDate::currentDate().addDays(-1);
    EXPECT_FALSE(validateDate(gestern));

    QDate heute;
    heute = QDate::currentDate();
    EXPECT_TRUE(validateDate(heute));
}
//========================================================================
//Unit-Test: TaskManager Funktionen
//========================================================================
TEST(UnitTest_TaskManagerFunktionen, T03_addAufgabeIndexCounter)
{
    TaskManager manager;
    int size_before = manager.getTasks().size();
    manager.addAufgabe(Task(size_before, "Test", "testen des Index Counters", "2025-07-27", false));
    int size_after = manager.getTasks().size();
    EXPECT_EQ(size_before + 1, size_after);
}

TEST(UnitTest_TaskManagerFunktionen, T04_delAufgabeMoveTasks)
{
    TaskManager manager;
    manager.addAufgabe(Task(0, "Test", "Beschreibung", "2025-07-27", false));
    int size_before = manager.getTasks().size();
    manager.delAufgabe(size_before - 1);
    int size_after = manager.getTasks().size();
    EXPECT_EQ(size_before - 1, size_after);
}
//========================================================================
//Integrationstest: Workflow wie in Testdokument beschrieben
//========================================================================
TEST(Integrationstest_Workflow, T05_AnwenderWorkflow)
{
    TaskManager manager;                                                                    //testen nur im Ram                                                                                    
    manager.addAufgabe(Task(0, "Integrationstest", "Test", "2025-07-25", false));
    manager.editAufgabe(0, "Erfolg", "TestErfolg", "2025-12-24");
    auto& tasks = manager.getTasks();
    ASSERT_EQ(tasks.size(), 1);                                                             //testen ob vector immer noch größe 1 hat
    EXPECT_EQ(tasks[0].getTitel(), "Erfolg");
    EXPECT_EQ(tasks[0].getBeschreibung(), "TestErfolg");
    EXPECT_EQ(tasks[0].getFaelligkeitsdatum(), "2025-12-24");
}


//========================================================================
//MAIN
//========================================================================
int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




