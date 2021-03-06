#ifndef Py_SIMPLEMODULE_H
#define Py_SIMPLEMODULE_H

#ifndef _SIMPLE_MODULE
	/* This section is used in modules that use _simple's C API */
	static void **PySimple_API;
	#define PySimple_Hello (*(void (*)(const char*)) PySimple_API[0])
	
	static int import_simple(void)
	{
	    PySimple_API = (void **)PyCapsule_Import("_simple._C_API", 0);
	    return (PySimple_API != NULL) ? 0 : -1;
	}
#endif

#endif /* !defined(Py_SIMPLEMODULE_H) */
