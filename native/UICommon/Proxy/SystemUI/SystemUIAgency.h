#ifndef SYSTEM_UI_AGENCY_H
#define SYSTEM_UI_AGENCY_H
#include <QObject>
#include "../../UIConstant/UILayout.h"
namespace uicommon{
    class SystemUIAgency: public QObject{
        Q_OBJECT
        Q_PROPERTY(QString focusApp READ focusApp NOTIFY onFocusAppChanged)
        public:
            virtual QString focusApp() const = 0; 
        signals:
            void onMainLayoutChanged(uicommon::UILayout::Layout, QStringList apps);
            void onFocusAppChanged();
    };
}

#endif 