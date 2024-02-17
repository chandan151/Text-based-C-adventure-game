/**
* @author Chandan Sharma
* @date 2022-03-15
*/

#ifndef ROBOTHELPER_H_INCLUDED
#define ROBOTHELPER_H_INCLUDED

#include <string>
#include "NPC.h"

/**
 * @class RobotHelper RobotHelper.h "RobotHelper.h"
 * @brief Implements a NPC that helps main character as a RobotHelper.
 */
class RobotHelper: public NPC {
 public:
  /**
  * @brief Default constructor, calls setName.
  */
  RobotHelper();

  /**
  * @brief Default destructor.
  */
  virtual ~RobotHelper();

  /**
  * @brief Prints the introduction of Robot helper.
  */
  void intro();

  /**
  * @brief Prints some sugestions for the main character, it gives knowledge based on observance.
  */
  void helpMainCharacter();
};

#endif
