OUT      = hys
TESTFILE = test.c

CXX       = clang++
CXXFLAGS = -std=c++17 -O0 -g -Wall -I.
OBJ      = assembler.o executor.o instruction.o utils.o main.o
TESTOUT  = $(basename $(TESTFILE)).asm
OUTFILES = *.o $(OUT)

.PHONY: build test simulate clean

build: $(OUT)

test: $(TESTOUT)

clean:
	rm -f $(OUTFILES)

$(TESTOUT): $(TESTFILE) $(OUT)
	./$(OUT) < $< > $@

$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)
