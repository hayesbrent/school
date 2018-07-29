// madlibs.cpp
// Brent Hayes, CISP 360
// 07-29-2018

#include <iostream>
using namespace std;



int main() {
    int firstIteration = 0;
    int userQuit = 0;
    int userChoice = 0;
    char userLoopChoice;

// Specification A1 - Main Game Loop
    do{
        if (firstIteration == 0) {
            cout << "Welcome to madlibs.cpp. This program accepts user input for a variety of words and places them within key locations of a prewritten story." << endl;
            while(true){
// Specification B4 - Simple Menu
                cout << "Main menu\n1 - Explain Mad Libs\n2 - Start Mad Libs\n3 - Quit." << endl;
                cin >> userChoice;
                if (userChoice==1) {
                    cout << "mad lips explanation" << endl;
                } else if (userChoice==2) {
                    break;
                } else if (userChoice==3) {
                    userQuit++;
                    break;
                } else {
                    cout << "Invalid Choice, please try again." << endl;
                }
            }
            if (userQuit!=0) {
                break;
            }
        }
//madlibs start        


//madlibs end
        while(true){
            cout << "Would you like to play Mad Libs again? (Y/N)" << endl;
            cin >> userLoopChoice;
            userLoopChoice = tolower(userLoopChoice);
            if(userLoopChoice == 'y') {
                break;

            } else if(userLoopChoice == 'n') {
                userQuit++;
                break;
            } else {
                cout << "Invalid choice, please enter Y for Yes, N for No." << endl;
            }
        }
        if (userQuit!=0) {
                break;
        }

    }while(true);
}