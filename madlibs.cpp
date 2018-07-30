// madlibs.cpp
// Brent Hayes, CISP 360
// 07-29-2018

#include <iostream>
using namespace std;

//prototype functions

int simpleMenu(int);

int main() {
    int firstIteration = 0;
    int userQuit = 0;

// Specification A1 - Main Game Loop
    do{
        userQuit = simpleMenu(firstIteration);
        firstIteration++;
        if (userQuit!=0) {
                break;
        }

//madlibs start        


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