/********************************************************************************
** Form generated from reading UI file 'dialogtaskbearbeiten.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTASKBEARBEITEN_H
#define UI_DIALOGTASKBEARBEITEN_H

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

class Ui_DialogTaskBearbeiten
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *titel;
    QDateEdit *faelligkeitsdatum;
    QTextEdit *beschreibung;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *AbbrechenDialog;
    QPushButton *AufgabeSpeichernDialog;

    void setupUi(QDialog *DialogTaskBearbeiten)
    {
        if (DialogTaskBearbeiten->objectName().isEmpty())
            DialogTaskBearbeiten->setObjectName("DialogTaskBearbeiten");
        DialogTaskBearbeiten->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogTaskBearbeiten);
        verticalLayout->setObjectName("verticalLayout");
        titel = new QLineEdit(DialogTaskBearbeiten);
        titel->setObjectName("titel");

        verticalLayout->addWidget(titel);

        faelligkeitsdatum = new QDateEdit(DialogTaskBearbeiten);
        faelligkeitsdatum->setObjectName("faelligkeitsdatum");

        verticalLayout->addWidget(faelligkeitsdatum);

        beschreibung = new QTextEdit(DialogTaskBearbeiten);
        beschreibung->setObjectName("beschreibung");

        verticalLayout->addWidget(beschreibung);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        AbbrechenDialog = new QPushButton(DialogTaskBearbeiten);
        AbbrechenDialog->setObjectName("AbbrechenDialog");

        horizontalLayout_3->addWidget(AbbrechenDialog);

        AufgabeSpeichernDialog = new QPushButton(DialogTaskBearbeiten);
        AufgabeSpeichernDialog->setObjectName("AufgabeSpeichernDialog");

        horizontalLayout_3->addWidget(AufgabeSpeichernDialog);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(DialogTaskBearbeiten);

        QMetaObject::connectSlotsByName(DialogTaskBearbeiten);
    } // setupUi

    void retranslateUi(QDialog *DialogTaskBearbeiten)
    {
        DialogTaskBearbeiten->setWindowTitle(QCoreApplication::translate("DialogTaskBearbeiten", "Aufgabe bearbeiten", nullptr));
        titel->setText(QString());
        AbbrechenDialog->setText(QCoreApplication::translate("DialogTaskBearbeiten", "Abbrechen", nullptr));
        AufgabeSpeichernDialog->setText(QCoreApplication::translate("DialogTaskBearbeiten", "Aufgabe speichern", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTaskBearbeiten: public Ui_DialogTaskBearbeiten {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTASKBEARBEITEN_H
