#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("username",ui->textUsername->text());
    jsonObj.insert("password",ui->textPassword->text());


    QString site_url=environment::base_url()+"/login";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::loginSlot);

    reply = manager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QMessageBox objMessageBox;
    if(response_data.length()<2 || response_data=="db_error"){
        qDebug()<<"Virhe yhteydessä";

        objMessageBox.setText("Virhe tietoliikenne yhteydessä");
        objMessageBox.exec();
    } else {
        if (response_data == "false") {
            qDebug() << "Tunnus tai salasana väärin";
            objMessageBox.setText("Tunnus ja salasana eivät täsmää");
            objMessageBox.exec();
        } else {
            qDebug() << response_data;
            QByteArray token="Bearer "+response_data;
            StudentMenu *objStudentMenu = new StudentMenu(this);
            objStudentMenu->setUsername(ui->textUsername->text());
            objStudentMenu->setWebToken(token);

            objStudentMenu->open();
        }
    }
}

