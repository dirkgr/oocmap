#ifndef OOCMAP_LAZYDICT_H
#define OOCMAP_LAZYDICT_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "oocmap.h"
#include "lmdb.h"

//
// OOCLazyDict
//

typedef struct {
    PyObject_HEAD
    OOCMapObject* ooc;
    uint32_t dictId;
} OOCLazyDictObject;

extern PyTypeObject OOCLazyDictType;

OOCLazyDictObject* OOCLazyDict_fastnew(OOCMapObject* ooc, uint32_t dictId);

Py_ssize_t OOCLazyDictObject_length(OOCLazyDictObject* self, MDB_txn* txn);

PyObject* OOCLazyDictObject_eager(OOCLazyDictObject* self, MDB_txn* txn);
PyObject* OOCLazyDict_eager(PyObject* pySelf);


//
// OOCLazyDictItems
//

typedef struct {
    PyObject_HEAD
    OOCLazyDictObject* dict;
} OOCLazyDictItemsObject;

extern PyTypeObject OOCLazyDictItemsType;

OOCLazyDictItemsObject* OOCLazyDictItems_fastnew(OOCMapObject* ooc, uint32_t dictId);


//
// OOCLazyDictItemsIter
//

typedef struct {
    PyObject_HEAD
    OOCLazyDictObject* dict;
    MDB_cursor* cursor;
} OOCLazyDictItemsIterObject;

extern PyTypeObject OOCLazyDictItemsIterType;

OOCLazyDictItemsIterObject* OOCLazyDictItemsIter_fastnew(OOCMapObject* ooc, uint32_t dictId);


#endif
