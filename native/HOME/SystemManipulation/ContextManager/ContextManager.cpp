#include "ContextManager.h"


ContextManager* ContextManager::singletonObject = nullptr;

ContextManager& ContextManager::getInstance(QQmlEngine* engine){
    static ContextManager instance(engine);
    return instance;
}
ContextManager::ContextManager(QQmlEngine* engine){
    if (engine){
        printf("Init object hererere \n");
        gEngine         = engine;
        singletonObject = this;
    }else{
        //throw 
    }
}
ContextManager::~ContextManager(){
    
}

