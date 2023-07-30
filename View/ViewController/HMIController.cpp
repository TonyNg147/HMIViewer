#include "HMIController.h"
#include "../Defines/Defines.h"
#include "../ScreenManager/ScreenManager.h"
Event_Register HMIController::mEvents;
HMIController::HMIController(QObject* parent )
    :QObject{parent}
{
    mView    = new QQuickView();
    mEngine  = mView->engine();
    mContext = mEngine->rootContext();
    qDebug()<<__LINE__;
    
    qDebug()<<__LINE__;
    ScreenManager::init(mEngine,mContext);
    // register context property
    {
        qDebug()<<"COntext hereer";
        mContext->setContextProperty("HMIComponent",nullptr);
        mContext->setContextProperty("HMIController",this);
    }
    mView->setSource(QUrl(ROOT_SCREEN));
}
HMIController& HMIController::getInstance(){
    static HMIController instance;
    return instance;
}
void HMIController::registerState(){
    for (size_t idx = 0; idx < size(SYSTEM_ALL_STATE) ; ++idx){
        for (size_t eventId = 0; eventId < SYSTEM_ALL_STATE[idx].eventSize ; ++eventId){
            qDebug()<<"register herere " << idx;
            mEvents[SYSTEM_ALL_STATE[idx].stateEvent[eventId].eventId] = SYSTEM_ALL_STATE[idx].stateEvent[eventId].destState;
        }
    }
}

void HMIController::changeScreen(uint16_t event){
    auto eventState = mEvents.find(event);
    if (eventState != mEvents.end()){
        ScreenManager::getInstance().showScreen((*eventState));
    }
}