// Jomikael Ruiz
// hw3.cpp
// Febuary 6th, 2023
// Purpose: implementing linked lists using pointers and user input
// and asking users to input values to place into each node of the list

#include <iostream>
#include "FancyList.h"
using namespace std;

const int END = 5;

// prints out the menu options and returns user input
int displayMenu();
// takes in user input and changes a FancyList object based on input
FancyList * evaluateInput(FancyList * list, int input);

int main(int argc, char *argv[]) {
    FancyList * fancyListPtr = nullptr;
    int userInput = 0;
    while(userInput != END) {
        userInput = displayMenu();
        fancyListPtr = evaluateInput(fancyListPtr, userInput);
    }
    delete fancyListPtr;
}

int displayMenu()
{
    int userInput = -1;
    cout << endl << endl;
    cout << "************ FancyList Menu ************" << endl;
    cout << "1:\tCreate a list" << endl;
    cout << "2:\tDisplay the list" 
         << endl;
    cout << "3:\tReverse the list" 
         << endl;
    cout << "4:\tDelete the n-th node from the end of the list" << endl;
    cout << "5:\tExit the Program" << endl << endl;
    cout << "Enter your choice: ";
    while(userInput < 1 || userInput > 6)
        cin >> userInput;
    cout << endl;
    return userInput;
}

FancyList * evaluateInput(FancyList * list, int input) {
    FancyList * listPtr = list;
    int elementRemoved = 0;
    switch(input) {
        case 1:
            listPtr = new FancyList;
            listPtr->inputList();
            break;
        case 2:
            cout << "Current list is: ";
            listPtr->printList();
            break;
        case 3:
            cout << "Current list after reversing is: ";
            listPtr->reverseList();
            listPtr->printList();
            break;
        case 4: 
            cout << "Delete n-th node from the end of the list, your n is: ";
            cin >> elementRemoved;
            cout << endl;
            list->removeNode(elementRemoved);
            cout << "Current list after deleting the " << elementRemoved 
                 << "-th node from the end is: ";
            list->printList();   
            break; 
    }      
    return listPtr;
}