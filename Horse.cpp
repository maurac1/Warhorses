// File: Horse.cpp
// Author: Maura Choudhary
// Date: 4/13/19
// Section: 4
// E-mail: maurac1@gl.umbc.edu
// Description: This is the class for a warhorse.

#include "Horse.h"

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: A horse is created
Horse::Horse(){

  srand(time(NULL));
}

// Overloaded Constructor
// Preconditions: Valid inputs (
// Postconditions: None
Horse::Horse(string name, Size s, int health, int speed){
  m_name = name;
  m_size = s;
  m_health = health;
  m_speed = speed;
  m_training = UNTRAINED;
}

// Destructor - virtual (implement in child classes)
// Preconditions: Horse object in memory
// Postconditions: Deallocates horse object in memory
// Implemented in Child classes

// getName() - returns the name of horse
// Preconditions: m_name is set
// Postconditions: Deallocates horse oject in memory
string Horse::getName(){
  return m_name;
}

// getSize() - returns the size of horse
// Preconditions: m_size is set
// Postconditions: returns an enumSize referring to the size of the horse
Size Horse::getSize(){
  return m_size;
}

// getHealth() - returns the health of horse
// Preconditions: m_health is set
// Postconditions: returns an int referring to health from (1 - MAX_HEALTH)
int Horse::getHealth(){
  return m_health;
}

// getSpeed() - returns the speed of the horse
// Preconditions: m_speed is set
// Postconditions: returns an int referring to speed from (1 - MAX_SPEED)
int Horse::getSpeed(){
  return m_speed;
}

// getTraining() - returns the training level of horse
// Preconditions: m_training is set
// Postconditions: returns an enum Training referring to training level of the horse
Training Horse::getTraining(){
  return m_training;
}

// setHealth() - updates the health of the horse
// Preconditions: m_health is set
// Postcondiitons: updates m_health
void Horse::setHealth(int health){
  m_health = health;
}

// increaseTraining() - increase training by one, up to max
// Preconditions: all variables are set valid
// Postconditions: returns a bool (true if increased, false if at max)
bool Horse::increaseTraining(){

  int max = MAX_TRAINING;
  int myTraining = m_training;
  if(myTraining < max){
    m_training = Training(m_training + 1);
    return true;
  }else{
    return false;
  }

  // default
  return false;
}

// specialize() - Attemtps to convert an Untrained horse to a war horse
//                (light, medium, or heavy)
//                Only Untrained type of horses can be specialized
// Preconditions: all variables are set valid
// Postcondiitons: returns a pointer to a new warhorse or NULL
Horse* Horse::specialize(){

  return nullptr;
}

// attack(string, int) - Virtual function for light/medium/heavy to attack
// Preconditions: all variables are set valid
// Postconditions: Child class will return the number of points of damage
// Implemented in Child classes

// train() - Test if horse was successfully trained
// Preconditions: all variables are set valid
// Postconditions: returns a bol of whether horse trained or not
// Implemented in Child classes


// battle() - Sends a horse to battle another horse
// Preconditions: all variables are set valid
// Postconditions: returns a bool of whether horse won the battle or not
bool Horse::battle(Horse* h){

  return false;
}

// Overloaded << - Prints the details of a horse
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of horse
ostream& operator<<(ostream& output, Horse& h){

  output  << setw(20) << h.getName() << '\t' << h.toString() << "\t\t"
       << h.getHealth() << '\t' << h.getSpeed() << '\t'
       << h.trainingString(h.getTraining()) << endl;
  return output;
}

// toString() - a string representation of the horse
// Preconditions: all variables are set valid
// Postconditions: returns a string describing the horse
// Implemented in Child classes

// randomPercentBased (Helper function)
// Precondition: Given int to "pass"
// Description: This function is used to see if a certain random event occurs
//              A random number 1-100 is compare to the int passed
//              If the random number is less than the passed value, return true
//              Else return false (30 = 30%, 70 = 70%)
// Postcondition: Returns boolean
bool Horse::randomPercentBased(int passNum){

  // generate a random number from 1-100
  int random = (rand() % 100) + 1;
  if(random < passNum){
    return true;
  }else{
    return false;
  }

  // default return statement
  return false;
}

// trainingString() - a string representation of a training level enum
// UNTRAINED = 0, SADDLE = 1, GREEN = 2, INTERMEDIATE = 3, EXPERT = 4, MASTER = 5
// Preconditions: Pass a training level to the function
// Postconditions: Returns the string of the enum
string Horse::trainingString(Training t){
  switch(t){

  case UNTRAINED:
    return "Untrained";
    break;
    
  case SADDLE:
    return "Saddle";
    break;
    
  case GREEN:
    return "Green";
    break;
    
  case INTERMEDIATE:
    return "Intermediate";
    break;
    
  case EXPERT:
    return "Expert";
    break;
    
  case MASTER:
    return "Master";
    break;
  }

  // default return
  return "Not a valid training";
}
