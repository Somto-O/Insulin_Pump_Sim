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
    QByteArrayData data[57];
    char stringdata0[1230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "updateReservoirDisplay"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "level"
QT_MOC_LITERAL(4, 41, 19), // "updateSensorDisplay"
QT_MOC_LITERAL(5, 61, 4), // "mmol"
QT_MOC_LITERAL(6, 66, 27), // "on_graphViewsButton_clicked"
QT_MOC_LITERAL(7, 94, 23), // "handleNewGlucoseReading"
QT_MOC_LITERAL(8, 118, 25), // "on_options_Button_clicked"
QT_MOC_LITERAL(9, 144, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 166, 33), // "on_personalProfile_button_cli..."
QT_MOC_LITERAL(11, 200, 24), // "on_historyButton_clicked"
QT_MOC_LITERAL(12, 225, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(13, 247, 23), // "on_backButton_2_clicked"
QT_MOC_LITERAL(14, 271, 23), // "on_backButton_3_clicked"
QT_MOC_LITERAL(15, 295, 18), // "on_unlock1_clicked"
QT_MOC_LITERAL(16, 314, 18), // "on_unlock2_clicked"
QT_MOC_LITERAL(17, 333, 18), // "on_unlock3_clicked"
QT_MOC_LITERAL(18, 352, 23), // "on_backButton_4_clicked"
QT_MOC_LITERAL(19, 376, 23), // "on_hpBackButton_clicked"
QT_MOC_LITERAL(20, 400, 23), // "on_dlBackButton_clicked"
QT_MOC_LITERAL(21, 424, 27), // "on_addProfileButton_clicked"
QT_MOC_LITERAL(22, 452, 30), // "on_updateProfileButton_clicked"
QT_MOC_LITERAL(23, 483, 29), // "on_viewProfilesButton_clicked"
QT_MOC_LITERAL(24, 513, 24), // "on_vppBackButton_clicked"
QT_MOC_LITERAL(25, 538, 23), // "on_vppButtonBox_clicked"
QT_MOC_LITERAL(26, 562, 16), // "QAbstractButton*"
QT_MOC_LITERAL(27, 579, 6), // "button"
QT_MOC_LITERAL(28, 586, 34), // "on_confirmProfileButtonBox_cl..."
QT_MOC_LITERAL(29, 621, 24), // "on_uppBackButton_clicked"
QT_MOC_LITERAL(30, 646, 24), // "on_sppBackButton_clicked"
QT_MOC_LITERAL(31, 671, 24), // "on_dppBackButton_clicked"
QT_MOC_LITERAL(32, 696, 23), // "on_spBackButton_clicked"
QT_MOC_LITERAL(33, 720, 37), // "on_uppConfirmProfileButtonBox..."
QT_MOC_LITERAL(34, 758, 20), // "updateBatteryDisplay"
QT_MOC_LITERAL(35, 779, 8), // "newLevel"
QT_MOC_LITERAL(36, 788, 21), // "updateBatteryDisplay2"
QT_MOC_LITERAL(37, 810, 30), // "on_deleteProfileButton_clicked"
QT_MOC_LITERAL(38, 841, 20), // "on_apProfileSelected"
QT_MOC_LITERAL(39, 862, 35), // "on_profilesCreatedLogButton_c..."
QT_MOC_LITERAL(40, 898, 35), // "on_profilesUpdatedLogButton_c..."
QT_MOC_LITERAL(41, 934, 35), // "on_profilesDeletedLogButton_c..."
QT_MOC_LITERAL(42, 970, 27), // "on_allHistoryButton_clicked"
QT_MOC_LITERAL(43, 998, 25), // "on_alertLogButton_clicked"
QT_MOC_LITERAL(44, 1024, 16), // "returnToLockPage"
QT_MOC_LITERAL(45, 1041, 11), // "eventFilter"
QT_MOC_LITERAL(46, 1053, 3), // "obj"
QT_MOC_LITERAL(47, 1057, 7), // "QEvent*"
QT_MOC_LITERAL(48, 1065, 5), // "event"
QT_MOC_LITERAL(49, 1071, 13), // "goToOffScreen"
QT_MOC_LITERAL(50, 1085, 21), // "beginShutdownSequence"
QT_MOC_LITERAL(51, 1107, 23), // "updateBatteryLevelValue"
QT_MOC_LITERAL(52, 1131, 30), // "on_selectProfileButton_clicked"
QT_MOC_LITERAL(53, 1162, 23), // "on_apBackButton_clicked"
QT_MOC_LITERAL(54, 1186, 13), // "startCharging"
QT_MOC_LITERAL(55, 1200, 16), // "simulateCharging"
QT_MOC_LITERAL(56, 1217, 12) // "startPowerOn"

    },
    "MainWindow\0updateReservoirDisplay\0\0"
    "level\0updateSensorDisplay\0mmol\0"
    "on_graphViewsButton_clicked\0"
    "handleNewGlucoseReading\0"
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
    "simulateCharging\0startPowerOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  249,    2, 0x08 /* Private */,
       4,    1,  252,    2, 0x08 /* Private */,
       6,    0,  255,    2, 0x08 /* Private */,
       7,    1,  256,    2, 0x08 /* Private */,
       8,    0,  259,    2, 0x08 /* Private */,
       9,    0,  260,    2, 0x08 /* Private */,
      10,    0,  261,    2, 0x08 /* Private */,
      11,    0,  262,    2, 0x08 /* Private */,
      12,    0,  263,    2, 0x08 /* Private */,
      13,    0,  264,    2, 0x08 /* Private */,
      14,    0,  265,    2, 0x08 /* Private */,
      15,    0,  266,    2, 0x08 /* Private */,
      16,    0,  267,    2, 0x08 /* Private */,
      17,    0,  268,    2, 0x08 /* Private */,
      18,    0,  269,    2, 0x08 /* Private */,
      19,    0,  270,    2, 0x08 /* Private */,
      20,    0,  271,    2, 0x08 /* Private */,
      21,    0,  272,    2, 0x08 /* Private */,
      22,    0,  273,    2, 0x08 /* Private */,
      23,    0,  274,    2, 0x08 /* Private */,
      24,    0,  275,    2, 0x08 /* Private */,
      25,    1,  276,    2, 0x08 /* Private */,
      28,    1,  279,    2, 0x08 /* Private */,
      29,    0,  282,    2, 0x08 /* Private */,
      30,    0,  283,    2, 0x08 /* Private */,
      31,    0,  284,    2, 0x08 /* Private */,
      32,    0,  285,    2, 0x08 /* Private */,
      33,    1,  286,    2, 0x08 /* Private */,
      34,    1,  289,    2, 0x08 /* Private */,
      36,    1,  292,    2, 0x08 /* Private */,
      37,    0,  295,    2, 0x08 /* Private */,
      38,    0,  296,    2, 0x08 /* Private */,
      39,    0,  297,    2, 0x08 /* Private */,
      40,    0,  298,    2, 0x08 /* Private */,
      41,    0,  299,    2, 0x08 /* Private */,
      42,    0,  300,    2, 0x08 /* Private */,
      43,    0,  301,    2, 0x08 /* Private */,
      44,    0,  302,    2, 0x08 /* Private */,
      45,    2,  303,    2, 0x08 /* Private */,
      49,    0,  308,    2, 0x08 /* Private */,
      50,    0,  309,    2, 0x08 /* Private */,
      51,    1,  310,    2, 0x08 /* Private */,
      52,    0,  313,    2, 0x08 /* Private */,
      53,    0,  314,    2, 0x08 /* Private */,
      54,    0,  315,    2, 0x08 /* Private */,
      55,    0,  316,    2, 0x08 /* Private */,
      56,    0,  317,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    3,
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
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, QMetaType::Float,   35,
    QMetaType::Void, QMetaType::Float,   35,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 47,   46,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    3,
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
        case 0: _t->updateReservoirDisplay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->updateSensorDisplay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->on_graphViewsButton_clicked(); break;
        case 3: _t->handleNewGlucoseReading((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->on_options_Button_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_personalProfile_button_clicked(); break;
        case 7: _t->on_historyButton_clicked(); break;
        case 8: _t->on_backButton_clicked(); break;
        case 9: _t->on_backButton_2_clicked(); break;
        case 10: _t->on_backButton_3_clicked(); break;
        case 11: _t->on_unlock1_clicked(); break;
        case 12: _t->on_unlock2_clicked(); break;
        case 13: _t->on_unlock3_clicked(); break;
        case 14: _t->on_backButton_4_clicked(); break;
        case 15: _t->on_hpBackButton_clicked(); break;
        case 16: _t->on_dlBackButton_clicked(); break;
        case 17: _t->on_addProfileButton_clicked(); break;
        case 18: _t->on_updateProfileButton_clicked(); break;
        case 19: _t->on_viewProfilesButton_clicked(); break;
        case 20: _t->on_vppBackButton_clicked(); break;
        case 21: _t->on_vppButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 22: _t->on_confirmProfileButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 23: _t->on_uppBackButton_clicked(); break;
        case 24: _t->on_sppBackButton_clicked(); break;
        case 25: _t->on_dppBackButton_clicked(); break;
        case 26: _t->on_spBackButton_clicked(); break;
        case 27: _t->on_uppConfirmProfileButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 28: _t->updateBatteryDisplay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 29: _t->updateBatteryDisplay2((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 30: _t->on_deleteProfileButton_clicked(); break;
        case 31: { QString _r = _t->on_apProfileSelected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->on_profilesCreatedLogButton_clicked(); break;
        case 33: _t->on_profilesUpdatedLogButton_clicked(); break;
        case 34: _t->on_profilesDeletedLogButton_clicked(); break;
        case 35: _t->on_allHistoryButton_clicked(); break;
        case 36: _t->on_alertLogButton_clicked(); break;
        case 37: _t->returnToLockPage(); break;
        case 38: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->goToOffScreen(); break;
        case 40: _t->beginShutdownSequence(); break;
        case 41: _t->updateBatteryLevelValue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 42: _t->on_selectProfileButton_clicked(); break;
        case 43: _t->on_apBackButton_clicked(); break;
        case 44: _t->startCharging(); break;
        case 45: _t->simulateCharging(); break;
        case 46: _t->startPowerOn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 27:
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
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
