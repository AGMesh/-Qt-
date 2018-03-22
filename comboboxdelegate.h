#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QItemDelegate>
/*!
     Класс, блокирующий ячейку таблицы под тип данных "ComboBox" (Выпадающий список)

*/
class ComboBoxDelegate : public QItemDelegate
{
public:
    ComboBoxDelegate(QWidget *parent = 0);
    ~ComboBoxDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
    QStringList list;
};

#endif // COMBOBOXDELEGATE_H
