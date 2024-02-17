/**
* @author Chandan Sharma
* @date 2022-03-14
*/

#ifndef MOVEMENTS_H_INCLUDED
#define MOVEMENTS_H_INCLUDED

#include <string>
#include "Environment.h"

/**
 * @class Movements Movements "Movements.h"
 * @brief Class that handles movements of the main character.
 */
class Movements {
 public:
   /**
   * @brief Default constructior.
   */
  Movements();

   /**
   * @brief Default destructor.
   */
  virtual ~Movements();

  /**
   * @brief moves the player in left direction.
   * @param Pointer to an object of Environment.
   * @throws error if no environment passed.
   */
  void moveLeft(Environment*);

  /**
   * @brief moves the player in right direction.
   * @param Pointer to an object of Environment.
   * @throws error if no environment passed.
   */
  void moveRight(Environment*);

  /**
   * @brief moves the player in forward direction.
   * @param Pointer to an object of Environment.
   * @throws error if no environment passed.
   */
  void moveForward(Environment*);

  /**
   * @brief moves the player in backward direction.
   * @param Pointer to an object of Environment.
   * @throws error if no environment passed.
   */
  void moveBackward(Environment*);

  /**
   * @brief moves the player from one environment to other environment.
   * @param Pointer to an object of Environment from which player is moving.
   * @param Pointer to an object of Environment to which player is moving into.
   * @throws error if no environment passed.
   */
  void moveEnvironment(Environment*&, Environment*);
};

#endif
