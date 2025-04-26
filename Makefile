

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g

SRC      := intbst.cpp
HEADERS  := intbst.h
TESTBST  := testbst.cpp
MYTEST   := test_intbst.cpp

.PHONY: all clean mytests

all: testbst

testbst: $(SRC) $(HEADERS) $(TESTBST)
	$(CXX) $(CXXFLAGS) $^ -o $@

mytests: $(SRC) $(HEADERS) $(MYTEST)
	$(CXX) $(CXXFLAGS) $^ -o mytests
	./mytests

clean:
	rm -f testbst mytests *.o
