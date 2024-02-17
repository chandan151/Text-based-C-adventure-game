/**
* @author Simon Rolfson
* @date 2022-03-15
*/

#ifndef ENVIRONMENT_H_INCLUDED
#define ENVIRONMENT_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "MainCharacter.h"
#include "Item.h"
#include "BackPack.h"
#include "Interaction.h"

/**
 * @class Environment Environment.h "Environment.h"
 * @brief it is a super class for all the Environments.
 */
class Environment{
 public:
  std::string getName();

  /**
  * @brief Default constructior.
  */
  Environment();

  /**
  * @brief Default destructor.
  */
  virtual ~Environment();

  /**
  * @brief sets the name of the environment.
  * @param String value to set the name of Environment.
  * @throws error if no value is passed.
  */
  void setName(std::string);

  /**
  * @brief sets the position of main character in a enviroment.
  * @param[in] position to move, value ranging 0 to 3,
  * 0 = center, 1 = left, 2 = right, 3 = forward.
  * @throws error if no value is passed.
  */
  void setPos(int);

  /**
  * @brief gets the position of main Character.
  */
  int getPos();

  /**
  * @brief sets a location to a boolean as it is completed.
  * @param[in] position that is completed.
  * @throws error in no input is given.
  */
  void setLocationComp(int);

  /**
  * @brief gets the Location missions completion stats.
  * @returns boolean value wether its done or not.
  */
  bool getLocationComp(int);

  /**
  * @brief sets encironmentCompletion True as it is fully visited.
  */
  void setEnvironmentComp();

  /**
  * @brief gets the environments all missions completion stats.
  * @returns boolean value wether its done or not.
  */
  bool getEnvironmentComp();

  /**
  * @brief Pure virtual fuction for viewing missions
  * @param[in] takes position of the main character.
  */
  virtual void viewMission(int) = 0;

  /**
  * @brief Pure virtual fuction for exploring an environment.
  */
  virtual void explore() = 0;

  /**
  * @brief Pure virtual fuction for Playing missions
  * param MainCharacter* pointer to a main character who is playing mission.
  * @param[in] takes position of the main character.
  */
  virtual void playMission(MainCharacter*, int) =  0;

  /**
  * @brief checks the level of move in a particular environment.
  * @returns Boolean.
  */
  bool checkLevelMove(std::string);

 private:
  std::string environmentName;
  bool environmentCompletion = false;
  bool locationCompletion[4] = {true, false, false, false};
  int position;
};

#endif
