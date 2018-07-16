// b2dl.cpp
// Brent Hayes, CISP 360
// 07-15-2018

#include <iostream>
#include <string>
using namespace std;
// Specification A2- No Globals
//general menu, accepts up to 3 strings returns 1 integer.
int generalMenu (string choice1, string choice2, string choice3) {
    string userString;
    int userChoice = 0; 
    while(true) {
        if(choice2.empty()) {
            cout << "Please type " << choice1 << " to turn to page " << choice1 << endl;


        } else if (choice3.empty()) {
            cout << "Please type either " << choice1 << " or " << choice2 << endl;

        } else {
            cout << "Please type one of the following options:\n" << choice1 << ", " << choice2 << ", " << choice3 << endl;

        }
        cin >> userString;
       if (userString.compare(choice1)==0) {
            userChoice = 1;
            break;
        }
        if (userString.compare(choice2)==0) {
            userChoice = 2;
            break;
        } 
        if (userString.compare(choice3)==0) {
            userChoice = 3;
            break;
        }  
    }
    return 0;
}

void A161() {
    cout << "You have reached A161\n";
}

void A173() {
    cout << "You have reached A173\n";
}
void A159() {
    cout << "You have reached A159\n";
}
void A212() {
    cout << "You have reached A212\n";
    A161();
}
void A13() {
    cout << "You have reached A13\n";
}
void A290() {
    cout << "You have reached A290\n";
    A161();
}
void A232() {
    cout << "You have reached A232\n";
}
void A167() {
    cout << "You have reached A167\n";
}
void A100() {
    cout << "You have reached A100\n";
}
bool A1() {
    bool flag167 = false;
    int userChoice = 0;
    string sA167 = "A167";
    string sA100 = "A100";
    string sNull;

    cout << "You have reached A1\n";
    userChoice = generalMenu(sA167, sA100, sNull);
    if(userChoice == 0) {
        flag167 = true;
    }
    return flag167;  
}
void endGame(bool flagDiplomat, bool flagA167, bool flagA290, bool flagA212, bool flagA173, bool flagA159) {
//Specification B1 - Booleans
    cout << "Current State of boolean variables:\n";
    cout << "Diplomat: " << flagDiplomat << endl;
    cout << "A167 Flag: " << flagA167 << endl;
    cout << "A290 Flag: " << flagA290 << endl;
    cout << "A212 Flag: " << flagA212 << endl;
    cout << "A173 Flag: " << flagA173 << endl;
    cout << "A159 Flag: " << flagA159 << endl;

// Specification B2 - Path
    cout << "\nRoute taken:\n";
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

//main function
int main () {
    char userChoice;
    bool contFlag = true;
    while (contFlag==true) {

        //page flags
        bool flagA167 = false;
        bool flagA290 = false;
        bool flagA212 = false;
        bool flagA173 = false;
        bool flagA159 = false;
        //class flags
        bool flagDiplomat = false;

        //begin story

        flagA167 = A1();
        if (flagA167==true) {
            flagDiplomat = true;
        }


        endGame(flagDiplomat, flagA167, flagA290, flagA212, flagA173, flagA159);
// Specification A3 - Game Loop
        while(true) {
            cout << "Would you like to return to the beginning of your adventure? (Y/N)" << endl;
            cin >> userChoice;
            if (tolower(userChoice) == 'y'){
                cout << endl;
                break;
                
            } else if (tolower(userChoice) == 'n') {
                    contFlag = false;
                    break; 
            } else {
                cout << "Your input was not valid. Please type Y for yes, N for no.\n";
            }

        }
    }

    
}