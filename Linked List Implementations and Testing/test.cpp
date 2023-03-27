// Jomikael Ruiz
// FancyList.cpp
// Febuary 16, 2023
// Purpose: Implements the FancyList class and defines all functions for class

#include <iostream>
#include "FancyList.h"
using namespace std;

const string X = "x";
const char SPACE = ' ';

// constructor that sets head to null
FancyList::FancyList() {
    head = nullptr;
}

// destructor that deallocates memory for each node
FancyList::~FancyList() {
    ListNode * nextNode;
    ListNode * currentNode = head;
    cout << "Deallocating..." << endl;
    while(currentNode != nullptr) {
        cout << "Deleting " << currentNode->data << endl;
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
}

// traverses the list to print out each value of the node
void FancyList::printList() const {
    ListNode * currentNode = head;
    while(currentNode != nullptr) {
        cout << currentNode->data << SPACE;
        currentNode = currentNode->next;
    }
}

// traverses to the end of the list and removes the parameter-th node from the
// end of the list
void FancyList::removeNode(int element) {
            ListNode * prev = nullptr;
            ListNode * curr = nullptr;
            ListNode * next = nullptr;
            int counter = 1;
            int difference = 0;
            if(!head) {
                return;
            } else {
                curr = head;
                while(curr) {
                    counter++;
                    curr = curr->next;
                }
                difference = counter - element;
                counter = 1;
                curr = head;
                if(counter == difference) {
                    next = curr->next;
                    delete curr;
                    head = next;

                } else {
                    while(curr && counter != difference) {
                        counter++;
                        prev = curr;
                        curr = curr->next;
                    }
                    if(curr) {
                        next = curr->next;
                        prev->next = next;
                        delete curr;
                    }
                }    
            }    

}

// takes in an int paramenter and creates a new node with value
// and appends it to the end of the list
void FancyList::appendNode(int num) {
    // pointers to traverse list
    ListNode * newNodePtr;
    ListNode * nodePtr;
    // creates new node with num parameter
    newNodePtr = new ListNode;
    newNodePtr->data = num;
    newNodePtr->next = nullptr;
    newNodePtr->previous = nullptr;
    // if head is null, makes new Node the head
    if(!head) {
        head = newNodePtr;
    } else {
        // else, goes to the end of the list and inserts node in
        nodePtr = head;
        while(nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        newNodePtr->previous = nodePtr;
        nodePtr->next = newNodePtr;
    }

}

// reverses nodes of the linked list
void FancyList::reverseList() {
    // pointers to traverse list
    ListNode * curr = nullptr;
    ListNode * next = nullptr;
    // if head is null, it ends the function
    if(!head) {
        return;
    }
    else {
        // sets the first node's next to null and sets next to the initial next
        next = head->next;
        head->next = nullptr;
        head->previous = next;
        curr = next;
        // traverses list and updates the next and previous pointers
        while(curr->next) {
            next = curr->next;
            curr->next = curr->previous;
            curr->previous = next;
            curr = next;
        }
        // sets the head to the last node and updates its next and previous
        head = curr;
        curr->next = curr->previous;
        curr->previous = nullptr;   
    }    
}

// asks user for input and calls apendNode to add to list
void FancyList::inputList() {
    bool endInput = true;
    int setInput = 0;
    string input = "";
    while(endInput) {
        cout << "Type a number for appending (Type x to stop): ";
        cin >> input;
        if(input == X) {
            endInput = false;
        } else {
            setInput = stoi(input);
            appendNode(setInput);
        }    
        cout << endl;
    }
}
