// Jomikael Ruiz
// March 1st, 2023
// Queue.h
// Purpose: Definitions for Stack Class

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue {
    private:
        struct Node {
            int val;
            Node * next;
        };
        Node * front;
        Node * rear;
        int numItems;
    public:
        Queue();
        ~Queue();
        void enqueue(int);
        int dequeue();
        bool isEmpty() const;
    
};
#endif