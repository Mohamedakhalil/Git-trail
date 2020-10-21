#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_A)
        check('A');
    if (event->key() == Qt::Key_B)
        check('B');
    if (event->key() == Qt::Key_C)
        check('C');
    if (event->key() == Qt::Key_D)
        check('D');
    if (event->key() == Qt::Key_E)
        check('E');
    if (event->key() == Qt::Key_F)
        check('F');
    if (event->key() == Qt::Key_G)
        check('G');
    if (event->key() == Qt::Key_H)
        check('H');
    if (event->key() == Qt::Key_I)
        check('I');
    if (event->key() == Qt::Key_J)
        check('J');
    if (event->key() == Qt::Key_K)
        check('K');
    if (event->key() == Qt::Key_L)
        check('L');
    if (event->key() == Qt::Key_M)
        check('M');
    if (event->key() == Qt::Key_N)
        check('N');
    if (event->key() == Qt::Key_O)
        check('O');
    if (event->key() == Qt::Key_P)
        check('P');
    if (event->key() == Qt::Key_Q)
        check('Q');
    if (event->key() == Qt::Key_R)
        check('R');
    if (event->key() == Qt::Key_S)
        check('S');
    if (event->key() == Qt::Key_T)
        check('T');
    if (event->key() == Qt::Key_U)
        check('U');
    if (event->key() == Qt::Key_V)
        check('V');
    if (event->key() == Qt::Key_W)
        check('W');
    if (event->key() == Qt::Key_X)
        check('X');
    if (event->key() == Qt::Key_Y)
        check('Y');
    if (event->key() == Qt::Key_Z)
        check('Z');
}
void Dialog::check(char x){
    if(message.contains(x)){
        index=message.indexOf(x);
        correctCount++;

       switch(index){
        case 0: ui->label_0->setText(message.at(index));
            break;
        case 1: ui->label_1->setText(message.at(index));
           break;
        case 2: ui->label_2->setText(message.at(index));
           break;
        case 3: ui->label_3->setText(message.at(index));
           break;
        case 4: ui->label_4->setText(message.at(index));
           ui->label_0->setText("CONGRATS");
           ui->label_1->hide();
           ui->label_2->hide();
           ui->label_3->hide();
           ui->label_4->hide();
           break;
        }
    }
    else{
        mistakeCount++;
        QPaintEvent *e;
        paintEvent(e, mistakeCount,scene);
    }

}
void Dialog::paintEvent(QPaintEvent *e, int i, QGraphicsScene *scene)
{
    Q_UNUSED( e )
    QPainter mytext(this);

   QPainter myLine(this);
   QPen Pen(Qt::black);
   Pen.setWidth(5);
   QPen Pen2(Qt::yellow);
   Pen2.setWidth(5);
   QBrush whiteBrush(Qt::white);

   myLine.setPen(Pen);
   switch (i) {

    case 1:x->setLine(50,500,450,500);
       scene->addLine(*x, Pen);
        break;
    case 2:x->setLine(250,500,250,50);
       scene->addLine(*x, Pen); //second mistake
        break;
    case 3:x->setLine(250,50,550,50);
       scene->addLine(*x, Pen);
        break;
    case 4:x->setLine(252,150,400,52);
       scene->addLine(*x, Pen); //forth mistake
        break;
    case 5:x->setLine(550,50,550,100);
       scene->addLine(*x, Pen);//Fith mistake
        break;
    case 6: ellipse = scene->addEllipse(QRectF(525,100, 50,50), Pen2, whiteBrush);
        break;
    case 7:x->setLine(550,150,550,275);
        scene->addLine(*x, Pen2); //seventh mistake
        break;
    case 8:x->setLine(552,175,600,200);
        scene->addLine(*x, Pen2); //eigth mistake
        break;
    case 9: x->setLine(548,175,500,200);
        scene->addLine(*x, Pen2); //ninth mistake
        break;
    case 10: x->setLine(550,275,600,300);
        scene->addLine(*x, Pen2); //tenth mistake
        break;
    case 11: x->setLine(550,275,500,300);
        scene->addLine(*x, Pen2); //elventh mistake
        ui->label_0->setText("GAME OVER");
        ui->label_1->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
       break;
}
}


