#include "BackPack.h"
#include <iostream>

BackPack::BackPack() {
}

BackPack::~BackPack() {
}

void BackPack::updateBackPackAdd(Item* newItem) {
    backPack.push_back(newItem);
}

void BackPack::updateBackPackRemove(Item* newItem) {
  for (int i = 0; i < backPack.size(); i++) {
    if (newItem -> getItem() == backPack[i] -> getItem()) {
      backPack.erase(backPack.begin() + i);
    }
  }
}

int BackPack::getBPSize() {
  int size = 0;
  int i = 0;

  while (i < backPack.size()) {
    size++;
    i++;
  }

  return size;
}

bool BackPack::checkBP(Item* lookFor) {
  for (int i = 0; i < backPack.size(); i++) {
    if (lookFor -> getItem() == backPack[i] -> getItem()) {
      return true;
    }
  }
  return false;
}

void BackPack::displayItems() {
  if (backPack.size() == 0) {
    std::cout << "Your backpack is empty" << std::endl;
  } else {
    std::cout << "The items in your BP are " << std::endl;
    for (int i = 0; i < backPack.size(); i++) {
      std::cout << backPack[i] -> itemToString(backPack[i]
                                               -> getItem()) << std::endl;
    }
  }
}
