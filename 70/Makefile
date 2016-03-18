CPP = g++
CPP_FILE = main.cpp
TEST_SH = ./test.sh
CFLAGS = -O2 -std=c++11 -Wall
PROGRAM = ./a.out

all: $(PROGRAM)

$(PROGRAM):$(CPP_FILE)
	$(CPP) $(CFLAGS) $(CPP_FILE) -o $(PROGRAM)

PHONY: check-syntax test

check-syntax:
	echo $(CPP) -fsyntax-only $(CFLAGS) $(CHK_SOURCES)
	$(CPP) -fsyntax-only $(CFLAGS) $(CHK_SOURCES)

test:$(PROGRAM)
	$(TEST_SH) $(PROGRAM)

