TEMPLATE = app

QT += qml quick widgets network

SOURCES += main.cpp \
    token.cpp \
    wallet.cpp \
    mainwindow.cpp \
    appcontroller.cpp \
    transaction.cpp \
    upayhttpsbackend.cpp \
    walletmanager.cpp \
    walletstorage.cpp

RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    token.h \
    wallet.h \
    mainwindow.h \
    appcontroller.h \
    transaction.h \
    upayhttpsbackend.h \
    walletmanager.h \
    walletstorage.h

FORMS += \
    mainwindow.ui
