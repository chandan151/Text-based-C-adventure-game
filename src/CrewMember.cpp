#include "CrewMember.h"
#include <iostream>

CrewMember::CrewMember() {
}

CrewMember::~CrewMember() {
}

void CrewMember::intro() {
  std::cout << "Hello I am your lost Crew member." << std::endl;
  std::cout << "I have been here for long time." << std::endl;
  std::cout << "I Know everything. Before Every level" << std::endl;
  std::cout << "I will give you info critical to your success" << std::endl;
}

void CrewMember::helpMainCharacter() {
  std::cout << "Hello" << std::endl;
}
