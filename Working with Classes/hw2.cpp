// Jomikael Ruiz
// hw2.cpp
// Febuary 5th, 2023
// Purpose: utilize multiple files to define and implement classes
// and compare and contrast two different IntegerSet class objects

#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main(int argc, char *argv[]) {
    int input;
    int TESTSIZE = 10;
    int TESTARRAY[10] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
    IntegerSet a;
    IntegerSet b;
    cout << endl << endl;
    cout << "Enter set A: " << endl;
    a.inputSet();
    cout << endl;
    cout << "Enter set B: " << endl;
    b.inputSet();
    cout << endl;
    cout << "Union of A and B is: ";
    a.unionOfSets(b);
    cout << endl << endl;
    cout << "Intersection of A and B is: ";
    a.intersectionOfSets(b);
    cout << endl << endl;
    if(a.isEqualTo(b)) {
        cout << "Set A is equal to set B" << endl;
    } else {
        cout << "Set A is not equal to set B" << endl;
    }
    cout << "What element would you like to insert into set A?: ";
    cin >> input;
    a.insertElement(input);
    cout << endl;
    cout << "Set A is now: ";
    a.printSet();
    cout << endl << endl;
    cout << "Deleting " << input << " from set A..." << endl;
    a.deleteElement(input);
    cout << "Set A is now: ";
    a.printSet();
    cout << endl << endl;
    cout << "Now creating a set of specific values and testing " 
         << "the bounds limits.";
    cout << endl;
    cout << "Creating array of size 10: {25, 67, 2, 9, 99, "
         << "105, 45, -5, 100, 1}";
    cout << endl;
    IntegerSet c = IntegerSet(TESTARRAY, TESTSIZE);
    cout << "Set C is: ";
    c.printSet();
    cout << endl << endl;
    return 0;
}
