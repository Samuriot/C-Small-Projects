// Jomikael Ruiz
// March 1st, 2023
// Stack.cpp
// Purpose: provide implementation for Stack class

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node * curr = top;
    Node * next = nullptr;
    while(curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    top = nullptr;
}

void Stack::push(int num) {
    Node * newNode = new Node;
    newNode->val = num;
    if(isEmpty()) {
        top = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

int Stack::pop() {
    Node * temp = nullptr;
    if(isEmpty()) {
        cout << "The stack is empty." << endl;
        return -1;
    } else {
        int returnVal = top->val;
        temp = top->next;
        delete top;
        top = temp;
        return returnVal;
    }
}

bool Stack::isEmpty() const {
    return top == nullptr;
}