#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "battleClasses.hpp"

using namespace std;

studentHP ana("ANA DAKKAR", "DOLPHIN", "BRIDGE"),
dev("DEV DAKKAR", "SHARK", "NULL"),
gem("GEMINI TWAIN", "SHARK", "BRIDGE"),
hal("HALIMAH NASSER", "DOLPHIN", "BRIDGE"),
lee("LEE-ANN BEST", "DOLPHIN", "BRIDGE"),
vir("VIRGIL ESPARZA", "DOLPHIN", "BRIDGE"),
jack("JACK WU", "DOLPHIN", "BRIDGE"),
jup("JUPITER", "ORIGINALLY STATIONED ON LINCOLN BASE", "KITCHEN"),
nel("NELINHA DA SILVA", "CEPHALOPOD", "ENGINE ROOM"),
fra("FRANKLIN COUCH", "ORCA", "MEDBAY"),
dru("DRU CARDENAS", "SHARK", "WEAPONS BAY"),
rob("ROBBIE BARR", "CEPHALOPOD", "ENGINE ROOM"),
coop("COOPER DUNNE", "SHARK", "WEAPONS BAY"),
kiya("KIYA JENSEN", "SHARK", "WEAPONS BAY"),
elo("ELOISE MCMANNS", "SHARK", "WEAPONS BAY"),
lin("LINZIE HUANG", "ORCA", "MEDBAY"),
tia("TIA ROMERO", "CEPHALOPOD", "ENGINE ROOM"),
mead("MEADOW NEWMAN", "CEPHALOPODS", "STAND-BY"),
kay("KAY RAMSAY", "CEPHALOPODS", "ENGINE ROOM"),
est("ESTER HARDING", "ORCA", "ADVISOR"),
rhys("RHYS MORROW", "ORCA", "MEDBAY"),
brig("BRIGID SALTER", "ORCA", "MEDBAY");

studentHP Students[] = {ana, dev, gem, hal, lee, vir, jack, jup, nel, fra, dru, rob, coop, kiya, elo, lin, tia, mead, kay, est, rhys, brig};

battleSim nautilus("THE NAUTILUS", "ALIVE", 100), aro("THE ARONNAX", "ALIVE", 100);//STATUS: FULLY OPERATIONAL

string action;
string enemyAction;
string enemyWeapon;
int enemyActionNum;
int enemyWeaponNum;

int didUserHit;
int didEnemyHit;
int whoDied;
bool enemyDisabled = false;

string lowercase(string toLower);

void viewRoom();
//SIMULATION
string simStart;
void startSim(battleSim firstSimObj, battleSim secSimObj);

//BATTLE START if take damage random number decides who goes to medbay
void startBattle(battleSim SimObjectOne, battleSim SimObjectTwo);//add shields and weapons
//ENEMY ATTACK
void enemysAction(battleSim SimObjOne, battleSim SimObjTwo);
//--------------------------------------------------------------------
int main() {

  srand(time(NULL));
  
  nautilus.disable(false);
  aro.disable(false);

  enemyActionNum = rand() % 3;//0, 1 ,2;
  /*if(enemyActionNum == 0) {
    enemyAction = "ATTACK";
  } else if(enemyActionNum == 1) {
    enemyAction == "DEFEND";
  } else {
    enemyAction == "EVADE";
  }*/ enemyAction = "ATTACK";
  if(enemyAction == "EVADE") {
    didUserHit = rand() % 2;
  } else {
    didUserHit = rand() % 3;
  }
  enemyWeaponNum = rand() % 7;
  if(enemyWeaponNum == 0 || enemyWeaponNum == 1 || enemyWeaponNum == 2 || enemyWeaponNum == 3) {
    enemyWeapon = "Leyden Cannons";
  } else if(enemyWeaponNum == 4 || enemyWeaponNum == 5) {
    enemyWeapon == "Torpedo";
  //} else {not coded yet
    //enemyWeapon = "Cold-Fusion Torpedo";
  //}
  didEnemyHit = (rand() % 2) + 1;//might need to redefine in funcs (1/2)
  whoDied = rand() % 22;//torpedo will take out multiple
  enemyDisabled = false;//leyden cannons will disable shields;
//TOUR THE NAUTILUS
  cout << endl << "WELCOME TO THE NAUTILUS" << endl << endl;
  cout << "BRIDGE\nWEAPONS BAY\nENGINE  ROOM\nMEDBAY\nLIBRARY\nKITCHEN\nBEDROOM\nSTORAGE\n\n";
 
  viewRoom();
  //simulation start (somewhere around here)
  cin.ignore();
  getline(cin, simStart);
  cout << endl;
  if(simStart == "START SIM" || simStart == "START" || simStart == "YES") {
    if(Students[name::ana].getStation() == "BRIDGE" && Students[name::gem].getStation() == "BRIDGE" && Students[name::hal].getStation() == "BRIDGE" && Students[name::lee].getStation() == "BRIDGE" && Students[name::vir].getStation() == "BRIDGE" && Students[name::jack].getStation() == "BRIDGE") {
      startSim(nautilus, aro);
    } else {
      cout << "REASSIGNING STUDENTS TO BRIDGE..." << endl << endl;
      Students[name::ana].reAssign("BRIDGE");
      Students[name::gem].reAssign("BRIDGE");
      Students[name::hal].reAssign("BRIDGE");
      Students[name::lee].reAssign("BRIDGE");
      Students[name::vir].reAssign("BRIDGE");
      Students[name::jack].reAssign("BRIDGE");
      startSim(nautilus, aro);
    }
    startBattle(nautilus, aro);
    enemysAction(nautilus, aro);
  }
}
//=================================================================
string lowercase(string toLower) {
  string blank = toLower;
  string lowerInput = "";
  char array[blank.length()];
  strcpy(array, blank.c_str());
  char newChar;

  for(int i = 0; i < blank.length(); i++) {
    array[i] = tolower(array[i]);
  } lowerInput = array;
  return lowerInput;
}
//-----------------------------------------------------------------

void viewRoom() {
  string choice;

  getline(cin, choice);
  cout << endl;
  for(int i = 0; i < 22; i++) {
    if(Students[i].getStation() == choice) {
      cout << Students[i].getStuName() << endl;
    }
  }
  string back;
  cin >> back;
  if(back == "BACK" || back == "back") {
    //cout << endl << "WELCOME TO THE NAUTILUS" << endl << endl;
    cout << endl << "BRIDGE\nWEAPONS BAY\nENGINE ROOM\nMEDBAY\nLIBRARY\nKITCHEN\nBEDROOM\nSTORAGE\n\n";
    cin.ignore();
    viewRoom();
  } else if(back == "END" || back == "end") {
      cout << "START SIM?" << endl;
  }
}
//--------------------------------------------------------------------

void startSim(battleSim firstSimObj, battleSim secSimObj) {
  if(firstSimObj.getStatus() == "ALIVE" && secSimObj.getStatus() == "ALIVE") {
    cout << "VESSEL: " << firstSimObj.getObjName() << endl << "STATUS: " << firstSimObj.getStatus() << endl << "HEALTH: " << firstSimObj.getHealth() << endl << endl << "VS." << endl << endl << "VESSEL: " << secSimObj.getObjName() << endl << "STATUS: " << secSimObj.getStatus() << endl << "HEALTH: " << secSimObj.getHealth() << endl << endl;
  }
}
//--------------------------------------------------------------------
void enemysAction(battleSim SimObjOne, battleSim SimObjTwo) {
  if(enemyAction == "ATTACK" && lowerInput != "evade") {
    didEnemyHit = (rand() % 3) + 1;
    cout << didEnemyHit << endl;
    if(enemyWeapon == "Leyden Cannons") {
      cout << "ENEMY FIRED LEYDEN CANNONS..." << endl;
      if(didEnemyHit == 1 || didEnemyHit == 2) {
        cout << "DAMAGE TO HULL SUSTAINED!" << endl;
        SimObjOne.subtractHealth(24);
      } else {
        cout << "ENEMY MISSED!" << endl; 
      }
    } else if(enemyWeapon == "Torpedo") {//40-50 damage
      cout << "INCOMING TORPEDO!!!" << endl;
      if(didEnemyHit == 1 || didEnemyHit == 2) {
        cout << "HEAVY DAMAGE SUSTAINED!" << endl;
        SimObjOne.subtractHealth(50/*40*/);
        //for() knock out 2-3 people;
      } else {
        cout << "TORPEDO AVOIDED" << endl;
      }
    }
  } else if(enemyAction == "ATTACK" && lowerInput == "evade") {
      didEnemyHit = (rand() % 4) + 1;
      cout << didEnemyHit << endl;
      if(enemyWeapon == "Leyden Cannons") {
        cout << "ENEMY FIRED LEYDEN CANNONS..." << endl;
        if(didEnemyHit == 2) {
          cout << "DAMAGE TO HULL SUSTAINED!" << endl;
          SimObjOne.subtractHealth(24);
        } else {
          cout << "ENEMY MISSED!" << endl; 
        }
     } else if(enemyWeapon == "Torpedo") {
       cout << "INCOMING TORPEDO!!" << endl;
       if(didEnemyHit == 3) {
         cout << "HEAVY DAMAGE SUSTAINED!" << endl;
         SimObjOne.subtractHealth(50/*40*/);
       } else {
         cout << "TORPEDO EVADED" << endl;
       }
     }
  }
  cout << SimObjOne.getObjName() << ": " << SimObjOne.getHealth() << "HP" << endl;
}
//--------------------------------------------------------------------
void startBattle(battleSim SimObjectOne, battleSim SimObjectTwo) {
  string weaponToUse;
  bool useLFrost = false;
  string shieldInput;
  string evadeInput;
  int damageDealt = 0;
  SimObjectOne.setShield(0);//need these called independently
  SimObjectTwo.setShield(0);
  
  
  cout << "Choose an action:" << endl << "ATTACK" << endl << "DEFEND" << endl << "EVADE" << endl << endl;
  
  cin >> action;
  lowerInput = lowercase(action);
  if(lowerInput == "attack") {
    cout << "Choose a weapon:" << endl << "Leyden Cannons" << endl << "Torpedoes" << endl << endl;
    cin.ignore();
    getline(cin, weaponToUse);
    if(weaponToUse == "LEYDEN CANNONS" || weaponToUse == "Leyden Cannons") {
      damageDealt += 20;
      for(int o = 0; o < 22; o++) {
        if(Students[o].getStation() == "WEAPONS BAY") {
          damageDealt += 1;
        }
      }
      if(didUserHit != 0) {
        SimObjectTwo.subtractHealth(damageDealt);
        cout << SimObjectTwo.getObjName() << ": " << SimObjectTwo.getHealth() << "HP" << endl;
      } else {
        cout << "MISSED" << endl;
      }
    }
  } /*else if(lowerInput == "defend") {

  } else if(lowerInput == "evade") {
add an escape with Cav Drive later
  }*/
}
