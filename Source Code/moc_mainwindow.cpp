/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu 3. May 00:22:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Inversion/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      23,   11,   11,   11, 0x0a,
      34,   11,   11,   11, 0x0a,
      45,   11,   11,   11, 0x0a,
      57,   11,   11,   11, 0x0a,
      67,   11,   11,   11, 0x0a,
      78,   11,   11,   11, 0x0a,
      90,   11,   11,   11, 0x0a,
     101,   11,   11,   11, 0x0a,
     120,   11,  116,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     136,   11,   11,   11, 0x0a,
     144,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openhelp()\0openquit()\0"
    "openedit()\0openreset()\0openmix()\0"
    "openplay()\0opensolve()\0openover()\0"
    "opencombo(int)\0int\0isWin()\0clik1()\0"
    "clik2()\0gameTimer_timeout()\0refreshScore()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openhelp(); break;
        case 1: _t->openquit(); break;
        case 2: _t->openedit(); break;
        case 3: _t->openreset(); break;
        case 4: _t->openmix(); break;
        case 5: _t->openplay(); break;
        case 6: _t->opensolve(); break;
        case 7: _t->openover(); break;
        case 8: _t->opencombo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: { int _r = _t->isWin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: _t->clik1(); break;
        case 11: _t->clik2(); break;
        case 12: _t->gameTimer_timeout(); break;
        case 13: _t->refreshScore(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
