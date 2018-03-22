#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"

#include <QFileDialog>
#include <QActionGroup>
#include <QLibraryInfo>
#include <QColorDialog>
#include <QMessageBox>
#include "table.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new QSettings(this);
    loadSettings();
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionCreate, SIGNAL(triggered()), this, SLOT(create()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->action_About_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionSet_Color_Window, SIGNAL(triggered()), this, SLOT(setColorWindow()));
    connect(ui->actionSet_Color_Text, SIGNAL(triggered()), this, SLOT(setColorText()));
    qApp->installTranslator(&appTranslator);
    qApp->installTranslator(&gtTranslator);
    qmPath = qApp->applicationDirPath() + "/tr";
    creatorLanguageMenu();
    QIcon Icon(":/new/prefix1/icon/folder.ico");
    this->setWindowIcon(Icon);
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::open()
{
    table *t = new table;
    t->setAttribute(Qt::WA_DeleteOnClose);
    t->setWindowTitle(tr("New Table"));
    t->openFile();
    t->show();
}

void MainWindow::create()
{
    table *t = new table;
    t->setAttribute(Qt::WA_DeleteOnClose);
    t->setWindowTitle(tr("New Table"));
    t->show();
}

void MainWindow::switchLanguage(QAction *action)
{
    QString locale = action->data().toString();
    appTranslator.load("Meshcheryakov_" + locale, qmPath);
    locale.chop(3);
    gtTranslator.load("qt_" + locale + ".qm", QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    ui->retranslateUi(this);
}

void MainWindow::about()
{
    aboutwindow a;
    a.exec();
}

void MainWindow::setColorWindow()
{
    QColor color = QColorDialog::getColor();
    colorWidget = "rgb(" + QString::number(color.red()) + ", " + QString::number(color.green()) + ", " + QString::number(color.blue()) + ");";
    if (colorWidget == colorText)
    {
    int answer = QMessageBox::question(this, tr("Set Color Window"), tr("The selected Color is the same as the text color.\nDo you really want to select this color?"),
                                   QMessageBox::Yes |
                                   QMessageBox::No);
    if (answer == QMessageBox::No)
        setColorWindow();
    else
        this->setStyleSheet("background-color: " + colorWidget + "color: " + colorText);
    }
    else
        this->setStyleSheet("background-color: " + colorWidget + "color: " + colorText);
}

void MainWindow::setColorText()
{
    QColor color = QColorDialog::getColor();
    colorText = "rgb(" + QString::number(color.red()) + ", " + QString::number(color.green()) + ", " + QString::number(color.blue()) + ");";
    if (colorWidget == colorText)
    {
    int answer = QMessageBox::question(this, tr("Set Color Window"), tr("The selected Color is the same as the text color.\nDo you really want to select this color?"),
                                   QMessageBox::Yes |
                                   QMessageBox::No);
    if (answer == QMessageBox::No)
        setColorText();
    else
        this->setStyleSheet("background-color: " + colorWidget + "color: " + colorText);
    }
    else
        this->setStyleSheet("background-color: " + colorWidget + "color: " + colorText);
}

void MainWindow::saveSettings()
{
    QString B = colorWidget;
    QString F = colorText;
    settings->setValue("Geometry", geometry());
    settings->setValue("Background", B);
    settings->setValue("Foreground", F);
}

void MainWindow::loadSettings()
{
    setGeometry(settings->value("Geometry", QRect(200, 200, 300, 300)).toRect());
    colorWidget = settings->value("Background", "rgb(240, 240, 240);").toString();
    colorText = settings->value("Foreground", "rgb(0, 0, 0);").toString();
    this->setStyleSheet("background-color: " + colorWidget + "color: " + colorText);
}

void MainWindow::creatorLanguageMenu()
{
    languageActionGroup = new QActionGroup(this);
    connect(languageActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(switchLanguage(QAction*)));
    QDir dir(qmPath);
    QStringList fileNames = dir.entryList(QStringList("Meshcheryakov_*.qm"));
    for (int var = 0; var < fileNames.size(); ++var)
    {
        QString locale = fileNames[var];
        locale.remove(0, locale.indexOf('_') + 1);
        locale.truncate(locale.lastIndexOf('.'));
        QTranslator translator;
        translator.load(fileNames[var], qmPath);
        QString language = translator.translate("MainWindow", "English");
        QIcon ico(QString(":/new/prefix1/icon/%1.png").arg(locale));
        QAction *action = new QAction(ico, tr("%1").arg(language), this);
        action->setCheckable(true);
        action->setData(locale);
        ui->menu_Language->addAction(action);
        languageActionGroup->addAction(action);
        if (language == "English")
            action->setChecked(true);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        QMenu menu; //Создание меню
        QAction * action_Create = menu.addAction(tr("Create"));
        QAction * action_Open = menu.addAction(tr("Open"));
        QAction * action = menu.exec(QCursor::pos());
        if (action == action_Create)
            create();
        if (action == action_Open)
            open();
    }
}
