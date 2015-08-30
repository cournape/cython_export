from cpython.pycapsule cimport PyCapsule_New

from _simple_impl cimport PySimple_Hello

cdef void *PySimple_API[1]

def simple_hello(message):
    PySimple_Hello(message)

cdef object __init_module():
    PySimple_API[0] = <void*>PySimple_Hello
    return PyCapsule_New(PySimple_API, "_simple._C_API", NULL)

_C_API = __init_module()
