CXX = c++

#SRC = source/hello.cc source/main.cc
#OBJ = $(SRC:.cc=.o)

install: main.x

main.x: libhello.so source/main.cc
	$(CXX) source/main.cc -o $@ -lhello -I include -L.
	#LD_LIBRARY_PATH=.
	#export LD_LIBRARY_PATH

libhello.so: source/hello.o
	$(CXX) -shared -o $@ $^

source/hello.o: source/hello.cc
	$(CXX) -fpic -o $@ -c $< -Iinclude

source/hello.o: include/hello.h

.PHONY: install
