/**
* @author Simon Rolfson
* @date 2022-03-14
*/

#ifndef BACKPACK_H_INCLUDED
#define BACKPACK_H_INCLUDED

#include <string>
#include <vector>
#include "Character.h"
#include "RealCharacter.h"
#include "Item.h"

/**
 * @class BackPack BackPack.h "BackPack.h"
 * @brief Class that handles the actions related to picking and storing objects.
 */
class BackPack{
 public:
  /**
  * @brief Default constructior.
  */
  BackPack();

  /**
  * @brief Default destructor.
  */
  virtual ~BackPack();

  /**
  * @brief Updates backpack when any object is added.
  * @param item Pointer to an item that is being added.
  * @throws error if no item passed.
  */
  void updateBackPackAdd(Item*);

  /**
  * @brief Updates backpack when any object is removed.
  * @param item Pointer to an item that is being removed.
  * @throws error if no item passed.
  */
  void updateBackPackRemove(Item*);

  /**
  * @brief to get the size of backpack.
  * @return size of backpack.
  */
  int getBPSize();

  /**
  * @brief Checks whether any given item is already in backpack or not.
  * @param item Pointer to an item.
  * @throws error if no item passed.
  * @return True is item is there and False if main character don't have that specific item.
  */
  bool checkBP(Item*);

  /**
  * @brief it shows all the items in the backpack.
  * @return a list of all the items.
  */
  void displayItems();

 private:
  std::vector<Item*> backPack;
};

#endif
