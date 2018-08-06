// zak.cpp
// Brent Hayes, CISP 360
// 08-05-2018

#include <iostream>
using namespace std;

void introduction();
string nameEntry();
int testEntry();

struct GradeBook {
    string name;
    string grade;
    double GPA;
    int test[100];
};



int main() {
   
    int classSize;
    int testQuantity;
    int countLoop = 0;

    GradeBook students[classSize];
    
    
    introduction();
// Specification A2 - Number of Students Prompt
    cout << "Enter the class size:" << endl;
    cin >> classSize;
    
// Specification B1 - Pseudo Dynamic Array
    cout << "How many tests were there?" << endl;
    cin >> testQuantity;

// Specification A1 - Main Student Loop
    do{
        countLoop++;


        students[countLoop].name = nameEntry();
        for(int i =0; i <= testQuantity; i++) {
            students[countLoop].test[i] = testEntry();
        }
   
    }while(countLoop <= classSize);

}

void introduction() {
    cout << "Welcome to zak.cpp. This program's function is to prompt the user for class size, student names, and test scores. After all data has been entered, the program will output the student's name, all test scores, their GPA, letter grade, and lastly a few words of advice." << endl;
}

// Specification C2 - Student Name
string nameEntry() {
    string studentName;
    char c;
    while(true) {
        cout << "Enter the student's first and last name on one line. (Ex. Mary Waterfall)." << endl;
        cin.ignore();
        getline(cin,studentName);
        for (unsigned int i = 0; i < studentName.length(); i++) {
            c = studentName[i];
            if (isspace(c)) {
                return studentName;
            }
        }
        cout << "Invalid entry, try again." << endl;
    }
}

// Specification C3 - Grade Input Validation
int testEntry() {
    int tempTest;
    while(true) {
        cout << "Please enter the test score (0-100)" << endl;
        cin >> tempTest;
        if ((tempTest>=0)&&(tempTest<=100)) {
            return tempTest;
        }
        cout << "Invalid entry, try agian." << endl;
    }

}