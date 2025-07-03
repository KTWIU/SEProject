#include <gtest/gtest.h>
#include <QString>

//Funktion die prüft, ob der Titel eingegeen wurde
bool validateTitel(const QString &title) {
    return !title.isEmpty();
}

TEST(TitleTest, CheckIfTitleExists) {
    QString title = "Mein Titel"; //Später durch richtiges Widget ersetzen
    EXPECT_TRUE(validateTitel(title));

    QString emptyTitle = ""; //Testet den Fall wenb kein Titel eingegeben wurde
    EXPECT_FALSE(validateTitel(emptyTitle));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




