#include "IntegerSet.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

const string X = "x";

IntegerSet::IntegerSet(int arr[], int size) {
    emptySet();
    this->size = size;
    for(int i = 0; i < size; i++) {
        insertElement(arr[i]);
    }
}

IntegerSet::IntegerSet() {
    emptySet();
}

void IntegerSet::unionOfSets(IntegerSet compareSet) {
    IntegerSet *ptr = new IntegerSet();
    for(int i = 0; i < MAXSIZE; i++) {
        if(this->arraySet[i] == 1) {
            ptr->insertElement(i);
        } else if(compareSet.arraySet[i] == 1) {
            ptr->insertElement(i);
        }
    }
    ptr->printSet();
    delete ptr;
}        
void IntegerSet::intersectionOfSets(IntegerSet compareSet) {
    IntegerSet *ptr = new IntegerSet();
    for(int i = 0; i < MAXSIZE; i++) {
        if(this->arraySet[i] == 1 && compareSet.arraySet[i] == 1) {
            ptr->insertElement(i);
        }
    }
    ptr->printSet();
    delete ptr;
}
void IntegerSet::insertElement(int element) {
    if(validEntry(element)) {
        arraySet[element] = 1;
    }    
}
void IntegerSet::deleteElement(int element) {
    if(validEntry(element)) {
        arraySet[element] = 0;
    }    
}
void IntegerSet::printSet() {
    bool isEmptySet = true;
    cout << endl << "{ ";
    for(int i = 0; i < MAXSIZE; i++) {
        if(arraySet[i] == 1) {
            isEmptySet = false;
            cout << i << " ";
        }
    }
    if(isEmptySet) {
        cout << "- ";
    }
    cout << "}";
}
bool IntegerSet::isEqualTo(IntegerSet compareSet) {
    int count = 0;
    while(count < MAXSIZE && arraySet[count] == compareSet.arraySet[count]) {
        count++;
    }
    if(count < MAXSIZE) {
        return false;
    } else {
        return true;
    }
}
void IntegerSet::emptySet() {
    for(int i = 0; i < MAXSIZE; i++) {
        arraySet[i] = 0;
    }
}
void IntegerSet::inputSet() {
    bool endInput = true;
    int setInput = 0;
    string input = "";
    while(endInput) {
        cout << "Enter an element (Type x to stop): ";
        cin >> input;
        if(input == X) {
            endInput = false;
        } else {
            setInput = stoi(input);
            if(validEntry(setInput)) {
                insertElement(setInput);
            }
        }    
        cout << endl;
    }
    cout << "Entry complete" << endl;
}
bool IntegerSet::validEntry(int setInput) {
    if(setInput < MIN || setInput > MAX) {
        cout << "Invalid insert of " << setInput << " attempted!" << endl;
        return false;
    }
    return true;
}