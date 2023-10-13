// Bryan Kim
// CPSC 2600
// HW2.cpp
// This code will have two user inputted subsets (A and B) of U = {0 through 9} and 
// find A union B, A intersect B, and A difference B

#include <iostream>

using namespace std;

//desc: creates a subset of the universal set
//pre : inputs an indicator char to indicate which set
//post: returns a set as a bit string
int create_subset(char indicator);

//desc: prints the desired set in binary from left to right
//pre : parameter of a set represented as a bitstring
//post: none
void print_bitstring(int set);

int main() {
    cout << endl << endl << "Welcome to my HW2." << endl
         << "Given subsets A and B of a universal set with 10 elements {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, " 
         << endl << "we will use bit strings to find A U B, A ∩ B, and A – B." << endl 
         << "Users will be asked to populate each set." << endl
         << "For example, if the user enters 1, 2, 6, the bit string will display from left to right and display 0110001000."
         << endl << endl;

    int A = create_subset('A');
    cout << endl;
    int B = create_subset('B');

    int intersect = A & B;
    int uni = A | B;
    int diff = A & (~B);

    cout << endl << endl << "Set A:  ";
    print_bitstring(A);
    cout << "Set B:  ";
    print_bitstring(B);
    cout << endl << endl << "Intersection:  ";
    print_bitstring(intersect);
    cout << "Union:  ";
    print_bitstring(uni);
    cout << "Difference:  ";
    print_bitstring(diff);

    return 0;
}

int create_subset(char indicator) {
    int set = 0;              // a variable to save the bit vector of set A
    int userInput = 0;             // a variable to save the user input
    while (userInput >= 0) {
        cout << "Please input a number for set " << indicator << " (enter -1 to stop): ";
        cin >> userInput;
        if (userInput <= 9) {
            set |= (1 << userInput);  // | is the bitwise-or; << is the left shift operator  
        } else {
            cout << endl << "Valid values are 0 through 9." << endl;
        }
    }
    return set;
}

void print_bitstring(int set) {
    for (int i = 0; i < 10; i++) {
        cout << ((set >> i) & 1);
    }
    cout << endl;
}