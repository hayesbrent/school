// acdt.cpp
// Brent Hayes, CISP 360
// 07-02-2018
//change linux VS change

#include <iostream>
#include <string>

using namespace std;

// Specification A3 - Modularized the program
char userInputVerify() {
  char YNVerifier;
  bool tempFlag = true;
  while(tempFlag == true){
    cin >> YNVerifier;
    if(tolower(YNVerifier)=='y') {
      tempFlag = false;
    } else if(tolower(YNVerifier) == 'n') {
      tempFlag= false;
    } else {
      cout << "Invalid input, please respond with 'Y' or 'N'\n";
    }
  }
  return YNVerifier;
}

void engineTree() {
  char tempChoice;
  cout << "Are you airborne? (Y/N)\n";
  tempChoice = userInputVerify();
  if (tempChoice == 'y') {
    cout << "Is the electrical system working? (Y/N)\n";
    tempChoice = userInputVerify();
    if(tempChoice == 'y') {
      cout << "Has the engine stopped running? (Y/N)\n";
      tempChoice = userInputVerify();
      if(tempChoice == 'y') {
        cout << "Are you over the mountains? (Y/N)\n";
        tempChoice = userInputVerify();
        if(tempChoice == 'y') {
          cout << "Are you flying at night? (Y/N)\n";
          tempChoice = userInputVerify();
          if(tempChoice == 'y') {
            cout << "Turn on the landing light and look out the window.\nDo you like what you see? (Y/N)\n";
            tempChoice = userInputVerify();
            if(tempChoice == 'y') {
              cout << "Make Emergency Landing.\n";
            } else {
              cout << "Turn off the Landing Light.\n";
            }

          } else {
            cout << "Make emergency landing.\n";
          }
      } else {
        cout << "Are you over water? (Y/N)\n";
        tempChoice = userInputVerify();
        if(tempChoice == 'y') {
          cout << "Inflate your life vest, make emergency landing.\n";
        } else {
          cout << "Make emergency landing on a road.\n";
        }
      }
    } else {
      cout << "Is the outside air temperature < 32 degrees? (Y/N)\n";
      tempChoice = userInputVerify();
      if(tempChoice == 'y') {
        cout << "Turn on Carburator Heat.\n";
      } else {
        cout << "Switch to other fuel tank.\n";
      }
    }

    } else {
      cout << "Turn on the Master Switch.\n";
    }
  } else {
    cout << "Have a drink and call a mechanic.\n";
  }

}
//Specification - A1 de-icing range check
void inFlightIcing() {
  double userIce = 0.0;
  cout << "How much ice is located on the wing? (0-10mm)\n";
  cin >> userIce;
  if(userIce<1.0) {
    cout << "Use 5% power.\n";
  } else if (userIce<=5.0) {
    cout << "Use 20% power.\n";
  } else if (userIce<=9.0) {
    cout << "Use 65% power.\n";
  } else if (userIce <=10.0) {
    cout << "Use 100% power.\n";
  } else {
    cout << "Enter a valid range please.";
  }

}

int main() {
  bool flag = true;
  char menuChoice;


  while(flag==true) {
    cout << "Hello Pilot, you have activated H.E.L.P.eR. what issue can I give you advice on?\n";
    cout << "C - Communications Failure\nE - Engine Failure\nI - In-flight Icing\nQ - Quit the program\n";
    cin >> menuChoice;
    // Specification A2 - Upper and Lower Case
    // Specification B1 - Main Menu with characters
    switch(tolower(menuChoice)) {
      // Specification C1 - communications
      case 'c':
      cout << "Switch to Alternate Radio";
        break;
      case 'e':
      // Specification C2 - engine failure tree
        engineTree();
        break;
      case 'i':
        // Specification C3 - inflight icing
        inFlightIcing();
        break;
      case 'q':
        // Specification C4 - Quit program
      flag = false;
        break;
        // Specification B2 - Main Menu Data Entry Check
      default:
        cout << "Invalid data entry. Terminating Program.\n";
        flag = false;

    }
    cout << endl;
  }
}
