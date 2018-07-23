// ttt.cpp
// Brent Hayes, CISP 360
// 07-22-2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
int beginning();
void boardDisplay(char[]);
int gameInputValidation(char[], int);

int main() {
    
    const int SIZE = 9; //state of the board will be 0-8, 9 for X, 10 for O
    char board[SIZE] = {'0','1','2','3','4','5','6','7','8'};
    int turnCount = 0;
    int startInfo, menuChoice, quitProgram, playAgain = 0;
    char restartChoice;

    do{
        if(turnCount==0) {
            cout <<  "Welcome to tic tac toe! This a Player vs AI program featuring the infamous tic tac toe game." << endl;
            while(true) {
                if (playAgain !=0) {
                    playAgain = 0;
                    break;

                }
                cout << "Please select from one of the following options:\n1 - Explain the Game\n2 - Play\n3 - Quit" << endl;
                cin >> menuChoice;
                if (menuChoice == 1) {
                    cout << "Add in instructions later" << endl;
                } else if (menuChoice==2) {
                    startInfo = beginning(); //0 for player, 1 for AI
                    break;
                } else if (menuChoice == 3) {
                    quitProgram++;
                    break;
                } else {
                    cout << "Invalid Selection, please try again" << endl;
                }
            }
            if (quitProgram!=0) {
                break; //breaks out of do while loop, terminates program
            }  
        }
        //Player Turn
        if(startInfo ==0) {
            cout << "Player will start now" << endl;
            turnCount++;
            startInfo++;

        //AI turn    
        } else if(startInfo ==1) {
            cout << "Computer will start now" << endl;
            turnCount++;
            startInfo--;

            
        }
        if (turnCount==9) {
            //display stats
            //restart?
            while (true) {
                cout << "would you like to restart?" << endl;
                cin >> restartChoice;
                if(tolower(restartChoice) == 'y') {
                    turnCount =0;
                    for(int i = 0; i <9;i++){
                        board[i] = '0' +(i*1);
                    }
                    break;
                    
                } else if(tolower(restartChoice)== 'n') {
                    quitProgram++;
                    break;
                } else {
                    cout << "Invalid Selection, please try again" << endl;
                } 
            }
            if (quitProgram!=0) {
                break; //breaks out of do while loop, terminates program
            }  

        }
    } while(true);
}

void boardDisplay(char board[9]) {
    cout << "--------------" << endl;
    cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
    cout << "--------------" << endl;
    cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
    cout << "--------------" << endl;
    cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
    cout << "--------------" << endl;
}


int gameInputValidation(char board[9], int startInfo) {
    int tempInput;
    //0 for player
    if (startInfo = 0) {
        while(true) {
            cout << "Please choose a valid square (anything not marked with an X or O)" << endl;
            cin >> tempInput;
            if ((board[tempInput]!='X') || (board[tempInput]!='O')) {
                break;
            } else {
                cout << "Invalid Selection, please try again" << endl;
            }

        }
    } else { //AI 
    

    }
    return tempInput;
}


int beginning(){
    unsigned seed;
    seed = time(0);
    srand(seed);
    if((rand()%2) == 0) {
        cout << "The player will begin the game first." << endl;
        return 0;
    } else {
        cout << "The AI will begin the game first." << endl;
        return 1;
    }
}

