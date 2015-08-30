from distutils.core import setup
from distutils.extension import Extension

extensions = [
    Extension("_simple", ["_simple_module.c"], define_macros=[("_SIMPLE_MODULE", 1)]),
    Extension("_client", ["_simple_client.c"])
]

setup(
    ext_modules=extensions
)
