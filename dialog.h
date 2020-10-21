#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include <QKeyEvent>
#include <QLine>
#include <QGraphicsEllipseItem>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    virtual void paintEvent(QPaintEvent *e, int i, QGraphicsScene *scene );
    void check(char x);

    QGraphicsEllipseItem* ellipse;


private:
    Ui::Dialog *ui;
    QString message="TRIAL";
    int index;
    int mistakeCount=0;
    int correctCount=0;
    QGraphicsScene* scene;
    QLine* x;

private slots:
    void keyPressEvent(QKeyEvent *event);
};
#endif // DIALOG_H
