from libc.stdio cimport printf
from cpython.pycapsule cimport PyCapsule_New
from cpython.module cimport PyImport_Import, PyModule_AddObject


cdef extern from "_simple_module.h":
    cdef void** PySimple_API
    cdef void PySimple_Hello(const char*)

cdef void PySimple_Hello(const char* message):
    assert message is not None
    printf("%s\n", message)

def simple_hello(message):
    PySimple_Hello(message)

cdef object __init_module():
    return PyCapsule_New(PySimple_API, "_simple._C_API", NULL)

_C_API = __init_module()
