#include "Character.h"

Character::Character() {
}

Character::~Character() {
}

std::string Character::getName() {
  return name;
}

void Character::setName(std::string newName) {
  name = newName;

  return;
}
