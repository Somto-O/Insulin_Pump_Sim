/****************************************************************************
** Meta object code from reading C++ file 'boluscalculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../InsulinPumpSim/boluscalculator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boluscalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BolusCalculator_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BolusCalculator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BolusCalculator_t qt_meta_stringdata_BolusCalculator = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BolusCalculator"
QT_MOC_LITERAL(1, 16, 15), // "bolusCalculated"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "totalBolus"
QT_MOC_LITERAL(4, 44, 9), // "immediate"
QT_MOC_LITERAL(5, 54, 8), // "extended"
QT_MOC_LITERAL(6, 63, 11), // "ratePerHour"
QT_MOC_LITERAL(7, 75, 14) // "bolusDelivered"

    },
    "BolusCalculator\0bolusCalculated\0\0"
    "totalBolus\0immediate\0extended\0ratePerHour\0"
    "bolusDelivered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BolusCalculator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,
       7,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    3,    4,    5,    6,
    QMetaType::Void,

       0        // eod
};

void BolusCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BolusCalculator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->bolusCalculated((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 1: _t->bolusDelivered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BolusCalculator::*)(float , float , float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BolusCalculator::bolusCalculated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BolusCalculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BolusCalculator::bolusDelivered)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BolusCalculator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BolusCalculator.data,
    qt_meta_data_BolusCalculator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BolusCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BolusCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BolusCalculator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BolusCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BolusCalculator::bolusCalculated(float _t1, float _t2, float _t3, float _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BolusCalculator::bolusDelivered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
