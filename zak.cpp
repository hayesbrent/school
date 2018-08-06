// zak.cpp
// Brent Hayes, CISP 360
// 08-05-2018

#include <iostream>
#include <iomanip>
#include <string> 

using namespace std;

struct GradeBook {
    string name;
    string grade;
    double GPA;
    int test[100];
    int droppedTest1;
    int droppedTest2;
    int droppedTest3;
};

void introduction();
string nameEntry(int);
int testEntry(int);
void calcGPA(GradeBook *students, int, int, int);
void printSummary(GradeBook * students, int, int);
void dropTest(GradeBook * students, int, int);

int main() {
   
    int classSize;
    int testQuantity;
    int countLoop = 0; 

    introduction();
// Specification A2 - Number of Students Prompt
    cout << "Enter the class size:" << endl;
    cin >> classSize;
    
// Specification B1 - Pseudo Dynamic Array
    cout << "How many tests were there?" << endl;
    cin >> testQuantity;

   GradeBook *students;
   students = new GradeBook[classSize];
   
// Specification A1 - Main Student Loop
    do{
        while(countLoop < classSize) {
            students[countLoop].name = nameEntry(countLoop);
            for(int i =0; i < testQuantity; i++) {
                students[countLoop].test[i] = testEntry(i);
            }
            calcGPA(students, countLoop, testQuantity, classSize);
            if(testQuantity >=4) {
                dropTest(students, countLoop, testQuantity);
            }
            countLoop++;
        }
        printSummary(students, classSize, testQuantity);
        break;

    }while(true);
    
}

void introduction() {
    cout << "Welcome to zak.cpp. This program's function is to prompt the user for class size, student names, and test scores. After all data has been entered, the program will output the student's name, all test scores, their GPA, letter grade, and lastly a few words of advice." << endl;
}

// Specification C2 - Student Name
string nameEntry(int studentNumber) {
    string studentName;
    char c;
    while(true) {
        cout << "Enter the student #" << (studentNumber+1) << "'s first and last name on one line. (Ex. Mary Waterfall)." << endl;
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
int testEntry(int testNumber) {
    int tempTest;
    while(true) {
        cout << "Please score (0-100) for test #" << (testNumber+1) << endl;
        cin >> tempTest;
        if ((tempTest>=0)&&(tempTest<=100)) {
            return tempTest;
        }
        cout << "Invalid entry, try agian." << endl;
    }

}

void calcGPA(struct GradeBook * students, int index, int testQuantity, int classSize) {
  //need to add dropped test scores

    double tempSum = 0;
    for (int i = 0; i < testQuantity; i++) {
        tempSum += students[index].test[i];
    }
    tempSum /= testQuantity;
    students[index].GPA = tempSum;
}

void printSummary(struct GradeBook * students, int classSize, int testQuantity) {
    
    for(int i = 0; i < classSize; i++) {
        cout << "Student: " << students[i].name << endl;
        for( int j = 0; j < testQuantity; j++) {

            cout << "Test #" << (j+1) << ": " << students[i].test[j];
            if ((j==students[j].droppedTest1)||(j==students[j].droppedTest2)||(j==students[j].droppedTest3)) {
                cout << " (DROPPED) ";
            }
            if (j+1 != testQuantity) {
                 cout << " || ";
            }

        }
        cout << endl;
        cout << "Student GPA: " << students[i].GPA << endl;
        cout << endl;
    }  
}

void dropTest(struct GradeBook * students, int index, int testQuantity) {

    int temp =0;
    int switchTemp = 0;
    int dropTemp1 =101;
    int dropTemp2 =101;
    int dropTemp3 =101;
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int switchIndex = 0;
    int tempSwitchIndex =0;

    for(int i = 0; i < testQuantity; i++) {
        temp = students[index].test[i];
        if(temp < dropTemp1) {
            switchIndex = index1;
            index1 =i;
            switchTemp = dropTemp1;
            dropTemp1 = temp;
            temp = switchTemp;

            if(temp < dropTemp2) {
                tempSwitchIndex = index2;
                index2 = switchIndex;
                switchIndex = tempSwitchIndex;

                switchTemp = dropTemp2;
                dropTemp2 = temp;
                temp = switchTemp;
                if (temp < dropTemp3) {
                    index3 = switchIndex;
                    dropTemp3 = temp;
                }
            }
        } else if(temp < dropTemp2) {
            switchIndex = index2;
            index2 = i;
            switchTemp = dropTemp2;
            dropTemp2 = temp;
            temp = switchTemp;
            if (temp < dropTemp3) {
                    index3 = switchIndex;
                    dropTemp3 = temp;
            }

        } else if(temp < dropTemp3) {
            index3 = i;
            dropTemp3 = temp;
            
        }
    }

    students[index].droppedTest1 =index1;
    students[index].droppedTest2 =index2;
    students[index].droppedTest3 =index3;

}