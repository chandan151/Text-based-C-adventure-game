/**
* @author Simon Rolfson
* @date 2022-03-13
*/

#ifndef INTERACTION_H_INCLUDED
#define INTERACTION_H_INCLUDED

#include <string>
#include <iostream>
#include "MainCharacter.h"
#include "Item.h"
#include "BackPack.h"

/**
 * @class Interaction "Interaction.h"
 * @brief Class that handles the actions related to interaction with objects and environments.
 */
class Interaction{
 public:
  /**
  * @brief Default constructior.
  */
  Interaction();

  /**
  * @brief Default destructor.
  */
  virtual ~Interaction();

  /**
  * @brief adds any item to the backpack.
  * @param MainCharacter Pointer to an MainCharacter on which action is being performed.
  * @param item Pointer to an item that is being added.
  * @throws error if no parameter or wrong parameter passed.
  */
  void addToBP(MainCharacter*, Item*);

  /**
  * @brief removes any item from the backpack.
  * @param MainCharacter Pointer to an MainCharacter on which action is being performed.
  * @param item Pointer to an item that is being removed.
  * @throws error if no parameter or wrong parameter passed.
  */
  void removeFromBP(MainCharacter*, Item*);

  /**
  * @brief inspects items in the backpack.
  * @param item Pointer to an item that need to be inspected.
  * @throws error if no parameter or wrong parameter passed.
  */
  void inspect(Item*);

  /**
  * @brief updates Health based to attack entity.
  * @param RealCharacter Pointer to a RealCharacetr.
  * @param int integer value of health damage or increase.
  * @throws error if no parameter or wrong parameter passed.
  */
  void attackFromPlayer(RealCharacter*, int);

  /**
  * @brief updates Health based to attack entity.
  * @param RealCharacter Pointer to a RealCharacetr.
  * @param int integer value of health damage or increase.
  * @throws error if no parameter or wrong parameter passed.
  */
  void attackFromVillain(MainCharacter*, int);
};

#endif
