#ifndef INSTRUCTIONDECODER_H
#define INSTRUCTIONDECODER_H

#include "../Instruction.h"

#include <string> 
#include <vector>

using namespace std;

class InstructionDecoder {
public:
    Instruction * decodeInstruction(vector<string> &instructionElements) {
        switch(atoi(instructionElements[0].c_str())) {
            case 20:  AddInstruction *_instruction = new AddInstruction();
                        _instruction->type = ADD_INSTRUCTION;
                        _instruction->dest = atoi(instructionElements[1].c_str());
                        _instruction->src1 = atoi(instructionElements[2].c_str());
                        _instruction->src2 = atoi(instructionElements[3].c_str());
                        // instruction = (Instruction *)_instruction;
                        return _instruction;

        }
    }
    bool isIntegerInstruction(Instruction *instruction) {
        return (instruction->type == ADD_INSTRUCTION) or (instruction->type == ADDI_INSTRUCTION);
    }
    bool isFloatingPointInstruction(Instruction *instruction) {
        // No FP instruction in ISA yet!!!
        return false;
    }
    bool isLoadStoreInstruction(Instruction *instruction) {
        return (instruction->type == LOADBYTE_INSTRUCTION) or (instruction->type == STOREBYTE_INSTRUCTION);
    }
    bool isControlFlowInstruction(Instruction *instruction) {
        return 
                (instruction->type == BEQ_INSTRUCTION) or 
                (instruction->type == BGTZ_INSTRUCTION) or 
                (instruction->type == BLEZ_INSTRUCTION) or 
                (instruction->type == BNE_INSTRUCTION) or 
                (instruction->type == JMP_INSTRUCTION) or 
                (instruction->type == JMPAL_INSTRUCTION) or 
                (instruction->type == JMPR_INSTRUCTION);
    }
};

#endif