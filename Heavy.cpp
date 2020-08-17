// File: Heavy.cpp
// Author: Maura Choudhary
// Date: 4/15/19
// Section: 4
// E-mail: maurac1@gl.umbc.edu
// Description: This is the code for a Heavy warhorse.

#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "Heavy.h"
#include "Warhorse.h"

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: None
Heavy::Heavy(){

}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Heavy::Heavy(string name, Size s, int health, int speed):Warhorse(name, s, health, speed){

}

// attack(string, int) - Returns amount of damage from attack
// Damage is calculated as health/6 + traiing level (0-5)
// Also, displays actual attack
// Finally, the heavy warhorse calls kick from attack (special attack for heavy)
// Preconditions: passed string name of target and attacker's health
// Postconditions: returns damage as integer
int Heavy::attack(string targetName, int health){

  int damage = (health/6) + getTraining();
  cout << "The heavy warhorse " << getName() << " hits " << targetName << endl;
  int kickDamage = kick();
  damage += kickDamage;
  return damage;
}

// toString() - a string representation of the child class
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the subclass (return "Heavy")
string Heavy::toString(){
  return "Heavy";
}

// kick() - a special attack by heavy warhorses
// Preconditions: all variables are set valid
// Postconditions: returns an int between 1 and 3 of additional damage
int Heavy::kick(){
  int kickDamage = (rand() % 3) + 1;
  cout << "The heavy warhorse spins and kicks the enemy!" << endl;
  return kickDamage;
}
