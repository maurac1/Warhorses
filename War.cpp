// File: War.cpp
// Author: Maura Choudhary
// Date: 4/15/19
// Section: 4
// E-mail: maurac1@gl.umbc.edu
// Description: This is the code for a War class.

#include "War.h"
#include "Horse.h"
#include "Warhorse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

// Menu Constants
const int DISPLAY_FRIENDLY = 1;
const int DISPLAY_ENEMY = 2;
const int ACQUIRE = 3;
const int TRAIN = 4;
const int BATTLE = 5;
const int QUIT = 6;

// Function prototype for helper function
int generateRandom(int, int);

// Default Constructor
// Preconditions: None
// Postconditions: Seeds srand only
War::War(){
  srand(time(NULL));
}

// Descructor
// Preconditions: m_myStable and/or m_enemyStable is populated
// Postconditions: Deallocates horse objects in all vectors
War::~War(){

  // loop through and deallocate m_myStable
  for(unsigned int i = 0; i < m_myStable.size(); i++){
    delete m_myStable.at(i);
    m_myStable.at(i) = nullptr;
  }

  //loop through and deallocate m_enemyStable
  for(unsigned int i = 0; i < m_enemyStable.size(); i++){
    delete m_enemyStable.at(i);
    m_enemyStable.at(i) = nullptr;
  }
}

// Name: loadHorses
// Desc - Loads each horse into m_enemyStable from file
// Preconditions - Requires file with valid horse data
// Postconditions - m_enemyStable is populated with enemy horse pointers
void War::loadHorses(char* fName){

  cout << "Welcome to UMBC War" << endl;
  cout << endl;

  // declare necessary variables
  string name;
  int size;
  int health;
  int speed;

  ifstream myfile(fName);
  if(myfile.is_open()){

    // while it isn't the end of the file
    while(myfile >> name){
      myfile >> size >> health >> speed;
      Size newSize = Size(size);

      //create a new horse to add to m_enemyStable
      Horse* newHorse = new Untrained(name, newSize, health, speed);
      
      m_enemyStable.push_back(newHorse);
    }
  }else{
    cout << "Unable to open file" << endl;
  }
  myfile.close();

  // specialize all of the enemy horses
  for(unsigned int i = 0; i < m_enemyStable.size(); i++){
    Horse* newHorse = m_enemyStable.at(i)->specialize();
    delete m_enemyStable.at(i);
    m_enemyStable.at(i) = newHorse;
    
  }
  
}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - m_enemyStable has been populated from file
// Postconditions - exits if user entered 6
void War::mainMenu(){

  int userInput = 0;
  
  while(m_enemyStable.size() > 0 && userInput != QUIT){

    // display main menu
    cout << "What would you like to do?" << endl;
    cout << "1. Display Friendly Stable" << endl;
    cout << "2. Display Enemy Stable" << endl;
    cout << "3. Acquire Horse" << endl;
    cout << "4. Train Horse" << endl;
    cout << "5. Battle" << endl;
    cout << "6. Quit" << endl;

    // get valid user input
    cin >> userInput;
    while((userInput < DISPLAY_FRIENDLY) || (userInput > QUIT)){
      cout << "Please enter a number 1-6" << endl;
      cin >> userInput;
    }
    
    switch(userInput){
    case DISPLAY_FRIENDLY:
      displayMyHorses();
      break;
    case DISPLAY_ENEMY:
      displayEnemyHorses();
      break;
    case ACQUIRE:
      acquireHorse();
      break;
    case TRAIN:
      trainHorse();
      break;
    case BATTLE:
      startBattle();
      break;
    default:
      cout << "Goodbye!" << endl;
      break;

    }

  }

  // if the user beat all of the horses
  if(m_enemyStable.size() <= 0){
    
    cout << "Congratulations! You beat all the enemy horses and won the game!"
	 << endl;
  }
  
}

// Name: acquireHorse()
// Desc - user randomly acquires a new untrained horse (random size)
// Preconditions - none
// Postconditions - new horse is added to m_myStable
void War::acquireHorse(){
  cout << "What would you like to name the horse?" << endl;
  string name;
  int health;
  int speed;
  if(cin.peek() == '\n'){
    cin.ignore();
  }
  
  getline(cin, name);
  while(name == ""){
    cout << "Please enter a name" << endl;
    getline(cin, name);
  }
  int newSize = rand() % 3;

  // create a random new Untrained horse
  switch(newSize){
  case SMALL:
    health = generateRandom(LT_MIN_HEALTH, LT_MAX_HEALTH);
    speed = generateRandom(LT_MIN_SPEED, LT_MAX_SPEED);
    break;
  case MEDIUM:
    health = generateRandom(MD_MIN_HEALTH, MD_MAX_HEALTH);
    speed = generateRandom(MD_MIN_SPEED, MD_MAX_SPEED);
    break;
  case LARGE:
    health = generateRandom(HV_MIN_HEALTH, HV_MAX_HEALTH);
    speed = generateRandom(HV_MIN_SPEED, HV_MAX_SPEED);
    break;

  }
  
  Size s = Size(newSize);
  Horse* newHorse = new Untrained(name, s, health, speed);
  m_myStable.push_back(newHorse);

  cout << "You have acquired a new horse." << endl;
  cout << endl;
}

// Name: trainHorse()
// Desc - user randomly acquires a horse
// Preconditions - none
// Postconditions - new horse is added to m_stable
void War::trainHorse(){

  // get the index of the chosen horse
  int index = chooseHorse() - 1;

  // if the horse is untrained specialize it
  if(m_myStable.at(index)->toString() == "Unknown"){ 
    Horse* newHorse = m_myStable.at(index)->specialize();
    delete m_myStable.at(index);
    m_myStable.at(index) = newHorse;
    cout << "Your horse is now a " << newHorse->toString() << " warhorse." << endl;
    cout << endl;

    // otherwise, train it
  }else{
    m_myStable.at(index)->train();
  }
  

}

// Name: generateRandom(int, int)
// Desc - generate a random number between two numbers
// Preconditions - none
// Postconditions - returns a random number in the range
int generateRandom(int min, int max){

  int random = rand() % (max + 1 - min) + min;
  return random;
}

// Name: startBattle()
// Desc - user selects a horse to battle with and fights first horse in enemy
// m_enemyStable. Horse that loses is removed from their respective stable
// forever. User must have at least ONE specialized horse at least training level
// 2 or higher
// Preconditions - User has at least one horse and horse is specialized trained
// Postconditions - m_myStable or m_enemyStable has loser removed
void War::startBattle(){

  // get the index of a user chosen horse
  int index = chooseHorse() - 1;

  // if the training level is Saddle or higher, send the horse to battle
  if(m_myStable.at(index)->getTraining() >= SADDLE){

    // if the user's horse wins the battle
    if(m_myStable.at(index)->battle(m_enemyStable.at(0))){

      // move everything up an index in the vector and put the horse
      // that is being removed at the end
      Horse* firstEnemy = m_enemyStable.at(0);
      for(unsigned int i = 0; i < m_enemyStable.size(); i++){
	if(i < (m_enemyStable.size() - 1)){
	  m_enemyStable.at(i) = m_enemyStable.at(i + 1);
	}
      }
      //remove the last horse in the vector
      m_enemyStable.at(m_enemyStable.size() - 1) = firstEnemy;
      delete m_enemyStable.at(m_enemyStable.size() - 1);
      m_enemyStable.pop_back();

      // the enemy horse wins the battle
    }else{

      // move each horse after the chosen one up an index and
      // put the horse to remove at the end
      Horse* chosenHorse = m_myStable.at(index);
      for(unsigned int i = index; i < m_myStable.size(); i++){
	if(i < (m_myStable.size() - 1)){
	  m_myStable.at(i) = m_myStable.at(i + 1);
	}
      }
      //remove the last horse in the vector
      m_myStable.at(m_myStable.size() - 1) = chosenHorse;
      delete m_myStable.at(m_myStable.size() - 1);
      m_myStable.pop_back();
    }

    // the horse is not yet trained enough to battle
  }else{
    cout << "That horse is not ready for battle yet." << endl;
    cout << endl;
  }
  
}

// Name: displayMyHorses()
// Desc - Displays all horses in m_myStable or empty message if no horses
// Preconditions - m_myStable is populated
// Postconditions - None
void War::displayMyHorses(){

  // check if the stable is empty
  if(m_myStable.size() == 0){
    cout << "The stable is empty." << endl;
  }else{
    
    cout << "My Horses" << endl;
  
    cout << "Num" << setw(20) << "Horse  " << '\t' << "Size" << "\t\t" << "Health"
	 << '\t' << "Speed" << '\t' << "Training" << endl;

    // print out info about each horse using the overloaded operator
    for(unsigned int i = 0; i < m_myStable.size(); i++){
      cout << (i + 1);
      cout << *m_myStable.at(i);
    }
    cout << endl;
  }
}

// Name: displayEnemyHorses()
// Desc - Displays all horses in m_enemyStable or win message if empty
// Preconditions - m_enemyStable is populated
// Postconditions - None
void War::displayEnemyHorses(){

  cout << "Enemy Horses" << endl;

  cout << "Num" << setw(20) << "Horse  " << '\t' << "Size" << "\t\t"  << "Health"
       << '\t' << "Speed" << '\t' << "Training" << endl;

  // loop through m_enemyHorses and print their information using the overloaded
  // operator
  for (unsigned int i = 0; i < m_enemyStable.size(); i++){
    cout << (i + 1);
    cout << *m_enemyStable.at(i);
  }
  cout << endl;
  
}

// Name: chooseHorse
// Desc - Helper that either displays that m_myStable is empty or allows user to
//        choose a horse to user for traiing or battle. Returns index + 1
// Preconditions - None
// Postconditions - None
int War::chooseHorse(){
  cout << "Which horse would you like to work with?" << endl;

  // display the horses to choose from
  displayMyHorses();
  int userInput;
  cin >> userInput;

  // get a valid index selection
  while((userInput < 1) || (userInput > int(m_myStable.size()))){
    cout << "Please choose a number between 1 and " << m_myStable.size() << endl;
    cin >> userInput;
  }
  return userInput;
}
