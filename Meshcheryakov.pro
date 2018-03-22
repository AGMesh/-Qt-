#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T21:31:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Meshcheryakov
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutwindow.cpp \
    complist.cpp \
    table.cpp \
    checkboxdelegate.cpp \
    spinboxdelegate.cpp \
    comboboxdelegate.cpp \
    comboboxdelegate2.cpp \
    doubledelegate.cpp \
    qcustomplot.cpp \
    histogram.cpp

HEADERS  += mainwindow.h \
    aboutwindow.h \
    complist.h \
    table.h \
    checkboxdelegate.h \
    spinboxdelegate.h \
    comboboxdelegate.h \
    comboboxdelegate2.h \
    doubledelegate.h \
    qcustomplot.h \
    histogram.h

FORMS    += mainwindow.ui \
    aboutwindow.ui \
    table.ui \
    histogram.ui

TRANSLATIONS += tr/Meshcheryakov_ru_RU.ts \
tr/Meshcheryakov_en_US.ts \
tr/Meshcheryakov_fr_BE.ts

RESOURCES += \
    icon.qrc
