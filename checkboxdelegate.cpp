#include "checkboxdelegate.h"
#include <QCheckBox>
#include <QApplication>

CheckBoxDelegate::CheckBoxDelegate(QWidget *parent): QStyledItemDelegate(parent)
{

}

CheckBoxDelegate::~CheckBoxDelegate()
{

}

QWidget *CheckBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QCheckBox *editor = new QCheckBox(parent);

    return editor;
}

void CheckBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
    bool value = index.model()->data(index, Qt::DisplayRole).toBool();
    checkBox->setChecked(value);
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);

    model->setData(index, checkBox->isChecked());
}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    bool value = index.data().toBool();

    QStyleOptionButton checkBox;
    checkBox.state = QStyle::State_Enabled;
    checkBox.rect = option.rect;
    if (value)
        checkBox.state |= QStyle::State_On;
    else
        checkBox.state |= QStyle::State_Off;//поразрядное сложение (сохраняется в одной переменой более или два значения)
    //i = i + 1; i++; i += 1;

    QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkBox, painter);

}

