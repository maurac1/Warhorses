// File: Medium.cpp
// Author: Maura Choudhary
// Date: 4/15/19
// Section: 4
// E-mail: maurac1@gl.umbc.edu
// Description: This is the code for a Medium warhorse.

#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "Medium.h"
#include "Warhorse.h"

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: None
Medium::Medium(){

}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Medium::Medium(string name, Size s, int health, int speed):Warhorse(name, s, health, speed){

}


// attack(string, int) - Returns amount of damage from attack
// Damage is calculated as health/6 + traiing level (0-5)
// Also, displays actual attack
// Preconditions: passed string name of target and attacker's health
// Postconditions: returns damage as integer
int Medium::attack(string targetName, int health){

  int damage = (health/6) + getTraining();
  cout << "The medium warhorse " << getName() << " hits " << targetName << endl;
  return damage;
}

// toString() - a string representation of the child class
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the subclass (return "Light")
string Medium::toString(){
  return "Medium";
}
