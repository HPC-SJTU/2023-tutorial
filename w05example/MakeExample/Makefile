CC = g++
DIRPATH=$(CURDIR)
CCFLAGS= -O2
SRC=a.cc src/b.cc
LIBPATH=$(CURDIR)/lib

LIBSRC=src/c.cc

.PHONY:dynamic static clean prepare

dynamic:  $(SRC) $(DIRPATH)/lib/libtest.so 
	$(CC) $(SRC) -o a_dynamic $(CCFLAGS) -I ./inc -L ./lib -ltest
static: $(SRC) $(DIRPATH)/lib/libtest.a prepare
	$(CC) $(SRC) -o a_static $(CCFLAGS) -I ./inc -L ./lib -l:libtest.a
prepare:
	@if [ ! -d $(LIBPATH) ]; then mkdir -p $(LIBPATH); fi 
$(DIRPATH)/lib/libtest.so: $(LIBSRC) prepare
	$(CC) $(LIBSRC) -fPIC -shared -o $(DIRPATH)/lib/libtest.so $(CCFLAGS) -I ./inc 
$(DIRPATH)/lib/libtest.a: $(LIBSRC) prepare
	$(CC) -c $(LIBSRC) -o $(DIRPATH)/lib/libtest.o $(CCFLAGS) -I ./inc 
	ar crf $(DIRPATH)/lib/libtest.a $(DIRPATH)/lib/libtest.o
clean:
	rm $(DIRPATH)/lib/libtest.* a_dynamic a_static