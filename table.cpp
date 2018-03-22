#include "table.h"
#include "ui_table.h"
#include <QWindow>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include "Histogram.h"

table::table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
    QIcon DIcon(":/new/prefix1/icon/document.ico");
    this->setWindowIcon(DIcon);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setItemDelegateForColumn(2, new ComboBoxDelegate2(this));
    ui->tableWidget->setItemDelegateForColumn(3, new CheckBoxDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(4, new ComboBoxDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(5, new SpinBoxDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(6, new CheckBoxDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(7, new DoubleDelegate(this));
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Manufacturer")));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Model")));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Type of shell")));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Power Supply")));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Motherboard")));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Number of USB")));
    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem(tr("In Stock")));
    ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Price")));
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

table::~table()
{
    delete ui;
}

void table::on_pushButton_Add_clicked()
{
    add();
}

void table::on_pushButton_Remove_clicked()
{
    remove();
}

void table::on_pushButton_Save_clicked()
{
    save();
}

void table::openFile()
{
    CompList basa;
    QFile file;
    int j;
    double f;
    QString str;
    QStringList list;
    QTextStream stream(&file);
    FileName = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), "Текстовые файлы (*.txt);;Файлы данных (*.dat)");
    if (FileName == "")
        return;
    file.setFileName(FileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << tr("Not opened");
        return;
    }
    else
    {
        QStringList::iterator i;
        QList<CompList>::iterator k;
        setWindowTitle(FileName);
        while(!stream.atEnd())
        {
            str = stream.readLine();
            list = str.split(";");
            i = list.begin();
            str = *i;
            basa.setMfr(str);
            i++;
            str = *i;
            basa.setMake(str);
            i++;
            str = *i;
            basa.setRType(str);
            i++;
            str = *i;
            j = str.toInt();
            basa.setPS(j);
            i++;
            str = *i;
            basa.setMB(str);
            i++;
            str = *i;
            j = str.toInt();
            basa.setUSB(j);
            i++;
            str = *i;
            j = str.toInt();
            basa.set_in_stock(j);
            i++;
            str = *i;
            f = str.toDouble();
            basa.setPrice(f);
            i++;
            str = *i;
            basalist << basa;
            }
        file.close();
        k = basalist.end();
        k--;
        ui->tableWidget->setRowCount(basalist.size());
        k = basalist.begin();
        for(j=0;k != basalist.end();j++,k++)
        {
            ui->tableWidget->setItem(j, 0, new QTableWidgetItem(k->getMfr()));
            ui->tableWidget->setItem(j, 1, new QTableWidgetItem(k->getMake()));
            ui->tableWidget->setItem(j, 2, new QTableWidgetItem(k->getRType()));
            ui->tableWidget->setItem(j, 3, new QTableWidgetItem(str.setNum(k->getPS())));
            ui->tableWidget->setItem(j, 4, new QTableWidgetItem(k->getMB()));
            ui->tableWidget->setItem(j, 5, new QTableWidgetItem(str.setNum(k->getUSB())));
            ui->tableWidget->setItem(j, 6, new QTableWidgetItem(str.setNum(k->get_in_stock())));
            ui->tableWidget->setItem(j, 7, new QTableWidgetItem(str.setNum(k->getPrice())));
        }
    }
}

void table::add()
{
    CompList basa1;
    QString str1;
    int r;
    int k;
    k=ui->tableWidget->rowCount();
    basalist.clear();
    QTableWidgetItem * getItem;
    for(r = 0; r < k; r++)
    {
        getItem = ui->tableWidget->item(r, 0);
        str1 = getItem->text();
        basa1.setMfr(str1);
        getItem = ui->tableWidget->item(r, 1);
        str1 = getItem->text();
        basa1.setMake(str1);
        getItem = ui->tableWidget->item(r, 2);
        str1 = getItem->text();
        basa1.setRType(str1);
        getItem = ui->tableWidget->item(r, 3);
        str1 = getItem->text();
        basa1.setPS(str1.toInt());
        getItem = ui->tableWidget->item(r, 4);
        str1 = getItem->text();
        basa1.setMB(str1);
        getItem = ui->tableWidget->item(r, 5);
        str1 = getItem->text();
        basa1.setUSB(str1.toInt());
        getItem = ui->tableWidget->item(r, 6);
        str1 = getItem->text();
        basa1.set_in_stock(str1.toInt());
        getItem = ui->tableWidget->item(r, 7);
        str1 = getItem->text();
        basa1.setPrice(str1.toDouble());
        basalist << basa1;
    }
    int i;
    CompList basa;
    basalist << basa;
    ui->tableWidget->setRowCount(basalist.size());
    for(i = 0; i < 8; i++)
    {
        ui->tableWidget->setItem(basalist.size()-1,i, new QTableWidgetItem("0"));
    }
}

void table::remove()
{
    CompList basa;
    QString str1;
    int i;
    int k;
        k=ui->tableWidget->rowCount();
        basalist.clear();
        QTableWidgetItem * getItem;
        for(i = 0; i < k; i++)
        {
            getItem = ui->tableWidget->item(i, 0);
            str1 = getItem->text();
            basa.setMfr(str1);

            getItem = ui->tableWidget->item(i, 1);
            str1 = getItem->text();
            basa.setMake(str1);

            getItem = ui->tableWidget->item(i, 2);
            str1 = getItem->text();
            basa.setRType(str1);

            getItem = ui->tableWidget->item(i, 3);
            str1 = getItem->text();
            basa.setPS(str1.toInt());

            getItem = ui->tableWidget->item(i, 4);
            str1 = getItem->text();
            basa.setMB(str1);

            getItem = ui->tableWidget->item(i, 5);
            str1 = getItem->text();
            basa.setUSB(str1.toInt());

            getItem = ui->tableWidget->item(i, 6);
            str1 = getItem->text();
            basa.set_in_stock(str1.toInt());

            getItem = ui->tableWidget->item(i, 7);
            str1 = getItem->text();
            basa.setPrice(str1.toDouble());
            basalist << basa;
    }
    int num;
    int j;
    QString str;
    if (basalist.isEmpty())
    {
        QMessageBox::warning(this, tr("Delete"), tr("List is empty"), QMessageBox::Ok);
    }
    else
    {
        num = ui->tableWidget->currentRow();
        if(num > basalist.size()-1)
            QMessageBox::warning(this, tr("Delete"), tr("NO!"), QMessageBox::Ok);
        else
        {
            basalist.removeAt(num);
            ui->tableWidget->setRowCount(basalist.size());
            QList<CompList>::iterator k = basalist.begin();
            for(j=0;k != basalist.end();j++,k++)
            {
                ui->tableWidget->setItem(j, 0, new QTableWidgetItem(k->getMfr()));
                ui->tableWidget->setItem(j, 1, new QTableWidgetItem(k->getMake()));
                ui->tableWidget->setItem(j, 2, new QTableWidgetItem(k->getRType()));
                ui->tableWidget->setItem(j, 3, new QTableWidgetItem(str.setNum(k->getPS())));
                ui->tableWidget->setItem(j, 4, new QTableWidgetItem(k->getMB()));
                ui->tableWidget->setItem(j, 5, new QTableWidgetItem(str.setNum(k->getUSB())));
                ui->tableWidget->setItem(j, 6, new QTableWidgetItem(str.setNum(k->get_in_stock())));
                ui->tableWidget->setItem(j, 7, new QTableWidgetItem(str.setNum(k->getPrice())));
            }
        }
    }

}

void table::save()
{
    CompList basa;
    QFile file;
    QString strfile;
    QTextStream out(&file);
     QString str;
    int i;
    int j,k;
    FileName = QFileDialog::getSaveFileName(this, tr("Saving file"), "", "Текстовые файлы (*.txt);;Файлы данных (*.dat)");
    file.setFileName(FileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << tr("Not opened");
        return;
    }
    else
    {
        k =  ui->tableWidget->rowCount();
         basalist.clear();
        QTableWidgetItem * getItem;
        for(i=0; i < k; i++)
        {
            strfile = "";
            getItem = ui->tableWidget->item(i, 0);
            str = getItem->text();
            basa.setMfr(str);

            getItem = ui->tableWidget->item(i, 1);
            str = getItem->text();
            basa.setMake(str);

            getItem = ui->tableWidget->item(i, 2);
            str = getItem->text();
            basa.setRType(str);

            getItem = ui->tableWidget->item(i, 3);
            str = getItem->text();
            basa.setPS(str.toInt());

            getItem = ui->tableWidget->item(i, 4);
            str = getItem->text();
            basa.setMB(str);

            getItem = ui->tableWidget->item(i, 5);
            str = getItem->text();
            basa.setUSB(str.toInt());

            getItem = ui->tableWidget->item(i, 6);
            str = getItem->text();
            basa.set_in_stock(str.toInt());

            getItem = ui->tableWidget->item(i, 7);
            str = getItem->text();
            basa.setPrice(str.toDouble());
            basalist << basa;
            for(j=0; j < 8 ;j++)
            {
                getItem = ui->tableWidget->item(i, j);
                str = getItem->text();
                qDebug() << str;
                strfile += str+ ";" ;
            }
        out << strfile << "\r\n";
        }
        file.close();
    }
}

void table::on_pushButton_Histogram_clicked()
{
    QStringList Mfr0;
    QStringList Mfr1;
    QList<int> Make;
    int i, j;
    int k, n;
    k =  ui->tableWidget->rowCount();
    QTableWidgetItem * getItem;
    for(i = 0; i < k; i++)
    {
        getItem = ui->tableWidget->item(i, 0);
        Mfr0 << getItem->text();
    }
    Mfr1 = Mfr0;
    Mfr1.removeDuplicates();
    for (i = 0; i < Mfr1.size(); i++)
    {
        n = 0;
        for (j = 0; j < Mfr0.size(); j++)
        {
            if (Mfr1[i]==Mfr0[j])
                n++;
        }
        Make << n;
    }
    Histogram *h = new Histogram(this, &Mfr1, &Make);
    h->show();
}
