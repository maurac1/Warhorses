// File: Warhorse.cpp
// Author: Maura Choudhary
// Date: 4/15/19
// Section: 4
// E-mail: maurac1@gl.umbc.edu
// Description: This is the class for a Warhorse

#include "Warhorse.h"
#include "Horse.h"
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: None
Warhorse::Warhorse(){

}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Warhorse::Warhorse(string name, Size s, int health, int speed):Horse(name, s, health, speed){

}

// train() - Gives a 50% chance of increasing training up to maximum.
// Precondiitons: all variables are set valid
// Postconditions: returns true if successfully trained
bool Warhorse::train(){

  // if the random number is less than 50
  if(randomPercentBased(50)){

    // if the horse was successfully trained
    if(increaseTraining()){
      cout << "Your horse was successfully trained." << endl;
      cout << endl;
      return true;
      
    }else{
      cout << "Your horse was not successfully trained." << endl;
      cout << endl;
      return false;
      
    }   
  }else{
    cout << "Your horse was not successfully trained." << endl;
    cout << endl;
    return false;
    
  }
  
}

// toString() - purely virtual
// Preconditions: all variables are set valid
// Postconditions: IMPLEMENTED IN SUBCLASES

// battle(Horse*) - passed enemy horse
// turns are based on speed - counter starts at 0 and if counter % speed = 0
// then that horse attacks. If attack leaves at or below 0 then that horse
// loses the battle
// Preconditions: enemy horse has been defined
// Postconditions: returns a bool of who won battle between two horses
bool Warhorse::battle(Horse* enemyHorse){

  // create necessary temporary variables
  int myHealth = getHealth();
  int enemyHealth = enemyHorse->getHealth();
  string myName = getName();
  string enemyName = enemyHorse->getName();

  // check if the horse is ready for battle
  if(getTraining() < SADDLE){
    cout << "This horse is not yet ready for battle." << endl;
    return false;
  }else{
    int counter = 0;
    // user's horse attacks first
    // enemyHealth = enemyHealth - attack(enemyName, myHealth);
    
    // while the neither horse has died
    while(myHealth > 0 && enemyHealth > 0){

      // user attacks FIRST
      if(counter % getSpeed() == 0){
	enemyHealth = enemyHealth - attack(enemyName, myHealth);
      }

      // enemy horse attacks
      if(counter % enemyHorse->getSpeed() == 0){
	myHealth = myHealth - enemyHorse->attack(myName, enemyHealth);
      }

      counter++;
    }

    // if user's horse died
    if(myHealth <= 0){
      cout << "Your horse perished in the battle" << endl;
      return false;
      
    }else{ //enemy horse died
      cout << "Congrats you won!" << endl;
      return true;
    }
  }
}

// attack(string, int) - purely virtual (IMPLEMENTED IN CHILD CLASSES)
