// Jomikael Ruiz
// January 22, 2023
// hw1.cpp
// Purpose: File Read Covid Data into a Dynamically Allocated Array
// and display basic information based on the information
// read and on user input

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

const char COMMA = ',';
const char YES = 'y';
const char NO = 'n';
const int WIDTH = 25;
const int DECIMALROUNDING = 2;
const int MIN_DEATHS = 100;

struct State {
    string date;
    string name;
    string stateCode;
    int numCases;
    int numDeaths;
    double deathRate;
};

// displays menu options and returns user input
int displayMenu();
// asks user for file name then fills dynamic array
State * fileRead(bool &fileSuccess, State dynamicArray[], int &arraySize);
// evaluates user input using a switch statement
char evaluateInput(int userInput, int counter, const State dataArray[]);
// prints the stats of a specific state
void printData(const State data);
// linear search to find and return state with the most cases in the array
State findMostCases(const State dataArray[], int counter);
// linear search to find and return state with the most deaths in the array
State findMostDeaths(const State dataArray[], int counter);
// goes through array and sums all cases and returns total
int sumCases(const State dataArray[], int counter);
// goes through array and sums all deaths and returns total
int sumDeaths(const State dataArray[], int counter);
// takes two int variables and divides them to return average
int takeAverage(int sum, int totalNumber);
// calculates the death average by dividing the deaths by numCases
double calculateDeathRate(const State data);
// finds the average deathrate among all the states
double averageDeathRate(const State dataArray[], int counter);
// returns the State with the highest deathrate with more than 100 deaths
State findHighestDeathRate(const State dataArray[], int counter);

int main(int argc, char *argv[])
{
    State * arrayPtr = 0;
    char userChoice = YES;
    int counter = 0;
    int menuSelection = -1;
    bool fileSuccess = false;
    arrayPtr = fileRead(fileSuccess, arrayPtr, counter);
    if(!fileSuccess) {
        cout << "File Read Error. Press enter to exit";
        cin.get();
        return 0;
    }
    while(userChoice == YES) {
        menuSelection = displayMenu();
        userChoice = evaluateInput(menuSelection, counter, arrayPtr);
    }
    delete [] arrayPtr;
    cout << endl << endl;
    return 0;
}

int displayMenu()
{
    int userInput = -1;
    cout << endl << endl;
    cout << "************Menu************" << endl;
    cout << "1:\tDisplay the COVID info of all states" << endl;
    cout << "2:\tDisplay the COVID info of the state that has the most cases" 
         << endl;
    cout << "3:\tDisplay the COVID info of the state that has the most deaths" 
         << endl;
    cout << "4:\tDisplay the statistics of all states" << endl;
    cout << "5:\tExit the Program" << endl;
    cout << "Enter your choice: ";
    while(userInput < 1 || userInput > 6)
        cin >> userInput;
    cout << endl;
    return userInput;
}

State * fileRead(bool &fileSuccess, State dynamicArray[], int &arraySize)
{
    string fileName, input;
    char testChar;
    ifstream inFile;
    int counter = 0;
    cout << "Input filename: ";
    cin >> fileName;
    inFile.open(fileName);
    if(inFile.fail()) {
        fileSuccess = false;
    } else {
        while(getline(inFile, input)) {
            arraySize++;
        }
        dynamicArray = new State[arraySize];
        inFile.clear();
        inFile.seekg(0);
        while(getline(inFile, dynamicArray[counter].date, COMMA)) {
            getline(inFile, dynamicArray[counter].name, COMMA);
            getline(inFile, dynamicArray[counter].stateCode, COMMA);
            inFile >> dynamicArray[counter].numCases;
            inFile >> testChar;
            inFile >> dynamicArray[counter].numDeaths;
            inFile >> testChar;
            dynamicArray[counter].deathRate = 
                calculateDeathRate(dynamicArray[counter]);
            counter++;
        }
        inFile.close();
        fileSuccess = true;
    }
    return dynamicArray;
}

void printData(const State data)
{
    cout << setw(WIDTH) << right << data.name;
    cout << setw(WIDTH) << right << data.numCases;
    cout << setw(WIDTH) << right << data.numDeaths;
}

State findMostCases(const State dataArray[], int counter)
{
    State mostCases = dataArray[0];
    for(int i = 1; i < counter; i++) {
        if(dataArray[i].numCases > mostCases.numCases) {
            mostCases = dataArray[i];
        }
    }
    return mostCases;
}

State findMostDeaths(const State dataArray[], int counter)
{
    State mostCases = dataArray[0];
    for(int i = 1; i < counter; i++) {
        if(dataArray[i].numDeaths > mostCases.numDeaths) {
            mostCases = dataArray[i];
        }
    }
    return mostCases;
}

int sumCases(const State dataArray[], int counter)
{
    int sum = 0;
    for(int i = 0; i < counter; i++) {
        sum += dataArray[i].numCases;
    }
    return sum;
}

int sumDeaths(const State dataArray[], int counter)
{
    int sum = 0;
    for(int i = 0; i < counter; i++) {
        sum += dataArray[i].numDeaths;
    }
    return sum;
}

int takeAverage(int sum, int totalNumber)
{
    return sum / totalNumber;
}

double calculateDeathRate(const State data)
{
    double castedCases = static_cast<double>(data.numCases);
    return (data.numDeaths / castedCases) * 100;
}

double averageDeathRate(const State dataArray[], int counter)
{
    double totalDeaths = 0.0;
    double totalCases = 0.0;
    for(int i = 0; i < counter; i++) {
        totalDeaths += dataArray[i].numDeaths;
        totalCases += dataArray[i].numCases;
    }
    return (totalDeaths / totalCases)*100;
}

State findHighestDeathRate(const State dataArray[], int counter)
{
    State selectedState = dataArray[0];
    for(int i = 1; i < counter; i++) {
        if(dataArray[i].numDeaths >= MIN_DEATHS
            && dataArray[i].deathRate >= selectedState.deathRate) {
                selectedState = dataArray[i];
            }
    }
    return selectedState;
}

char evaluateInput(int userInput, int counter, const State dataArray[])
{
    State selectedState;
    int sum = 0;
    int average = 0;
    cout << endl;
    switch(userInput) {
        case 1:
            cout << endl;
            cout << setw(WIDTH) << right << "**State**"; 
            cout << setw(WIDTH) << right << "**Cases**"; 
            cout << setw(WIDTH) << right << "**Deaths**";
            cout << endl;
            for(int i = 0; i < counter; i++) {
                printData(dataArray[i]);
                cout << endl;
            }
            return YES;
        case 2:
            selectedState = findMostCases(dataArray, counter); 
            cout << selectedState.name << " has the most cases: " 
                 << selectedState.numCases;
            return YES;
        case 3:
            selectedState = findMostDeaths(dataArray, counter);
            cout << selectedState.name << " has the most deaths: " 
                 << selectedState.numDeaths;
            return YES;
        case 4:
            sum = sumCases(dataArray, counter);
            cout << "(a) There are " << sum << " cases in total, ";
            average = takeAverage(sum, counter);
            cout << average << " on average.";
            cout << endl;
            sum = sumDeaths(dataArray, counter);
            cout << "(b) There are " << sum << " deaths in total, ";
            average = takeAverage(sum, counter);
            cout << average << " on average.";
            cout << endl;
            cout << setprecision(DECIMALROUNDING) << fixed
                 << "(c) The average death rate for all states is " 
                 << averageDeathRate(dataArray, counter) << "%" << endl;
            selectedState = findHighestDeathRate(dataArray, counter);
            cout << setprecision(DECIMALROUNDING) << fixed 
                 << "(d) Among all states that have more than 100 deaths, "
                 << selectedState.name << " has the highest death rate of "
                 << selectedState.deathRate << "%" << endl << endl;
            return YES;
        case 5:
            return NO;
        default: 
            cout << "An Error has occured. Please retry" << endl;
            return YES;
    }
}