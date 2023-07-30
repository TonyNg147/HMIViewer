#include <QGuiApplication>
#include <HMIController.h>
#include <ViewDefines.h>
int main(int argc, char** argv){
    QGuiApplication app(argc,argv);
    qmlRegisterType<ViewEnums>("HMIEvent",1,0,"HMIEvent");
    HMIController::registerState(SYSTEM_ALL_STATE, size(SYSTEM_ALL_STATE));
    HMIController::getInstance();
    HMIController::getInstance().changeScreen(ViewEnums::TO_A);
    HMIController::getInstance().show();
    return app.exec();
};