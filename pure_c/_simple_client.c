#include <Python.h>

#include "_simple_module.h"

static PyMethodDef client_methods[] = {
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
init_client(void)
{
	PyObject *m;

	m = Py_InitModule("_client", client_methods);
	if (m == NULL)
		return;

	if (import_simple() < 0)
		return;

	printf("init from client done\n");
	PySimple_Hello("yolo");
}
