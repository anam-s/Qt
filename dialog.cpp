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
 painter.drawLine(10,10,100,100);
}

