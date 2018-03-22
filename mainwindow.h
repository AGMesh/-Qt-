#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QSettings>
#include <QMouseEvent>
#include <QThread>
#include <QDebug>

namespace Ui {
class MainWindow;
}
/*!
    \brief Родительский класс Главное окно программы.

    Данный класс дает возможность изменить настройки главного окна, выбрать язык, вызвать окна для работы с информацией по варианту, посмотреть информацию о программе и студенте.
*/
class QActionGroup;
class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    /// Метод открытия файла
    void open();
    /// Метод создания нового окна
    void create();
    /// Метод переключателя языка
    void switchLanguage(QAction *action);
    /// Метод вызова окна "О программе"
    void about();
    /// Метод установки цвета окна
    void setColorWindow();
    /// Метод установки цвета текста
    void setColorText();
private:
    Ui::MainWindow *ui;
    QSettings* settings;
    /// Метод сохранения настроек в реестр
    void saveSettings();
    /// Метод загрузки настроек из реестра
    void loadSettings();
    QTranslator appTranslator;
    QTranslator gtTranslator;
    QActionGroup *languageActionGroup;
    QString qmPath;
    QString colorWidget = "rgb(240, 240, 240);";
    QString colorText = "rgb(0, 0, 0);";
    /// Метод создания меню "язык"
    void creatorLanguageMenu();
};

#endif // MAINWINDOW_H
