#ifndef SYSTEM_MANIPULATION_H
#define SYSTEM_MANIPULATION_H
#include <QQmlEngine>
#include "UIControl/UIControl.h"
#include "ContextManager/ContextManager.h"
#include <QQuickView>
#include <QQmlComponent>
class SystemManipulation{
    private:
        SystemManipulation();
    public:
        ~SystemManipulation();
        static SystemManipulation* getInstance();
        static void applyEngine(QQmlEngine* engine);
    private:
        static QQmlEngine* gEngine;
        ContextManager&    mContextMng;
        UIControl&          mUIControl;

        QQuickView*        mCenterView;

};
#endif 