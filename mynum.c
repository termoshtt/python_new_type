
#include <Python.h>

static PyModuleDef mynum_mod = {
    PyModuleDef_HEAD_INIT,
    "noddy",
    "Example module that creates an extension type.",
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL};

PyMODINIT_FUNC PyInit_mynum(void) {
  PyObject *m;

  m = PyModule_Create(&mynum_mod);
  if (m == NULL)
    return NULL;

  return m;
}
