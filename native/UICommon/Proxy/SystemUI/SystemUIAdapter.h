#ifndef SYSTEM_UI_ADAPTER_H
#define SYSTEM_UI_ADAPTER_H
#include <QDBusAbstractAdaptor>
#include "../../UIConstant/UILayout.h"
namespace uicommon{
    class SystemUIAdapter: public QDBusAbstractAdaptor{
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface","uicommon::systemUI")
        Q_CLASSINFO("D-Bus Introspection",  ""
                                            " <interface name=\"uicommon::systemUI\">                                                                       \n"            
                                            "     <property type=\"s\" name=\"focusApp\" access=\"read\">                                                  \n"
                                            "     <signal name=\"onMainLayoutChanged\">                                                                     \n" 
                                            "         <arg direction=\"out\" type=\"{i}\">                                                                  \n"                        
                                            "         <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::UILayout::Layout\"/>      \n"        
                                            "         <arg direction=\"out\" type=\"as\">                                                                   \n"                        
                                            "     </signal>                                                                                                 \n"    
                                            " </interface>                                                                                                  \n"
                                            "")
        Q_PROPERTY(QString focusApp READ focusApp NOTIFY onFocusAppChanged)
        public:
            SystemUIAdapter(QObject* parent);
            QString focusApp();
        signals:
            void onMainLayoutChanged(uicommon::UILayout::Layout, QStringList apps);
            void onFocusAppChanged();   
    };
};

#endif  