#ifndef INSTRUCTION_H


#define INSTRUCTION_H 

enum InstructionType {
    ADD_INSTRUCTION, 
    ADDU_INSTRUCTION,
    ADDI_INSTRUCTION,
    SUB_INSTRUCTION, 
    MUL_INSTRUCTION, 
    BEQ_INSTRUCTION, 
    BGTZ_INSTRUCTION,
    BLEZ_INSTRUCTION,
    BNE_INSTRUCTION,
    JMP_INSTRUCTION, 
    JMPAL_INSTRUCTION,
    JMPR_INSTRUCTION,
    CMP_INSTRUCTION
};



class Instruction {
public:
    InstructionType type;
};

class AddInstruction: public Instruction {
public:
    int src1, src2;
    int dest;
};


#endif