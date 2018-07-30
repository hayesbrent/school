// madlibs.cpp
// Brent Hayes, CISP 360
// 07-29-2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

//prototype functions

int simpleMenu(int);
string randomWord();
float randomFloat();
string simpleMenu();
string verb5Validation();
string noun1Validation();
string verb3Smallest();
string phraseValidation(int);
string basicGet(int);

int main() {
    int firstIteration = 0;
    int userQuit = 0;
    string temp;

// Specification A1 - Main Game Loop
    do{
        userQuit = simpleMenu(firstIteration);
        firstIteration++;
        if (userQuit!=0) {
                break;
        }

//madlibs start        
temp =phraseValidation(0);
cout << temp;
//madlibs end
    } while(true);
}





int simpleMenu(int firstIteration) { 
    int userChoice = 0;  
    char userLoopChoice;  
    if(firstIteration==0) {
        cout << "Welcome to madlibs.cpp. This program accepts user input for a variety of words and places them within key locations of a prewritten story." << endl;
        while(true){
// Specification B4 - Simple Menu
            cout << "Main menu\n1 - Explain Mad Libs\n2 - Start Mad Libs\n3 - Quit" << endl;
            cin >> userChoice;
            if (userChoice==1) {
                cout << "Mad Libs is a phrasal template word game where you, the player, are prompted for a list of words to substitute for blanks in a story. Once the list is completed the blanks are filled in and the story is sent to the player to read aloud." << endl;
            } else if (userChoice==2) {
                return 0;
            } else if (userChoice==3) {
                return 1;
            } else {
                cout << "Invalid Choice, please try again." << endl;
            }
        }
    } else {
         while(true){
            cout << "Would you like to play Mad Libs again? (Y/N)" << endl;
            cin >> userLoopChoice;
            userLoopChoice = tolower(userLoopChoice);
            if(userLoopChoice == 'y') {
                return 0;

            } else if(userLoopChoice == 'n') {
                return 1;
            } else {
                cout << "Invalid choice, please enter Y for Yes, N for No." << endl;
            }
        }
    }
}

// Specification C1 - Random Word
string randomWord() {
    int temp = 0;
    string rando[3] = {"comb", "paint", "remove"};
    unsigned seed;
    seed = time(0);
    srand(seed);
    temp = rand()%3;
    return rando[temp];

}

// Specification C2 - Random Float
float randomFloat() {
    unsigned seed;
    seed = time(0);
    srand(seed);
    float temp = ((float)rand()/(float)RAND_MAX) *15.0;
    if(temp <= 0.044) {
        temp = 0.0;
    }
    return temp;
}

// Specification B4 - Simple Menu
string simpleMenu() {
    string userMenuChoice[3] = {"breakfast", "fishes", "copper coins"};
    string userTempInput;
    cin.ignore();
    while(true) {
        cout << "Please choose between " << userMenuChoice[0] << ", " <<userMenuChoice[2] << ", " << userMenuChoice[1] << endl;
        
        
        getline(cin,userTempInput);
        for( unsigned int i = 0; i < userTempInput.length(); i++) {
            userTempInput[i] = tolower(userTempInput[i]);
        }
        for (int i = 0; i < 3; i++) {
            if (userTempInput.compare(userMenuChoice[i])==0) {
                return userTempInput;
            }
        }
        cout << "Invalid Input, please try again." << endl;
    }

}

// Specification B3 - Range Validation
string verb5Validation() {
    string userTempInput;
    cin.ignore();
    while(true) {
        cout << "Please enter a verb that is between 4-20 characters in length." << endl;
        cin >> userTempInput;
        if ((userTempInput.length() >4)&&(userTempInput.length()<20)) {
            for (unsigned int i = 0; i < userTempInput.length(); i++) { 
                userTempInput[i] = tolower(userTempInput[i]);
            }
            return userTempInput;
        } else {
            cout << "Invalid Input, please try again." << endl;
        }
    }
}

// Specification B2 - Maximum Word Size Validation
string noun1Validation() {
    string userTempInput;
    cin.ignore();
    while(true) {
        cout << "Please enter a noun that is less than 16 characters in length." << endl;
         cin >> userTempInput;
        if (userTempInput.length() <16) {
            for (unsigned int i = 0; i < userTempInput.length(); i++) { 
                userTempInput[i] = tolower(userTempInput[i]);
            }
            return userTempInput;
        } else {
            cout << "Invalid Input, please try again." << endl;
        }
    }
}

// Specification A3 - Smallest Word
string verb3Smallest() {
    string userTempInput;
    cin.ignore();
    string userEntry1;
    string userEntry2;
    while(true) {
        cout << "Please enter a verb:" << endl;
        cin >> userEntry1;
        cout << "Please enter another verb:" << endl;
        cin >> userEntry2;
        if (userEntry1.length() < userEntry2.length()) {
            for (unsigned int i = 0; i < userEntry1.length(); i++) { 
                userEntry1[i] = tolower(userEntry1[i]);
            }
            return userEntry1;
        } else {
             for (unsigned int i = 0; i < userEntry2.length(); i++) { 
                userEntry2[i] = tolower(userEntry2[i]);
            }
            return userEntry2;
        }
    }
}

// Specification B1 - Phrase Validation
string phraseValidation(int variationTest) {
    cin.ignore();
    string userTempInput;
    char c;
    while(true) {
        if (variationTest == 0) {
            cout << "Please enter a famous person (First Last)" << endl;
        } else {
            cout << "Please enter a 2 word occupation" << endl;
        }
        getline(cin,userTempInput);
        for (unsigned int i = 0; i < userTempInput.length(); i++) {
            c = userTempInput[i];
            if (isspace(c)) {
                return userTempInput;
            }
        }
        cout << "Invalid Input, please try again." << endl;
    }

}

string basicGet(int variation) {
    cin.ignore();
    string userTempInput;

    if (variation == 0) {
        cout << "Please enter a verb:" << endl;
    } else if (variation == 1) {
        cout << "Please enter a noun:" << endl;
    } else if (variation == 2) {
        cout << "Please enter an adjective:" << endl;
    }
    for (unsigned int i = 0; i < userTempInput.length(); i++) { 
        userTempInput[i] = tolower(userTempInput[i]);
    }
    return userTempInput;
    
}