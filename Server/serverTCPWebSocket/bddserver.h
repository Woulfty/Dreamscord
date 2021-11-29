#pragma once
#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <qstring.h>

class bddserver {
private :
	bddserver *bdd;
public :
	//Initialisation de le BDD
	void bddInit(QString type, QString host, QString name, QString login, QString mdp);
	
	//Vérification de la connexion à la BDD
	void bddConnect(QSqlDatabase bdd);
	
	//Fonction de connexion de l'utilisateur
	QString connexion(QString login, QString mdp);
	
	//Fonction d'inscription de l'utilisateur
	QString inscription(QString login, QString mdp);
	
	//Fonction d'ajout de message à la BDD
	void insertMessage(QString login, QString message);
};