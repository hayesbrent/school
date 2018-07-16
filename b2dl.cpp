// b2dl.cpp
// Brent Hayes, CISP 360
// 07-15-2018

#include <iostream>
using namespace std;

//page flags
bool flagA167, flagA290, flagA212, flagA173, flagA159;
//class flags
bool INTIMIDATOR, DIPLOMAT;

void A1() {
    cout << "You have reached A1\n";
}

void A167() {
    cout << "You have reached A167\n";
}

void A100() {
    cout << "You have reached A100\n";
}

void A232() {
    cout << "You have reached A232\n";
}

void A290() {
    cout << "You have reached A290\n";
}

void A13() {
    cout << "You have reached A13\n";
}

void A161() {
    cout << "You have reached A161\n";
}

void A212() {
    cout << "You have reached A212\n";
}

void A173() {
    cout << "You have reached A173\n";
}

void A159() {
    cout << "You have reached A159\n";
}
void endGame() {

    cout << "Current State of boolean variables:\n";


    cout << "Route taken:\n";
    if (flagA167 == 1) {
        cout << "A1-> A167-> A232-> ";
    } else {
        cout << "A1-> A100-> A232-> ";
    }
    if (flagA290 == 1) {
        cout << "A290-> A161\n";
    } else {
        cout << "A13-> ";
    }
    if (flagA212 == 1) {
        cout << "A212-> A161\n";
    }
    if (flagA173 == 1) {
        cout << "A173\n";
    }
    if (flagA159 == 1) {
        cout << "A159]\n";
    }
   

}


//general menu, accepts up to 3 strings returns 1 integer.
int generalMenu (/*string string1, string string2, string string3*/) {
    return 0;
}

//main function
int main () {
    
}