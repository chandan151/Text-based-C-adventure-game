#include "Interaction.h"

Interaction::Interaction() {
}

Interaction::~Interaction() {
}

void Interaction::addToBP(MainCharacter* mainCharacter, Item* item) {
  if (mainCharacter -> backpack -> checkBP(item)) {
    std::cout << "This item is already in your backpack" << std::endl;
  } else {
    mainCharacter -> backpack -> updateBackPackAdd(item);
    std::cout << "Item added to BP" << std::endl;
  }
}

void Interaction::removeFromBP(MainCharacter* mainCharacter, Item* item) {
  if (mainCharacter -> backpack -> checkBP(item)) {
    mainCharacter -> backpack -> updateBackPackRemove(item);
      std::cout << "This item has been removed from your backpack" << std::endl;
  } else {
    std::cout << "This item is not in your backpack" << std::endl;
  }
}

void Interaction::inspect(Item* item) {
  std::cout <<  item -> description(item -> getItem()) << std::endl;
}

void Interaction::attackFromPlayer(RealCharacter* villain, int damage) {
  villain -> updateHealth(damage);
  std::cout << villain -> getName();
  std::cout << " took " << damage << " damage!!!\n";
}

void Interaction::attackFromVillain(MainCharacter* player, int damage) {
  player -> updateHealth(damage);
  std::cout << player -> getName();
  std::cout << " took " << damage << " damage!!!\n";
}
