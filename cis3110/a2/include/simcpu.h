#ifndef __DHERA_SIMCPU__
#define __DHERA_SIMCPU__

typedef struct Burst
{
	int cputTime;
	int ioTime;
}Burst;

// typedef struct Thread
// {

// }

typedef struct Process
{
    int processCount;
    int threadSwitch;
    int processSwitch;
    int detailFlag;
    int verboseFlag;
    int roundRobinFlag;
    int quantumInteger;

    Burst * cpuBurst;

}Process;


#endif
