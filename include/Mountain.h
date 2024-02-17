#ifndef MOUNTAIN_H_INCLUDED
#define MOUNTAIN_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "MainCharacter.h"
#include "Item.h"
#include "BackPack.h"
#include "Interaction.h"
#include "Environment.h"

/**
 * @class Mountain Mountain.h "Mountain.h"
 * @brief First Location class that inherits Environment.
 */
class Mountain: public Environment{
 public:
  /**
  * @brief Default constructior.
  */
  Mountain();

  /**
  * @brief Default destructior.
  */
  virtual ~Mountain();

  /**
  * @brief Shows the availiable missions in the present locaion.
  * @param[in] integer value 0,1,2,3 for the position of player.
  * @throws error if no parameter is passed.
  */
  void viewMission(int);

  /**
  * @brief Shows the availiable items in the present location.
  * @return list of items.
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
  * @brief mountain climbing mission.
  */
  void climbMountain();

  /**
  * @brief spider's attack mission.
  * @param Pointer to the MainCharacter who is playing the mission.
  */
  void spiderAttack(MainCharacter*);

  /**
  * @brief Mission of solving puzzles.
  */
  void puzzle();

 private:
  std::string environmentName;
};

#endif
