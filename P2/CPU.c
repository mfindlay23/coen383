  #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "CPU.h"
#include "Job.h"

CPU* createCPU() {
    CPU* cpu = malloc(sizeof(CPU));
    cpu->cpuState = available;
    cpu->global_time = 0;

    return cpu;
}

void giveCPUJob(CPU* cpu, Job *job) {
    cpu->job = job;
    cpu->cpuState = busy;
}

void freeCPU(CPU* cpu) {
    cpu->cpuState = available;
}

void runIdle(CPU *cpu, unsigned time_delta, int output) {
    for (int i = 0; i < time_delta; i++) {
        if (output == 1) {
            if ((cpu->global_time + i) % 5 == 4) printf("\n");
            printf("%d: Idle.\t", cpu->global_time + i);
        }
    }
    cpu->global_time += time_delta;
}

// Return amount of time ran
int runCurrentJob(CPU *cpu, unsigned time_delta, int output) {
    cpu->job->remaining_service_time -= time_delta;
    if (cpu->job->remaining_service_time < 0) {
        time_delta += cpu->job->remaining_service_time;
        cpu->job->remaining_service_time = 0;
    }

    for (int i = 0; i < time_delta; i++) {
        if (output == 1) {
            if ((cpu->global_time + i) % 5 == 4) printf("\n");
            printf("%d: Job %d\t", cpu->global_time + i, cpu->job->pid);
        }
    }

    if (cpu->job->start_time == -1)
        cpu->job->start_time = cpu->global_time;
    cpu->global_time += time_delta;
    if (cpu->job->remaining_service_time == 0)
        cpu->job->finish_time = cpu->global_time;

    cpu->job->age = 0;
    return time_delta;
}
