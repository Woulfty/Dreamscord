#include <QObject>
#include <qtcpsocket.h>
#include <QtWidgets/QMainWindow>
#include "ui_client.h"
#include <qtcpserver.h>

class client : public QMainWindow
{
	Q_OBJECT

private:
	Ui::clientClass ui;
	QTcpSocket * socket;
	QTcpServer * server;

public:
	client(QWidget *parent = Q_NULLPTR);

public slots:
	void connexion();
	void inscription();
	void message();
	void receivedTextMessage();
	void onConnectButtonClicked(QString message);
	void onInscriptionButtonClicked(QString message);
	void onMessageButtonClicked(QString message);
};
