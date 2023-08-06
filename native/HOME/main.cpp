#include <QtAppManCommon/global.h>
#include <QtAppManCommon/logging.h>
#include <QtAppManMain/main.h>
#include <QtAppManMain/configuration.h>
#include <QtAppManPackage/packageutilities.h>
#include <QtAppManManager/sudo.h>
#include "UIProperties.h"
#include "SystemManipulation/SystemManipulation.h"
#include <QQmlApplicationEngine>
#include <uicommon.h>
QT_USE_NAMESPACE_AM

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName(QStringLiteral("HOME"));
    QCoreApplication::setApplicationVersion(QStringLiteral("0.1"));

    Logging::initialize(argc, argv);
    Sudo::forkServer(Sudo::DropPrivilegesPermanently);
    try {   
        UIPro::registerProes();
        uicommon::init();
        Main a(argc, argv);
        
        Configuration cfg;
        cfg.parseWithArguments(QCoreApplication::arguments());
        
        a.setup(&cfg);
        SystemManipulation::applyEngine(a.qmlEngine());
        SystemManipulation* sysManipulate = SystemManipulation::getInstance();
        a.loadQml(cfg.loadDummyData());
        a.showWindow(cfg.fullscreen() && !cfg.noFullscreen());

        return MainBase::exec();
    } catch (const std::exception &e) {
        qCCritical(LogSystem) << "ERROR:" << e.what();
        return 2;
    }
}
