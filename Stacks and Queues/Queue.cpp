// Jomikael Ruiz
// March 1st, 2023
// Queue.cpp
// Purpose: provide implementation for Queue class

#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    Node * curr = front;
    Node * next;
    while(curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int num) {
    Node * newNode = new Node;
    newNode->val = num;
    newNode->next = nullptr;
    if(isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

int Queue::dequeue() {
    if(isEmpty()) {
        cout << "The queue is empty." << endl; 
        return -1;
    } else {
        int val = front->val;
        Node * temp = front;
        front = front->next;
        delete temp;
        numItems--;
        return val;
    }
}

bool Queue::isEmpty() const {
    return numItems == 0;
}