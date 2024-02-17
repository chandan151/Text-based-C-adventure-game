#include "Item.h"
#include <iostream>

Item::Item() {
}

Item::~Item() {
}

void Item::setItem(ItemType newItem) {
  item = newItem;
}

Item::ItemType Item::getItem() {
  return item;
}

std::string Item::itemToString(Item::ItemType convert) {
  switch (convert) {
    case ItemType::Gun:
      return "Gun";
    case ItemType::Flashlight:
      return "Flashlight";
    case ItemType::Map:
      return "Map";
    case ItemType::Bandages:
      return "Bandages";
    case ItemType::Food:
      return "Food";
    case ItemType::Ammo:
      return "Ammo";
  }
  return "";
}

std::string Item::description(Item::ItemType describe) {
  switch (describe) {
    case ItemType::Gun:
      return "HMMMM -- that seems to be a gun";
    case ItemType::Flashlight:
      return "An item that allows you to see in the dark";
    case ItemType::Map:
      return "A Map -- this could give me some clues";
    case ItemType::Bandages:
      return "Something to heal with";
    case ItemType::Food:
      return "Food -- just in case I get hungry";
    case ItemType::Ammo:
      return "Nice, some ammo";
  }
  return "";
}

