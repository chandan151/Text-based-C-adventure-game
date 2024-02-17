#include "RobotHelper.h"
#include <iostream>

RobotHelper::RobotHelper() {
}

RobotHelper::~RobotHelper() {
}

void RobotHelper::intro() {
  std::cout << "Hello, I'm robot helper!!!" << std::endl;
}

void RobotHelper::helpMainCharacter() {
  std::cout << "I am no use to you." << std::endl;
  std::cout << "Unfortunately, I was trained on\n";
  std::cout << "the wrong data set. My AI is remedial\n";
}
