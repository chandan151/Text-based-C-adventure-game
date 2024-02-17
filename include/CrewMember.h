/**
* @author Chandan Sharma
* @date 2022-03-15
*/

#ifndef CREWMEMBER_H_INCLUDED
#define CREWMEMBER_H_INCLUDED

#include <string>
#include "NPC.h"

/**
 * @class CrewMember CrewMember.h "CrewMember.h"
 * @brief Implements a NPC that helps main character as a CrewMember.
 */
class CrewMember: public NPC {
 public:
  /**
  * @brief Default constructor, calls setName.
  */
  CrewMember();

  /**
  * @brief Default destructor.
  */
  virtual ~CrewMember();

  /**
  * @brief Prints the introduction of crew member, different at different locations.
  */
  void intro();

  /**
  * @brief Prints some sugestions for the main character. he provides knowledge based on personel experince.
  */
  void helpMainCharacter();
};

#endif
