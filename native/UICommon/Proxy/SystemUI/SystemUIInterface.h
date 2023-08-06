#ifndef SYSTEM_UI_INTERFACE_H
#define SYSTEM_UI_INTERFACE_H
#include <QDBusAbstractInterface>
#include <QObject>
#include "../../UIConstant/UILayout.h"
#include <QDBusPendingReply>
namespace uicommon{
    class SystemUIInterface: public QDBusAbstractInterface{
        Q_OBJECT
        Q_PROPERTY(QString focusApp READ focusApp NOTIFY onFocusAppChanged)
        private:
            SystemUIInterface(const QString&, const QString&, const QDBusConnection&, QObject* parent = nullptr);
        public:
            static SystemUIInterface& getInstance();
            QDBusPendingReply<QString> focusApp(){
                return asyncCallWithArgumentList("focusApp",QList<QVariant>());
            }
        signals:
            void onMainLayoutChanged(uicommon::UILayout::Layout, QStringList apps);
            void onFocusAppChanged();
    };
};
#endif //SYSTEM_UI_INTERFACE_H
