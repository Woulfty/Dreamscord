#include <iostream>
#include <memory>

#include <QDebug>
#include <QObject>
#include <QList>
#include <QTcpSocket>
#include <QTcpServer>
#include "bddserver.h"

class QtserverWebSocket;

class QtserverTCP : public QObject {
	Q_OBJECT
		QList<QTcpSocket*> tcpclients;
		QMap<QTcpSocket*, QString> tcpsocketToUsername;
		bddserver *bdd;
private:
	QTcpSocket * tcpSocket;
	QTcpServer * tcpServer;
	QtserverWebSocket * wsServer;

public:
	QtserverTCP(bddserver *bdd, uint16_t port);
	void setWSServer(QtserverWebSocket * server);
	QMap<QTcpSocket*, QString> & getSockets() {
		return tcpsocketToUsername;
	}

public slots:
	//Connexion du server TCP
	void onNewConnection();
	
	//Récupère les messages envoyé par le client
	void processTextMessage();
	
	//Envoie les 100 derniers messages aux clients 
	void selectMessageTCP(QSqlQuery query, QTcpSocket *tcp);
	
	//Déconnexion du serveur TCP
	void socketDisconnected();

signals:
	void closed();
};
