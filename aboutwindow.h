#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

namespace Ui {
class aboutwindow;
}
/*!
    \brief Класс "О Программме"

    Содержится информация о студенте, а также о программе.
*/
class aboutwindow : public QDialog
{
    Q_OBJECT

public:
    explicit aboutwindow(QWidget *parent = 0);
    ~aboutwindow();

private slots:
    /// Функция закрытия окна по нажатию кнопки
    void on_pushButton_clicked();

private:
    Ui::aboutwindow *ui;
};

#endif // ABOUTWINDOW_H
