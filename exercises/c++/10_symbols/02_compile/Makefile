EXE = exe

LFLAGS = -lutil -I include -L.
CXX = g++
CXXFLAGS = -fpic -I include -std=c++11

SRC = src/src1.cc src/src2.cc
OBJ = ${SRC:.cc=.o}

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)

libutil.so: $(OBJ)
	$(CXX) -shared -o $@ $^

$(EXE): libutil.so
	$(CXX) main.cc -o $(EXE) $(LFLAGS)
	@LD_LIBRARY_PATH=.
	@export LD_LIBRARY_PATH

src/src1.o: include/utility.h include/src1.h
src/src2.o: include/utility.h include/src2.h

clean:
	rm -rf src/*.o $(EXE) */*~ *~

.PHONY: clean all


#@LD_LIBRARY_PATH=.
#@export LD_LIBRARY_PATH


