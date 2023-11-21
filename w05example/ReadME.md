## Compile training

#### Example: Basic Compiler Usage

```shell
cd Example
#dynamic lib
g++ src/c.cc -fPIC -shared -o lib/libtest.so -I ./inc
#static lib
g++ -c src/c.cc -o libtest.o -I ./inc
ar crf lib/libtest.a libtest.o

g++ a.cc src/b.cc -o a_static -I ./inc -L ./lib -l:libtest.a
g++ a.cc src/b.cc -o a_dynamic -I ./inc -L ./lib -ltest

./a_static
./a_dynamic
```

#### Example: Basic Make Usage

```shell
cd MakeExample
make 
```

#### Example: Basic CMake Usage
```shell
cd CMakeExample
cmake -Bbuild
cd build

#cmake --build .
make
```