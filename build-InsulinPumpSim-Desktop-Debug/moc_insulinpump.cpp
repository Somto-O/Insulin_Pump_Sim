/****************************************************************************
** Meta object code from reading C++ file 'insulinpump.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../InsulinPumpSim/insulinpump.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'insulinpump.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InsulinPump_t {
    QByteArrayData data[11];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InsulinPump_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InsulinPump_t qt_meta_stringdata_InsulinPump = {
    {
QT_MOC_LITERAL(0, 0, 11), // "InsulinPump"
QT_MOC_LITERAL(1, 12, 19), // "batteryLevelChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "newLevel"
QT_MOC_LITERAL(4, 42, 15), // "batteryDepleted"
QT_MOC_LITERAL(5, 58, 15), // "batteryCritical"
QT_MOC_LITERAL(6, 74, 21), // "reservoirLevelChanged"
QT_MOC_LITERAL(7, 96, 5), // "level"
QT_MOC_LITERAL(8, 102, 12), // "drainBattery"
QT_MOC_LITERAL(9, 115, 18), // "deliverHourlyBolus"
QT_MOC_LITERAL(10, 134, 14) // "drainReservoir"

    },
    "InsulinPump\0batteryLevelChanged\0\0"
    "newLevel\0batteryDepleted\0batteryCritical\0"
    "reservoirLevelChanged\0level\0drainBattery\0"
    "deliverHourlyBolus\0drainReservoir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InsulinPump[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InsulinPump::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InsulinPump *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->batteryLevelChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->batteryDepleted(); break;
        case 2: _t->batteryCritical(); break;
        case 3: _t->reservoirLevelChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->drainBattery(); break;
        case 5: _t->deliverHourlyBolus(); break;
        case 6: _t->drainReservoir(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InsulinPump::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InsulinPump::batteryLevelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InsulinPump::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InsulinPump::batteryDepleted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InsulinPump::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InsulinPump::batteryCritical)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (InsulinPump::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InsulinPump::reservoirLevelChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InsulinPump::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_InsulinPump.data,
    qt_meta_data_InsulinPump,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InsulinPump::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InsulinPump::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InsulinPump.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int InsulinPump::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void InsulinPump::batteryLevelChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InsulinPump::batteryDepleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void InsulinPump::batteryCritical()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void InsulinPump::reservoirLevelChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
