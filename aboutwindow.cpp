#include "aboutwindow.h"
#include "ui_aboutwindow.h"

#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QFont>
#include <QIcon>

aboutwindow::aboutwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutwindow)
{
    QIcon infoIcon(":/new/prefix1/icon/info.ico");
    this->setWindowIcon(infoIcon);
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    QPixmap myPixmap(":/new/prefix1/icon/istas.png");
    ui->label_pix->setPixmap(myPixmap);
    QFont font;
    font.setPointSize(12);
    font.setFamily("Times New Roman");
    ui->label_text->setFont(font);
    ui->label_variant->setFont(font);
    ui->label_text->setText(tr("Meshcheryakov Alexander IIEIS II-1, 2017"));
    ui->label_variant->setText(tr("Program in C ++ / Qt with GUI in accounting\n Devices of the PC \"System Block\""));
}

aboutwindow::~aboutwindow()
{
    delete ui;
}

void aboutwindow::on_pushButton_clicked()
{
    close();
}
