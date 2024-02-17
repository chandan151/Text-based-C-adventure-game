/**
* @author Simon Rolfson
* @date 2022-03-14
*/

#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>
#include <vector>
#include "Character.h"
#include "NPC.h"

/**
 * @class NPC NPC.h "NPC.h"
 * @brief an interface for CrewMember and RobotHelper and it inherits Character.
 */
class NPC: public Character{
 public:
  /**
  * @brief Prints the introduction of a NPC
  */
  virtual void intro() = 0;

  /**
  * @brief Prints the suggestions for main character.
  */
  virtual void helpMainCharacter() = 0;
};

#endif
