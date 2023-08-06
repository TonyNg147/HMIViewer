#include "UIControl.h"
#include "../ContextManager/ContextManager.h"
UIControl& UIControl::getInstance(){
    static UIControl instance;
    return instance;
}

UIControl::UIControl()
    :uicommon::SystemUIAgency()
{
    
    ContextManager::registerProperty("UIControl",QVariant::fromValue(this));

}
UIControl::~UIControl(){
    ContextManager::registerProperty("UIControl",nullptr);
    // release resource
}

void UIControl::changeLayout(uicommon::UILayout::Layout layout){
    if (layout == mCurrentLayout) return;
    mCurrentLayout = layout;
    QStringList apps;
    if (layout == uicommon::UILayout::Layout::LAYOUT_1_1_1){
        apps = mMainViewApplications;
    }else{
        if (mMainViewApplications.count() == 3){
            apps << mMainViewApplications[0] << mMainViewApplications[1];
        }
    }
    onMainLayoutChanged(layout, apps);
}

void UIControl::callOutToExpand(QString app){
    if (app != mCurrentApp){
        mCurrentApp = app;
        onFocusAppChanged();
        expandApplication(app);
    }
}