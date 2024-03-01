// main.cpp
// Assuming C++17
//
// g++ -std=c++17 -O3 cpuinfo.cpp main.cpp
//
// Test the utility code

#include <iostream>
#include <chrono>

#include "cpuinfo.h"
#include "timer.h"

using namespace std;
using namespace std::chrono;

int main (int argc, char *argv[]) {
    timer<int, nano> nanoseconds;

    // Make sure we have the proper level of CPU functionality
    cout << "CPU ";
    if (is_cpu_gen_4())
        cout << "\x1b[32mis\x1b[0m ";
    else
        cout << "\x1b[31mis not\x1b[0m ";
    cout << "x86-64 4th gen compatible." << endl;

    // Output elapsed time
    auto elapsed = nanoseconds.elapsed();

    cout.imbue(std::locale(""));
    cout << "Elapsed time " << elapsed << " ns." << endl;

    return 0;
}
