#ifndef CONTEXT_MANAGER_H
#define CONTEXT_MANAGER_H
#include <QQmlContext>
#include <QQmlEngine>
class SystemManipulation;
class ContextManager{
    friend class SystemManipulation;
    public:
        template<typename _T>
        static bool registerProperty(const QString& pro, _T val){
            if (singletonObject){
                return singletonObject->setProperty(pro,val);
            }
            return false;
        }
    private:
        ContextManager(QQmlEngine* engine);
        ~ContextManager();
        static ContextManager* singletonObject;
        static ContextManager& getInstance(QQmlEngine* engine);
    private:
        template<typename _T>
        bool setProperty(const QString& pro, _T val){
            gEngine->rootContext()->setContextProperty(pro,val);
            return true;
        }
    private:
        QQmlEngine*     gEngine;
};
#endif 