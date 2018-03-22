#ifndef DOUBLEDELEGATE_H
#define DOUBLEDELEGATE_H

#include <QItemDelegate>
/*!
     Класс, блокирующий ячейку таблицы под тип данных "Double"

*/
class DoubleDelegate : public QItemDelegate
{
public:
    DoubleDelegate(QWidget *parent = 0);
    ~DoubleDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // DOUBLEDELEGATE_H
