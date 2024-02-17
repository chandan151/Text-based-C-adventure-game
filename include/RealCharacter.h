/**
* @author Simon Rolfson
* @date 2022-03-12
*/

#ifndef REALCHARACTER_H_INCLUDED
#define REALCHARACTER_H_INCLUDED

#include <string>
#include "Character.h"

/**
 * @class RealCharacter RealCharacter.h "RealCharacter.h"
 * @brief Class that handles the operations on RealCharacter and it implements Character.
 */
class RealCharacter: public Character{
 public:
 /**
  * @brief Default constructior.
  */
  RealCharacter();

  /**
  * @brief Default destructor.
  */
  virtual ~RealCharacter();

  /**
  * @brief Checks the health of Real character.
  * @return true if health is Zero and False if Health is positive integer value.
  */
  bool checkDeath();

  /**
  * @brief Checks the health of Real character.
  * @return integer value of health of real character.
  */
  int getHealth();

  /**
  * @brief Checks the ammo in the inventory and backpack.
  * @return integer value of count of the ammo.
  */
  int getAmmo();

  /**
  * @brief updates the health of Real character.
  * @param[in] takes the integer value and updates accordingly.
  */
  void updateHealth(int);

 private:
  int ammoCount = 10;
  int health = 100;
  bool deathStatus;
};

#endif
