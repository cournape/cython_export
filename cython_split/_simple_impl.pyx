from libc.stdio cimport printf


cdef void PySimple_Hello(const char* message):
    assert message is not None
    printf("%s\n", message)
