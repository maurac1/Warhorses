// File: Untrained.cpp
// Author: Maura Choudhary
// Date: 4/14/19
// Section: 4
// E-mail: maurac1@gl.umbc.edu
// Description: This is the code for the Untrained horses class.

#include "Untrained.h"
#include "Horse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"

#include <string>
#include <cstdlib>

using namespace std;

// Default Constructor
// Precondiitons: None
// Postconditions: None
Untrained::Untrained(){

}

// Overloaded Constructor
// Preconditions: Valid inputs
// Post conditions: None
Untrained::Untrained(string name, Size s, int health, int speed):Horse( name, s, health, speed){
  
}

// specialize() - if a horse successfully produces specializes it is replaced
//                by a corresponding warhorse
// Preconditions: all variables are set valid
// Postconditions: returns a pointer to a new warhorse or NULL
Horse* Untrained::specialize(){

  Size size = getSize();

  // create a new horse based on the size and return the horse pointer
  if(size == SMALL){
    Horse* lightHorse = new Light(getName(), SMALL, getHealth(), getSpeed());
    return lightHorse;
  }else if(size == MEDIUM){
    Horse* mediumHorse = new Medium(getName(), MEDIUM, getHealth(), getSpeed());
    return mediumHorse;
  }else if(size == LARGE){
    Horse* heavyHorse = new Heavy(getName(), LARGE, getHealth(), getSpeed());
    return heavyHorse;
  }
  return nullptr;
}

// train() : attempts to train an untrained horse
// Preconditions: all variables are set valid
// Postconditions: says that horses cannot be trained
bool Untrained::train(){

  cout << "You can't train an untrained horse." << endl;
  return false;
}

// toString() - a string representation of the untrained horse
// Preconditions: all variables are set valid
// Postconditions: returns a string describing the horse
string Untrained::toString(){
  return "Unknown";
}

// attack(string, int) - only light, medium, and heavy can attack
// Preconditions: target passed and health of attacker
// Postconditions: displays that untrained horses can't attack
int Untrained::attack(string target, int attackerHealth){

  cout << "Untrained horses can't attack." << endl;
  return -1;
}
