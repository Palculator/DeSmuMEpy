#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#include <Python.h>
#include <numpy/arrayobject.h>

#include <X11/Xlib.h>
#include <SDL.h>
#include <SDL_thread.h>

#include <NDSSystem.h>

static PyObject *arrayTest(PyObject *self, PyObject *args) {
    unsigned int* vector = new unsigned int[4];
    for (int i = 0; i < 4; i++){
        vector[i] = i+1;
    }
    npy_intp dims[] = {4};
    PyObject *ret = PyArray_SimpleNewFromData(1, dims, NPY_UINT32, vector);
    return ret;
}

static PyMethodDef DeSmuMEpy_FunctionsTable[] = {
    {
        "array_test",
        arrayTest,
        METH_VARARGS,
        "Testing array stuff" // documentation
    }, {
        NULL, NULL, 0, NULL
    }
};

static struct PyModuleDef DeSmuMEpy_Module = {
    PyModuleDef_HEAD_INIT,
    "desmumepy",
    "Python bindings for the DeSmuME emulator.",
    -1,
    DeSmuMEpy_FunctionsTable
};

PyMODINIT_FUNC PyInit_desmumepy(void) {
    import_array();
    return PyModule_Create(&DeSmuMEpy_Module);
}
