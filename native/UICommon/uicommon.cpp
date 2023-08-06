#include "uicommon.h"
#include "Proxy/SystemUI/SystemUITypeInfo.h"
#include <QDBusMetaType>
QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::UILayout::Layout& message){
    argument.beginStructure();
    argument << (int)message;
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::UILayout::Layout &message){
    uchar value = 0;
    argument.beginStructure();
    argument >> value;
    argument.endStructure();
    message = static_cast<uicommon::UILayout::Layout>(value);
    return argument;
}
namespace uicommon{
    void init(){
        qDBusRegisterMetaType<uicommon::UILayout::Layout>();
    }
}
