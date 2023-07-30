#include <QGuiApplication>
#include "View/ViewController/HMIController.h"
int main(int argc, char** argv){
    QGuiApplication app(argc,argv);
    qmlRegisterType<ViewEnums>("HMIEvent",1,0,"HMIEvent");
    HMIController::registerState();
    HMIController::getInstance();
    HMIController::getInstance().changeScreen(ViewEnums::TO_A);
    HMIController::getInstance().show();
    return app.exec();
};