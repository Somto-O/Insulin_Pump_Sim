/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../InsulinPumpSim/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[61];
    char stringdata0[1297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "updateSensorDisplay"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "mmol"
QT_MOC_LITERAL(4, 37, 27), // "on_graphViewsButton_clicked"
QT_MOC_LITERAL(5, 65, 23), // "handleNewGlucoseReading"
QT_MOC_LITERAL(6, 89, 5), // "level"
QT_MOC_LITERAL(7, 95, 25), // "on_options_Button_clicked"
QT_MOC_LITERAL(8, 121, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 143, 33), // "on_personalProfile_button_cli..."
QT_MOC_LITERAL(10, 177, 24), // "on_historyButton_clicked"
QT_MOC_LITERAL(11, 202, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(12, 224, 23), // "on_backButton_2_clicked"
QT_MOC_LITERAL(13, 248, 23), // "on_backButton_3_clicked"
QT_MOC_LITERAL(14, 272, 18), // "on_unlock1_clicked"
QT_MOC_LITERAL(15, 291, 18), // "on_unlock2_clicked"
QT_MOC_LITERAL(16, 310, 18), // "on_unlock3_clicked"
QT_MOC_LITERAL(17, 329, 23), // "on_backButton_4_clicked"
QT_MOC_LITERAL(18, 353, 23), // "on_hpBackButton_clicked"
QT_MOC_LITERAL(19, 377, 23), // "on_dlBackButton_clicked"
QT_MOC_LITERAL(20, 401, 27), // "on_addProfileButton_clicked"
QT_MOC_LITERAL(21, 429, 30), // "on_updateProfileButton_clicked"
QT_MOC_LITERAL(22, 460, 29), // "on_viewProfilesButton_clicked"
QT_MOC_LITERAL(23, 490, 24), // "on_vppBackButton_clicked"
QT_MOC_LITERAL(24, 515, 23), // "on_vppButtonBox_clicked"
QT_MOC_LITERAL(25, 539, 16), // "QAbstractButton*"
QT_MOC_LITERAL(26, 556, 6), // "button"
QT_MOC_LITERAL(27, 563, 34), // "on_confirmProfileButtonBox_cl..."
QT_MOC_LITERAL(28, 598, 24), // "on_uppBackButton_clicked"
QT_MOC_LITERAL(29, 623, 24), // "on_sppBackButton_clicked"
QT_MOC_LITERAL(30, 648, 24), // "on_dppBackButton_clicked"
QT_MOC_LITERAL(31, 673, 23), // "on_spBackButton_clicked"
QT_MOC_LITERAL(32, 697, 37), // "on_uppConfirmProfileButtonBox..."
QT_MOC_LITERAL(33, 735, 20), // "updateBatteryDisplay"
QT_MOC_LITERAL(34, 756, 8), // "newLevel"
QT_MOC_LITERAL(35, 765, 21), // "updateBatteryDisplay2"
QT_MOC_LITERAL(36, 787, 30), // "on_deleteProfileButton_clicked"
QT_MOC_LITERAL(37, 818, 20), // "on_apProfileSelected"
QT_MOC_LITERAL(38, 839, 35), // "on_profilesCreatedLogButton_c..."
QT_MOC_LITERAL(39, 875, 35), // "on_profilesUpdatedLogButton_c..."
QT_MOC_LITERAL(40, 911, 35), // "on_profilesDeletedLogButton_c..."
QT_MOC_LITERAL(41, 947, 27), // "on_allHistoryButton_clicked"
QT_MOC_LITERAL(42, 975, 25), // "on_alertLogButton_clicked"
QT_MOC_LITERAL(43, 1001, 16), // "returnToLockPage"
QT_MOC_LITERAL(44, 1018, 11), // "eventFilter"
QT_MOC_LITERAL(45, 1030, 3), // "obj"
QT_MOC_LITERAL(46, 1034, 7), // "QEvent*"
QT_MOC_LITERAL(47, 1042, 5), // "event"
QT_MOC_LITERAL(48, 1048, 13), // "goToOffScreen"
QT_MOC_LITERAL(49, 1062, 21), // "beginShutdownSequence"
QT_MOC_LITERAL(50, 1084, 23), // "updateBatteryLevelValue"
QT_MOC_LITERAL(51, 1108, 30), // "on_selectProfileButton_clicked"
QT_MOC_LITERAL(52, 1139, 23), // "on_apBackButton_clicked"
QT_MOC_LITERAL(53, 1163, 13), // "startCharging"
QT_MOC_LITERAL(54, 1177, 16), // "simulateCharging"
QT_MOC_LITERAL(55, 1194, 12), // "startPowerOn"
QT_MOC_LITERAL(56, 1207, 17), // "setCGMStateToIdle"
QT_MOC_LITERAL(57, 1225, 19), // "setCGMStateToEating"
QT_MOC_LITERAL(58, 1245, 20), // "setCGMStateToFasting"
QT_MOC_LITERAL(59, 1266, 15), // "startSimulation"
QT_MOC_LITERAL(60, 1282, 14) // "stopSimulation"

    },
    "MainWindow\0updateSensorDisplay\0\0mmol\0"
    "on_graphViewsButton_clicked\0"
    "handleNewGlucoseReading\0level\0"
    "on_options_Button_clicked\0"
    "on_pushButton_clicked\0"
    "on_personalProfile_button_clicked\0"
    "on_historyButton_clicked\0on_backButton_clicked\0"
    "on_backButton_2_clicked\0on_backButton_3_clicked\0"
    "on_unlock1_clicked\0on_unlock2_clicked\0"
    "on_unlock3_clicked\0on_backButton_4_clicked\0"
    "on_hpBackButton_clicked\0on_dlBackButton_clicked\0"
    "on_addProfileButton_clicked\0"
    "on_updateProfileButton_clicked\0"
    "on_viewProfilesButton_clicked\0"
    "on_vppBackButton_clicked\0"
    "on_vppButtonBox_clicked\0QAbstractButton*\0"
    "button\0on_confirmProfileButtonBox_clicked\0"
    "on_uppBackButton_clicked\0"
    "on_sppBackButton_clicked\0"
    "on_dppBackButton_clicked\0"
    "on_spBackButton_clicked\0"
    "on_uppConfirmProfileButtonBox_clicked\0"
    "updateBatteryDisplay\0newLevel\0"
    "updateBatteryDisplay2\0"
    "on_deleteProfileButton_clicked\0"
    "on_apProfileSelected\0"
    "on_profilesCreatedLogButton_clicked\0"
    "on_profilesUpdatedLogButton_clicked\0"
    "on_profilesDeletedLogButton_clicked\0"
    "on_allHistoryButton_clicked\0"
    "on_alertLogButton_clicked\0returnToLockPage\0"
    "eventFilter\0obj\0QEvent*\0event\0"
    "goToOffScreen\0beginShutdownSequence\0"
    "updateBatteryLevelValue\0"
    "on_selectProfileButton_clicked\0"
    "on_apBackButton_clicked\0startCharging\0"
    "simulateCharging\0startPowerOn\0"
    "setCGMStateToIdle\0setCGMStateToEating\0"
    "setCGMStateToFasting\0startSimulation\0"
    "stopSimulation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  269,    2, 0x08 /* Private */,
       4,    0,  272,    2, 0x08 /* Private */,
       5,    1,  273,    2, 0x08 /* Private */,
       7,    0,  276,    2, 0x08 /* Private */,
       8,    0,  277,    2, 0x08 /* Private */,
       9,    0,  278,    2, 0x08 /* Private */,
      10,    0,  279,    2, 0x08 /* Private */,
      11,    0,  280,    2, 0x08 /* Private */,
      12,    0,  281,    2, 0x08 /* Private */,
      13,    0,  282,    2, 0x08 /* Private */,
      14,    0,  283,    2, 0x08 /* Private */,
      15,    0,  284,    2, 0x08 /* Private */,
      16,    0,  285,    2, 0x08 /* Private */,
      17,    0,  286,    2, 0x08 /* Private */,
      18,    0,  287,    2, 0x08 /* Private */,
      19,    0,  288,    2, 0x08 /* Private */,
      20,    0,  289,    2, 0x08 /* Private */,
      21,    0,  290,    2, 0x08 /* Private */,
      22,    0,  291,    2, 0x08 /* Private */,
      23,    0,  292,    2, 0x08 /* Private */,
      24,    1,  293,    2, 0x08 /* Private */,
      27,    1,  296,    2, 0x08 /* Private */,
      28,    0,  299,    2, 0x08 /* Private */,
      29,    0,  300,    2, 0x08 /* Private */,
      30,    0,  301,    2, 0x08 /* Private */,
      31,    0,  302,    2, 0x08 /* Private */,
      32,    1,  303,    2, 0x08 /* Private */,
      33,    1,  306,    2, 0x08 /* Private */,
      35,    1,  309,    2, 0x08 /* Private */,
      36,    0,  312,    2, 0x08 /* Private */,
      37,    0,  313,    2, 0x08 /* Private */,
      38,    0,  314,    2, 0x08 /* Private */,
      39,    0,  315,    2, 0x08 /* Private */,
      40,    0,  316,    2, 0x08 /* Private */,
      41,    0,  317,    2, 0x08 /* Private */,
      42,    0,  318,    2, 0x08 /* Private */,
      43,    0,  319,    2, 0x08 /* Private */,
      44,    2,  320,    2, 0x08 /* Private */,
      48,    0,  325,    2, 0x08 /* Private */,
      49,    0,  326,    2, 0x08 /* Private */,
      50,    1,  327,    2, 0x08 /* Private */,
      51,    0,  330,    2, 0x08 /* Private */,
      52,    0,  331,    2, 0x08 /* Private */,
      53,    0,  332,    2, 0x08 /* Private */,
      54,    0,  333,    2, 0x08 /* Private */,
      55,    0,  334,    2, 0x08 /* Private */,
      56,    0,  335,    2, 0x08 /* Private */,
      57,    0,  336,    2, 0x08 /* Private */,
      58,    0,  337,    2, 0x08 /* Private */,
      59,    0,  338,    2, 0x08 /* Private */,
      60,    0,  339,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::Float,   34,
    QMetaType::Void, QMetaType::Float,   34,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 46,   45,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateSensorDisplay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->on_graphViewsButton_clicked(); break;
        case 2: _t->handleNewGlucoseReading((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->on_options_Button_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_personalProfile_button_clicked(); break;
        case 6: _t->on_historyButton_clicked(); break;
        case 7: _t->on_backButton_clicked(); break;
        case 8: _t->on_backButton_2_clicked(); break;
        case 9: _t->on_backButton_3_clicked(); break;
        case 10: _t->on_unlock1_clicked(); break;
        case 11: _t->on_unlock2_clicked(); break;
        case 12: _t->on_unlock3_clicked(); break;
        case 13: _t->on_backButton_4_clicked(); break;
        case 14: _t->on_hpBackButton_clicked(); break;
        case 15: _t->on_dlBackButton_clicked(); break;
        case 16: _t->on_addProfileButton_clicked(); break;
        case 17: _t->on_updateProfileButton_clicked(); break;
        case 18: _t->on_viewProfilesButton_clicked(); break;
        case 19: _t->on_vppBackButton_clicked(); break;
        case 20: _t->on_vppButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 21: _t->on_confirmProfileButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 22: _t->on_uppBackButton_clicked(); break;
        case 23: _t->on_sppBackButton_clicked(); break;
        case 24: _t->on_dppBackButton_clicked(); break;
        case 25: _t->on_spBackButton_clicked(); break;
        case 26: _t->on_uppConfirmProfileButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 27: _t->updateBatteryDisplay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 28: _t->updateBatteryDisplay2((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 29: _t->on_deleteProfileButton_clicked(); break;
        case 30: { QString _r = _t->on_apProfileSelected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->on_profilesCreatedLogButton_clicked(); break;
        case 32: _t->on_profilesUpdatedLogButton_clicked(); break;
        case 33: _t->on_profilesDeletedLogButton_clicked(); break;
        case 34: _t->on_allHistoryButton_clicked(); break;
        case 35: _t->on_alertLogButton_clicked(); break;
        case 36: _t->returnToLockPage(); break;
        case 37: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: _t->goToOffScreen(); break;
        case 39: _t->beginShutdownSequence(); break;
        case 40: _t->updateBatteryLevelValue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 41: _t->on_selectProfileButton_clicked(); break;
        case 42: _t->on_apBackButton_clicked(); break;
        case 43: _t->startCharging(); break;
        case 44: _t->simulateCharging(); break;
        case 45: _t->startPowerOn(); break;
        case 46: _t->setCGMStateToIdle(); break;
        case 47: _t->setCGMStateToEating(); break;
        case 48: _t->setCGMStateToFasting(); break;
        case 49: _t->startSimulation(); break;
        case 50: _t->stopSimulation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
