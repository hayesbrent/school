// final.cpp
// Brent Hayes, CISP 360
// 08-07-2018


#include <iostream>
#include <string>
using namespace std;

struct monsterInfo {
    string name;
    int health;
    int strength;
};
struct playerInfo {
    string name;
    int health = 200;
    int strength = 15;

};

void monsterPopulate(monsterInfo *monster);


int main() {
    monsterInfo *monster;
   monster = new monsterInfo[5];


   monsterPopulate(monster);


}

//populates monster basic information. name, health, strength
void monsterPopulate(struct monsterInfo * monster) {
    monsterInfo monster[] = {
        {"Spider", 50, 20},
        {"Cyclops", 80, 30},
        {"Orc", 70, 15},
        {"Goblin", 20, 10},
        {"Rock Lobster", 100, 10}

    };
}


