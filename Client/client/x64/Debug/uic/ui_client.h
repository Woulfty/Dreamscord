/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientClass
{
public:
    QWidget *centralWidget;
    QPushButton *connexionButton;
    QLineEdit *speudoLineEdit;
    QLineEdit *mot_passeLineEdit;
    QLabel *pseudo;
    QLabel *connexion;
    QLabel *motdepasse;
    QLabel *dreamscord;
    QPushButton *envoyerButton;
    QLabel *incription;
    QLabel *pseudolabel_2;
    QLabel *motDePasselabel_3;
    QLabel *confirmationMDPlabel_4;
    QLineEdit *speudoinscritionlineEdit;
    QLineEdit *MDPlineEdit_2;
    QLineEdit *confirmationlineEdit_3;
    QPushButton *InscriptionButton;
    QTextBrowser *messageEnvoyer;
    QLineEdit *zone_de_test;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *clientClass)
    {
        if (clientClass->objectName().isEmpty())
            clientClass->setObjectName(QString::fromUtf8("clientClass"));
        clientClass->resize(759, 551);
        centralWidget = new QWidget(clientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connexionButton = new QPushButton(centralWidget);
        connexionButton->setObjectName(QString::fromUtf8("connexionButton"));
        connexionButton->setGeometry(QRect(260, 280, 111, 31));
        connexionButton->setStyleSheet(QString::fromUtf8("font: 8pt \"Noto Sans Arabic\";"));
        speudoLineEdit = new QLineEdit(centralWidget);
        speudoLineEdit->setObjectName(QString::fromUtf8("speudoLineEdit"));
        speudoLineEdit->setGeometry(QRect(370, 160, 141, 31));
        mot_passeLineEdit = new QLineEdit(centralWidget);
        mot_passeLineEdit->setObjectName(QString::fromUtf8("mot_passeLineEdit"));
        mot_passeLineEdit->setGeometry(QRect(370, 240, 141, 31));
        pseudo = new QLabel(centralWidget);
        pseudo->setObjectName(QString::fromUtf8("pseudo"));
        pseudo->setGeometry(QRect(260, 150, 91, 41));
        connexion = new QLabel(centralWidget);
        connexion->setObjectName(QString::fromUtf8("connexion"));
        connexion->setGeometry(QRect(360, 90, 161, 31));
        motdepasse = new QLabel(centralWidget);
        motdepasse->setObjectName(QString::fromUtf8("motdepasse"));
        motdepasse->setGeometry(QRect(220, 240, 131, 31));
        dreamscord = new QLabel(centralWidget);
        dreamscord->setObjectName(QString::fromUtf8("dreamscord"));
        dreamscord->setGeometry(QRect(300, 0, 251, 71));
        envoyerButton = new QPushButton(centralWidget);
        envoyerButton->setObjectName(QString::fromUtf8("envoyerButton"));
        envoyerButton->setGeometry(QRect(630, 400, 111, 31));
        incription = new QLabel(centralWidget);
        incription->setObjectName(QString::fromUtf8("incription"));
        incription->setGeometry(QRect(360, 70, 131, 41));
        pseudolabel_2 = new QLabel(centralWidget);
        pseudolabel_2->setObjectName(QString::fromUtf8("pseudolabel_2"));
        pseudolabel_2->setGeometry(QRect(290, 120, 161, 31));
        motDePasselabel_3 = new QLabel(centralWidget);
        motDePasselabel_3->setObjectName(QString::fromUtf8("motDePasselabel_3"));
        motDePasselabel_3->setGeometry(QRect(250, 180, 201, 31));
        confirmationMDPlabel_4 = new QLabel(centralWidget);
        confirmationMDPlabel_4->setObjectName(QString::fromUtf8("confirmationMDPlabel_4"));
        confirmationMDPlabel_4->setGeometry(QRect(140, 240, 261, 21));
        speudoinscritionlineEdit = new QLineEdit(centralWidget);
        speudoinscritionlineEdit->setObjectName(QString::fromUtf8("speudoinscritionlineEdit"));
        speudoinscritionlineEdit->setGeometry(QRect(370, 130, 151, 21));
        MDPlineEdit_2 = new QLineEdit(centralWidget);
        MDPlineEdit_2->setObjectName(QString::fromUtf8("MDPlineEdit_2"));
        MDPlineEdit_2->setGeometry(QRect(380, 190, 151, 21));
        confirmationlineEdit_3 = new QLineEdit(centralWidget);
        confirmationlineEdit_3->setObjectName(QString::fromUtf8("confirmationlineEdit_3"));
        confirmationlineEdit_3->setGeometry(QRect(410, 240, 141, 21));
        InscriptionButton = new QPushButton(centralWidget);
        InscriptionButton->setObjectName(QString::fromUtf8("InscriptionButton"));
        InscriptionButton->setGeometry(QRect(460, 280, 101, 31));
        messageEnvoyer = new QTextBrowser(centralWidget);
        messageEnvoyer->setObjectName(QString::fromUtf8("messageEnvoyer"));
        messageEnvoyer->setGeometry(QRect(50, 70, 661, 261));
        zone_de_test = new QLineEdit(centralWidget);
        zone_de_test->setObjectName(QString::fromUtf8("zone_de_test"));
        zone_de_test->setGeometry(QRect(50, 390, 571, 51));
        clientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(clientClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 759, 26));
        clientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(clientClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        clientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(clientClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        clientClass->setStatusBar(statusBar);

        retranslateUi(clientClass);
        QObject::connect(InscriptionButton, SIGNAL(clicked()), clientClass, SLOT(inscription()));
        QObject::connect(connexionButton, SIGNAL(clicked()), clientClass, SLOT(connexion()));
        QObject::connect(connexionButton, SIGNAL(clicked(bool)), clientClass, SLOT(onConnectButtonClicked()));
        QObject::connect(envoyerButton, SIGNAL(clicked()), clientClass, SLOT(message()));

        QMetaObject::connectSlotsByName(clientClass);
    } // setupUi

    void retranslateUi(QMainWindow *clientClass)
    {
        clientClass->setWindowTitle(QCoreApplication::translate("clientClass", "client", nullptr));
#if QT_CONFIG(tooltip)
        connexionButton->setToolTip(QCoreApplication::translate("clientClass", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        connexionButton->setText(QCoreApplication::translate("clientClass", "Connexion", nullptr));
        pseudo->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">pseudo :</span></p></body></html>", nullptr));
        connexion->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">Connexion</span></p></body></html>", nullptr));
        motdepasse->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">mot de passe :</span></p></body></html>", nullptr));
        dreamscord->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p><img src=\":/newPrefix/reamscord-removebg-preview.png\"/></p></body></html>", nullptr));
        envoyerButton->setText(QCoreApplication::translate("clientClass", "envoyer", nullptr));
        incription->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Insciption</span></p></body></html>", nullptr));
        pseudolabel_2->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\"> Pseudo :</span></p></body></html>", nullptr));
        motDePasselabel_3->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\"> mot de passe :</span></p></body></html>", nullptr));
        confirmationMDPlabel_4->setText(QCoreApplication::translate("clientClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">confirmation du mot du passe :</span></p></body></html>", nullptr));
        speudoinscritionlineEdit->setText(QString());
        InscriptionButton->setText(QCoreApplication::translate("clientClass", "Inscription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientClass: public Ui_clientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
