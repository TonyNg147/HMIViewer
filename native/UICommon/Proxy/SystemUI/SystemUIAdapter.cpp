#include "SystemUIAdapter.h"

namespace uicommon{
    SystemUIAdapter::SystemUIAdapter(QObject* parent)
        :QDBusAbstractAdaptor{parent}
    {
        setAutoRelaySignals(true);
    }

    QString SystemUIAdapter::focusApp(){
        QMetaObject::invokeMethod(parent(),"focusApp");
    };
};