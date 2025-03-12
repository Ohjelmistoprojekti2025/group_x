#include "studentmenu.h"
#include "ui_studentmenu.h"

StudentMenu::StudentMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentMenu)
{
    ui->setupUi(this);
}

StudentMenu::~StudentMenu()
{
    delete ui;
}

void StudentMenu::setUsername(const QString &newUsername)
{
    username = newUsername;
    ui->labelUsername->setText(username);
}

void StudentMenu::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug()<<webToken;
}
