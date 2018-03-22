#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include "complist.h"
#include "mainwindow.h"
#include "checkboxdelegate.h"
#include "spinboxdelegate.h"
#include "comboboxdelegate.h"
#include "comboboxdelegate2.h"
#include "doubledelegate.h"
#include "Histogram.h"

namespace Ui {
class table;
}
/*!
    \brief  Класс, создающий таблицу с данными

     Отвеает за заполнение таблицы, удаление элементов, добавление новых и их перемещение внутри программы. Дает возможность сформировать гистограмму.
*/
class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();
    ///Метод открытия файла
    void openFile();
    ///Метод добавления новой строки в таблицу
    void add();
    ///Метод удаления строки из таблицы
    void remove();
    ///Метод сохранения таблицы в txt файл
    void save();

private slots:
    ///Метод вызова создания новой строки в таблице по нажатию кнопки
    void on_pushButton_Add_clicked();
    ///Метод вызова удаления строки по нажатию кнопки
    void on_pushButton_Remove_clicked();
    ///Метод вызова сохранения по нажатию кнопки
    void on_pushButton_Save_clicked();
    ///Метод вызова гистограммы по нажатию кнопки
    void on_pushButton_Histogram_clicked();

private:
    Ui::table *ui;
    QList<CompList>basalist;
    QString FileName;
    QString colorWidget = "rgb(240, 240, 240);";
    QString colorText = "rgb(0, 0, 0);";
protected:
public slots:
};

#endif // TABLE_H
