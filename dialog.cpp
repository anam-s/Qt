#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::paintEvent(QPaintEvent *e)
{
 QPainter painter(this);
 painter.drawLine(50,50,200,200);

 //QRect rec(30,30,100,100);
 //QPen framepen(Qt::blue);
 //painter.drawRect(rec);

 QPen pen1(Qt::black);
    pen1.setWidth(5);

    QPen pen2(Qt::red);
    pen2.setWidth(5);

    QPen pen3(Qt::green);
    pen3.setWidth(5);

    QPen pen4(Qt::blue);
    pen4.setWidth(5);

    int x0 = 100;
    int y0 = 100;
    int width = 200;
    int height = 200;
    QRect rect(10, 10, width, height);

    // original rectangle
    painter.setPen(pen1);
    painter.drawRect(rect);


    // rotation
    // rotate around (0,0) which is top-left
    // rect center (xc,yc)
    //int xc = x0 + width/2;
    //int yc = y0 + height/2;
    int xc = 200 + width/2;
    int yc = 200 + height/2;

    // order of transformation
    //  (1) translate to top-left
    //  (2) rotate
    //  (3) move back to (xc,yc)
    //
    painter.translate(xc+100, yc+100);    //(3)
    painter.rotate(45);           //(2)
    painter.translate(-xc, -yc);  //(1)

    painter.setPen(pen2);
    painter.drawRect(rect);

    // scale -> 1/2
    painter.translate(xc+100, yc+100);
    painter.scale(0.5,0.5);
    painter.translate(-xc+100, -yc+100);

    painter.setPen(pen3);
    painter.drawRect(rect);

    // Back to the initial state
    // shear
    painter.resetTransform();
    painter.translate(xc+200, yc+200);
    painter.shear(0.5,0.5);
    painter.translate(-xc, -yc);

    painter.setPen(pen4);
    painter.drawRect(rect);
}



