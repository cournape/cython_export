#include <Python.h>
#define _SIMPLE_MODULE
#include "_simple_module.h"

static void PySimple_Hello(const char* message)
{
	printf("Message: %s\n", message);
}

static PyObject *
simple_hello(PyObject *self, PyObject *args)
{
	const char *message;

	if (!PyArg_ParseTuple(args, "s", &message))
		return NULL;

	PySimple_Hello(message);

	Py_INCREF(Py_None);
	return Py_None;
}

static PyMethodDef simple_methods[] = {
	{"hello",  simple_hello, METH_VARARGS, "Print a message."},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
init_simple(void)
{
	PyObject *m;
    	PyObject *c_api_object;

	m = Py_InitModule("_simple", simple_methods);
	if (m == NULL)
		return;

	/* Create a Capsule containing the API pointer array's address */
	c_api_object = PyCapsule_New((void *)PySimple_API, "_simple._C_API", NULL);

	if (c_api_object != NULL)
		PyModule_AddObject(m, "_C_API", c_api_object);
}
