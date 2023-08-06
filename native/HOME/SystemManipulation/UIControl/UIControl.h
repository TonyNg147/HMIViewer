#ifndef UI_CONTROL_H
#define UI_CONTROL_H
#include <QObject>
#include <QQmlEngine>
#include <QQmlContext>
#include <QString>
#include <UIConstant/UILayout.h>
#include <Proxy/SystemUI/SystemUIInterface.h>
#include <Proxy/SystemUI/SystemUIAgency.h>
class UIControl: public uicommon::SystemUIAgency
{
    Q_OBJECT
    Q_PROPERTY(QString focusApp READ focusApp NOTIFY onFocusAppChanged)
    private:
        UIControl();
    public: 
        ~UIControl();
        static UIControl& getInstance();
        QString focusApp() const override {return mCurrentApp;}
    public slots:   
        void changeLayout(uicommon::UILayout::Layout);
        void callOutToExpand(QString app);
    signals:
        void expandApplication(QString app);
    private:
        QStringList   mMainViewApplications; // This will contain the applications are currently in the main view layout
        QString       mCurrentApp = "HOME";
    private:
        uicommon::UILayout::Layout       mCurrentLayout = uicommon::UILayout::Layout::LAYOUT_1_1_1;
    
};
#endif //UI_CONTROL_H