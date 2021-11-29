#include <QtCore/QCoreApplication>
#include "serverTCP.h"
#include "serverWebSocket.h"
#include "bddserver.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//Connexion à la BDD
	bddserver *bdd = new bddserver();
	bdd->bddInit("QMYSQL", "192.168.65.58", "servertcpwebsocket", "root", "root");

	//Appel du server WS
	QtserverWebSocket serverWebSocket(bdd, 1234);

	//Appel du server TCP
	QtserverTCP serverTcp(bdd, 4321);

	serverTcp.setWSServer(&serverWebSocket);
	serverWebSocket.setTcpServer(&serverTcp);

	return a.exec();
}
