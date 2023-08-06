#include "SystemManipulation.h"
QQmlEngine* SystemManipulation::gEngine = nullptr;
SystemManipulation* SystemManipulation::getInstance(){
    if(gEngine){
        static SystemManipulation instance;
        return &instance;
    }   
    return nullptr;
}
void SystemManipulation::applyEngine(QQmlEngine* engine){
    if (engine){
        gEngine = engine;
    }
}

SystemManipulation::SystemManipulation()
    :mContextMng{ContextManager::getInstance(gEngine)}
    ,mUIControl{UIControl::getInstance()}
{
    QQmlComponent* centerView = new QQmlComponent(gEngine,"qrc:/HMI/CenterDisplay.qml");
    if(centerView->errorString().size()){
        qWarning()<<"Error when create main window "<<centerView->errorString();
    }
    mCenterView = qobject_cast<QQuickWindow*>(centerView->create(gEngine->rootContext()));
    delete centerView;
    mContextMng.registerProperty("CENTER_DISPLAY",QVariant::fromValue(mCenterView));
}

SystemManipulation::~SystemManipulation(){

}
