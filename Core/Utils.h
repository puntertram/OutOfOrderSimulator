#ifndef UTILS_H

#define UTILS_H

#include <string>
#include <vector>
using namespace std;


vector<string> getElements(string data) {
    // In a space separated string of elements, get the elements 
    string element = "";
    vector<string> elements;
    for(char d : data) {
        if(d == ' ') {
            if(element.size() != 0)
                elements.push_back(element);
            element = "";
        } else {
            element += d;
        }
    }
    elements.push_back(element);
    return elements;
}
#endif