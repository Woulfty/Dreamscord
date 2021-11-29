#include "serverTCP.h"
#include "serverWebSocket.h"
#include <qmap.h>

QtserverTCP::QtserverTCP(bddserver *bdd, uint16_t port){

	tcpServer = new QTcpServer(this);

	if (tcpServer->listen(QHostAddress::AnyIPv4, port)) {
		QObject::connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
		qInfo() << "Serveur TCP: Nouvelle connexion";
	}
	else {
		qInfo() << "Serveur TCP: Erreur d'ecoute IP ou Port";
	}
}

void QtserverTCP::setWSServer(QtserverWebSocket * server)
{
	this->wsServer = server;
}

//Connexion du serveur TCP
void QtserverTCP::onNewConnection() {
	QTcpSocket * socket = this->tcpServer->nextPendingConnection();
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(processTextMessage()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

	this->tcpclients.push_back(socket);
}

//Récupère les messages envoyé par le client
void QtserverTCP::processTextMessage() {
	QTcpSocket * tcp = qobject_cast<QTcpSocket*>(sender());
	QByteArray data = tcp->readAll();

	QString message(data);
	QSqlQuery query;

	//Authentification de l'utilisateur
	if (message.startsWith("Auth") == true) {
		QString data = QStringRef(&message, 4, message.length() - 4).toString();
		QString login = data.section(";", 0, 0);
		QString mdp = data.section(";", 1, 1);
		QString pseudo = bdd->connexion(login, mdp);
		if (pseudo.size() > 0){
			tcpsocketToUsername[tcp] = pseudo;
			tcp->write("Authtrue");
		}
	}
	//Incription de l'utilisateur
	if (message.startsWith("Salt") == true) {
		QString data = QStringRef(&message, 4, message.length() - 4).toString();
		QString login = data.section(";", 0, 0);
		QString mdp = data.section(";", 1, 1);
		QString pseudo = bdd->inscription(login, mdp);
		tcpsocketToUsername[tcp] = pseudo;
		tcp->write("Salttrue");
	}
	//Affichage des messages
	if (message.startsWith("Bdd") == true) {
		QString data = QStringRef(&message, 3, message.length() - 3).toString();
		QString pseudo = tcpsocketToUsername[tcp];
		bdd->insertMessage(pseudo, data);

		QString sentence = pseudo + ": " + data;
		for (QList<QTcpSocket*>::iterator it = tcpclients.begin(); it != tcpclients.end(); it++) {
			(*it)->write(sentence.toUtf8());
		}

		auto wsclients = wsServer->getSockets();
		for (auto it = wsclients.begin(); it != wsclients.end(); it++) {
			QWebSocket * ws = it.key();
			ws->sendTextMessage(sentence.toUtf8());
		}
	}
	//Renvoie les 100 derniers message
	if (message == "sendok") {
		selectMessageTCP(query, tcp);
	}
}

//Envoie les 100 derniers messages aux clients 
void QtserverTCP::selectMessageTCP(QSqlQuery query, QTcpSocket *tcp) {
	query.exec("SELECT `login`,`message` FROM `user`, `message` WHERE id=iduser ORDER BY `date` LIMIT 100");
	while (query.next()) {
		QString login = query.value(0).toString();
		QString message = query.value(1).toString();
		QString sendText = login + ": " + message;
		tcp->write(sendText.toUtf8()+"#&%@");
	}
}

//Déconnexion du serveur TCP
void QtserverTCP::socketDisconnected() {
	QTcpSocket * tcp = qobject_cast<QTcpSocket*>(sender());
	qInfo() << "Server TCP: Deconnexion";
	this->tcpclients.removeAll(tcp);
}