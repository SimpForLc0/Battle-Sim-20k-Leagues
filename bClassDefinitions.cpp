#include <iostream>
#include <string>
#include "battleClasses.hpp"
//create new files as/when needed

using namespace std;

//Students On Sub
studentHP::studentHP(string newStuName, string newStuHouse, string newStation)
: stuName(newStuName), stuHouse(newStuHouse), station(newStation) {}

void studentHP::reAssign(string setNewStation) {
  station = setNewStation;
}

string studentHP::getStuName() {
  return stuName;
}

string studentHP::getStuHouse() {
  return stuHouse;
}

string studentHP::getStation() {
  return station;
}

//Battle Simulator

battleSim::battleSim(string setObjName, string newStatus, int newObjHealth)
: simObjName(setObjName), lifeStatus(newStatus), objHealth(newObjHealth) {}

battleSim::~battleSim() {}

void battleSim::setObjHealth(int setHealth) {
  objHealth = setHealth;
}

void battleSim::setStatus(string setNewStatus) {
  lifeStatus = setNewStatus;
}

void battleSim::addHealth(int addMoreHealth) {
  objHealth += addMoreHealth;
}

void battleSim::subtractHealth(int subtrHealth) {
  objHealth -= subtrHealth;
}

void battleSim::disable(bool able) {
  disabled = able;
}

void battleSim::addShield(int shieldHP) {
  shieldAmount += shieldHP;
}

void battleSim::setShield(int setNewShield) {
  shieldAmount = setNewShield;
}

int battleSim::getHealth() {
  return objHealth;
}

string battleSim::getStatus() {
  return lifeStatus;
}

string battleSim::getObjName() {
  return simObjName;
}

bool battleSim::getDisabled() {
  return disabled;
}

int battleSim::getShields() {
  return shieldAmount;
}
