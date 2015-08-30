Variations on a simple C extension exporting a C API export.

Every example achieves the same goal:

        * implement a simple "hello" function available at the python level
        * exports the underlying implemention PySimple_Hello of hello for other
          extensions to use.
        * the _client extension reuses the PySimple_Hello through the capsule
          mechanism

pure_c
======

Everything done in pure C.

cython
======

The _simple extension is entirely written in Cython.

cython_split
============

The _simple extension is entirely written in Cython, but using 2 cython
modules: one that implements PySimple_Hello, another one exposing it in python
and exporting it for other C extensions.

cython_wrapping
===============

Here, _simple is implemented in a mix of cython and hand-written C:

* the hand written C code implements the functionality
* the cython part exports the hand written C code at the python level, as well as exporting the C API.

This example is the closest to the approach to use for numpy: each of
multiarray and umfunc would be modified to get their PyMODULE_INIT owned by
cython, while the rest of the code stays as is. Once this step is implemented,
one can start cythonizing the actual implementation of numpy.
