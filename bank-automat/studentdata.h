#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QDialog>


namespace Ui {
class StudentData;
}

class StudentData : public QDialog
{
    Q_OBJECT

public:
    explicit StudentData(QWidget *parent = nullptr);
    ~StudentData();



    void setMyData(const QByteArray &newMyData);

private:
    Ui::StudentData *ui;
    QByteArray myData;

};

#endif // STUDENTDATA_H
