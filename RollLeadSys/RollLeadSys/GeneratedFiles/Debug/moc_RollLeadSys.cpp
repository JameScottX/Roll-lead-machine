/****************************************************************************
** Meta object code from reading C++ file 'RollLeadSys.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RollLeadSys.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RollLeadSys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RollLeadSys_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RollLeadSys_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RollLeadSys_t qt_meta_stringdata_RollLeadSys = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RollLeadSys"
QT_MOC_LITERAL(1, 12, 8), // "set_show"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "order_Check"
QT_MOC_LITERAL(4, 34, 11), // "eventFilter"
QT_MOC_LITERAL(5, 46, 3), // "obj"
QT_MOC_LITERAL(6, 50, 7), // "QEvent*"
QT_MOC_LITERAL(7, 58, 5), // "event"
QT_MOC_LITERAL(8, 64, 10), // "closeEvent"
QT_MOC_LITERAL(9, 75, 12), // "QCloseEvent*"
QT_MOC_LITERAL(10, 88, 13) // "params_Config"

    },
    "RollLeadSys\0set_show\0\0order_Check\0"
    "eventFilter\0obj\0QEvent*\0event\0closeEvent\0"
    "QCloseEvent*\0params_Config"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RollLeadSys[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    2,   41,    2, 0x08 /* Private */,
       8,    1,   46,    2, 0x08 /* Private */,
      10,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 9,    7,
    QMetaType::Void,

       0        // eod
};

void RollLeadSys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RollLeadSys *_t = static_cast<RollLeadSys *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_show(); break;
        case 1: _t->order_Check(); break;
        case 2: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->params_Config(); break;
        default: ;
        }
    }
}

const QMetaObject RollLeadSys::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RollLeadSys.data,
      qt_meta_data_RollLeadSys,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RollLeadSys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RollLeadSys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RollLeadSys.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RollLeadSys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
