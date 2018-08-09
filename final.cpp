// final.cpp
// Brent Hayes, CISP 360
// 08-07-2018


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct monsterInfo {
    string name = "";
    int health;
    int strength;
};
struct playerInfo {
    string name;
    int health = 200;
    int strength = 15;

};

//void monsterPopulate(monsterInfo *monster);
int monsterSelect();
void floor1(playerInfo &, int [10]);
void floor2a(playerInfo &, int [10]);
void floor2b(playerInfo &, int [10]);
void floor2c(playerInfo &, int [10]);
void floor3a(playerInfo &, int [10]);
void floor3b(playerInfo &, int [10]);
void floor3c(playerInfo &, int [10]);
void floor3(playerInfo &, int [10]);
int playerDirection(int, int, int, int, playerInfo &);
void playerInputValidation(playerInfo &, int);

void introduction(playerInfo &);



int main() {
    playerInfo player;
// Specification B2 - Array of structs
   monsterInfo monster[5] = {
        {"Spider", 50, 20},
        {"Cyclops", 80, 30},
        {"Orc", 70, 15},
        {"Goblin", 20, 10},
// Specification B1 - add more monsters
        {"Rock Lobster", 100, 10}

    };
    int roomstate[8] = {0,0,0,0,0,0,0,0};
    

    introduction(player);
    floor3(player,roomstate);

    cout << "Amazing job," << player.name << ", you are a hero among heroes! You have made it out of the dungeon!!!" << endl;
   
    

}

/*
void monsterPopulate(struct monsterInfo * monster) {
    cout << monster[3].name;
}
*/
// void combat(struct monsterInfo * monster, ) {

int monsterSelect() {
    int monsterRandom;
    unsigned seed;
    seed = time(0);
    srand(seed);
   
    monsterRandom = rand()%5;

    switch(monsterRandom) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        default:
            break;
    }
    return 0;
}

void playerInputValidation (playerInfo &player, int set) {
    int intChoice =0;
    string invalid = "Invalid selection, please try again.";
    //room3
    if(set ==30) {
        while(true) {
            cin >> intChoice;
            if(intChoice==1) {
                cout << "Haha well then " << player.name << ", prepare to join us in an eternal sleep as this dungeon consumes you!" << endl;
                return;

            } else if (intChoice ==2) {
                cout << "I can see your family crest from here you fool, " << player.name << " of the royal family. Your King has doomed our lost souls to this dungeon, and now we shall repay the favor in kind." << endl;             
                return;

            } else {
                cout << invalid << endl;
            }
        }
    }
}


void introduction(playerInfo &player) {
    cout << "Welcome to final.cpp. This program consists of a short text based adventure dungeon crawler. You have fallen down an abandoned mining shaft and will have to fight your way to the top." << endl;
    cout << "Brave (but unfortunate) adventurer, what is your name\?" << endl;
// Specification C2
    getline(cin,player.name);
    cout << "Well then, " << player.name << ", steel your blade against the darkness and forge on ahead!" << endl;
}




void floor3(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[0] == 0) {
    cout << "You peer into the darkness of the room, and suddenly a specter appears before you. His wide smile sends chills down to your soul. \"What is your name adventurer\?\"" << endl;
    cout << "1 - State your name proudly\n2 - Keep wary of the ghastly ghoul and say nothing" << endl;
    playerInputValidation(player, 30);
     roomstate[0] = 1;
    }
    playerMovement = playerDirection(1,0,1,1,player);
    if (playerMovement == 1) {
        floor3b(player, roomstate);
    } else if (playerMovement == 3) {
        floor3c(player, roomstate);
    } else if (playerMovement == 4) {
        floor3a(player, roomstate);
    }
}
void floor3a(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[1] == 0) {
        roomstate[1] = 1;
    }
    playerMovement = playerDirection(1,1,1,0,player);
    if (playerMovement == 1) {
        floor2a(player, roomstate);

    } else if (playerMovement == 2) {
        floor3(player, roomstate);
    } else if (playerMovement == 3) {
        floor3b(player, roomstate);
    }
}
void floor3b(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[2] == 0) {
        roomstate[2] = 1;
    }
    playerMovement = playerDirection(1,1,1,1,player);

     if (playerMovement == 1) {
        floor2b(player, roomstate);

    } else if (playerMovement == 2) {
        floor3(player, roomstate);
    } else if (playerMovement == 3) {
        floor3c(player, roomstate);
    } else if (playerMovement == 4) {
        floor3a(player, roomstate);
    }
}
void floor3c(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[3] == 0) {
        roomstate[3] = 1;
    }
    playerMovement = playerDirection(1,1,0,1,player);
     if (playerMovement == 1) {
        floor2c(player, roomstate);

    } else if (playerMovement == 2) {
        floor3(player, roomstate);
    } else if (playerMovement == 4) {
        floor3b(player, roomstate);
    }
}
void floor2a(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[4] == 0) {
        roomstate[4] = 1;
    }
    playerMovement = playerDirection(1,1,1,0,player);
     if (playerMovement == 1) {
        floor1(player, roomstate);
    } else if (playerMovement == 2) {
        floor3a(player, roomstate);
    } else if (playerMovement == 3) {
        floor2b(player, roomstate);
    } 
}
void floor2b(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[5] == 0) {
        roomstate[5] = 1;
    }
    playerMovement = playerDirection(1,1,1,1,player);
     if (playerMovement == 1) {
        floor1(player, roomstate);

    } else if (playerMovement == 2) {
        floor3b(player, roomstate);
    } else if (playerMovement == 3) {
        floor2c(player, roomstate);
    } else if (playerMovement == 4) {
        floor2a(player, roomstate);
    }
}

// Specification B3 - Add more rooms
void floor2c(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[6] == 0) {
        roomstate[6] = 1;
    }
    playerMovement = playerDirection(1,1,0,1,player);
     if (playerMovement == 1) {
        floor1(player, roomstate);

    } else if (playerMovement == 2) {
        floor3c(player, roomstate);
    } else if (playerMovement == 4) {
        floor2b(player, roomstate);
    }
}

// Specification C1
void floor1(playerInfo &player, int roomstate[8]) {
    int playerMovement = 0;
    if ( roomstate[7] == 0) {
    roomstate[7] = 1;
    }
    playerMovement = playerDirection(1,1,1,1,player);
     if (playerMovement == 1) {
        return;

    } else if (playerMovement == 2) {
        floor2b(player, roomstate);
    } else if (playerMovement == 3) {
        floor2c(player, roomstate);
    } else if (playerMovement == 4) {
        floor2a(player, roomstate);
    }

}

int playerDirection(int north, int south, int east, int west, playerInfo &player) {
    char playerChoice;
    int directionChosen = 0;
    
    while(true) {
        cout << "Where would you like to move, " << player.name << endl;
        if(north!=0) {
            cout << "N - North" << endl;
        }
        if(south!=0) {
            cout << "S - South" << endl;
            
        }
        if(east!=0) {
            cout << "E - East" << endl;
            
        }
        if(west!=0) {
            cout << "W - West" << endl;           
        }
        cin >> playerChoice;
        if (tolower(playerChoice)=='n') {
            directionChosen = 1;
            break;
        } else if (tolower(playerChoice)=='s') {
            directionChosen = 2;
            break;
        } else if (tolower(playerChoice)=='e') {
            directionChosen = 3;
            break;
        } else if (tolower(playerChoice)=='w') {
            directionChosen = 4;
            break;
        }
    }
    return directionChosen;
}

