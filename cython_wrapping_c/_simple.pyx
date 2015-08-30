import sys

from cpython.pycapsule cimport PyCapsule_New

cdef extern from "simple.h":
    cdef const char* PySimple_GetVersion()

cdef extern from "_simple_module.h":
    cdef void** PySimple_API

def get_version():
    return PySimple_GetVersion()

if sys.version_info[0] >= 3:
    def get_version3():
        return PySimple_GetVersion()

cdef object __init_module():
    return PyCapsule_New(PySimple_API, "_simple._C_API", NULL)

_C_API = __init_module()
