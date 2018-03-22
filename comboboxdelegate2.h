#ifndef COMBOBOXDELEGATE2_H
#define COMBOBOXDELEGATE2_H

#include <QItemDelegate>
/*!
     Класс, блокирующий ячейку таблицы под тип данных "ComboBox" (Выпадающий список)

*/
class ComboBoxDelegate2 : public QItemDelegate
{
public:
    ComboBoxDelegate2(QWidget *parent = 0);
    ~ComboBoxDelegate2();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
    QStringList list;
};

#endif // COMBOBOXDELEGATE_H
