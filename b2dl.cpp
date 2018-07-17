// b2dl.cpp
// Brent Hayes, CISP 360
// 07-15-2018

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
// Specification A2 - No Globals

// Specification B5 - Function Prototype
int generalMenu(string, string, string);
void A161();
void A173();
void A159();
void A212();
int A13(bool);
void A290();
bool A232();
void A167();
void A100();
bool A1();
void endGame(bool, bool, bool, bool, bool, bool);

//main function
int main () {
    string userChoice;
    
    bool contFlag = true;
    while (contFlag) {
        int userA13choice = 0;
        //page flags
        bool flagA167 = false;
        bool flagA290 = false;
        bool flagA212 = false;
        bool flagA173 = false;
        bool flagA159 = false;
        //class flags
        bool flagDiplomat = false;

        //begin story

        flagA167 = A1();
        if (flagA167) {
            flagDiplomat = true;
            A167();
        } else {
            A100();
        }
        flagA290 = A232();
        if (flagA290 == true) {
            A290();
        } else {
            userA13choice = A13(flagDiplomat);
        }
        if (userA13choice!=0) {
            if (userA13choice == 3) {
                flagA212 = true;
                A212();
            } else if (userA13choice == 1) {
                flagA173 = true;
                A173();
            } else {
                flagA159 = true;
                A159();
            }
        }
        
        endGame(flagDiplomat, flagA167, flagA290, flagA212, flagA173, flagA159);
// Specification A3 - Game Loop
        while(true) {
            cout << "Would you like to return to the beginning of your adventure\? (Yes/No)" << endl;
            cin >> userChoice;
// Specification A4 - Accepts all variations of proper input (Upper/lower, Yes, ye, y, No, n)
            for(unsigned i = 0; i <= userChoice.length();i++) {
                userChoice[i] = tolower(userChoice[i]);
            }
            if ((userChoice.compare("yes")==0) || (userChoice.compare("ye")==0) || (userChoice.compare("y")==0)){
                cout << endl;
                break;
                
            } else if ((userChoice.compare("no")==0)||(userChoice.compare("n")==0)) {
                    contFlag = false;
                    break; 
            } else {
                cout << "Your input was not valid. Please type \"Yes\" or \"No\".\n";
            }

        }
    }  
}
// Specification B3 - General Menu
int generalMenu (string choice1, string choice2, string choice3) {
    string userString;
    int userChoice = 0; 
    while(true) {
// Specification C2 - Simple Menu
        if (choice1.compare("DONE")==0) {
            while(true) {
                cout << "Please type \"Done\" to finish your adventure." << endl;
                cin >> userString;
                for(unsigned i = 0; i <= userString.length();i++) {
                    userString[i] = toupper(userString[i]);
                }
                if((userString.compare("DONE")==0)) {
                    break;
                }
            }
            break;
        }
        if(choice2.empty()) {
            cout << "Please type " << choice1 << " to turn to page " << choice1 << endl;
        } else if (choice3.empty()) {
            cout << "Please type either " << choice1 << " or " << choice2 << endl;

        } else {
            cout << "Please type one of the following options:\n" << choice1 << ", " << choice2 << ", " << choice3 << endl;
        }
// Specification A1 - Input Validation
        cin >> userString;
        userString[0] = toupper(userString[0]);
        if (userString.compare(choice1)==0) {
            userChoice = 1;
            break;
        }
        if (userString.compare(choice2)==0) {
            userChoice = 2;
            break;
        } 
        if (userString.compare(choice3)==0) {
            userChoice = 3;
            break;
        }
        cout << "Invalid selection, please try again" << endl;  
    }
    return userChoice;
}
// Specification C1 - Individual Functions
void A161() {
    string sDONE = "DONE";
    string sNull;
    cout << "You move away from Haiken, whose hand still hovers uncertainly over the cutlery, to serve Mal rat heads. Finally Haiken makes a decision and picks up a carapace-cracking-spork. Mal chuckles at his ignorance. \"By Stygias, Captain - have you been in the field so long that you\'ve forgotten the basic functions of tableware\?\" Haiken grimaces. \"Pardon me, your Pettiness. I may have had a noble birth, yet life as a soldier puts me out of touch with certain niceties. We tend to eat with our hands.\" Mal laughs. \"Well, let us not stand on ceremony, Captain! I am happy to do it your way!\" Mal picks up a rat head with his hand and shovels it into his mouth. Haiken happily follows suit, munching and cracking skulls with his teeth. Inwardly, you give a sigh. No doubt with such messy fingers, Mal will stain the dragon bone. Why, you have often wondered, would anyone fashion a dining chair out of such easily blemished material as bleached porous bone\? Just as you fear, Mal leans back to rest his grubby mitts upon the armrests. The CHAIR IS DIRTY. You move back to the wall while your lords eat, to remain in waiting. A butler\'s work is never\n1. Done" << endl;
    generalMenu(sDONE, sNull, sNull);
}

void A173() {
    string sDONE = "DONE";
    string sNull;
    cout << "As they gnash away, Mal and Haiken discuss the Captain\'s recent raid on the town of Greenflower. \"Honestly,\" says Haiken, \"those wretched Brightlanders are so easily slaughtered, sometimes I almost feel bad for them.\" Mal laughs at this hilarious joke. \"Ha! That\'s a good one, Captain. But tell me, what of your primary objective\?\" \"I am pleased to report success, my lord.\" \"You have brought me a virgin\?\" \"She languishes in your dungeon even now - lovely, virtu- ous and ripe for sacrifice.\" \"Excellent. My skywatchers predict a full moon in three nights time - perfect conditions for the ceremony.\" Footsteps sound at the dining hall entrance, and a goblin messen- ger, whom you recognize as Peedy, enters wearing a feathered hat and carrying a scroll. Mal\'s gaze slides to him. \"What is it\?\" Peedy clears his throat. \"Apologies for the interruption, Your Atrocious- ness. I bring you word from Vorganis Castle.\" \"Oh\?\" Mal\'s tone is so instantly cold that the very temperature of the room seems to drop. \"Er... yes, my lord. Lord Nefarian accepts your kind invitation to attend the Stygias Ceremony, and intends to arrive tomorrow morn- ing.\" Mal\'s eyes narrow. You know he does not care for his cousin Nefarian, not least because the man is next in line to the throne. Ne- farian\'s presence at the ceremony, however, must be tolerated, for he is a powerful lord in his own right, with many allies amongst Noc- turnia\'s nobility - a fact which Mal does not enjoy being reminded of. \"Why bring me such news at lunch\?\" he growls. \"It has put a foul taste in my mouth and sullied my food.\" He drums his fingers on the dragon bone armrest, and fiery sparks flare at his fingertips. Peedy quails, for he knows that Mal is prone to taking out his anger on the bearers of bad news. It would be a shame, however (and a staffing issue), to lose a competent messenger to a moment of ill temper over something that really isn\'t his fault.\n1. Do you attempt to intercede on Peedy\'s behalf\?(Done) \n2. Or abandon him to his miserable fate\? (Done)" << endl;
    generalMenu(sDONE, sNull, sNull);
}
void A159() {
    string sDONE = "DONE";
    string sNull;
    cout << "You clear your throat and speak softly. \"That little one there is your rat-head-eating-fork, my lord.\" Despite your attempt to be sub- tle, Mal registers the exchange and chortles. Haiken, embarrassed to be found ignorant, frowns. \"I know what fork to use, you stupid butler! Begone before I stab you in the eye with it.\" With your lords served, you move back from the table to remain in waiting. Somehow you doubt Haiken\'s bedclothes will be properly turned.\n1. Done" << endl;
    generalMenu(sDONE, sNull, sNull);
}
void A212() {
    
    string sA161 = "A161";
    string sNull;
    cout << "You clear your throat very slightly, and Haiken glances up at you. As you move your hand back from his plate, you let your finger rest momentarily on the appropriate rat-head-eating fork. Haiken under- stands, and gives you a relieved look. Mal is too busy shoveling slug meat into his gullet to notice the exchange, so HAIKEN IS GRATE- FUL. You add some rat heads to Mal\'s plate and move back from the table to take a place in waiting. \n1. Nicely done, Mr Artanon. (turn to A161)" << endl;
    generalMenu(sA161, sNull, sNull);
    A161();
}
int A13(bool flagDiplomat) {
    cout << "Feeling dangerous, Mr Artanon\? You move past Mal to Captain Haiken and, using a pair of tongs fashioned to look like crow\'s claws, start placing rat heads onto his plate. As you do, you glance surrep- titiously at Mal, wondering if you have irritated him by serving his guest first - he is not exactly known for his good manners - but he does not seem to have noticed. At any rate, your first footman, Kalag - a young man who shows much promise - hops to action, to lay sliv- ers of slug meat on Mal\'s plate. \"Er...\" says Haiken, his meaty hand skimming the tableware. You realize he is uncertain about what, amongst the array of cutlery laid out on either side of his plate, is the correct implement to use for rat heads." << endl;
    int userChoice = 0;
    string sA212 = "A212";
    string sA173 = "A173";
    string sA159 = "A159";
    string sNull;
// Specification B4 - Valid choices only
    if (flagDiplomat) {
        cout << "1. Are you a DIPLOMAT?" << endl;
        generalMenu(sA212, sNull, sNull);
        userChoice = 3;
    } else {
        cout << "2. If not, do you simply inform him which is the proper rat-head- eating-fork\? (turn to A159)\n3. Or do you let him flounder\? (turn to A173)" << endl;
        userChoice = generalMenu(sA173, sA159, sNull);
    }
    return userChoice;
}
void A290() {
    string sA161 = "A161";
    string sNull;
    cout << "As is only fitting, you serve your master first. As you place the largest and juiciest rat heads before him, your first footman Kalag - a young fellow who shows much promise - moves to Haiken and starts laying slug meat on his plate. \"Er,\" says Haiken, \"not too much slug for me, thank you - I have an allergy.\" Mal, who is in mid-chew, scoffs, and shoots a shard of half-chewed rat skull out of his nostril to ping off a wine glass. \"Rut me, Haiken,\" he says. \"I\'ve seen you rip the throat from a charging horse, yet you can\'t stomach a little slug\?\" Haiken seems embarrassed. \"They give me hives, my lord.\" \"Ha! Well, better get over there with some of his precious rat heads, Mr Artanon.\" You do as you are bid, and place the remaining rat heads on Haiken\'s plate. They are a little on the smaller side, and you notice a wistful look in Haiken\'s eye as Mal lifts another plump one to his mouth. With your lords served, you move back from the table to remain in waiting.\n1. Excellent posture, Mr Artanon. (turn to A161)" << endl;
    generalMenu(sA161, sNull, sNull);
    A161();
}
bool A232() {
    
    bool flag290 = false;
    int userChoice = 0;
    string sA290 = "A290";
    string sA13 = "A13";
    string sNull;

    cout << "You overtake the footmen along a corridor lit by stuttering can- dles, and lead them through a wide archway into the airy dining hall. Great windows stand open along one wall, looking out upon a pleas- ant view of circling lizard-birds cannibalizing their young. Down the length of the hall runs an immense marble table, at the head of which the Dark Lord Malacandros reclines in a chair of elaborately carved dragon bone. He is a gaunt man with darting eyes and sharp features, currently dressed in a very tasteful grey robe (which you helped him get into this morning), his black hair clasped in a pony- tail down his back. To his right sits Captain Haiken, one of his fa- vored brutes, a well muscled orc in polished steel. \"Ah, Mr Artanon,\" says Mal, \"I was beginning to worry we\'d been forgotten.\" He gives you a thin smile, which warns you he is very close to becoming irked. You bow deeply. \"My humble apologies, oh Intolerant One. Repugnis is putting the final touches on today\'s main course, and you know what a perfectionist he is. In the meantime,\" you whisk a platter from one of the footmen, \"here are some starters to whet your appetites.\" As you move toward the head of the table, Haiken licks his lips. \"Rat heads!\" he exclaims. \"My favorite.\"Who will you serve first\? \n1. The enthusiastic Captain Haiken\? (turn to A13) \n2. Or your master, Malacandros\? (turn to A290)";
    userChoice = generalMenu(sA290, sA13, sNull);
    if(userChoice == 1) {
        flag290 = true;
    }
    return flag290;  
}
void A167() {
    string sA232 = "A232";
    string sNull;
    cout << "Repugnis nods eagerly, which ripples his many chins. \'Yes sir, of course! Let me see now...\' He glances around and spots a bench where several platters are being assembled. \'Ah! How about some pickled rat heads and delectable carpaccio of slug\?\' \'Very good,\' you say. \'I am told that Captain Haiken is particularly partial to rat. But see that you hurry along now, Repugnis. I don\'t need to remind you that his lordship\'s patience is virtually non-existent.\' \'Of course, sir, of course.\' You click your fingers at some waiting footmen and they leap to action, seizing the platters and heading for the door. It seems you are a DIPLOMAT.\n1. Onwards, Mr Artanon. (turn to A232)" << endl;
    generalMenu(sA232, sNull, sNull);
}
void A100() {
    string sA232 = "A232";
    string sNull;
    cout << "Repugnis turns a paler shade of green, and gulps. \"I beg you, Mr Artanon, stay your hand. I\'m sure that something must be ready.\" The cook glances around and spots a bench at which several trays are being assembled. \"Ah!\" he says. \"How about some pickled rat heads and carpaccio of slug\?\" You scowl, long enough to make Repugnis quiver, then turn and snap at some lurking footmen. \"Get those trays up to his lordship without delay!\" The footmen spring into action, seizing the trays and heading for the door. \"Thank you, sir,\" says Repugnis. \"The roast will not be far behind, I promise.\" \"See that it isn\'t,\" you reply, \"or the next item on the menu might be goblin stew.\" It seems you are an INTIMIDATOR.\n1. Onwards, Mr Artanon. (turn to A232)" << endl;
    generalMenu(sA232, sNull, sNull);
}
bool A1() {
    bool flag167 = false;
    int userChoice = 0;
    string sA167 = "A167";
    string sA100 = "A100";
    string sNull;

    cout << "Well, Mr Artanon, look at you. Who would have thought that the son of a lowly spider farmer could rise to such esteemed heights\? Yet here you are, standing in the kitchens of Cayfax Castle, dressed in the finest livery onyx can buy. For you, sir, are butler to Malacandros, Dark Lord of all Nocturnia. The flames of fireplaces tickle suspended pots, which thicken the air with competing scents. Workers along stone benches busily chop and kill ingredients - nothing but the best for his lordship, of course. In the centre of the chamber a great oven blazes, its cracked chimney oozing smoke. \'Ah, Mr Artanon,\' simpers Repugnis, the head cook. He\'s a fat goblin who samples too many of his own creations, as evidenced by his bulging belly and the delta of stains down his apron. \'I\'m roasting his Horrendousness a prime briar beast basted in snake oil. Mmm-mmm! The intestines are stuffed with rotten apple and breadcrumb, and I\'ve shoved a carrot up its arse.\' You arch an eyebrow, for Mal is already situated upstairs in the dining hall. With midday waning, he will be growing hungry. \'And just how long,\' you ask, \'do you intend to keep his lordship staring at an empty plate\?\' Repugnis titters nervously, and glances towards the oven. \'Good sir, a roast takes as long as a roast takes. If I stoke the flames any hotter the skin will crisp to charcoal. At best I could aim for a rare cut\?\' What is your reply\? 1. \'It\'s you who\'ll get a rare cut across that corpulent neck of yours if you don\'t speed things along, you feckless blob of festering lard.\' (turn to A100)2. \'Surely in such an industrious kitchen, there must be a starter or two ready to send along and sate His Abhorentness\'s appetite\?\' (turn to A167)" << endl;
    userChoice = generalMenu(sA167, sA100, sNull);
    if(userChoice == 1) {
        flag167 = true;
    }
    return flag167;  
}
void endGame(bool flagDiplomat, bool flagA167, bool flagA290, bool flagA212, bool flagA173, bool flagA159) {
// Specification B1 - Booleans
    cout << "\nCurrent State of boolean variables:\n";
    cout << "Diplomat: " << flagDiplomat << endl;
    cout << "A167 Flag: " << flagA167 << endl;
    cout << "A290 Flag: " << flagA290 << endl;
    cout << "A212 Flag: " << flagA212 << endl;
    cout << "A173 Flag: " << flagA173 << endl;
    cout << "A159 Flag: " << flagA159 << endl;

// Specification B2 - Path
    cout << "\nRoute taken:\n";
    if (flagA167) {
        cout << "A1-> A167-> A232-> ";
    } else {
        cout << "A1-> A100-> A232-> ";
    }
    if (flagA290) {
        cout << "A290-> A161\n";
    } else {
        cout << "A13-> ";
    }
    if (flagA212) {
        cout << "A212-> A161\n";
    }
    if (flagA173) {
        cout << "A173\n";
    }
    if (flagA159) {
        cout << "A159\n";
    }
   

}


