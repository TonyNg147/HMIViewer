#ifndef SYSTEM_UI_TYPE_H
#define SYSTEM_UI_TYPE_H
#include <UILayout.h>
#include <QMetaType>
#include <QDBusArgument>
Q_DECLARE_METATYPE(uicommon::UILayout::Layout)
QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::UILayout::Layout& message);
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::UILayout::Layout &message);
#endif 