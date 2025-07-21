/********************************************************************************
** Form generated from reading UI file 'ueberfaelligeaufgaben.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UEBERFAELLIGEAUFGABEN_H
#define UI_UEBERFAELLIGEAUFGABEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_ueberfaelligeAufgaben
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidgetUeberfaellige;

    void setupUi(QDialog *ueberfaelligeAufgaben)
    {
        if (ueberfaelligeAufgaben->objectName().isEmpty())
            ueberfaelligeAufgaben->setObjectName("ueberfaelligeAufgaben");
        ueberfaelligeAufgaben->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ueberfaelligeAufgaben);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidgetUeberfaellige = new QListWidget(ueberfaelligeAufgaben);
        listWidgetUeberfaellige->setObjectName("listWidgetUeberfaellige");

        horizontalLayout->addWidget(listWidgetUeberfaellige);


        retranslateUi(ueberfaelligeAufgaben);

        QMetaObject::connectSlotsByName(ueberfaelligeAufgaben);
    } // setupUi

    void retranslateUi(QDialog *ueberfaelligeAufgaben)
    {
        ueberfaelligeAufgaben->setWindowTitle(QCoreApplication::translate("ueberfaelligeAufgaben", "\303\234berf\303\244llige Aufgaben", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ueberfaelligeAufgaben: public Ui_ueberfaelligeAufgaben {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UEBERFAELLIGEAUFGABEN_H
