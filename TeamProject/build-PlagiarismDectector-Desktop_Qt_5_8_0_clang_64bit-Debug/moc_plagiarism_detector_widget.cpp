/****************************************************************************
** Meta object code from reading C++ file 'plagiarism_detector_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Software-Plagiarism-Detection/plagiarism_detector_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plagiarism_detector_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlagiarismDetectorWidget_t {
    QByteArrayData data[8];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlagiarismDetectorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlagiarismDetectorWidget_t qt_meta_stringdata_PlagiarismDetectorWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "PlagiarismDetectorWidget"
QT_MOC_LITERAL(1, 25, 19), // "change_mode_to_file"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 22), // "change_mode_to_project"
QT_MOC_LITERAL(4, 69, 12), // "read_folder1"
QT_MOC_LITERAL(5, 82, 12), // "read_folder2"
QT_MOC_LITERAL(6, 95, 20), // "read_from_input_text"
QT_MOC_LITERAL(7, 116, 6) // "detect"

    },
    "PlagiarismDetectorWidget\0change_mode_to_file\0"
    "\0change_mode_to_project\0read_folder1\0"
    "read_folder2\0read_from_input_text\0"
    "detect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlagiarismDetectorWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlagiarismDetectorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlagiarismDetectorWidget *_t = static_cast<PlagiarismDetectorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_mode_to_file(); break;
        case 1: _t->change_mode_to_project(); break;
        case 2: _t->read_folder1(); break;
        case 3: _t->read_folder2(); break;
        case 4: _t->read_from_input_text(); break;
        case 5: _t->detect(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PlagiarismDetectorWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlagiarismDetectorWidget.data,
      qt_meta_data_PlagiarismDetectorWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlagiarismDetectorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlagiarismDetectorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlagiarismDetectorWidget.stringdata0))
        return static_cast<void*>(const_cast< PlagiarismDetectorWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlagiarismDetectorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
