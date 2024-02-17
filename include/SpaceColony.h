#ifndef SPACECOLONY_H_INCLUDED
#define SPACECOLONY_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "MainCharacter.h"
#include "Item.h"
#include "BackPack.h"
#include "Interaction.h"
#include "Environment.h"

/**
 * @class SpaceColony SpaceColony.h "SpaceColony.h"
 * @brief Second Location class that inherits Environment.
 */
class SpaceColony: public Environment{
 public:
  /**
  * @brief Default constructior.
  */
  SpaceColony();

  /**
  * @brief Default destructior.
  */
  virtual ~SpaceColony();

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
  * @brief a guessing puzzle.
  */
  void guessGame();

  /**
  * @brief sand storm mission.
  * @param Pointer to the MainCharacter who is playing the mission.
  */
  void sandStorm(MainCharacter*);

  /**
  * @brief mission for cracking a lock.
  * @param Pointer to the MainCharacter who is playing the mission.
  */
  void crackLock(MainCharacter*);

 private:
  std::string environmentName = "Space Colony";
};
#endif
