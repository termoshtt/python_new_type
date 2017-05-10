
#include <Python.h>
#include <numpy/arrayobject.h>
#include <numpy/ufuncobject.h>

static PyObject *zeros_1d(PyObject *_module, PyObject *args) {
  int arg1;
  if (!PyArg_ParseTuple(args, "i", &arg1))
    return NULL;

  npy_intp dims[] = {arg1};

  PyObject *a = PyArray_ZEROS(1, dims, NPY_DOUBLE, 0);
  return a;
}

static PyMethodDef mynum_methods[] = {
    {"zeros_1d", zeros_1d, METH_VARARGS, "get NumPy Array"},
    {NULL, NULL, 0, NULL}};

static PyModuleDef mynum_mod = {PyModuleDef_HEAD_INIT, "mynum",
                                "Test module of NumPy C API", -1,
                                mynum_methods};

PyMODINIT_FUNC PyInit_mynum(void) {
  PyObject *m;

  m = PyModule_Create(&mynum_mod);

  import_array();
  import_ufunc();

  return m;
}
