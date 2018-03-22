#include "doubledelegate.h"
#include <QDoubleSpinBox>
#include <QApplication>

DoubleDelegate::DoubleDelegate(QWidget *parent): QItemDelegate(parent)
{

}

DoubleDelegate::~DoubleDelegate()
{

}

QWidget *DoubleDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    editor->setMinimum(0);
    editor->setSingleStep(.01);
    editor->setMaximum(100000);
    return editor;
}

void DoubleDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    double value = index.model()->data(index, Qt::EditRole).toDouble();
    QDoubleSpinBox *spinBox = qobject_cast<QDoubleSpinBox *>(editor);
    if (value)
        spinBox->setValue(value);
}

void DoubleDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = qobject_cast<QDoubleSpinBox *>(editor);
    double value = spinBox->value();
    if (value)
        model->setData(index, value, Qt::EditRole);
}

void DoubleDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
