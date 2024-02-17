/**
* @author Simon Rolfson
* @date 2022-03-10
*/

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>

/**
 * @class Character Character.h "Character.h"
 * @brief Super class for all the Characters.
 */
class Character {
 public:
  std::string getName();

  /**
  * @brief Default constructor.
  */
  Character();

  /**
  * @brief Default Destructor
  */
  virtual ~Character();

  /**
  * @brief sets the name of the character.
  * @param string it takes a string value
  * @throws error if nothing passed.
  */
  void setName(std::string);

 private:
  std::string name;
};

#endif

