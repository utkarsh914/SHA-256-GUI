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
    QString about = "";
    about += "Project Submitted by: TEAM-29\n\n";
    about += "1. Utkarsh Tiwari (1816015) - EIE\n";
    about += "2. Baibhab Chakraborty (1816009) - EIE\n";
    about += "3. Abhishek Baghele (1816010) - EIE\n";
    about += "4. Siddharth Garlapati (1816060) - EIE\n";
    about += "5. Mohit Kumar Kharwar (1816022) - EIE\n";
    about += "6. Shrihari Khetre (1816039) - EIE\n";

    QMessageBox::about(this, "About this app", about);
}
