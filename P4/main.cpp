# include <iostream>
# include <stdlib.h>
# include <time.h>
# include "CPU.h"
# include "Process.h"

const unsigned QUANTUM = 100;
extern const unsigned RUN_TIME = 60000; // milliseconds
extern const unsigned JOB_COUNT = 150;
extern const unsigned NUM_PAGES = 100;

int main() {
    srand(time(NULL));

    CPU cpu = CPU(RANDOM);
    while (!cpu.isProcessesComplete()
            && cpu.getClockTime() <= RUN_TIME) {
        Process *p = cpu.getNextProcess();
        bool a = p == nullptr;
        //std::cout << a << std::endl;
        cpu.runProcess(QUANTUM, p);
    }
}
