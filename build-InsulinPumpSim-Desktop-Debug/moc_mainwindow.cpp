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
    QByteArrayData data[45];
    char stringdata0[997];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "handleNewGlucoseReading"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "level"
QT_MOC_LITERAL(4, 42, 25), // "on_options_Button_clicked"
QT_MOC_LITERAL(5, 68, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 90, 33), // "on_personalProfile_button_cli..."
QT_MOC_LITERAL(7, 124, 24), // "on_historyButton_clicked"
QT_MOC_LITERAL(8, 149, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(9, 171, 23), // "on_backButton_2_clicked"
QT_MOC_LITERAL(10, 195, 23), // "on_backButton_3_clicked"
QT_MOC_LITERAL(11, 219, 18), // "on_unlock1_clicked"
QT_MOC_LITERAL(12, 238, 18), // "on_unlock2_clicked"
QT_MOC_LITERAL(13, 257, 18), // "on_unlock3_clicked"
QT_MOC_LITERAL(14, 276, 23), // "on_backButton_4_clicked"
QT_MOC_LITERAL(15, 300, 23), // "on_hpBackButton_clicked"
QT_MOC_LITERAL(16, 324, 23), // "on_dlBackButton_clicked"
QT_MOC_LITERAL(17, 348, 27), // "on_addProfileButton_clicked"
QT_MOC_LITERAL(18, 376, 30), // "on_updateProfileButton_clicked"
QT_MOC_LITERAL(19, 407, 29), // "on_viewProfilesButton_clicked"
QT_MOC_LITERAL(20, 437, 24), // "on_vppBackButton_clicked"
QT_MOC_LITERAL(21, 462, 23), // "on_vppButtonBox_clicked"
QT_MOC_LITERAL(22, 486, 16), // "QAbstractButton*"
QT_MOC_LITERAL(23, 503, 6), // "button"
QT_MOC_LITERAL(24, 510, 34), // "on_confirmProfileButtonBox_cl..."
QT_MOC_LITERAL(25, 545, 24), // "on_uppBackButton_clicked"
QT_MOC_LITERAL(26, 570, 24), // "on_sppBackButton_clicked"
QT_MOC_LITERAL(27, 595, 24), // "on_dppBackButton_clicked"
QT_MOC_LITERAL(28, 620, 23), // "on_spBackButton_clicked"
QT_MOC_LITERAL(29, 644, 37), // "on_uppConfirmProfileButtonBox..."
QT_MOC_LITERAL(30, 682, 20), // "updateBatteryDisplay"
QT_MOC_LITERAL(31, 703, 8), // "newLevel"
QT_MOC_LITERAL(32, 712, 21), // "updateBatteryDisplay2"
QT_MOC_LITERAL(33, 734, 30), // "on_deleteProfileButton_clicked"
QT_MOC_LITERAL(34, 765, 22), // "changePageToBatteryLow"
QT_MOC_LITERAL(35, 788, 35), // "on_profilesCreatedLogButton_c..."
QT_MOC_LITERAL(36, 824, 35), // "on_profilesUpdatedLogButton_c..."
QT_MOC_LITERAL(37, 860, 35), // "on_profilesDeletedLogButton_c..."
QT_MOC_LITERAL(38, 896, 27), // "on_allHistoryButton_clicked"
QT_MOC_LITERAL(39, 924, 25), // "on_alertLogButton_clicked"
QT_MOC_LITERAL(40, 950, 16), // "returnToLockPage"
QT_MOC_LITERAL(41, 967, 11), // "eventFilter"
QT_MOC_LITERAL(42, 979, 3), // "obj"
QT_MOC_LITERAL(43, 983, 7), // "QEvent*"
QT_MOC_LITERAL(44, 991, 5) // "event"

    },
    "MainWindow\0handleNewGlucoseReading\0\0"
    "level\0on_options_Button_clicked\0"
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
    "changePageToBatteryLow\0"
    "on_profilesCreatedLogButton_clicked\0"
    "on_profilesUpdatedLogButton_clicked\0"
    "on_profilesDeletedLogButton_clicked\0"
    "on_allHistoryButton_clicked\0"
    "on_alertLogButton_clicked\0returnToLockPage\0"
    "eventFilter\0obj\0QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x08 /* Private */,
       4,    0,  197,    2, 0x08 /* Private */,
       5,    0,  198,    2, 0x08 /* Private */,
       6,    0,  199,    2, 0x08 /* Private */,
       7,    0,  200,    2, 0x08 /* Private */,
       8,    0,  201,    2, 0x08 /* Private */,
       9,    0,  202,    2, 0x08 /* Private */,
      10,    0,  203,    2, 0x08 /* Private */,
      11,    0,  204,    2, 0x08 /* Private */,
      12,    0,  205,    2, 0x08 /* Private */,
      13,    0,  206,    2, 0x08 /* Private */,
      14,    0,  207,    2, 0x08 /* Private */,
      15,    0,  208,    2, 0x08 /* Private */,
      16,    0,  209,    2, 0x08 /* Private */,
      17,    0,  210,    2, 0x08 /* Private */,
      18,    0,  211,    2, 0x08 /* Private */,
      19,    0,  212,    2, 0x08 /* Private */,
      20,    0,  213,    2, 0x08 /* Private */,
      21,    1,  214,    2, 0x08 /* Private */,
      24,    1,  217,    2, 0x08 /* Private */,
      25,    0,  220,    2, 0x08 /* Private */,
      26,    0,  221,    2, 0x08 /* Private */,
      27,    0,  222,    2, 0x08 /* Private */,
      28,    0,  223,    2, 0x08 /* Private */,
      29,    1,  224,    2, 0x08 /* Private */,
      30,    1,  227,    2, 0x08 /* Private */,
      32,    1,  230,    2, 0x08 /* Private */,
      33,    0,  233,    2, 0x08 /* Private */,
      34,    0,  234,    2, 0x08 /* Private */,
      35,    0,  235,    2, 0x08 /* Private */,
      36,    0,  236,    2, 0x08 /* Private */,
      37,    0,  237,    2, 0x08 /* Private */,
      38,    0,  238,    2, 0x08 /* Private */,
      39,    0,  239,    2, 0x08 /* Private */,
      40,    0,  240,    2, 0x08 /* Private */,
      41,    2,  241,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Float,   31,
    QMetaType::Void, QMetaType::Float,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 43,   42,   44,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleNewGlucoseReading((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->on_options_Button_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_personalProfile_button_clicked(); break;
        case 4: _t->on_historyButton_clicked(); break;
        case 5: _t->on_backButton_clicked(); break;
        case 6: _t->on_backButton_2_clicked(); break;
        case 7: _t->on_backButton_3_clicked(); break;
        case 8: _t->on_unlock1_clicked(); break;
        case 9: _t->on_unlock2_clicked(); break;
        case 10: _t->on_unlock3_clicked(); break;
        case 11: _t->on_backButton_4_clicked(); break;
        case 12: _t->on_hpBackButton_clicked(); break;
        case 13: _t->on_dlBackButton_clicked(); break;
        case 14: _t->on_addProfileButton_clicked(); break;
        case 15: _t->on_updateProfileButton_clicked(); break;
        case 16: _t->on_viewProfilesButton_clicked(); break;
        case 17: _t->on_vppBackButton_clicked(); break;
        case 18: _t->on_vppButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 19: _t->on_confirmProfileButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 20: _t->on_uppBackButton_clicked(); break;
        case 21: _t->on_sppBackButton_clicked(); break;
        case 22: _t->on_dppBackButton_clicked(); break;
        case 23: _t->on_spBackButton_clicked(); break;
        case 24: _t->on_uppConfirmProfileButtonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 25: _t->updateBatteryDisplay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 26: _t->updateBatteryDisplay2((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 27: _t->on_deleteProfileButton_clicked(); break;
        case 28: _t->changePageToBatteryLow(); break;
        case 29: _t->on_profilesCreatedLogButton_clicked(); break;
        case 30: _t->on_profilesUpdatedLogButton_clicked(); break;
        case 31: _t->on_profilesDeletedLogButton_clicked(); break;
        case 32: _t->on_allHistoryButton_clicked(); break;
        case 33: _t->on_alertLogButton_clicked(); break;
        case 34: _t->returnToLockPage(); break;
        case 35: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 24:
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
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
