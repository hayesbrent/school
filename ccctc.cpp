// ccctc.cpp
// Brent Hayes, CISP 360
// 07-06-2018

//I wasn't able to fix a couple bugs when the program loops back around
//tempMin & tempMax have an unrestainable precision. setprecision(x) did nothing
//line 29 somehow gets automatic cin from restarts 'y' I tried cin.ignore() as well as cin.clear() with no success

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

//global variables for objects
    const string CAT = "cat";
    const string COT = "cot";
    const string CAP = "cap";
    const string BAT = "bat";


//userInput function checks for user input length, and if the characters match hardcoded objects.
//returns matched object (string)
// Specification A1 - Sophisticated Word Check
string userInput() { 
    
    string userString;
    bool tempflag = true;
    while (tempflag==true) {
        cout << "Please enter one of the following objects\n to convert it's temperature:\ncot, cat, cap, bat.\n";
        getline(cin,userString);
        if (userString.length()!=3) {
            cout << "Invalid choice, please enter again\n";
            continue;
        }
        for(int i = 0; i < 3; i++) {
           userString[i] = tolower(userString[i]);
        }
// Specification C1 - Only Valid Words
        if (userString.compare(CAT)==0) {
            return userString;
        } 
        if (userString.compare(COT)==0) {
            return userString;
        } 
        if (userString.compare(CAP)==0) {
            return userString;
        }
// Specification A2 - Another Thing
        if (userString.compare(BAT)==0) {
            return userString;
        }
        cout << "Invalid choice, please enter again\n";

    }
    //return set to bypass -Wall warning. this is a bad return that should never be used.
    return 0;

}
//temperatureConvert function imports object (string), proceeds to gather user input for temperature
//  checks if the input is valid, then converts to all 4 different units of measurement (Celsius, Kelvin, Rankine, Newton)
//  simple switch menu to determine which units to display and finally outputs table. doesn't return anything
void temperatureConvert(string userString) {
// Specification B1 - Floats for Temps
    double objectTemp, tempMin, tempMax, convertC, convertK, convertR, convertN; 
    int userChoice;
    bool tempflag = true;
        if (userString.compare(CAT)==0) {
            tempMin = 86.0;
            tempMax = 102.0;  
        } 
        if (userString.compare(COT)==0) {
            tempMin = 54.0;
            tempMax = 80.0;         
        } 
        if (userString.compare(CAP)==0) {
            tempMin = 72.0;
            tempMax = 88.0;
        }
        if (userString.compare(BAT)==0) {
            tempMin = 49.1;
            tempMax = 111.2;
        }
    cout << "The correct range for " << userString << " is " << tempMin << "-" << tempMax << " Fahrenheit.\n";
// Specification B2 - Valid Temps Only
    while(tempflag == true){
        cout << "Enter the correct temperature:\n";
        cin >> objectTemp;
        if ((objectTemp>=tempMin)&&(objectTemp<=tempMax)) {
            tempflag = false;
            continue;
        }
        cout << "That value is not in the predefined range of "  << tempMin << "-" << tempMax << " Fahrenheit. Please try again.\n";
    }
    //converting user Fahrenheit to Celsius [original formula C=(F-32)*5/9]
    convertC = (objectTemp -32.0) *(5.0/9.0);

    //converting Celsius to Kelvin [Original formula K = C + 273.15]
    convertK = convertC + 273.15;

    //converting Kelvin to Rankine [Original formula R = (C + 273.15)*9/5]
    convertR = convertK * 1.8;

// Specification A3 - Another Temperature Scale
    //converting Celsius to Newton [Original formula N = C * 33/100]
    convertN = convertC * 0.33;

    //menu verification
// Specification C3 - Valid Scale Menu Check
    while(tempflag == false) {
// Specification C2 - Temp Scale Menu
        cout << "\nConvert to which of the following:\n1. Celsius\n2. Kelvin\n3. Rankine\n4. Newton\n5. All of the above.\n";
        cin >> userChoice;
        if ((userChoice >=1) && (userChoice <=5)){
            tempflag = true;
            break;
        }
        cout << "That isn't a valid menu option please try again.\n";

    }
    cout << endl;
// Specification B3 - Fancy Output
    cout << left << setw(10) << "Scale" << setw(8) << "Temp" << endl;
    switch(userChoice){
        case 1:
            cout << left << setw(10) << "Celsius" << setw(8) <<  fixed << showpoint  << setprecision(3)  << right << convertC << endl;
            tempflag = true;
            break;
        case 2:
            cout << left << setw(10) << "Kelvin" << setw(8) << fixed << showpoint << setprecision(3)  << right << convertK << endl;
            tempflag = true;
            break;           
        case 3:
            cout << left << setw(10) << "Rankine" << setw(8) << fixed << showpoint << setprecision(3)  << right << convertR << endl;
            tempflag = true;
            break;  
        case 4:
            cout << left << setw(10) << "Newton" << setw(8) <<  fixed << showpoint << setprecision(3)  << right << convertN << endl;
            tempflag = true;
            break;  
        case 5:
            cout << left << setw(10) << "Celsius" << setw(8) <<  fixed << showpoint  << setprecision(3)  << right << convertC << endl;
            cout << left << setw(10) << "Kelvin" << setw(8) << fixed << showpoint << setprecision(3)  << right << convertK << endl;
            cout << left << setw(10) << "Rankine" << setw(8) << fixed << showpoint << setprecision(3)  << right << convertR << endl;
            cout << left << setw(10) << "Newton" << setw(8) <<  fixed << showpoint << setprecision(3)  << right << convertN << endl;
            tempflag = true;
            break;      
    }
    cout << endl;
}


//main body of the program
int main() {
    bool flag = true;
    bool restartFlag = true;
    string temp = "";
    char userCont;

    //descriptive greeting
    cout << "Hello user. This Cat, Cot, Cap Temperature Calculator \n is designed to convert the Fahrenheit temperatures\n of a Cat, a Cot, a Cap, a Bat to different unit\n measurements(Celsius, Kelvin, Rankine, Newton).\n" << endl;
    

    while(flag == true) {
        restartFlag = true;
// Specification A4 - Used functions to help organize and compartmentalize code
        temp = userInput();
        temperatureConvert(temp);

        //restart verification
        while (restartFlag == true) {
            cout << "Would you like to restart?(Y/N)\n";
            cin >> userCont;
            if(tolower(userCont)=='y'){
                restartFlag = false;
                break;
            }
            if(tolower(userCont)=='n') {
                restartFlag = false;
                flag = false;
            }
            if(tolower(userCont)!='n') {
                cout << "I'm sorry that is not a valid input. Please type 'Y' or 'N'.\n";
            }
        }
        
        

    }


}