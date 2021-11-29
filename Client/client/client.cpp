#include "client.h"

client::client(QWidget *parent) : QMainWindow(parent)
{
	socket = new QTcpSocket();
	socket->connectToHost("127.0.0.1", 4321);
	if (socket->state() == QTcpSocket::ConnectedState) {
		qDebug() << "Client TCP: Nouvelle connexion";
	}
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(receivedTextMessage()));

	ui.setupUi(this);

	ui.dreamscord->setVisible(true); //logo
	//inscription
	ui.incription->setVisible(false); //  text insciption
	ui.MDPlineEdit_2->setVisible(false); //mot de passe de l'inscription
	ui.confirmationMDPlabel_4->setVisible(false); //label confirmation mot de passe inscription
	ui.confirmationlineEdit_3->setVisible(false); //conf mot de passe inscription
	ui.InscriptionButton->setVisible(true); // button d'inscription
	ui.motDePasselabel_3->setVisible(false); // label mot de passe inscription
	ui.pseudolabel_2->setVisible(false); // label du pseudo d'inscription
	ui.speudoinscritionlineEdit->setVisible(false);  // pseudo inscription

	//connexion
	ui.connexion->setVisible(true); // text connexion 
	ui.connexionButton->setVisible(true); //bouton connexion
	ui.motdepasse->setVisible(true); // label  mot de passe de conexion
	ui.pseudo->setVisible(true);  //label pseudo connxion
	ui.speudoLineEdit->setVisible(true);// pseudo connexion
	ui.mot_passeLineEdit->setVisible(true); // mot de passe connexion

	//messagerrie
	ui.envoyerButton->setVisible(false); // bouton d'envoye de message
	ui.messageEnvoyer->setVisible(false); // cadre des messages envoyer
	ui.zone_de_test->setVisible(false); // zone de text pour evoyer un message
}

void client::connexion()
{
	ui.dreamscord->setVisible(true); //logo

	//inscription
	ui.incription->setVisible(false); //  text insciption
	ui.MDPlineEdit_2->setVisible(false); //mot de passe de l'inscription
	ui.confirmationMDPlabel_4->setVisible(false); //label confirmation mot de passe inscription
	ui.confirmationlineEdit_3->setVisible(false); //conf mot de passe inscription
	ui.InscriptionButton->setVisible(true); // button d'inscription
	ui.motDePasselabel_3->setVisible(false); // label mot de passe inscription
	ui.pseudolabel_2->setVisible(false); // label du pseudo d'inscription
	ui.speudoinscritionlineEdit->setVisible(false);  // pseudo inscription

	//connxion
	ui.connexion->setVisible(true); // text connexion 
	ui.connexionButton->setVisible(true); //bouton connexion
	ui.motdepasse->setVisible(true); // label  mot de passe de conexion
	ui.pseudo->setVisible(true);  //label pseudo connxion
	ui.speudoLineEdit->setVisible(true);// pseudo connexion
	ui.mot_passeLineEdit->setVisible(true); // mot de passe connexion

	//messagerrie
	ui.envoyerButton->setVisible(false); // bouton d'envoye de message
	ui.messageEnvoyer->setVisible(false); // cadre des messages envoyer
	ui.zone_de_test->setVisible(false); // zone de text pour evoyer un message

	if (ui.speudoLineEdit->text().size() > 0 && ui.mot_passeLineEdit->text().size() > 0) {
		QString login = ui.speudoLineEdit->text();
		QString mdp = ui.mot_passeLineEdit->text();

		QString data = "Auth" + login + ";" + mdp;

		onConnectButtonClicked(data);
	}
}

void client::inscription()
{
	ui.dreamscord->setVisible(true);
	//inscription
	ui.incription->setVisible(true);
	ui.MDPlineEdit_2->setVisible(true);
	ui.confirmationMDPlabel_4->setVisible(true);
	ui.confirmationlineEdit_3->setVisible(true);
	ui.InscriptionButton->setVisible(true);
	ui.speudoinscritionlineEdit->setVisible(true);
	ui.pseudolabel_2->setVisible(true);
	ui.motDePasselabel_3->setVisible(true);

	//connexion
	ui.connexion->setVisible(false);
	ui.connexionButton->setVisible(true);
	ui.motdepasse->setVisible(false);
	ui.pseudo->setVisible(false);
	ui.speudoLineEdit->setVisible(false);
	ui.envoyerButton->setVisible(false);
	ui.mot_passeLineEdit->setVisible(false);
	//message
	ui.messageEnvoyer->setVisible(false);
	ui.zone_de_test->setVisible(false);
	ui.envoyerButton->setVisible(false);

	if (ui.speudoinscritionlineEdit->text().size() > 0 && ui.MDPlineEdit_2->text().size() > 0) {
		QString login = ui.speudoinscritionlineEdit->text();
		QString mdp = ui.MDPlineEdit_2->text();

		QString data = "Salt" + login + ";" + mdp;

		onInscriptionButtonClicked(data);
	}
}

void client::message()
{
	ui.dreamscord->setVisible(true);
	//inscription
	ui.incription->setVisible(false);
	ui.MDPlineEdit_2->setVisible(false);
	ui.confirmationMDPlabel_4->setVisible(false);
	ui.confirmationlineEdit_3->setVisible(false);
	ui.InscriptionButton->setVisible(false);
	ui.speudoinscritionlineEdit->setVisible(false);
	ui.pseudolabel_2->setVisible(false);
	ui.motDePasselabel_3->setVisible(false);

	//connexion
	ui.connexion->setVisible(false);
	ui.connexionButton->setVisible(true);
	ui.motdepasse->setVisible(false);
	ui.pseudo->setVisible(false);
	ui.speudoLineEdit->setVisible(false);
	ui.mot_passeLineEdit->setVisible(false);
	//message
	ui.messageEnvoyer->setVisible(true);
	ui.zone_de_test->setVisible(true);
	ui.envoyerButton->setVisible(true);

	if (ui.zone_de_test->text().size() > 0) {
		QString message = ui.zone_de_test->text();

		QString data = "Bdd" + message;

		onMessageButtonClicked(data);
		ui.zone_de_test->clear();
	}
}

void client::onConnectButtonClicked(QString message)
{
	socket->write(message.toUtf8());
}

void client::onInscriptionButtonClicked(QString message)
{
	socket->write(message.toUtf8());
}

void client::onMessageButtonClicked(QString message)
{
	socket->write(message.toUtf8());
}

void client::receivedTextMessage()
{
	QByteArray data = socket->read(socket->bytesAvailable());
	QString str(data);

	if (str == "Authtrue" || str == "Salttrue") {
		message();
		socket->write("sendok");
	}
	else {
		QStringList data = str.split(QString("#&%@"));
		for (QString message : data) {
			ui.messageEnvoyer->append(message);
		}
	}
}