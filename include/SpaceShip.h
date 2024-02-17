#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "MainCharacter.h"
#include "Item.h"
#include "BackPack.h"
#include "Interaction.h"
#include "Environment.h"

/**
 * @class SpaceShip SpaceShip.h "SpaceShip.h"
 * @brief Third Location class that inherits Environment.
 */
class SpaceShip: public Environment{
 public:
  /**
  * @brief Default constructior.
  */
  SpaceShip();

  /**
  * @brief Default destructior.
  */
  virtual ~SpaceShip();

  /**
  * @brief Shows the availiable missions in the present locaion.
  * @param[n] integer value 0,1,2,3 for the position of player.
  * @throws error if no parameter is passed.
  */
  void viewMission(int);

  /**
  * @brief Shows the availiable items in the present locaion.
  * @return list of items
  */
  void explore();

  /**
  * @brief starts the mission.
  * @param MainCharacter* pointer to a main character who is playing mission.
  * @param[in] integer value 0,1,2,3 for the position of player.
  * @throws error if no parameter is passed.
  */
  void playMission(MainCharacter*, int);

  /**
  * @brief Aestroid Attack mission.
  * @param Pointer to the MainCharacter who is playing the mission.
  */
  void asteroidAttack(MainCharacter*);

  /**
  * @brief Mission of solving math puzzles.
  */
  void mathPuzzle();

  /**
  * @brief Alien attacks our player mission.
  * @param Pointer to the MainCharacter who is playing the mission.
  */
  void alienAttack(MainCharacter*);

 private:
  std::string environmentName = "Space Ship";
};

#endif
