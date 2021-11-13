#ifndef BRANCHPREDICTOR_H
#define BRANCHPREDICTOR_H

enum BranchDirection {
    TAKE_BRANCH, DO_NOT_TAKE_BRANCH
};


class BranchPredictor {
public:
    BranchDirection getPrediction() {
        return TAKE_BRANCH;
    }
    void update(int PC, BranchDirection actualDirection) {
        // TODO: update our predictor for the instruction at PC.
    }
};

#endif 
