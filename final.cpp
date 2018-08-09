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
void floor1();
void floor2a();
void floor2b();
void floor2c();
void floor3a();
void floor3b();
void floor3c();
int floor3();
int playerDirection();

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


    introduction(player);
   int test = 0;
   test = monsterSelect();
    cout << test;
    

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

//char playerInputValidation () {

//}


void introduction(playerInfo &player) {
    cout << "Welcome to final.cpp. This program consists of a short text based adventure dungeon crawler. You have fallen down an abandoned mining shaft and will have to fight your way to the top." << endl;
    cout << "Brave (but unfortunate) adventurer, what is your name\?" << endl;
// Specification C2
    getline(cin,player.name);
    cout << "Well then, " << player.name << ", steel your blade against the darkness and forge on ahead!" << endl;
}

int floor3() {
    cout << "You peer into the darkness of the room, and suddenly a specter appears before you. His smile sends chills down to your soul. \"What is your name adventurer\?\"" << endl;
    cout << "1 - State your name proudly\n2 - Keep weary of the ghastly ghoul and say nothing" << endl;

}
void floor3a() {
    
}
void floor3b() {
    
}
void floor3c() {
    
}
void floor2a() {
    
}
void floor2b() {
    
}

// Specification B3 - Add more rooms
void floor2c() {
    
}

// Specification C1
void floor1() {

}