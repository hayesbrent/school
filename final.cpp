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

void monsterPopulate(monsterInfo *monster);
int monsterSelect();
void floor1(playerInfo &, int [10], monsterInfo *monster);
void floor2a(playerInfo &, int [10], monsterInfo *monster);
void floor2b(playerInfo &, int [10], monsterInfo *monster);
void floor2c(playerInfo &, int [10], monsterInfo *monster);
void floor3a(playerInfo &, int [10], monsterInfo *monster);
void floor3b(playerInfo &, int [10], monsterInfo *monster);
void floor3c(playerInfo &, int [10], monsterInfo *monster);
void floor3(playerInfo &, int [10], monsterInfo *monster);
int playerDirection(int, int, int, int, playerInfo &);
void playerInputValidation(playerInfo &, int);
int roomCommand();

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
    floor3(player,roomstate, monster);

    cout << "Amazing job," << player.name << " , you are a hero among heroes! You have made it out of the dungeon!!!" << endl;
   
    

}


void monsterPopulate(struct monsterInfo * monster) {
    int temp;
    temp = monsterSelect();
    cout << "As you make your way into the room, a " << monster[temp].name << " appears before you. Frightened it scampers off as fast as it can. One ponders why a creator would make such easily scared yet powerful monsters." << endl;
}

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
// Specification C2 - Player Name
    getline(cin,player.name);
    cout << "Well then, " << player.name << ", steel your blade against the darkness and forge on ahead!" << endl;
}




void floor3(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    int playerMovement = 0;
    int command = 0;
    string room_title = "floor3";
    string room_description = "Abandoned mine shaft";
// Specification C4 - Abbreviated Room Description
    cout << room_title << endl;
    if ( roomstate[0] == 0) {
        cout << room_description;
        cout << "You peer into the darkness of the room, and suddenly a specter appears before you. His wide smile sends chills down to your soul. \"What is your name adventurer\?\"" << endl;
        cout << "1 - State your name proudly\n2 - Keep wary of the ghastly ghoul and say nothing" << endl;
        playerInputValidation(player, 30);
        roomstate[0] = 1;
    monsterPopulate(monster);
    }
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, but come up empty." << endl;
        } else if (command ==3) {
            cout << "From where you are, the air is still as can be." << endl;
        } else if (command == 4) {
            break;
        } 
    }

    playerMovement = playerDirection(1,0,1,1,player);
    if (playerMovement == 1) {
        floor3b(player, roomstate, monster);
    } else if (playerMovement == 3) {
        floor3c(player, roomstate, monster);
    } else if (playerMovement == 4) {
        floor3a(player, roomstate, monster);
    }
}
void floor3a(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    string room_title = "floor3a";
    string room_description = "minecart storage area";
    cout << room_title << endl;
    int playerMovement = 0;
    int command = 0;
    if ( roomstate[1] == 0) {
        cout << room_description;
        roomstate[1] = 1;
    }
    monsterPopulate(monster);
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, but come up empty." << endl;
        } else if (command ==3) {
            cout << "From where you are, the air is still as can be." << endl;
        } else if (command == 4) {
            break;
        } 
    }
    playerMovement = playerDirection(1,1,1,0,player);
    if (playerMovement == 1) {
        floor2a(player, roomstate, monster);

    } else if (playerMovement == 2) {
        floor3(player, roomstate, monster);
    } else if (playerMovement == 3) {
        floor3b(player, roomstate, monster);
    }
}
void floor3b(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    string room_title = "floor3b";
    string room_description = "dusty forge";
    cout << room_title << endl;
    int playerMovement = 0;
    int command = 0;
    if ( roomstate[2] == 0) {
        cout << room_description << endl;
        roomstate[2] = 1;
    }
    monsterPopulate(monster);
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, but come up empty." << endl;
        } else if (command ==3) {
            cout << "From where you are, the air is still as can be." << endl;
        } else if (command == 4) {
            break;
        } 
    }
    playerMovement = playerDirection(1,1,1,1,player);

     if (playerMovement == 1) {
        floor2b(player, roomstate, monster);

    } else if (playerMovement == 2) {
        floor3(player, roomstate, monster);
    } else if (playerMovement == 3) {
        floor3c(player, roomstate, monster);
    } else if (playerMovement == 4) {
        floor3a(player, roomstate, monster);
    }
}
void floor3c(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    string room_title = "floor3c";
    string room_description = "underground cliffside";
    cout << room_title << endl;
    int playerMovement = 0;
    int command = 0;
    if ( roomstate[3] == 0) {
        cout << room_description << endl;
        roomstate[3] = 1;
    }
    monsterPopulate(monster);
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, but come up empty." << endl;
        } else if (command ==3) {
            cout << "From where you are, the air is still as can be." << endl;
        } else if (command == 4) {
            break;
        } 
    }
    playerMovement = playerDirection(1,1,0,1,player);
     if (playerMovement == 1) {
        floor2c(player, roomstate, monster);

    } else if (playerMovement == 2) {
        floor3(player, roomstate, monster);
    } else if (playerMovement == 4) {
        floor3b(player, roomstate, monster);
    }
}
void floor2a(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    string room_title = "2a";
    string room_description = "weathered away barracks";
    cout << room_title << endl;
    int playerMovement = 0;
    int command = 0;
    if ( roomstate[4] == 0) {
        cout << room_description << endl;
        roomstate[4] = 1;
    }
    monsterPopulate(monster);
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, and find some tasty treats!" << endl;
        } else if (command ==3) {
            cout << "A faint breeze can be felt across your face." << endl;
        } else if (command == 4) {
            break;
        } 
    }
    playerMovement = playerDirection(1,1,1,0,player);
     if (playerMovement == 1) {
        floor1(player, roomstate, monster);
    } else if (playerMovement == 2) {
        floor3a(player, roomstate, monster);
    } else if (playerMovement == 3) {
        floor2b(player, roomstate, monster);
    } 
}
void floor2b(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    string room_title = "floor2b";
    string room_description = "forgotten tavern";
    cout << room_title << endl;
    int playerMovement = 0;
    int command = 0;
    if ( roomstate[5] == 0) {
        cout << room_description << endl;
        roomstate[5] = 1;
    }
    monsterPopulate(monster);
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, and find some tasty treats!" << endl;
        } else if (command ==3) {
            cout << "A faint breeze can be felt across your face." << endl;
        } else if (command == 4) {
            break;
        } 
    }
    playerMovement = playerDirection(1,1,1,1,player);
     if (playerMovement == 1) {
        floor1(player, roomstate, monster);

    } else if (playerMovement == 2) {
        floor3b(player, roomstate, monster);
    } else if (playerMovement == 3) {
        floor2c(player, roomstate, monster);
    } else if (playerMovement == 4) {
        floor2a(player, roomstate, monster);
    }
}

// Specification B3 - Add more rooms
void floor2c(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    string room_title = "floor2c";
    string room_description = "narrow bridge";
    cout << room_title << endl;
    int playerMovement = 0;
    int command = 0;
    if ( roomstate[6] == 0) {
        cout << room_description << endl;
        roomstate[6] = 1;
    }
    monsterPopulate(monster);
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, and find some tasty treats!" << endl;
        } else if (command ==3) {
            cout << "A faint breeze can be felt across your face." << endl;
        } else if (command == 4) {
            break;
        } 
    }
    playerMovement = playerDirection(1,1,0,1,player);
     if (playerMovement == 1) {
        floor1(player, roomstate, monster);

    } else if (playerMovement == 2) {
        floor3c(player, roomstate, monster);
    } else if (playerMovement == 4) {
        floor2b(player, roomstate, monster);
    }
}

// Specification C1 - Five Rooms
void floor1(playerInfo &player, int roomstate[8], struct monsterInfo * monster) {
    string room_title = "floor1";
    string room_description = "cavern entrance way";
    cout << room_title << endl;
    int playerMovement = 0;
    int command = 0;
    if ( roomstate[7] == 0) {
        cout << room_description << endl;
    roomstate[7] = 1;
    }
    monsterPopulate(monster);
    while(true) {
        command = roomCommand();
        if (command==1) {
            cout << room_title << endl;
            cout << room_description << endl;
        } else if (command==2) {
            cout << "You search around the area for plants, the entire room is full of them. You have a feast of mushrooms and ferns." << endl;
        } else if (command ==3) {
            cout << "A torrent of wind is blowing from the northern entrance way." << endl;
        } else if (command == 4) {
            break;
        } 
    }
    playerMovement = playerDirection(1,1,1,1,player);
     if (playerMovement == 1) {
        return;

    } else if (playerMovement == 2) {
        floor2b(player, roomstate, monster);
    } else if (playerMovement == 3) {
        floor2c(player, roomstate, monster);
    } else if (playerMovement == 4) {
        floor2a(player, roomstate, monster);
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
        if(north==0) {
           if (tolower(playerChoice)=='n') {
               cout << "Invalid, please try again" << endl;
               continue;
           }
        }
        if(south==0) {
           if (tolower(playerChoice)=='s') {
               cout << "Invalid, please try again" << endl;
               continue;
           }            
        }
        if(east==0) {
            if (tolower(playerChoice)=='e') {
                cout << "Invalid, please try again" << endl;
                continue;
           }
        }
        if(west==0) {
            if (tolower(playerChoice)=='w') {
                cout << "Invalid, please try again" << endl;
                continue;
           }          
        }
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
        } else {
            cout << "Invalid, please try again" << endl;
        }
    }
    return directionChosen;
}

//Specification C3 - Input Validation
int roomCommand() {
    char roomCommand;
    int userChoice =0;
    while(true) {
// Specification B4 - Add More Command Options
        cout << "L - Look around the room\nC - Check for edible plants\nW - See if you are able to sense a wind\nM - Make your way through a doorway" << endl;
        cin >> roomCommand;
// Specification C5 - Detailed Look
        if(tolower(roomCommand)=='l') {
            userChoice =1;
            break;            
        } else if(tolower(roomCommand)=='m') {
            userChoice =4;
            break;
        } else if(tolower(roomCommand)=='c') {
            userChoice =2;
            break;
        } else if(tolower(roomCommand)=='w') {
            userChoice =3;
            break;
        } else {
            cout  << "Invalid Choice, please try again" << endl;
        }
    }
    return userChoice;
}
