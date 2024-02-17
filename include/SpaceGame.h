#ifndef SPACEGAME_H_INCLUDED
#define SPACEGAME_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "MainCharacter.h"
#include "Interaction.h"
#include "Item.h"
#include "Environment.h"
#include "Mountain.h"
#include "SpaceShip.h"
#include "SpaceColony.h"
#include "Movements.h"
#include "NPC.h"
#include "RobotHelper.h"
#include "CrewMember.h"

/**
 * @class SpaceGame SpaceGame.h "SpaceGame.h"
 * @brief It is main class responsible for whole gamePlay.
 */
class SpaceGame{
 public:
  /**
  * @brief Default constructior.
  */
  SpaceGame();

  /**
  * @brief Default destructior.
  */
  virtual ~SpaceGame();

  /**
  * @brief main method to starts the game.
  */
  void playGame();

  /**
  * @brief This method is responsible for all the movements,
  * @brief from one location to other and from one position to other.
  * @param first Environment pointer points to the current Environment.
  * @param takes pointers that points to the three major Environments.
  * @param MainChracter takes a pointer to the MainChracter.
  * @throws exception if no and Wrong parametrs are passed.
  */
  void moveOptions(Environment*&, Environment*,
                   Environment*, Environment*,
                   Movements*, MainCharacter*);

  /**
  * @brief checks the validity of user inputs.
  * @param char [] new char being added.
  * @param char* [] takes one of the six constant arrays.
  * @param[in] it takes the size of array being used.
  * @throws exception if anything other that defined constants are passed.
  */
  bool checkValidInput(char[], const char* [], int);

  /**
  * @brief this method takes care of all the user Inputs.
  * @param char* [] takes one of the six constant arrays.
  * @param[in] it takes the size of array being used.
  * @throws exception if anything other that defined constants are passed.
  */
  std::string  getValidInput(const char* [], int);

  /**
  * @brief Starts missions availiable at particular location.
  * @param Environment pointer points to the current Environment.
  * @param MainChracter takes a pointer to the MainChracter object.
  */
  void viewOrPlayMission(MainCharacter*, Environment*);

  /**
  * @brief Prints out the introduction of NPCs and lets player know there use.
  */
  void introduceNPCs();

  /**
  * @brief this method contains the logic for ending of game.
  * @param takes pointers that points to three major Environments.
  */
  void checkEndGame(Environment*, Environment*, Environment*);

  /**
  * @brief Prints out the introduction of Main Character based on user input.
  * @param MainCharacter* Pointer that points to the current player( MainCharacter class object)
  */
  void intro(MainCharacter*);
};

#endif
