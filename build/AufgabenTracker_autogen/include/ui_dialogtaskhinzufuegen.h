/********************************************************************************
** Form generated from reading UI file 'dialogtaskhinzufuegen.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTASKHINZUFUEGEN_H
#define UI_DIALOGTASKHINZUFUEGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTaskHinzufuegen
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *titel;
    QDateEdit *faelligkeitsdatum;
    QTextEdit *beschreibung;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *AbbrechenDialog;
    QPushButton *AufgabeSpeichernDialog;

    void setupUi(QDialog *DialogTaskHinzufuegen)
    {
        if (DialogTaskHinzufuegen->objectName().isEmpty())
            DialogTaskHinzufuegen->setObjectName("DialogTaskHinzufuegen");
        DialogTaskHinzufuegen->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogTaskHinzufuegen);
        verticalLayout->setObjectName("verticalLayout");
        titel = new QLineEdit(DialogTaskHinzufuegen);
        titel->setObjectName("titel");

        verticalLayout->addWidget(titel);

        faelligkeitsdatum = new QDateEdit(DialogTaskHinzufuegen);
        faelligkeitsdatum->setObjectName("faelligkeitsdatum");

        verticalLayout->addWidget(faelligkeitsdatum);

        beschreibung = new QTextEdit(DialogTaskHinzufuegen);
        beschreibung->setObjectName("beschreibung");

        verticalLayout->addWidget(beschreibung);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        AbbrechenDialog = new QPushButton(DialogTaskHinzufuegen);
        AbbrechenDialog->setObjectName("AbbrechenDialog");

        horizontalLayout_3->addWidget(AbbrechenDialog);

        AufgabeSpeichernDialog = new QPushButton(DialogTaskHinzufuegen);
        AufgabeSpeichernDialog->setObjectName("AufgabeSpeichernDialog");

        horizontalLayout_3->addWidget(AufgabeSpeichernDialog);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(DialogTaskHinzufuegen);

        QMetaObject::connectSlotsByName(DialogTaskHinzufuegen);
    } // setupUi

    void retranslateUi(QDialog *DialogTaskHinzufuegen)
    {
        DialogTaskHinzufuegen->setWindowTitle(QCoreApplication::translate("DialogTaskHinzufuegen", "Aufgabe hinzuf\303\274gen", nullptr));
        titel->setText(QString());
        AbbrechenDialog->setText(QCoreApplication::translate("DialogTaskHinzufuegen", "Abbrechen", nullptr));
        AufgabeSpeichernDialog->setText(QCoreApplication::translate("DialogTaskHinzufuegen", "Aufgabe speichern", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTaskHinzufuegen: public Ui_DialogTaskHinzufuegen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTASKHINZUFUEGEN_H
