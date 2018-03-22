#ifndef SPINBOXDELEGETA_H
#define SPINBOXDELEGETA_H

#include <QItemDelegate>
/*!
     Класс, блокирующий ячейку таблицы под тип данных "SpinBox"

*/
class SpinBoxDelegate : public QItemDelegate
{
public:
    SpinBoxDelegate(QWidget *parent = 0);
    ~SpinBoxDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // SPINBOXDELEGETA_H
