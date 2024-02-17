/**
* @author Chandan Sharma
* @date 2022-03-14
*/

#include "Movements.h"
#include <string>

Movements::Movements() {
}

Movements::~Movements() {
}


void Movements::moveLeft(Environment* current) {
  if (current->getPos() == 3) {
    current->setPos(0);
    std::cout << "You are now in home location";
    std::cout << " of " << current -> getName() << std::endl;
  } else if (current->getPos() == 0) {
    current->setPos(1);
    std::cout << "You are now in left location";
    std::cout << " of " << current -> getName() << std::endl;
  } else {
    std::cout << "This is an invalid move!!!!";
    std::cout << " You did not move." << std::endl;
  }
}

void Movements::moveRight(Environment* current) {
  if (current->getPos() == 1) {
    current->setPos(0);
    std::cout << "You are now in home location";
    std::cout << " of " << current -> getName() << std::endl;
  } else if (current->getPos() == 0) {
    current->setPos(3);
    std::cout << "You are now in right location";
    std::cout << " of " << current -> getName() << std::endl;
  } else {
    std::cout << "This is an invalid move!!!!";
    std::cout << " You did not move." << std::endl;
  }
}

void Movements::moveForward(Environment* current) {
  if (current->getPos() == 0) {
    current->setPos(2);
    std::cout << "You are now in upward location";
    std::cout << " of " << current -> getName() << std::endl;
  } else {
    std::cout << "This is an invalid move!!!!";
    std::cout << " You did not move." << std::endl;
  }
}

void Movements::moveBackward(Environment* current) {
  if (current->getPos() == 2) {
    current->setPos(0);
    std::cout << "You are now in home location";
    std::cout << " of " << current -> getName() << std::endl;
  } else {
    std::cout << "This is an invalid move!!!!";
    std::cout << " You did not move." << std::endl;
  }
}

void Movements::moveEnvironment(Environment*& current,
                                Environment* destination) {
  if (current == destination) {
    std::cout << "You are already located at " << current -> getName();
    std::cout << std::endl;
  } else {
    std::cout << "You are moving from ";
    std::cout << current -> getName() << " to ";
    std::cout << destination -> getName() << std::endl;
    current = destination;
  }
}
