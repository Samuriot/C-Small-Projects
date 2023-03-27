// Jomikael Ruiz
// FancyList.h
// Febuary 16, 2023
// Purpose: Define the FancyList Class for implementation

#ifndef FANCYLIST_H
#define FANCYLIST_H

class FancyList {
    private:
        // linked list node definition
        struct ListNode {
            int data;
            ListNode * next;
            ListNode * previous;
        };
        // head of the linked list
        ListNode * head;
    public:
        // constructor
        FancyList();
        // destructor
        ~FancyList();
        // prints the list
        void printList() const;
        // asks for user input to append to list
        void inputList();
        // takes a parameter and removes the n-th node from the end of list
        void removeNode(int);
        // takes a parameter and adds it to the end of the list
        void appendNode(int);
        // reverses the entire linked list
        void reverseList();
};

#endif