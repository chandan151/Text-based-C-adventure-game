/**
* @author Simon Rolfson
* @date 2022-03-14
*/

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>

/**
 * @class Item Item.h "Item.h"
 * @brief Class that handles all the items in the game.
 */
class Item {
 public:
  enum ItemType
  {Gun, Flashlight, Map, Bandages, Food, Ammo};

  /**
  * @brief Default constructior.
  */
  Item();

  /**
  * @brief Default destructor.
  */
  virtual ~Item();

  /**
  * @brief sets the items that will be used.
  * @param ItemType enum of all the items.
  * @throws error if no parameter is passed.
  */
  void setItem(Item::ItemType);

  /**
  * @brief getter for the items.
  * @return a list of Items.
  */
  Item::ItemType getItem();

  /**
  * @brief gives a item.
  * @param ItemType enum of all the items.
  * @return string name of item.
  */
  std::string itemToString(Item::ItemType);

  /**
  * @brief gives a description of item.
  * @param ItemType enum of all the items.
  * @return string description of item
  */
  std::string description(Item::ItemType);

 private:
  Item::ItemType item;
};

#endif
