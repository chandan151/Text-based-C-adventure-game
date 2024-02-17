#include "SpaceShip.h"

SpaceShip::SpaceShip() {
}

SpaceShip::~SpaceShip() {
}

void SpaceShip::viewMission(int c1) {
  if (c1 == 1) {
    std::cout << "For this level, you will be asked to " << std::endl;
    std::cout << "solve 3 mathematical expression. " << std::endl;
    std::cout << "Once you answer all correctly,  " << std::endl;
    std::cout << "the level will be complete." << std::endl;
  } else if (c1 == 2) {
    std::cout << "You and your crew enter your spaceship" << std::endl;
    std::cout << "and are met with an asteroid storm." << std::endl;
    std::cout << "It's your job to navigate and save the" << std::endl;
    std::cout << "crew, or else DEATH awaits" << std::endl;
  } else if (c1 == 3) {
    std::cout << "For this level, you will be attacked " << std::endl;
    std::cout << "by Aliens. The aliens quiz you on your" << std::endl;
    std::cout << "history smarts. There are 3 questions.Get one  " << std::endl;
    std::cout << "wrong and you will take damage. Good Luck " << std::endl;
  } else {
    std::cout << "There are no missions on the home base\n";
  }
}

void SpaceShip::explore() {
  std::cout << "Welcome to the Space Ship." << std::endl;
  std::cout << "This is your home base." << std::endl;
  std::cout << "You are relatively safe here, " << std::endl;
  std::cout << "but beware the asteroids.\n" << std::endl;
}

void SpaceShip::asteroidAttack(MainCharacter* player) {
  if (getLocationComp(2) == false) {
    Interaction* inter = new Interaction();
    std::cout << "\nYOU MUST DODGE THE ASTEROIDS\n" << std::endl;
    int counter = 0;
    std::string move;
    std::cout << player -> getName();
    std::cout << " currently has ";
    std::cout << player -> getHealth();
    std::cout << " health.\n";
    std::cout << "Hey, its me again, your crew mate.\n";
    std::cout << "I heard the asteroids have a tendancy of";
    std::cout << " going left...\n";
    do {
      RealCharacter* asteroid = new RealCharacter();
      asteroid -> setName("Asteroid");
      do {
      std::cout << "Pick a direction to dodge(left/right)\n";
      std::cin >> move;
      } while (checkLevelMove(move) != true);
      if (move == "right") {
        inter -> attackFromPlayer(asteroid, -100);
        std::cout << "Asteroid hit and destroyed\n";
      } else {
        inter -> attackFromVillain(player, -50);
        std::cout << "You failed to dodge\n";
      }
      counter++;
      delete asteroid;
    } while (player -> checkDeath() == true
                 && counter < 3);
    if (player -> checkDeath() == false) {
      std::cout << "YOU DIED!!!!! RIP!!!";
      std::cout << std::endl;
      exit(1);
    } else {
      std::cout << "You passed this level\n";
      setLocationComp(2);
      setEnvironmentComp();
    }
    delete inter;
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void SpaceShip::mathPuzzle() {
  if (getLocationComp(1) == false) {
    std::cout << "\nWELCOME TO THE MATH GAME!!!\n" << std::endl;
    std::cout << "LEVEL:EASY\n";
    std::cout << "Hey, its your mate, I cant help you much here.\n";
    std::cout << "Use that brain of yours.\n";
    int answer;
    do {
      std::cout << "9 + 10 = ";
      std::cin >> answer;
      if (answer == 19) {
      std::cout << "CORRECT, MOVING ON \n";
      } else {
      std::cout << "INCORRECT, TRY AGAIN \n";
      }
    } while (answer != 19);
    std::cout << "LEVEL:MEDIUM\n";
    do {
      std::cout << "234 - 78 = ";
      std::cin >> answer;
      if (answer == 156) {
      std::cout << "CORRECT, MOVING ON \n";
      } else {
    std::cout << "INCORRECT, TRY AGAIN \n";
      }
    }while(answer != 156);
    std::cout << "LEVEL:MATH GENIUS\n";
    do {
      std::cout << "5 * 7 + 10 / 2 = ";
      std::cin >> answer;
      if (answer == 40) {
      std::cout << "CORRECT, YOU WIN \n";
      } else {
    std::cout << "INCORRECT, TRY AGAIN \n";
      }
    }while(answer != 40);
    std::cout << "WOW, the aliens will study you.\n";
    std::cout << "They have never seen such a smart human.\n";
    std::cout << "You passed this mission.\n";
    setLocationComp(1);
    setEnvironmentComp();
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void SpaceShip::alienAttack(MainCharacter* player) {
  if (getLocationComp(3) == false) {
    std::cout << "\nTHE ALIENS ARE ATTACKING!!!\n";
    std::cout << "WE MUST FIGHT BACK\n";
    std::cout << "It's me again, I can't help you much,";
    std::cout << " use that brain of yours.\n";
    RealCharacter* alien = new RealCharacter;
    Interaction* inter = new Interaction();
    alien -> setName("The Aliens");
    int year;
    std::cout << player -> getName();
    std::cout << " currently has ";
    std::cout << player -> getHealth();
    std::cout << " health.\n";
    std::cout << "You currently have" << player -> getHealth();
    std::cout << " health\n";
    std::cout << "First Question: What year did 9/11 happen?\n";
    std::cin >> year;
    if (year == 2001) {
      std::cout << "CORRECT\n";
    } else {
      std::cout << "wrong";
      inter -> attackFromVillain(player, -30);
    }
    std::cout << "Next Question: What year was this game made?\n";
    std::cin >> year;
    if (year == 2023) {
      std::cout << "CORRECT\n";
    } else {
      std::cout << "wrong";
      inter -> attackFromVillain(player, -40);
    }
    std::cout << "Next Question:What year was TRUMP elected president?\n";
    std::cin >> year;
    if (year == 2016) {
      std::cout << "CORRECT\n";
    } else {
      std::cout << "wrong";
      inter -> attackFromVillain(player, -40);
      std::cout << player -> getHealth();
    }
    if (player -> getHealth() <= 0) {
      std::cout << "YOU DIED!!!!! RIP!!!";
      std::cout << std::endl;
      exit(1);
    } else {
      std::cout << "You passed this mission.\n";
      std::cout << "Harder challenges await.\n";
      setLocationComp(3);
      setEnvironmentComp();
    }
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void SpaceShip::playMission(MainCharacter* player, int c1) {
  if (c1 == 1) {
    mathPuzzle();
  } else if (c1 == 2) {
    asteroidAttack(player);
  } else if (c1 == 3) {
    alienAttack(player);
  } else {
    std::cout << "You are safe from danger here\n";
  }
}
