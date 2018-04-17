/****************************************************************************
** Meta object code from reading C++ file 'PIAGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PIAGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PIAGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PIAGUI_t {
    QByteArrayData data[10];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PIAGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PIAGUI_t qt_meta_stringdata_PIAGUI = {
    {
QT_MOC_LITERAL(0, 0, 6), // "PIAGUI"
QT_MOC_LITERAL(1, 7, 16), // "loadDataFromFile"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "dataGcur"
QT_MOC_LITERAL(4, 34, 16), // "DisplayCtlPoints"
QT_MOC_LITERAL(5, 51, 19), // "DisplayBsplineCurve"
QT_MOC_LITERAL(6, 71, 14), // "DisplayCtlPoly"
QT_MOC_LITERAL(7, 86, 17), // "DisplayDataPoints"
QT_MOC_LITERAL(8, 104, 14), // "OneStepIterate"
QT_MOC_LITERAL(9, 119, 11) // "m_PIAButton"

    },
    "PIAGUI\0loadDataFromFile\0\0dataGcur\0"
    "DisplayCtlPoints\0DisplayBsplineCurve\0"
    "DisplayCtlPoly\0DisplayDataPoints\0"
    "OneStepIterate\0m_PIAButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PIAGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void PIAGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PIAGUI *_t = static_cast<PIAGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadDataFromFile(); break;
        case 1: _t->dataGcur(); break;
        case 2: _t->DisplayCtlPoints(); break;
        case 3: _t->DisplayBsplineCurve(); break;
        case 4: _t->DisplayCtlPoly(); break;
        case 5: _t->DisplayDataPoints(); break;
        case 6: _t->OneStepIterate(); break;
        case 7: _t->m_PIAButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PIAGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PIAGUI.data,
      qt_meta_data_PIAGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PIAGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PIAGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PIAGUI.stringdata0))
        return static_cast<void*>(const_cast< PIAGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PIAGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
