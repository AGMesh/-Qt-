#ifndef COMPLIST_H
#define COMPLIST_H

#include <QString>
#include <QList>
/*!
    \brief Класс унаследованный от <QList>

    Данный класс создает двухсвязный список из 8 элементов.
*/
class CompList
{
    QString mfr;
    QString make;
    QString RType;
    int PS;
    QString MB;
    int USB;
    int in_stock;
    double Price;
public:
    CompList();
    CompList(const QString recMfr,
             const QString recMake,
             const QString kType,
             const int recPS,
             const QString kMB,
             const int USB,
             const int rec_in_stock,
             const int Price);
    /// Функция изменения Производителя
    void setMfr(const QString recMfr);
    /// Функция, возвращающая название Производителя
    QString getMfr() const;
    /// Функция изменения Модели
    void setMake(const QString recMake);
    /// Функция, возвращающая название Модели
    QString getMake() const;
    /// Функция изменения Типа корпуса
    void setRType(const QString kType);
    /// Функция, возвращающая Тип корпуса
    QString getRType() const;
    /// Функция изменения наличия Блока питания
    void setPS(const int recPS);
    /// Функция, возвращающая значение наличия Блока питания
    int getPS() const;
    /// Функция изменения Материнской платы
    void setMB(const QString kMB);
    /// Функция, возвращающая название Материнской платы
    QString getMB() const;
    /// Функция изменения количества USB портов
    void setUSB(const int rUSB);
    /// Функция, возвращающая количество USB портов
    int getUSB() const;
    /// Функция изменения наличия
    void set_in_stock(const int rec_in_stock);
    /// Функция, возвращающая значение наличия
    int get_in_stock() const;
    /// Функция изменения цены
    void setPrice(const double rPrice);
    /// Функция, возвращающая значение цены
    double getPrice() const;
};

#endif // COMPLIST_H
