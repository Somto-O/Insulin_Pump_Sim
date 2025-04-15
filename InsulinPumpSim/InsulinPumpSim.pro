QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++11 automoc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boluscalculator.cpp \
    cgm.cpp \
    history.cpp \
    insulinpump.cpp \
    main.cpp \
    mainwindow.cpp \
    profile.cpp \
    systemalerts.cpp \
    user.cpp

HEADERS += \
    boluscalculator.h \
    cgm.h \
    history.h \
    insulinpump.h \
    mainwindow.h \
    profile.h \
    systemalerts.h \
    user.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
