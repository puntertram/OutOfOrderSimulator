#ifndef FETCHUNIT_H 

#define FETCHUNIT_H 
#include "./ICache.h"
#include "../Constants.h"
#include "../Instruction.h"
#include "./InstructionDecoder.h"
#include "./BranchPredictionUnit.h"
#include "../Utils.h"

#include <iostream>
#include <vector>

using namespace std;


class FetchUnit {
public:
    ICache *icache;
    InstructionDecoder *instructionDecoder;
    BranchPredictionUnit *branchPredictionUnit;
    vector<Instruction *> *instructionQueue;
    bool stalled;
    FetchUnit() {
        this->icache = new ICache();
        this->instructionDecoder = new InstructionDecoder();
    }
    int PC;
    void fetch() {
        if((icache->getStatus() == ICACHE_BUSY) or (instructionQueue->size() == INSTRUCTION_QUEUE_CAPACITY)) {
            cout << "Fetch unit stalled\n";
            stalled = true;
        } else {
            vector<string> data = icache->getData(PC, NUMBER_OF_INSTRUCTIONS_FETCH_PER_CYCLE);
            for(string d : data) {
                Instruction *instruction = NULL;
                vector<string> instructionElements = getElements(d);
                instruction = instructionDecoder->decodeInstruction(instructionElements);  
                if(instructionDecoder->isControlFlowInstruction(instruction)) {
                    updatePC(instruction);
                    break;
                }
                instructionQueue->push_back(instruction); 
            }
            
        }
    }
    void updatePC(Instruction *instruction) {
        PC = PC + 4;
        if(instructionDecoder->isControlFlowInstruction(instruction)) {
            if(instruction->type == BEQ_INSTRUCTION) {
                // It is a conditional branch
                if(branchPredictionUnit->branchPredictor->getPrediction() == TAKE_BRANCH) {
                    cout << "Branch predicted taken\n";
                    PC = PC + branchPredictionUnit->btb->getTargetAddress();
                }  else {
                    cout << "Branch predicted not taken\n";
                }
            }
        }
    }
};


#endif