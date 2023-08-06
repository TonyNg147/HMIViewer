#ifndef UI_LAYOUT_H
#define UI_LAYOUT_H
#include <QObject>
namespace uicommon{
    class UILayout: public QObject{
        Q_OBJECT
        Q_ENUMS(Layout)
        public:
            enum Layout: uchar{
                LAYOUT_1_1_1 = 0,
                LAYOUT_1_2,
                LAYOUT_2_1,
            };
    };
}
#endif