// Jomikael Ruiz
// March 1st, 2023
// Stack.h
// Purpose: Definitions for Stack Class

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack {
    private:
        struct Node {
            int val;
            Node * next;
        };
        Node * top;
    public:
        Stack();
        ~Stack();
        void push(int);
        int pop();
        bool isEmpty() const;

};
#endif