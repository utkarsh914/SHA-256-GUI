#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <sha_256.h>

using std::string;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_messagePlainTextEdit_textChanged()
{
    string message = ui->messagePlainTextEdit->toPlainText().toStdString();
    string hash = SHA_256::get_hash(message);
    ui->hashLabel->setText(QString::fromStdString(hash));
}


void Widget::on_aboutButton_clicked()
{
    QString about = "Made by - Utkarsh Tiwari";
    QMessageBox::about(this, "About this app", about);
}
