/**
* @author Simon Rolfson
* @date 2022-03-12
*/

#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED

#include <string>
#include <vector>
#include "Character.h"
#include "RealCharacter.h"
#include "BackPack.h"

/**
 * @class MainCharacter MainCharacter.h "MainCharacter.h"
 * @brief Class that handles the operations on MainCharacter and it implements real character.
 */
class MainCharacter: public RealCharacter{
 public:
  BackPack b;
  BackPack* backpack = &b;

  /**
  * @brief Default constructior.
  */
  MainCharacter();

  /**
  * @brief Default destructor.
  */
  virtual ~MainCharacter();
};

#endif
