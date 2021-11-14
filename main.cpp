#include <bits/stdc++.h>
#include "./Core/Core.h"


using namespace std;
int main(int argc, char **argv) {
    Core *c1 = new Core(0);
    while(true) {
        c1->cycle();
        char ch;
        cout << "Next cycle? (Y/N)\n";
        cin >> ch;
        if(ch == 'Y') {
            continue;
        } else {
            break;
        }
    }

    return 0;
}