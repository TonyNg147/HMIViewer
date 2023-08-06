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
    mCenterView = qobject_cast<QQuickView*>(centerView->create(gEngine->rootContext()));
    delete centerView;
    qWarning()<<__LINE__;
    mContextMng.registerProperty("CENTER_DISPLAY",QVariant::fromValue(mCenterView));
    qWarning()<<__LINE__;
}

SystemManipulation::~SystemManipulation(){

}
