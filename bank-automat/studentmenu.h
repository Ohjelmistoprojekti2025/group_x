#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <QDialog>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QMessageBox>
#include "environment.h"
#include "studentdata.h"

namespace Ui {
class StudentMenu;
}

class StudentMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMenu(QWidget *parent = nullptr);
    ~StudentMenu();

    void setUsername(const QString &newUsername);

    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_btnMyData_clicked();
    void myDataSlot(QNetworkReply *reply);
    void myGradeSlot(QNetworkReply *reply);

    void on_btnGrades_clicked();

private:
    Ui::StudentMenu *ui;
    QString username;
    QByteArray webToken;

    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // STUDENTMENU_H
