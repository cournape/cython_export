#ifndef Py_SIMPLEMODULE_H
#define Py_SIMPLEMODULE_H

#ifdef _SIMPLE_MODULE
	/* This section is used when compiling the _simple extension */
	static void PySimple_Hello(const char*) ;

 	static void *PySimple_API[] = {
		(void*)PySimple_Hello,
	};

#else
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
