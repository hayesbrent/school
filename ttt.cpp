// ttt.cpp
// Brent Hayes, CISP 360
// 07-22-2018
// Plagiarism Checker showed a 10% match. the only matches (medium) were the headers at the top, the entire function boardDisplay, and part of winCheck function

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;
int beginning();
void boardDisplay(char[]);
int gameInputValidation(char[], int);
int winCheck(char[]);

int main() {
    
    const int SIZE = 9; //state of the board will be 0-8
    char board[SIZE] = {'0','1','2','3','4','5','6','7','8'};
    int record[SIZE] = {};
    int turnCount = 0;
    int startInfo =0;
    int menuChoice=0;
    int quitProgram=0; 
    int tempInfo = 0;
    int victoryState = 0;
    int startPlayer = 0;
    char restartChoice;
    int scoreKeepAI = 0;
    int scoreKeepPlayer =0;
    int scoreKeepDraw = 0;
    int restartFlag = 0;

// Specification A1 - Main Game Loop
    do{
        if(turnCount==0) {
            
            while(true) {
                if (restartFlag!=0) {
                startInfo = beginning();
                startPlayer = startInfo;
                break;
            }
                 cout <<  "Welcome to tic tac toe! This a Player vs AI program featuring the infamous tic tac toe game." << endl;
// Specification B1 - Start Menu
                cout << "Please select from one of the following options:\n1 - Explain the Game\n2 - Play\n3 - Quit" << endl;
                cin >> menuChoice;
// Specification B2 - Valid Menu Choices
                if (menuChoice == 1) {
                    cout << "Tic Tac Toe is a game where you choose one of the squares on a 3x3 grid." << endl;
                    cout << "The first player to connect 3 of the squares together horizontally, vertically, or diagonally wins." << endl;
                } else if (menuChoice==2) {
                    startInfo = beginning(); //0 for player, 1 for AI
                    startPlayer = startInfo;
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
        boardDisplay(board);
        if(startInfo ==0) {
            cout << "Player will make their move." << endl;
            tempInfo = gameInputValidation(board,startInfo);
            board[tempInfo] = 'X';
            record[turnCount] = tempInfo;
            turnCount++;
            startInfo++;

        //AI turn    
        } else if(startInfo ==1) {
            cout << "Computer will make it's move." << endl;
            tempInfo = gameInputValidation(board,startInfo);
            board[tempInfo] = 'O';
            record[turnCount] = tempInfo;
            turnCount++;
            startInfo--;
            
        }
        victoryState = winCheck(board);
        if (victoryState!=0) {
            turnCount =9;
            boardDisplay(board);
        }
        if (turnCount==9) {
            if (victoryState==1) {
                cout << "The Player decimated their AI foe!" << endl;
                scoreKeepPlayer++;
            } else if (victoryState ==2) {
                cout << "The mighty computer has triumphed!" << endl;
                scoreKeepAI++;
            } else if (victoryState == 0) {
                cout << "The match has ended in a draw." << endl;
                scoreKeepDraw++;
            }
// Specification A4 - Play by play
            cout << "The turn order was:" << endl;
            for(int i = 0; i <turnCount; i++){
                cout << "Turn " << i << " ";
                if(startPlayer == 0) {
                    cout << left << setw(8) << "Player: ";
                } else {
                    cout << left << setw(8) << "AI: ";
                }
                cout << record[i] << endl;
                if ((record[i+1]== '\0') && (record[i+2]== '\0')) {
                       break;
                }
                if(startPlayer==0) {
                    startPlayer++;
                } else {
                    startPlayer = 0;
                }
            }
            cout << endl;

            while (true) {
// Specification A2 - Simple Prompt
                cout << "\nwould you like to restart?(Y/N)" << endl;
                cin >> restartChoice;
                if(tolower(restartChoice) == 'y') {
                    turnCount =0;
                    restartFlag = 1;
                    for(int i = 0; i <9;i++){
                        board[i] = '0' +(i*1);
                    }
                    break;
                    
                } else if(tolower(restartChoice)== 'n') {
                    quitProgram++;
// Specification A3 - Keep Score
                    cout << "Current score is:" << endl;
                    cout << "Player: " << scoreKeepPlayer << " || " << "AI: " << scoreKeepAI << " || Draws: " << scoreKeepDraw << endl;
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

// Specification B3 - Pretty Display
// Specification C2 - Simple Display
void boardDisplay(char board[9]) {
    cout << "-------------" << endl;
    cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
    cout << "-------------" << endl;
}
// Specification C4 - Decide Winner
int winCheck(char board[9]) {
    //1 for Player Victory, 2 for AI Victory
    
    if((board[0]=='X')&&(board[1]=='X')&&(board[2]=='X')) {
        return 1;
    } else if((board[3]=='X')&&(board[4]=='X')&&(board[5]=='X')) {
        return 1;
    } else if((board[6]=='X')&&(board[7]=='X')&&(board[8]=='X')) {
        return 1;
    } else if((board[0]=='X')&&(board[3]=='X')&&(board[6]=='X')) {
        return 1;
    } else if((board[1]=='X')&&(board[4]=='X')&&(board[7]=='X')) {
        return 1;
    } else if((board[2]=='X')&&(board[5]=='X')&&(board[8]=='X')) {
        return 1;
    } else if((board[0]=='X')&&(board[4]=='X')&&(board[8]=='X')) {
        return 1;
    } else if((board[2]=='X')&&(board[4]=='X')&&(board[6]=='X')) {
        return 1;
    } else if((board[0]=='O')&&(board[1]=='O')&&(board[2]=='O')) {
        return 2;
    } else if((board[3]=='O')&&(board[4]=='O')&&(board[5]=='O')) {
        return 2;
    } else if((board[6]=='O')&&(board[7]=='O')&&(board[8]=='O')) {
        return 2;
    } else if((board[0]=='O')&&(board[3]=='O')&&(board[6]=='O')) {
        return 2;
    } else if((board[1]=='O')&&(board[4]=='O')&&(board[7]=='O')) {
        return 2;
    } else if((board[2]=='O')&&(board[5]=='O')&&(board[8]=='O')) {
        return 2;
    } else if((board[0]=='O')&&(board[4]=='O')&&(board[8]=='O')) {
        return 2;
    } else if((board[2]=='O')&&(board[4]=='O')&&(board[6]=='O')) {
        return 2;
    } else {
        return 0;
    }
}

// Specification B4 - Valid Move
int gameInputValidation(char board[9], int startInfo) {
    int tempInput;
    //0 for player
    if (startInfo == 0) {
        while(true) {
            cout << "Please choose a valid square (anything not marked with an X or O)" << endl;
            cin >> tempInput;
            if ((board[tempInput]!='X') && (board[tempInput]!='O')) {
                break;
            } else {
                cout << "Invalid Selection, please try again" << endl;
            }

        }
// Specification C3 - AI
    } else { //AI turn
        unsigned seed;
        seed = time(0);
        srand(seed);
        while(true) {
            tempInput = rand()%9;
            if ((board[tempInput]!='X') && (board[tempInput]!='O')) {
                break;
            }
        }

    }
    return tempInput;
}


int beginning(){
    unsigned seed;
    seed = time(0);
    srand(seed);
// Specification C1 - Random Start
    if((rand()%2) == 0) {
        cout << "The player will begin the game first." << endl;
        return 0;
    } else {
        cout << "The AI will begin the game first." << endl;
        return 1;
    }
}

