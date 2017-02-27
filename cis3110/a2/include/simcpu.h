#ifndef __DHERA_SIMCPU__
#define __DHERA_SIMCPU__

typedef struct Thread
{
	int threadNum;
	int arrivalTime;
	int cpuCount;
	int cpuTime;
	int ioTime;

}Thread;

typedef struct Process
{
    int processCount;
    int threadSwitch;
    int processSwitch;
    int averageTurnAroundTime;
    int totalTime;
    int cpuUtilization;

    int detailFlag;
    int verboseFlag;
    int roundRobinFlag;
    int quantumInteger;

    Thread * cpuThread;

}Process;


#endif
