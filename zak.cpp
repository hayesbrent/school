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
    double AVG;
    int test[100];
    double classTestAverage;
};

void introduction();
string nameEntry(int);
int testEntry(int);
void calcAVG(GradeBook *students, int, int);
void printSummary(GradeBook * students, int, int);
void dropTest(GradeBook * students, int, int);
void sortTest(GradeBook * students, int, int);
void classAverage(GradeBook * students, int, int);
void studentGrade(GradeBook * students, int);

int main() {
   
    int classSize;
    int testQuantity;
    int countLoop = 0; 
    char zakChoice;
    bool flag = true;

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
            countLoop++;

        }
        classAverage(students, classSize, testQuantity);

        for (int i = 0; i <classSize; i++) {
            sortTest(students, i, testQuantity);
            calcAVG(students, i, testQuantity);
        }

        printSummary(students, classSize, testQuantity);
        while (true) {
            cout << "Would you like to enter a new class Professor Zak? (Y/N)" << endl;
            cin >> zakChoice;
            if (tolower(zakChoice) == 'y') {
                cout << "Enter the class size:" << endl;
                cin >> classSize;
                cout << "How many tests were there?" << endl;
                cin >> testQuantity;
            } else if (tolower(zakChoice) == 'n') {
                flag = false;
                break;
            } else {
                cout << "Invalid choice, please try again." << endl;
            }
        }


    }while(flag ==true);
    
}

void introduction() {
    cout << "Welcome to zak.cpp. This program's function is to prompt the user for class size, number of tests, student names, and test scores. After all data has been entered, the program will output the student's name, all test scores, their GPA, letter grade, and lastly a few words of advice." << endl;
}

// Specification C2 - Student Name
string nameEntry(int studentNumber) {
    string studentName;
    char c;
    while(true) {
        cout << "\nEnter the student #" << (studentNumber+1) << "'s first and last name on one line. (Ex. Mary Waterfall)." << endl;
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
        cout << "Invalid entry, try again." << endl;
    }

}

void calcAVG(struct GradeBook * students, int index, int testQuantity) {
 
    double tempSum = 0;
    if(testQuantity >=4) {
            for (int i = 0; i <(testQuantity-3);i++) {
                tempSum += students[index].test[i];
            }
              
    } else {
        for (int i = 0; i < testQuantity; i++) {
        
            tempSum += students[index].test[i];
        }
    }
    if(testQuantity >=4) {
        tempSum = tempSum / (testQuantity-3);
        students[index].AVG = tempSum;

    } else {
        tempSum /= testQuantity;
        students[index].AVG = tempSum;
    }
}


void printSummary(struct GradeBook * students, int classSize, int testQuantity) {
    cout << endl;
    for(int i = 0; i < classSize; i++) {
        cout << "Student: " << students[i].name << endl;
        cout << "Test Scores: ";

        for( int j = 0; j < testQuantity; j++) {
// Specification B3 - Signify Dropped                        
            cout << students[i].test[j];
            if (testQuantity >=4) {
                if (j>= (testQuantity-3)) {
                    cout << " (DROPPED)";
                }  
            }
            if (j+1 != testQuantity) {
                 cout << " || ";
            }
        }
        cout << endl;
        cout << "Student Grade: ";
        studentGrade(students, i);
        cout << endl;
        
    }  
    cout << "Class Average:" <<endl;
    for(int i = 0; i < testQuantity; i++) {
        cout << "Test #" << (i+1) << ": " << students[i].classTestAverage;
        if( i+1 != testQuantity) {
            cout << " || ";
        }
    }
    cout << endl;
}



// Specification B4 - Sorted Output
void sortTest(struct GradeBook * students, int index, int testQuantity) {
    int temp=0;
    int x =0;
    bool swap = true;

    while (swap) {
        swap = false;
        x++;

        for (int i = 0; i < testQuantity-x; i++) {
            if(students[index].test[i]< students[index].test[i+1]) {
                temp = students[index].test[i];
                students[index].test[i] = students[index].test[i+1];
                students[index].test[i+1] = temp;
                swap = true;

            }
        } 
    } 
}

void classAverage(struct GradeBook * students, int classSize, int testQuantity) {
    double temp = 0.0;
    for(int i = 0; i < testQuantity; i++) {
        for(int j = 0; j < classSize; j++) {
           temp += students[j].test[i];

        }
        students[i].classTestAverage = temp/classSize;
        temp = 0.0;
    }
}

// Specification C4 - GPA Advice
void studentGrade(struct GradeBook * students, int index) {
    double temp = 0.0;
    temp = students[index].AVG;

    if (temp>=90.0) {
        cout << "A" << endl;
        cout << "Wow, excellent job! You've done very well, keep up the hard work!" << endl;
    } else if (temp>=80.0) {
        cout << "B" << endl;
        cout << "Good effort, but you can do better. Push yourself even further and you'll make it to the top." << endl;
    } else if (temp>=70.0) {
        cout << "C" << endl;
        cout << "Acceptable performance. There are a lot of areas you can improve on to better yourself." << endl;   
    } else if (temp>=60.0) {
        cout << "D" << endl;
        cout << "Nearly acceptable, but not quite enough. You will need to put a lot more effort and time into your studies to pass the course." << endl;
    } else {
        cout << "F" << endl;
        cout << "Unfortunately not even close to passing. You'll need to dedicate much more effort to the class to even pass. You might be better off taking it again next semester." << endl;
    }

}