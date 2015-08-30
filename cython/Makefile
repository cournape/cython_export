all: _simple.so

_client.so: _simple_client.o
	gcc -shared $< -o $@

_simple.so: _simple.o
	gcc -shared _simple.o -o _simple.so

_simple.o: _simple.c
	gcc -c -fPIC $< -I /usr/include/python2.7 -W -o $@ -D_SIMPLE_MODULE

%.o: %.c
	gcc -c -fPIC $< -I /usr/include/python2.7 -W -o $@

_simple.c: _simple.pyx
	cython _simple.pyx

clean:
	rm -f _simple.c
	rm -f _simple.so
	rm -f *.o
