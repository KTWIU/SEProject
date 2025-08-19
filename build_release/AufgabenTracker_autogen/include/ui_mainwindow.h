/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pBAufgabeHinzufuegen;
    QPushButton *pBAufgabeErledigt;
    QPushButton *pBAufgabeEntfernen;
    QLabel *label;
    QPushButton *pBUeberfaelligeA;
    QPushButton *pBErledigteA;
    QCalendarWidget *calendarWidget;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(763, 660);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pBAufgabeHinzufuegen = new QPushButton(centralwidget);
        pBAufgabeHinzufuegen->setObjectName("pBAufgabeHinzufuegen");

        verticalLayout->addWidget(pBAufgabeHinzufuegen);

        pBAufgabeErledigt = new QPushButton(centralwidget);
        pBAufgabeErledigt->setObjectName("pBAufgabeErledigt");

        verticalLayout->addWidget(pBAufgabeErledigt);

        pBAufgabeEntfernen = new QPushButton(centralwidget);
        pBAufgabeEntfernen->setObjectName("pBAufgabeEntfernen");

        verticalLayout->addWidget(pBAufgabeEntfernen);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        pBUeberfaelligeA = new QPushButton(centralwidget);
        pBUeberfaelligeA->setObjectName("pBUeberfaelligeA");

        verticalLayout->addWidget(pBUeberfaelligeA);

        pBErledigteA = new QPushButton(centralwidget);
        pBErledigteA->setObjectName("pBErledigteA");

        verticalLayout->addWidget(pBErledigteA);

        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout->addWidget(calendarWidget);


        horizontalLayout->addLayout(verticalLayout);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(listWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Aufgabenplaner", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "smpl task planner", nullptr));
        pBAufgabeHinzufuegen->setText(QCoreApplication::translate("MainWindow", "Aufgabe hinzuf\303\274gen", nullptr));
        pBAufgabeErledigt->setText(QCoreApplication::translate("MainWindow", "Aufgabe erledigt", nullptr));
        pBAufgabeEntfernen->setText(QCoreApplication::translate("MainWindow", "Aufgabe entfernen", nullptr));
        label->setText(QString());
        pBUeberfaelligeA->setText(QCoreApplication::translate("MainWindow", "\303\234berf\303\244llige Aufgaben", nullptr));
        pBErledigteA->setText(QCoreApplication::translate("MainWindow", "Erledigte Aufgaben", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
