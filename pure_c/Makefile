all: _simple.so

_client.so: _simple_client.o
	gcc -shared $< -o $@

_simple.so: _simple_module.o
	gcc -shared _simple_module.o -o _simple.so

#libimpl.a: _simple_impl.o
#	ar rc $@ $<
#	ranlib $@

%.o: %.c
	gcc -c -fPIC $< -I /usr/include/python2.7 -W -o $@

clean:
	rm -f _simple.so
	rm -f *.o
