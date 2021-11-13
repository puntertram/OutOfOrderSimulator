#ifndef ICACHE_H

#define ICACHE_H
#include <vector>
#include <string>
using namespace std;

/*

    status: 1 bit representing two states: 
        1 - ready
        0 - busy

*/


enum ICacheStatus {
    ICACHE_BUSY, ICACHE_READY
};

class ICache {
public:
    ICacheStatus status;
    ICache() {
        this->status = ICACHE_READY;
    }
    ICacheStatus getStatus() {
        return status;
    }
    vector<string> getData(int PC, int count) {
        // Fetch next count instructions from PC
        vector<string> instructions = {"20 3 1 2", "20 4 3 5", "20 5 3 4", "20 4 3 5"};
        return instructions;
    }

};

#endif