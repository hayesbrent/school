// madlibs.cpp
// Brent Hayes, CISP 360
// 07-29-2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <string>
using namespace std;

//prototype functions

int simpleMenu(int);
string randomWord();
float randomFloat();
string wordMenu();
string verb5Validation();
string noun1Validation();
string verb3Smallest();
string phraseValidation(int);
string basicGet(int);
int integerGet();

int main() {
    int firstIteration = 0;
    int userQuit = 0;
    string temp[20];
    float tempUse;
    int integerTemp =0;

// Specification A1 - Main Game Loop
    do{
        userQuit = simpleMenu(firstIteration);
        firstIteration++;
        if (userQuit!=0) {
                break;
        }
//
//0 verb, 1 noun, 2 adjective,3 plural/singular noun, 4 plural noun,  5time span, 6 integer
//madlibs start
temp[0] = basicGet(5);
temp[1] = noun1Validation();
temp[2] = basicGet(0);
temp[3] = randomWord();
temp[4] = basicGet(3);
temp[5] = basicGet(1);
temp[6] = verb3Smallest();
temp[7] = phraseValidation(1);
temp[8] = basicGet(1);
temp[9] = basicGet(1);
temp[10] = phraseValidation(0);
temp[11] = basicGet(2);
temp[12] = basicGet(0);
temp[13] = wordMenu();
temp[14] = basicGet(4);
temp[15] = basicGet(2);
temp[16] = basicGet(4);
temp[17] = phraseValidation(3);
integerTemp = integerGet();
temp[18] = verb5Validation();
tempUse = randomFloat();


cout << "Every " << temp[0] << ", I wake up and get off my " << temp[1] << ". I don't always have time to " << temp[2] << " a shower, but I always make sure to " << temp[3] 
    << " my hair. Once that's done I get some " << temp[4] << ", and then it's off to my first " << temp[5] << ". I often get caught " << temp[6] << " in class. No one likes it when the " << temp[7]
    << " gives a surprise " << temp[8] << ". My second class is " << temp[9] << " Theory. Dr. " << temp[10] << " is incredibly " << temp[11] << ", but I never " << temp[12] << " her because of her thick "
    << temp[13] << ". Her " << temp[14] << ", however, are really " << temp[15] << ". After lunch, I have no more " << temp[16] << " and I'm free to " << temp[17] << " my friends. This is right around "
    << integerTemp << "O' clock. Before I go to bed I " << temp[18] << " a little bit, in my room, " << fixed << setprecision(1) << tempUse << endl;

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

// Specification C3 - Word Menu
string wordMenu() {
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
        cout << "Please enter a verb ending in -ing:" << endl;
        cin >> userEntry1;
        cout << "Please enter another verb ending in -ing:" << endl;
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
        } else if (variationTest == 1) {
            cout << "Please enter a 2 word occupation" << endl;
        } else {
            cout << "Please enter a verb with a preposition:" << endl;
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

//0 verb, 1 noun, 2 adjective,3 plural/singular noun, 4 plural noun,  5time span, 6 integer
string basicGet(int variation) {
    cin.ignore();
    string userTempInput;

    if (variation == 0) {
        cout << "Please enter a verb:" << endl;
    } else if (variation == 1) {
        cout << "Please enter a noun:" << endl;
    } else if (variation == 2) {
        cout << "Please enter an adjective:" << endl;
    } else if (variation == 3) {
        cout << "Please enter either a singular or a plural noun:" << endl;
    } else if (variation == 4) {
        cout << "Please enter a plural noun:" << endl;
    } else if (variation == 5) {
        cout << "Please enter a time span:" << endl;
    } 
    cin >> userTempInput;
    for (unsigned int i = 0; i < userTempInput.length(); i++) { 
        userTempInput[i] = tolower(userTempInput[i]);
    }
    return userTempInput;
    
}
int integerGet() {
    cin.ignore();
    int userTempInt = 0;
    while (true) {
        cout << "Please enter a single integer 1-12" << endl;
        cin >> userTempInt;
        if ((userTempInt>=1) && (userTempInt <=12)) {
            return userTempInt;
        }
        cout << "Invalid selection please try again." << endl;
    }
}