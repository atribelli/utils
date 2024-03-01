# makefile

optcpp = -std=c++17 -O3
optc   = -std=c17 -O3
#optdb  = -g

all: test

test: main.o cpuinfo.o
	g++ $(optdb) -o test $(optcpp) main.o cpuinfo.o

main.o: timer.h cpuinfo.h main.cpp
	g++ $(optdb) -c $(optcpp) main.cpp

cpuinfo.o: cpuinfo.h cpuinfo.cpp
	g++ $(optdb) -c $(optcpp) cpuinfo.cpp

clean:
	rm -f test a.out *.o
