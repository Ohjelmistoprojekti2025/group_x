#include "studentdata.h"
#include "ui_studentdata.h"

#include <QJsonDocument>
#include <QJsonObject>



StudentData::StudentData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentData)
{
    ui->setupUi(this);
}

StudentData::~StudentData()
{
    delete ui;
}

void StudentData::setMyData(const QByteArray &newMyData)
{
    myData = newMyData;
    //qDebug()<<myData;
    //muutetaan QByteArray json dokumentiksi
    QJsonDocument json_doc = QJsonDocument::fromJson(myData);
    //muutetaan json dokumentti json objektiksi
    QJsonObject json_obj = json_doc.object();
    QString studentName=json_obj["fname"].toString()+" "+json_obj["lname"].toString();
    QString streetAddress=json_obj["streetaddress"].toString();
    QString email=json_obj["email"].toString();

    ui->labelStudentName->setText(studentName);
    ui->labelStreetAddress->setText(streetAddress);
    ui->labelEmail->setText(email);
    qDebug()<<studentName;

}

