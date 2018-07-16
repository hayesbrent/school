// b2dl.cpp
// Brent Hayes, CISP 360
// 07-15-2018

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
// Specification A2- No Globals

//Specification B5 - Function Prototype
int generalMenu(string, string, string);
void A161();
void A173();
void A159();
void A212();
int A13(bool);
void A290();
bool A232();
void A167();
void A100();
bool A1();
void endGame(bool, bool, bool, bool, bool, bool);

//main function
int main () {
    char userChoice;
    
    bool contFlag = true;
    while (contFlag==true) {
        int userA13choice = 0;
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
            A167();
        } else {
            A100();
        }
        flagA290 = A232();
        if (flagA290 == true) {
            A290();
        } else {
            userA13choice = A13(flagDiplomat);
        }
        if (userA13choice!=0) {
            if (userA13choice == 3) {
                flagA212 = true;
                A212();
            } else if (userA13choice == 1) {
                flagA173 = true;
                A173();
            } else {
                flagA159 = true;
                A159();
            }
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
// Specification B3 - General Menu
int generalMenu (string choice1, string choice2, string choice3) {
    string userString;
    int userChoice = 0; 
    while(true) {
// Specification C2 - Simple Menu
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
        cout << "Invalid selection, please try again" << endl;  
    }
    return userChoice;
}
// Specification C1 - Individual Functions
void A161() {
    cout << "You have reached A161\n";
}

void A173() {
    cout << "As they gnash away, Mal and Haiken discuss the Captain\'s recent raid on the town of Greenflower. \"Honestly,\" says Haiken, \"those wretched Brightlanders are so easily slaughtered, sometimes I almost feel bad for them.\" Mal laughs at this hilarious joke. \"Ha! That\'s a good one, Captain. But tell me, what of your primary objective\?\" \"I am pleased to report success, my lord.\" \"You have brought me a virgin\?\" \"She languishes in your dungeon even now - lovely, virtu- ous and ripe for sacrifice.\" \"Excellent. My skywatchers predict a full moon in three nights time - perfect conditions for the ceremony.\" Footsteps sound at the dining hall entrance, and a goblin messen- ger, whom you recognize as Peedy, enters wearing a feathered hat and carrying a scroll. Mal\'s gaze slides to him. \"What is it?\" Peedy clears his throat. \"Apologies for the interruption, Your Atrocious- ness. I bring you word from Vorganis Castle.\" \"Oh?\" Mal\'s tone is so instantly cold that the very temperature of the room seems to drop. \"Er... yes, my lord. Lord Nefarian accepts your kind invitation to attend the Stygias Ceremony, and intends to arrive tomorrow morn- ing.\" Mal\'s eyes narrow. You know he does not care for his cousin Nefarian, not least because the man is next in line to the throne. Ne- farian\'s presence at the ceremony, however, must be tolerated, for he is a powerful lord in his own right, with many allies amongst Noc- turnia\'s nobility - a fact which Mal does not enjoy being reminded of. \"Why bring me such news at lunch\?\" he growls. \"It has put a foul taste in my mouth and sullied my food.\" He drums his fingers on the dragon bone armrest, and fiery sparks flare at his fingertips. Peedy quails, for he knows that Mal is prone to taking out his anger on the bearers of bad news. It would be a shame, however (and a staffing issue), to lose a competent messenger to a moment of ill temper over something that really isn\'t his fault.\n1. Do you attempt to intercede on Peedy\'s behalf\? \n2. Or abandon him to his miserable fate\?" << endl;
}
void A159() {
    cout << "You have reached A159\n";
}
void A212() {
    
    string sA161 = "A161";
    string sNull;
    cout << "You clear your throat very slightly, and Haiken glances up at you. As you move your hand back from his plate, you let your finger rest momentarily on the appropriate rat-head-eating fork. Haiken under- stands, and gives you a relieved look. Mal is too busy shoveling slug meat into his gullet to notice the exchange, so HAIKEN IS GRATE- FUL. You add some rat heads to Mal\'s plate and move back from the table to take a place in waiting. \n1. Nicely done, Mr Artanon. (turn to A161)" << endl;
    generalMenu(sA161, sNull, sNull);
    A161();
}
int A13(bool flagDiplomat) {
    cout << "You have reached A13\n";
    int userChoice = 0;
    string sA212 = "A212";
    string sA173 = "A173";
    string sA159 = "A159";
    string sNull;
// Specification B4 - Valid choices only
    if (flagDiplomat == true) {
        generalMenu(sA212, sNull, sNull);
        userChoice = 3;
    } else {
        userChoice = generalMenu(sA173, sA159, sNull);
    }
    return userChoice;
}
void A290() {
    string sA161 = "A161";
    string sNull;
    cout << "You have reached A290\n";
    generalMenu(sA161, sNull, sNull);
    A161();
}
bool A232() {
    
    bool flag290 = false;
    int userChoice = 0;
    string sA290 = "A290";
    string sA13 = "A13";
    string sNull;

    cout << "You have reached A232\n";
    userChoice = generalMenu(sA290, sA13, sNull);
    if(userChoice == 1) {
        flag290 = true;
    }
    return flag290;  
}
void A167() {
    string sA232 = "A232";
    string sNull;
    cout << "You have reached A167\n";
    generalMenu(sA232, sNull, sNull);
}
void A100() {
    string sA232 = "A232";
    string sNull;
    cout << "You have reached A100\n";
    generalMenu(sA232, sNull, sNull);
}
bool A1() {
    bool flag167 = false;
    int userChoice = 0;
    string sA167 = "A167";
    string sA100 = "A100";
    string sNull;

    cout << "You have reached A1\n";
    userChoice = generalMenu(sA167, sA100, sNull);
    if(userChoice == 1) {
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
        cout << "A159\n";
    }
   

}


