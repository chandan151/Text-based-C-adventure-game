#include "Environment.h"
const char* levelMovements[] = {"left", "right"};
Environment::Environment() {
}

Environment::~Environment() {
}

std::string Environment::getName() {
  return environmentName;
}

void Environment::setName(std::string newName) {
  environmentName = newName;
}

void Environment::setPos(int newPos) {
  position = newPos;
}

int Environment::getPos() {
  return position;
}

void Environment::setLocationComp(int pos) {
  locationCompletion[pos] = true;
}

bool Environment::getLocationComp(int pos) {
  return locationCompletion[pos];
}

void Environment::setEnvironmentComp() {
    for (int i = 0; i < 4; i++) {
    if (locationCompletion[i] == false) {
      environmentCompletion = false;
      return;
    }
  }
  environmentCompletion = true;
}

bool Environment::getEnvironmentComp() {
  return environmentCompletion;
}

bool Environment::checkLevelMove(std::string move) {
  for (int i = 0; i < 2; i++) {
    if (move == levelMovements[i]) {
      return true;
    }
  }
  return false;
}
