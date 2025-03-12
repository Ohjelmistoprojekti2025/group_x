#include "studentgrade.h"
#include "ui_studentgrade.h"

#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>

StudentGrade::StudentGrade(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentGrade)
{
    ui->setupUi(this);
}

StudentGrade::~StudentGrade()
{
    delete ui;
}

void StudentGrade::setMyGrades(const QByteArray &newMyGrades)
{
    myGrades = newMyGrades;
    //qDebug()<<myGrades;
    //muutetaan QByteArray json dokumentiksi
    QJsonDocument json_doc = QJsonDocument::fromJson(myGrades);
    //muutetaan json dokumentti json arrayksi
    QJsonArray json_array = json_doc.array();
    QString grades;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        grades+=json_obj["course_name"].toString()+" | "+QString::number(json_obj["grade"].toInt())+" | "+json_obj["grade_date"].toString()+"\r";
    }
    qDebug()<<grades;
    ui->textGrades->setText(grades);
}
