#include "spinboxdelegate.h"
#include <QSpinBox>
#include <QApplication>

SpinBoxDelegate::SpinBoxDelegate(QWidget *parent): QItemDelegate(parent)
{

}

SpinBoxDelegate::~SpinBoxDelegate()
{

}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(20);
    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(editor);
    if (value)
        spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(editor);
    int value = spinBox->value();
    if (value)
        model->setData(index, value, Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
