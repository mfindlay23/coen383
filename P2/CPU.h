# ifndef CPU_H
# define CPU_H

#include "Job.h"

typedef enum CPU_State {available, busy} CPU_State;

typedef struct CPU {
	unsigned global_time;
	CPU_State cpuState;
	Job *job;
} CPU;

CPU* createCPU();

void giveCPUJob(CPU* cpu, Job *job);

void freeCPU(CPU* cpu);

void runIdle(CPU *cpu, unsigned time_delta, int output);

int runCurrentJob(CPU *cpu, unsigned time_delta, int output);

# endif /* CPU_H */
