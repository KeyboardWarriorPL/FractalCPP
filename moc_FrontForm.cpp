/****************************************************************************
** Meta object code from reading C++ file 'FrontForm.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FrontForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrontForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FrontForm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      25,   10,   10,   10, 0x08,
      37,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FrontForm[] = {
    "FrontForm\0\0drawFractal()\0saveImage()\0"
    "resetPos()\0"
};

void FrontForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FrontForm *_t = static_cast<FrontForm *>(_o);
        switch (_id) {
        case 0: _t->drawFractal(); break;
        case 1: _t->saveImage(); break;
        case 2: _t->resetPos(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FrontForm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FrontForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FrontForm,
      qt_meta_data_FrontForm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FrontForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FrontForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FrontForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FrontForm))
        return static_cast<void*>(const_cast< FrontForm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FrontForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
