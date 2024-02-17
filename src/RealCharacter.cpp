#include "RealCharacter.h"

RealCharacter::RealCharacter() {
}

RealCharacter::~RealCharacter() {
}


bool RealCharacter::checkDeath() {
  if (health <= 0) {
    deathStatus = false;
    return false;
  } else {
    return true;
  }
}

int RealCharacter::getHealth() {
  return health;
}

int RealCharacter::getAmmo() {
  return ammoCount;
}

void RealCharacter::updateHealth(int newHealth) {
  health += newHealth;
  return;
}
