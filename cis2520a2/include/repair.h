#ifndef __REPAIR_LINKEDLIST__
#define __REPAIR_LINKEDLIST__

struct Repair{
    char * repairPlateNum;
    int repairMileage;
    // int repairExpectedReturnDate;
    struct Repair * next;
};

typedef struct Repair Repair;

Repair * createRecord(char * repairPlateNum, int repairMileage);
char * printRepairRecord(Repair * toPrintRepair);
void printRepairList(Repair * repairList);
int isRepairEmpty(Repair * repairList);

#endif
