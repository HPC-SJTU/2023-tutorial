CC = g++
DIRPATH=$(CURDIR)
CCFLAGS= -O2
SRC=a.cc src/b.cc


LIBSRC=src/c.cc

.PHONY:dynamic static clean

dynamic: $(SRC) libtest.so
	$(CC) $(SRC) -o a_dynamic $(CCFLAGS) -I ./inc -L ./lib -ltest
static: $(SRC) libtest.a
	$(CC) $(SRC) -o a_static $(CCFLAGS) -I ./inc -L ./lib -l:libtest.a
libtest.so: $(LIBSRC)
	$(CC) $(LIBSRC) -fPIC -shared -o $(DIRPATH)/lib/libtest.so $(CCFLAGS) -I ./inc 
libtest.a: $(LIBSRC)
	$(CC) -c $(LIBSRC) -o $(DIRPATH)/lib/libtest.o $(CCFLAGS) -I ./inc 
	ar crf $(DIRPATH)/lib/libtest.a $(DIRPATH)/lib/libtest.o
clean:
	rm $(DIRPATH)/lib/libtest.* a_dynamic a_static