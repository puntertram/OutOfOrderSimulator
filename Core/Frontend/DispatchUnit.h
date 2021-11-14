#ifndef DISPATCH_H

#define DISPATCH_H
#include "../Instruction.h"
#include "../Backend/ReservationStation.h"

#include <vector>

using namespace std;

class DispatchUnit {
public:
    vector<Instruction *> *instructionQueue;
    InstructionDecoder *instructionDecoder;
    INTReservationStation* intRS;
    FPReservationStation* fpRS;
    LSReservationStation* lsRS;
    bool stalled;
    DispatchUnit() {
        intRS = NULL;
        fpRS = NULL;
        lsRS = NULL;
        instructionQueue = NULL;
        instructionDecoder = NULL;
    }
    void dispatch() {
        if(instructionDecoder->isIntegerInstruction(instructionQueue->front())) {

        } else if(instructionDecoder->isFloatingPointInstruction(instructionQueue->front())) {
            
        } else if(instructionDecoder->isLoadStoreInstruction(instructionQueue->front())) {
            
        }
    }
};

#endif