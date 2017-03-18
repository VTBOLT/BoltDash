/****************************************************************************
** Meta object code from reading C++ file 'rosprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/rosprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rosprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RosProcess_t {
    QByteArrayData data[25];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RosProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RosProcess_t qt_meta_stringdata_RosProcess = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RosProcess"
QT_MOC_LITERAL(1, 11, 17), // "updateBatteryTemp"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "temp"
QT_MOC_LITERAL(4, 35, 9), // "updateRPM"
QT_MOC_LITERAL(5, 45, 3), // "rpm"
QT_MOC_LITERAL(6, 49, 14), // "updateRPM_QVar"
QT_MOC_LITERAL(7, 64, 13), // "updateRMScurr"
QT_MOC_LITERAL(8, 78, 4), // "curr"
QT_MOC_LITERAL(9, 83, 12), // "updateDCvolt"
QT_MOC_LITERAL(10, 96, 4), // "volt"
QT_MOC_LITERAL(11, 101, 17), // "updateDCVolt_QVar"
QT_MOC_LITERAL(12, 119, 12), // "updateHStemp"
QT_MOC_LITERAL(13, 132, 15), // "updateMotorTemp"
QT_MOC_LITERAL(14, 148, 15), // "updateVoltAngle"
QT_MOC_LITERAL(15, 164, 5), // "angle"
QT_MOC_LITERAL(16, 170, 12), // "updateIQcurr"
QT_MOC_LITERAL(17, 183, 9), // "sendEMCY6"
QT_MOC_LITERAL(18, 193, 3), // "emc"
QT_MOC_LITERAL(19, 197, 9), // "sendEMCY7"
QT_MOC_LITERAL(20, 207, 10), // "sendD6stat"
QT_MOC_LITERAL(21, 218, 4), // "stat"
QT_MOC_LITERAL(22, 223, 10), // "sendD7stat"
QT_MOC_LITERAL(23, 234, 8), // "readData"
QT_MOC_LITERAL(24, 243, 9) // "readError"

    },
    "RosProcess\0updateBatteryTemp\0\0temp\0"
    "updateRPM\0rpm\0updateRPM_QVar\0updateRMScurr\0"
    "curr\0updateDCvolt\0volt\0updateDCVolt_QVar\0"
    "updateHStemp\0updateMotorTemp\0"
    "updateVoltAngle\0angle\0updateIQcurr\0"
    "sendEMCY6\0emc\0sendEMCY7\0sendD6stat\0"
    "stat\0sendD7stat\0readData\0readError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RosProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       6,    1,  100,    2, 0x06 /* Public */,
       7,    1,  103,    2, 0x06 /* Public */,
       9,    1,  106,    2, 0x06 /* Public */,
      11,    1,  109,    2, 0x06 /* Public */,
      12,    1,  112,    2, 0x06 /* Public */,
      13,    1,  115,    2, 0x06 /* Public */,
      14,    1,  118,    2, 0x06 /* Public */,
      16,    1,  121,    2, 0x06 /* Public */,
      17,    1,  124,    2, 0x06 /* Public */,
      19,    1,  127,    2, 0x06 /* Public */,
      20,    1,  130,    2, 0x06 /* Public */,
      22,    1,  133,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  136,    2, 0x0a /* Public */,
      24,    0,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::QVariant,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::QVariant,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RosProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RosProcess *_t = static_cast<RosProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBatteryTemp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateRPM((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->updateRPM_QVar((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 3: _t->updateRMScurr((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateDCvolt((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->updateDCVolt_QVar((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 6: _t->updateHStemp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateMotorTemp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->updateVoltAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateIQcurr((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->sendEMCY6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->sendEMCY7((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->sendD6stat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->sendD7stat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->readData(); break;
        case 15: _t->readError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateBatteryTemp)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateRPM)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(const QVariant & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateRPM_QVar)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateRMScurr)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateDCvolt)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(const QVariant & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateDCVolt_QVar)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateHStemp)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateMotorTemp)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateVoltAngle)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::updateIQcurr)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::sendEMCY6)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::sendEMCY7)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::sendD6stat)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (RosProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosProcess::sendD7stat)) {
                *result = 13;
                return;
            }
        }
    }
}

const QMetaObject RosProcess::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RosProcess.data,
      qt_meta_data_RosProcess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RosProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RosProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RosProcess.stringdata0))
        return static_cast<void*>(const_cast< RosProcess*>(this));
    return QThread::qt_metacast(_clname);
}

int RosProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void RosProcess::updateBatteryTemp(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RosProcess::updateRPM(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RosProcess::updateRPM_QVar(const QVariant & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RosProcess::updateRMScurr(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RosProcess::updateDCvolt(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RosProcess::updateDCVolt_QVar(const QVariant & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RosProcess::updateHStemp(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RosProcess::updateMotorTemp(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RosProcess::updateVoltAngle(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void RosProcess::updateIQcurr(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void RosProcess::sendEMCY6(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void RosProcess::sendEMCY7(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void RosProcess::sendD6stat(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void RosProcess::sendD7stat(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
