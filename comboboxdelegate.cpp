#include "comboboxdelegate.h"
#include <QComboBox>
#include <QApplication>
#include "table.h"
#include <QMetaProperty>
#include <QStringList>

ComboBoxDelegate::ComboBoxDelegate(QWidget *parent): QItemDelegate(parent)
{
    list << "ATX" << "mATX" << "FlexATX" << "DTX" << "ITX";
}

ComboBoxDelegate::~ComboBoxDelegate()
{

}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    for (int var = 0; var < list.size(); var++)
    {
        editor->addItem(list[var]);
    }
    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *ComboBox = qobject_cast<QComboBox *>(editor);
    QString v = index.model()->data(index, Qt::DisplayRole).toString();
    int value;
    if (v == list[0])
        value = 0;
    else
        if (v == list[1])
            value = 1;
        else
            if (v == list[2])
                value = 2;
            else
                if (v == list[3])
                    value = 3;
                else
                    if (v == list[4])
                        value = 4;
    ComboBox->setCurrentIndex(value);
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *ComboBox = static_cast<QComboBox*>(editor);
    QString value = ComboBox->currentText();
    model->setData(index, value, Qt::DisplayRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
