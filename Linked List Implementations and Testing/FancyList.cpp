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
    ListNode * removedNode = head;
    ListNode * prevNode = nullptr;
    ListNode * nextNode = nullptr;
    // counter to keep track of place in list
    int counter  = 1;
    // if list is empty, does nothing
    if(!head) 
        return;
    else {
        // while loop to reach very last node
        while(removedNode->next) {
            removedNode = removedNode->next;
        }  
        // removes last node if element is 1
        if(counter == element) {
            prevNode = removedNode->previous;
            prevNode->next = nullptr;
            delete removedNode;
        } else {
            // traverses linked list to reach element
            while(element != counter) {
                counter++;
                removedNode = removedNode->previous;
            }
            // checks if the removedNode is the first node
            if(removedNode->previous == nullptr) {
                nextNode = removedNode->next;
                nextNode->previous = nullptr;
                head = nextNode;
                delete removedNode;
            } else if(removedNode) {
                prevNode = removedNode->previous;
                nextNode = removedNode->next;
                delete removedNode;
                prevNode->next = nextNode;
                nextNode->previous = prevNode;
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
