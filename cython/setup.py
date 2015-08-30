from distutils.core import setup
from distutils.extension import Extension

from Cython.Build import cythonize

extensions = [
    Extension("_simple", ["_simple.pyx"], define_macros=[("_SIMPLE_MODULE", 1)]),
    Extension("_client", ["_simple_client.c"])
]

setup(
    ext_modules=cythonize(extensions)
)
