// Jomikael Ruiz
// hw4.cpp
// March 4th, 2023
// Purpose: driver program to test out stacks and queues to act as a
// basic calculator as well as a calculator to find the average of an array
// with an inputted size value for the windows

#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
using namespace std;

const char PLUS = '+';
const char MINUS = '-';
const string STOP = "#";

// fills the stack based on the values in the string
void fillStack(string, Stack *);
// pops all values of the stack and returns the addition of all values
int calculateStack(Stack *);
// takes user input for an equation and calls the above functions to complete
// usage of a calculator
void evalExpression(Stack *);
// file reads and fills an array based on the contents of a file
int * fillArray(string, int &);
// finds the average of the sliding windows in the array and queues them
// into the stack and eventually dequeues all the values and prints
void calcAverage(Queue *, int[], int, int);

int main(int argc, char * argv[]) {
    Stack * s = new Stack;
    Queue * q = new Queue;
    int * arr;
    int size = 0;
    evalExpression(s);
    arr = fillArray(argv[1], size);
    calcAverage(q, arr, size, stoi(argv[2]));
    delete s;
    delete q;
    return 0;
}

void fillStack(string input, Stack * s) {
    string temp = "";
    unsigned int counter = 1;
    temp += input[0];
        while(counter != input.length()) {
            if(input[counter] == PLUS) {
                s->push(stoi(temp));
                counter++;
                temp = "";
            } else if(input[counter] == MINUS) {
                s->push(stoi(temp));
                temp = "";
                temp += input[counter];
                counter++;
            } else {
                temp += input[counter];
                counter++;
            }
        }
    s->push(stoi(temp));    
}

int calculateStack(Stack * s) {
    int total = 0;
    while(!s->isEmpty()) {
        total += s->pop();
    }
    return total;
}

void evalExpression(Stack * s) {
    string input = "";
    cout << "****Showcasing the first task****" << endl;
    while(input != STOP) {
        cout << "\tType the expression (type # to quit): ";
        cin >> input;
        if(input != STOP) {
            fillStack(input, s);
            cout << "\tThe value of this expression is " << calculateStack(s);
            cout << endl << endl;
        }
    }
    cout << endl << endl;
}

int * fillArray(string fileName, int & arrSize) {
    string input;
    ifstream inFile;
    arrSize = 0;
    int * arr;
    int counter = 0;
    inFile.open(fileName);
    while(getline(inFile, input)) {
        arrSize++;
    }
    arr = new int[arrSize];
    inFile.clear();
    inFile.seekg(0);
    while(inFile >> arr[counter]) {
        inFile.get();
        counter++;
    }
    inFile.close();
    return arr;
}

void calcAverage(Queue * q, int arr[], int size, int N) {
    cout << "****Showcasing the second task****" << endl;
    int average;
    for(int i = 0; i <= size-N; i++) {
        average = 0;
        for(int j = i; j < N+i; j++) {
            average += arr[j];
        }
        average = average/N;
        q->enqueue(average);
    }
    cout << "\tThe averages in each window of size " << N <<" are ";
    cout << "[ ";
    while(!q->isEmpty()) {
        cout << q->dequeue() << " ";
    }
    cout << "]";
    cout << endl << endl;
}