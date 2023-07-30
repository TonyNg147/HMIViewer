QT += quick
TEMPLATE=app
include(View/View.pri)
include(HMIController/HMIController.pri)
RESOURCES+= \
            HMIResources.qrc
SOURCES+= \
        main.cpp
