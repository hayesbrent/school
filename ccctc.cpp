// ccctc.cpp
// Brent Hayes, CISP 360
// 07-06-2018

#include <iostream>
#include <cstring>
#include <string>

using namespace std;



int userInput() {
    string CAT = "cat";
    string COT = "cot";
    string CAP = "cap";
    string userString;
    bool tempflag = true;

    while (tempflag==true) {
        cout << "Please enter one of the following objects you would like to convert it's temperature:\ncot, cat, cap.\n";
        getline(cin,userString);
        if (userString.length()!=3) {
            cout << "Invalid choice, please enter agian\n";
            continue;
        }
        for(int i = 0; i < 3; i++) {
           userString[i] = tolower(userString[i]);
        }
        if (userString.compare(CAT)==0) {
            return 0;
        } 
        if (userString.compare(COT)==0) {
            return 1;
        } 
        if (userString.compare(CAP)==0) {
            return 2;
        }
        cout << "Invalid choice, please enter agian\n";

    }
    return 0;

}





int main() {
    bool flag = true;
    int test = 0;
    cout << "Hello user. This Cat, Cot, Cap Temperature Calculator is designed to convert the Fahrenheit\ntemperatures of a Cat, a Cot, a Cap to different unit measurements(Celsius, Kelvin, Rankine).\n" << endl;
    

    while(flag == true) {
        
        test = userInput();
        

        flag = false;

    }


}