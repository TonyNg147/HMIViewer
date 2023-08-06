TEMPLATE=lib
QT+= quick dbus
include(HMIController/HMIController.pri)
TARGET=UICommon
DESTDIR=$$OUT_PWD/../../apps/libraries


SOURCES += \
            uicommon.cpp \
            Proxy/SystemUI/SystemUIAdapter.cpp \
            Proxy/SystemUI/SystemUIInterface.cpp 

HEADERS += \
            UIConstant/UILayout.h \ 
            Proxy/SystemUI/SystemUIAdapter.h \
            Proxy/SystemUI/SystemUIInterface.h \
            Proxy/SystemUI/SystemUIAgency.h 
INCLUDEPATH += \
                $$PWD/UIConstant