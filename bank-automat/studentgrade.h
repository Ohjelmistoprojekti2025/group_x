#ifndef STUDENTGRADE_H
#define STUDENTGRADE_H

#include <QDialog>

namespace Ui {
class StudentGrade;
}

class StudentGrade : public QDialog
{
    Q_OBJECT

public:
    explicit StudentGrade(QWidget *parent = nullptr);
    ~StudentGrade();

    void setMyGrades(const QByteArray &newMyGrades);

private:
    Ui::StudentGrade *ui;
    QByteArray myGrades;
};

#endif // STUDENTGRADE_H
