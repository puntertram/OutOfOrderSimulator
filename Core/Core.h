#ifndef CORE_H
#define CORE_H
#include "./Frontend/FetchUnit.h"
#include "./Frontend/DispatchUnit.h"
#include "./Instruction.h"

using namespace std;

class Core {
public:
    vector<Instruction *> instructionQueue;
    FetchUnit *fetchUnit;
    DispatchUnit *dispatchUnit;
    bool stalled;
    int cycleCounter;
    int id;
    Core(int _id) {
        id = _id;
        cycleCounter = 0;
        fetchUnit = new FetchUnit();
        dispatchUnit = new DispatchUnit();
        fetchUnit->instructionQueue = &instructionQueue;
        dispatchUnit->instructionQueue = &instructionQueue;
        stalled = false;
    }
    void cycle() {
        // Run one cycle of this core
        if(stalled) {
            cout << "[ " << cycleCounter << "] Core " << id << "stalled\n";
        }
        fetchUnit->fetch();
        dispatchUnit->dispatch();
        updateStalledStatus();
        cycleCounter++;
    }
    void updateStalledStatus() {
        if(fetchUnit->stalled and dispatchUnit->stalled) {
            stalled = true;
        }
    }
};
#endif