/****************************************************************************
** Meta object code from reading C++ file 'CalibrationApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CalibrationApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalibrationApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalibrationApp_t {
    QByteArrayData data[14];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalibrationApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalibrationApp_t qt_meta_stringdata_CalibrationApp = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CalibrationApp"
QT_MOC_LITERAL(1, 15, 13), // "registerTools"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "startConnectTimer"
QT_MOC_LITERAL(4, 48, 16), // "stopConnectTimer"
QT_MOC_LITERAL(5, 65, 14), // "getConnectData"
QT_MOC_LITERAL(6, 80, 14), // "startpointpick"
QT_MOC_LITERAL(7, 95, 11), // "startUSpick"
QT_MOC_LITERAL(8, 107, 15), // "OutputTransData"
QT_MOC_LITERAL(9, 123, 13), // "ReadTransData"
QT_MOC_LITERAL(10, 137, 11), // "ReadSegData"
QT_MOC_LITERAL(11, 149, 13), // "Docalibration"
QT_MOC_LITERAL(12, 163, 11), // "DoMediumcal"
QT_MOC_LITERAL(13, 175, 12) // "DocaliResult"

    },
    "CalibrationApp\0registerTools\0\0"
    "startConnectTimer\0stopConnectTimer\0"
    "getConnectData\0startpointpick\0startUSpick\0"
    "OutputTransData\0ReadTransData\0ReadSegData\0"
    "Docalibration\0DoMediumcal\0DocaliResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalibrationApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
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

       0        // eod
};

void CalibrationApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalibrationApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->registerTools(); break;
        case 1: _t->startConnectTimer(); break;
        case 2: _t->stopConnectTimer(); break;
        case 3: _t->getConnectData(); break;
        case 4: _t->startpointpick(); break;
        case 5: _t->startUSpick(); break;
        case 6: _t->OutputTransData(); break;
        case 7: _t->ReadTransData(); break;
        case 8: _t->ReadSegData(); break;
        case 9: _t->Docalibration(); break;
        case 10: _t->DoMediumcal(); break;
        case 11: _t->DocaliResult(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CalibrationApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CalibrationApp.data,
    qt_meta_data_CalibrationApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalibrationApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalibrationApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalibrationApp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CalibrationApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
