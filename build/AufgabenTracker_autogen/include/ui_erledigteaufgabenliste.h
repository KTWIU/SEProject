/********************************************************************************
** Form generated from reading UI file 'erledigteaufgabenliste.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERLEDIGTEAUFGABENLISTE_H
#define UI_ERLEDIGTEAUFGABENLISTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_erledigteAufgabenliste
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidgetErledigteAufgaben;

    void setupUi(QDialog *erledigteAufgabenliste)
    {
        if (erledigteAufgabenliste->objectName().isEmpty())
            erledigteAufgabenliste->setObjectName("erledigteAufgabenliste");
        erledigteAufgabenliste->resize(400, 300);
        horizontalLayout = new QHBoxLayout(erledigteAufgabenliste);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidgetErledigteAufgaben = new QListWidget(erledigteAufgabenliste);
        listWidgetErledigteAufgaben->setObjectName("listWidgetErledigteAufgaben");

        horizontalLayout->addWidget(listWidgetErledigteAufgaben);


        retranslateUi(erledigteAufgabenliste);

        QMetaObject::connectSlotsByName(erledigteAufgabenliste);
    } // setupUi

    void retranslateUi(QDialog *erledigteAufgabenliste)
    {
        erledigteAufgabenliste->setWindowTitle(QCoreApplication::translate("erledigteAufgabenliste", "Erledigte Aufgaben", nullptr));
    } // retranslateUi

};

namespace Ui {
    class erledigteAufgabenliste: public Ui_erledigteAufgabenliste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERLEDIGTEAUFGABENLISTE_H
