#include "serverTCP.h"
#include "serverWebSocket.h"

QtserverWebSocket::QtserverWebSocket(bddserver *bdd, uint16_t port)
	: websocketServer(new QWebSocketServer(QStringLiteral("Server WebSocket"), QWebSocketServer::NonSecureMode))
{
	this->bdd = bdd;
	if (this->websocketServer->listen(QHostAddress::AnyIPv4, port)) {
		qInfo() << "Server WebSocket: Nouvelle connexion";
		QObject::connect(websocketServer.get(), SIGNAL(newConnection()), this, SLOT(onNewConnection()));
	}
	else{
		qInfo() << "Server WebSocket: Erreur d'ecoute IP ou Port";
	}
}

void QtserverWebSocket::setTcpServer(QtserverTCP * server)
{
	this->tcpServer = server;
}

void QtserverWebSocket::onNewConnection(){
	QWebSocket * socket = this->websocketServer->nextPendingConnection();
	QObject::connect(socket, SIGNAL(textMessageReceived(const QString&)), this, SLOT(processTextMessage(const QString&)));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

	this->wsclients.push_back(socket);
}

//Récupère les messages envoyé par le client
void QtserverWebSocket::processTextMessage(const QString& message){
	QWebSocket * ws = qobject_cast<QWebSocket*>(sender());
	QSqlQuery query;

	//Authentification de l'utilisateur
	if (message.startsWith("Auth") == true) {
		QString data = QStringRef(&message, 4, message.length() - 4).toString();
		QString login = data.section(";", 0, 0);
		QString mdp = data.section(";", 1, 1);
		QString pseudo = bdd->connexion(login, mdp);
		if (pseudo.size() > 0){
			wsocketToUsername[ws] = pseudo;
			ws->sendTextMessage("Authtrue");
			selectMessageWS(query, ws);
		}
	}
	//Incription de l'utilisateur
	if (message.startsWith("Salt") == true) {
		QString data = QStringRef(&message, 4, message.length() - 4).toString();
		QString login = data.section(";", 0, 0);
		QString mdp = data.section(";", 1, 1);
		QString pseudo = bdd->inscription(login, mdp);
		wsocketToUsername[ws] = pseudo;
		ws->sendTextMessage("Salttrue");
		selectMessageWS(query, ws);
	}
	//Affichage des messages
	if (message.startsWith("Bdd") == true) {
		QString data = QStringRef(&message, 3, message.length() - 3).toString();
		QString pseudo = wsocketToUsername[ws];
		bdd->insertMessage(pseudo, data);
		
		QString sentence = pseudo + " : " + data;
		for(QList<QWebSocket*>::iterator it = wsclients.begin(); it != wsclients.end(); it++) {
			(*it)->sendTextMessage(sentence);
		}

		auto tcpclients = tcpServer->getSockets();
		for (auto it = tcpclients.begin(); it != tcpclients.end(); it++) {
			it.key()->write(sentence.toUtf8());
		}
	}
}

//Envoie les 100 derniers messages aux clients 
void QtserverWebSocket::selectMessageWS(QSqlQuery query, QWebSocket *ws) {
	query.exec("SELECT `login`,`message` FROM `user`, `message` WHERE id=iduser ORDER BY `date` LIMIT 100");
	while (query.next()) {
		QString login = query.value(0).toString();
		QString message = query.value(1).toString();
		QString sendText = login + ": " + message;
		ws->sendTextMessage(sendText);
	}
}

//Déconnexion du server WS
void QtserverWebSocket::socketDisconnected(){
	QWebSocket * ws = qobject_cast<QWebSocket*>(sender());
	qInfo() << "Server WebSocket: Deconnexion";
	this->wsclients.removeAll(ws);
}