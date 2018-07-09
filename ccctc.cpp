// ccctc.cpp
// Brent Hayes, CISP 360
// 07-06-2018

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
//global variables for objects
    const string CAT = "cat";
    const string COT = "cot";
    const string CAP = "cap";
    const string BAT = "bat";


string userInput() {
   
    string userString;
    bool tempflag = true;

    while (tempflag==true) {
        cout << "Please enter one of the following objects you would like to convert it's temperature:\ncot, cat, cap, bat.\n";
        getline(cin,userString);
        if (userString.length()!=3) {
            cout << "Invalid choice, please enter again\n";
            continue;
        }
        for(int i = 0; i < 3; i++) {
           userString[i] = tolower(userString[i]);
        }
        if (userString.compare(CAT)==0) {
            return userString;
        } 
        if (userString.compare(COT)==0) {
            return userString;
        } 
        if (userString.compare(CAP)==0) {
            return userString;
        }
        if (userString.compare(BAT)==0) {
            return userString;
        }
        cout << "Invalid choice, please enter again\n";

    }
    //return set to bypass -Wall warning. this is a bad return that should never be used.
    return 0;

}

void temperatureConvert(string userString) {
    double objectTemp, tempMin, tempMax, convertC, convertK, convertR, convertN; 
    int userChoice;
    bool tempflag = true;
        if (userString.compare(CAT)==0) {
            tempMin = 86.0;
            tempMax = 102.0;  
        } 
        if (userString.compare(COT)==0) {
            tempMin = 54.0;
            tempMax = 102.0;         
        } 
        if (userString.compare(CAP)==0) {
            tempMin = 72.0;
            tempMax = 88.0;
        }
        if (userString.compare(BAT)==0) {
            tempMin = 49.1;
            tempMax = 111.2;
        }
    cout << "The correct range for " << userString << " is "  << tempMin << "-" << tempMax << " Fahrenheit.\n";
    while(tempflag == true){
        cout << "Enter the correct temperature:\n";
        cin >> objectTemp;
        if ((objectTemp>=tempMin)&&(objectTemp<=tempMax)) {
            tempflag = false;
            continue;
        }
        cout << "That value is not in the predefined range of " << tempMin << "-" << tempMax << " Fahrenheit. Please try again.\n";
    }
    //converting user Fahrenheit to Celcius [original formula F=C*9/5+32]
    convertC = (objectTemp * 1.8) + 32;

    //converting Celcius to Kelvin [Original formula K = C + 273.15]
    convertK = convertC + 273.15;

    //converting Kelvin to Rankine [Original formula R = (C + 273.15)*9/5]
    convertR = convertK * 1.8;

    //converting Celcius to Newton [Original formula N = C * 33/100]
    convertN = convertC * 0.33;





    while(tempflag == false) {
        cout << "\nConvert to which of the following:\n1. Celcius\n2. Kelvin\n3. Rankine\n4. Newton\n5. All of the above.\n";
        cin >> userChoice;
        switch(userChoice){
            case 1:
                cout << convertR << convertN;
                cout << "1";
                tempflag = true;
                break;
            case 2:
                cout << "2";
                tempflag = true;
                break;           
            case 3:
                cout << "5";
                tempflag = true;
                break;  
            case 4:
                cout << "4";
                tempflag = true;
                break;  
            case 5:
                cout << "2";
                tempflag = true;
                break;  
            default: 
            cout << "That isn't a valid menu option please try again.";
        }
    }

    



}



int main() {
    bool flag = true;
    string temp = "";
    cout << "Hello user. This Cat, Cot, Cap Temperature Calculator is designed to convert the Fahrenheit\ntemperatures of a Cat, a Cot, a Cap, a Bat to different unit measurements(Celsius, Kelvin, Rankine).\n" << endl;
    

    while(flag == true) {
        
        temp = userInput();
        temperatureConvert(temp);
        cout << "Would you like to RE:Zero?\n";
        flag = false;

    }


}