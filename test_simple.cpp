#include <gtest/gtest.h>
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/TaskManager.h" 
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/TaskManager.cpp" 
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/Task.h" 
#include "C:/Users/kevin/OneDrive/Desktop/Projekt/repo/Task.cpp" 
#include <QString>
#include <QDate>

//========================================================================
//Eingabevalidierung
//========================================================================
bool validateTitel(const QString &title) {
    return !title.isEmpty();
}

TEST(Eingabevalidierung, CheckIfTitleExists) {
    QString title = "Mein Titel"; 
    EXPECT_TRUE(validateTitel(title));

    QString emptyTitle = ""; //Testet den Fall wenb kein Titel eingegeben wurde
    EXPECT_FALSE(validateTitel(emptyTitle));
}

bool validateDate(const QDate &faelligkeitsdatum){
    if(faelligkeitsdatum < QDate::currentDate()){
        return false;
    }else{
        return true;
    }
}

TEST(Eingabevalidierung, CheckIfDateGreaterOrEqualToday){
    QDate gestern;
    gestern = QDate::currentDate().addDays(-1);
    EXPECT_FALSE(validateDate(gestern));

    QDate heute;
    heute = QDate::currentDate();
    EXPECT_TRUE(validateDate(heute));
}
//========================================================================
//TaskManager Funktionen
//========================================================================
TEST(TaskManagerFunktionen, addAufgabeIndexCounter){
    TaskManager manager;
    int size_before = manager.getTasks().size();
    manager.addAufgabe(Task(size_before, "Test", "testen des Index Counters", "2025-07-27", false));
    int size_after = manager.getTasks().size();
    EXPECT_EQ(size_before + 1, size_after);
}

TEST(TaskManagerFunktionen, delAufgabeMoveTasks){
    TaskManager manager;
    manager.addAufgabe(Task(0, "Test", "Beschreibung", "2025-07-27", false));
    int size_before = manager.getTasks().size();
    manager.delAufgabe(size_before - 1);
    int size_after = manager.getTasks().size();
    EXPECT_EQ(size_before - 1, size_after);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




