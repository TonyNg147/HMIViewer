TEMPLATE = app
TARGET   = HOME
DESTDIR = $$OUT_PWD/../../apps/HOME
CONFIG += c++11 link_pkgconfig exceptions
CONFIG -= app_bundle qml_debug

DEFINES += QT_MESSAGELOGCONTEXT

QT = appman_main-private

HEADERS += \
            SystemManipulation/UIControl/UIControl.h \
            UIProperties.h \
            SystemManipulation/ContextManager/ContextManager.h \
            SystemManipulation/SystemManipulation.h
SOURCES += \
            main.cpp \
            SystemManipulation/UIControl/UIControl.cpp \
            SystemManipulation/ContextManager/ContextManager.cpp \
            SystemManipulation/SystemManipulation.cpp


INCLUDEPATH += $$PWD/../UICommon

LIBS+= -L $$OUT_PWD/../../apps/libraries -lUICommon

RESOURCES += \
             Resources/HMI.qrc 
