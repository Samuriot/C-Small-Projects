#ifndef INTEGERSET_H
#define INTEGERSET_H
const int MAXSIZE = 101;
const int MIN = 0;
const int MAX = 100;

class IntegerSet {
    public:
        // constructor with no parameters
        IntegerSet();
        // constructor that takes and int array and size int to fill arraySet
        IntegerSet(int[], int);
        // dynamically allocates a new IntegerSet Object and compares the
        // current object with the taken in IntegerSet Parameter to find
        // the union of the arraySets
        void unionOfSets(IntegerSet);
        // dynamically allocates a new IntegerSet Object and compares the
        // current object with the taken in IntegerSet Parameter to see
        // which values are the same between the two
        void intersectionOfSets(IntegerSet);
        // takes in integer input to insert an element into arraySet
        void insertElement(int);
        // takes in integer input to delete an element from arraySet
        void deleteElement(int);
        // prints out the which elements are stored in arraySet
        void printSet();
        // returns a bool and takes in an IntegerSet to see if the two sets
        // are equal
        bool isEqualTo(IntegerSet);
        // sets all the elements of arraySet to 0
        void emptySet();
        // asks user for userInput to place into the arraySet
        void inputSet();
        // takes in an integer to check if the variable is between 0 to 100
        bool validEntry(int);
    private:
        int arraySet[MAXSIZE];
        int size;
};

#endif