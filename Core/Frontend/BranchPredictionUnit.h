#ifndef BRANCHPREDICTIONUNIT_H
#define BRANCHPREDICTIONUNIT_H

#include "./BranchPredictor.h"
#include "./BTB.h"

class BranchPredictionUnit {
public:
    BTB *btb;
    BranchPredictor *branchPredictor;
};

#endif