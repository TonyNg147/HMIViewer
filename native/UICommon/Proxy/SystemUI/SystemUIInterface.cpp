#include "SystemUIInterface.h"
namespace uicommon{
    SystemUIInterface& SystemUIInterface::getInstance(){
        static SystemUIInterface instance("uicommon::systemUI","/SYSUI",QDBusConnection::sessionBus(),nullptr);
        return instance;
    }

    SystemUIInterface::SystemUIInterface(const QString& service, const QString& path, const QDBusConnection& connection, QObject* parent)
        :QDBusAbstractInterface(service,path,"uicommon::systemUI",connection, parent)
    {

    }
};
