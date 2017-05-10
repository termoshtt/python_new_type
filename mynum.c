
#include <Python.h>
#include <numpy/arrayobject.h>
#include <numpy/ufuncobject.h>

static PyObject *example(PyObject *_module, PyObject *args) {
  PyObject *arg1 = NULL, *arg2 = NULL, *out = NULL;
  PyObject *arr1 = NULL, *arr2 = NULL, *oarr = NULL;

  if (!PyArg_ParseTuple(args, "OOO!", &arg1, &arg2, &PyArray_Type, &out))
    return NULL;

  arr1 = PyArray_FROM_OTF(arg1, NPY_DOUBLE, NPY_IN_ARRAY);
  if (arr1 == NULL)
    return NULL;
  arr2 = PyArray_FROM_OTF(arg2, NPY_DOUBLE, NPY_IN_ARRAY);
  if (arr2 == NULL)
    goto fail;
  oarr = PyArray_FROM_OTF(out, NPY_DOUBLE, NPY_INOUT_ARRAY);
  if (oarr == NULL)
    goto fail;

  /* code that makes use of arguments */
  /* You will probably need at least
     nd = PyArray_NDIM(<..>)    -- number of dimensions
     dims = PyArray_DIMS(<..>)  -- npy_intp array of length nd
                                   showing length in each dim.
     dptr = (double *)PyArray_DATA(<..>) -- pointer to data.

     If an error occurs goto fail.
   */

  Py_DECREF(arr1);
  Py_DECREF(arr2);
  Py_DECREF(oarr);
  Py_INCREF(Py_None);
  return Py_None;

fail:
  Py_XDECREF(arr1);
  Py_XDECREF(arr2);
  PyArray_XDECREF_ERR(oarr);
  return NULL;
}

static PyMethodDef mynum_methods[] = {
    {"example", example, METH_VARARGS, "sample C function"},
    {NULL, NULL, 0, NULL}};

static PyModuleDef mynum_mod = {
    PyModuleDef_HEAD_INIT, "noddy",
    "Example module that creates an extension type.", -1, mynum_methods};

PyMODINIT_FUNC PyInit_mynum(void) {
  PyObject *m;

  m = PyModule_Create(&mynum_mod);
  if (m == NULL)
    return NULL;

  import_array();
  import_ufunc();

  return m;
}
