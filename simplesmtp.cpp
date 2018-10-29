#include "simplesmtp.h"
#include "ui_simplesmtp.h"
#include <QMessageBox>

SimpleSMTP::SimpleSMTP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleSMTP)
{
    ui->setupUi(this);
    socket = SMTPSocket::getSocket();
}

SimpleSMTP::~SimpleSMTP()
{
    delete ui;
}

void SimpleSMTP::on_pushButton_clicked()
{
    QMessageBox::warning(this, "Hello", "Hello");
    socket->sendToAllClients(220, {ui->allClientMsg->text()});
}
