#ifndef UI_PROPERTY_H
#define UI_PROPERTY_H
#include <QObject>
#include <UIConstant/UILayout.h>
#include <QQmlEngine>
class UIPro: public QObject{
    Q_OBJECT
    public:
        static void registerProes();
};

inline void UIPro::registerProes(){
    qmlRegisterType<uicommon::UILayout>("UIConstant",1,0,"UIConstant");
}
#endif