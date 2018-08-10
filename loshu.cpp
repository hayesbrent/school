// loshu.cpp
// Brent Hayes, CISP 360
// 08-09-2018


#include <iostream>
using namespace std;

int main() {
    int userInput =0;
    int sumRequirement =0;
    int sumTemp1 =0;
    int sumTemp2 =0;
    int sumTemp3 =0;
    int sumTemp4 =0;
    int sumTemp5 =0;
    int sumTemp6 =0;
    
    int count =1;
    int loshuSquares[3][3];
    bool badFlag = false;
    bool tempFlag = false;
    cout << "1|2|3\n-----\n4|5|6\n-----\n7|8|9" << endl;
    cout << "Please enter an inclusive range of 1-9 with no repeats for each square" << endl;
    while(count<=9) {
        cout << "Square #" << count << ":" << endl;
        cin >> userInput;
        if((userInput<1) || (userInput>9) ){
            cout << "Invalid please try again" << endl;
            continue;
        }
        for(int i =0; i <=2;i++) {
            for(int j=0; j<=2; j++) {
                if (loshuSquares[i][j]==userInput) {
                    tempFlag = true;
                    i=6;
                    j=6;
                    break;
                } 
            }
        }
        if (tempFlag == true) {
            cout << "Number is already taken, please try again" << endl;
            tempFlag = false;
            continue;


        } else {
            switch(count) {
                        case 1:
                        loshuSquares[0][0] = userInput;

                        case 2:
                        loshuSquares[0][1] = userInput;
                        case 3:
                        loshuSquares[0][2] = userInput;
                        case 4:
                        loshuSquares[1][0] = userInput;
                        case 5:
                        loshuSquares[1][1] = userInput;
                        case 6:
                        loshuSquares[1][2] = userInput;
                        case 7:
                        loshuSquares[2][0] = userInput;
                        case 8:
                        loshuSquares[2][1] = userInput;
                        case 9:
                        loshuSquares[2][2] = userInput;
                    };
        }

        count++;

    }

    cout << "Numbers selected, checking for magic square" << endl;
    for (int i=0;i<=2;i++) {
        sumRequirement += loshuSquares[0][i];
    }
    /*
    for(int i =0; i <=2;i++) {
        for(int j=0; j<=2; j++) {
            cout << loshuSquares[i][j] << endl;
        }
    }


            
            sumTemp += loshuSquares[i][j];
            cout << sumTemp << " " << i << j << endl;
            if (j==2) {
                if(sumTemp!=sumRequirement){
                    
                    i=5;
                    j=5;
                    badFlag=true;
                } else {
                    sumTemp=0;
                }
            }
        }
        */

       //horizontal
       sumTemp1=  loshuSquares[0][0] +  loshuSquares[0][1] +  loshuSquares[0][2];
       sumTemp2=  loshuSquares[1][0] +  loshuSquares[1][1] +  loshuSquares[1][2];
       sumTemp3=  loshuSquares[2][0] +  loshuSquares[2][1] +  loshuSquares[2][2];
        //veritcal
       sumTemp4=  loshuSquares[0][0] +  loshuSquares[1][0] +  loshuSquares[2][0];
       sumTemp5=  loshuSquares[0][1] +  loshuSquares[1][1] +  loshuSquares[2][1];
       sumTemp6=  loshuSquares[0][2] +  loshuSquares[1][2] +  loshuSquares[2][2];
    if((sumRequirement!=sumTemp1)||(sumRequirement!=sumTemp2)||(sumRequirement!=sumTemp3)||(sumRequirement!=sumTemp4)||(sumRequirement!=sumTemp5)||(sumRequirement!=sumTemp6)) {
        badFlag=true;
    }
    cout << sumRequirement << " " << sumTemp1 << " " << sumTemp2 << " " << sumTemp3 << " " << sumTemp4 << " " << sumTemp5 << " " << sumTemp6 <<endl; 

    
    if(badFlag ==true) {
        cout << "Not a magic square!~" << endl;
    } else {
        cout << "You got yourself a magic square! All rows and all columns each add up to:" << sumRequirement << endl;
    }
}