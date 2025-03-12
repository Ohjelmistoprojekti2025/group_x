#include "studentgrade.h"
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

void StudentMenu::on_btnMyData_clicked()
{
    QString site_url=environment::base_url()+"/student/"+username;
    QNetworkRequest request(site_url);
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &StudentMenu::myDataSlot);

    reply = manager->get(request);
}

void StudentMenu::myDataSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    StudentData *objStudentData=new StudentData(this);
    objStudentData->setMyData(response_data);
    objStudentData->open();
    //qDebug()<<response_data;
    reply->deleteLater();
    manager->deleteLater();
}


void StudentMenu::on_btnGrades_clicked()
{
    QString site_url=environment::base_url()+"/grade/"+username;
    QNetworkRequest request(site_url);
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &StudentMenu::myGradeSlot);

    reply = manager->get(request);
}

void StudentMenu::myGradeSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    StudentGrade *objStudentGrade=new StudentGrade(this);
    objStudentGrade->setMyGrades(response_data);
    objStudentGrade->open();


    reply->deleteLater();
    manager->deleteLater();
}
