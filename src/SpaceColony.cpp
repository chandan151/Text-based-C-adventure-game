#include "SpaceColony.h"


SpaceColony::SpaceColony() {
}

SpaceColony::~SpaceColony() {
}

void SpaceColony::viewMission(int c1) {
    if (c1 == 1) {
      std::cout << "For this level, your job is" << std::endl;
      std::cout << "to unscramble a certain word." << std::endl;
      std::cout << "Make sure your answer is typed correctly " << std::endl;
      std::cout << "and guess away." << std::endl;
    } else if (c1 == 2) {
      std::cout << "For this level, your crew got caught in" << std::endl;
      std::cout << "a sandstorm. Your goal is to make it " << std::endl;
      std::cout << "out alive, without being killed by the " << std::endl;
      std::cout << "strong gust of nasty sand and wind." << std::endl;
    } else if (c1 == 3) {
      std::cout << "For this level, you need to  " << std::endl;
      std::cout << "need to guess the numbers to " << std::endl;
      std::cout << "pick a lock. There is only 3,  " << std::endl;
      std::cout << "but every incorrect guess cost you" << std::endl;
      std::cout << "5 health." << std::endl;
    } else {
      std::cout << "There are no missions at home base/n";
    }
}

void SpaceColony::explore() {
  std::cout << "This is the Space colony." << std::endl;
  std::cout << "For the most part, everyone is friendly." << std::endl;
  std::cout << "Except for a few, and the asteroids...\n" << std::endl;
}

void SpaceColony::guessGame() {
  if (getLocationComp(1) == false) {
    std::string decipher;
    std::cout << "\nYou must decipher this word: eholl\n" << std::endl;
    std::cout << "Hey it's your crew mate again, ";
    std::cout << "this is one of the easier missions...\n";
    do {
      std::cin >> decipher;
      if (decipher == "hello") {
      std::cout << "You passed\n";
      setLocationComp(1);
      setEnvironmentComp();
      } else {
      std::cout << "Wrong Guess\n";
      }
    }while (decipher != "hello");
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void SpaceColony::sandStorm(MainCharacter* player) {
  if (getLocationComp(2) == false) {
    Interaction* inter = new Interaction();
    std::cout <<"\n THE SANDSTORM IS HERE\n" << std::endl;
    std::cout << "It's your crewmate again, I say go left:)\n";
    int counter = 0;
    std::string move;
    std::cout << player -> getName();
    std::cout << " currently has ";
    std::cout << player -> getHealth();
    std::cout << " health.\n";
    do {
      RealCharacter* sandStorm = new RealCharacter();
      sandStorm -> setName("Sand");
      do {
      std::cout << "Pick a direction to dodge(left/right)\n";
      std::cin >> move;
      } while (checkLevelMove(move) != true);
      if (move == "right") {
      inter -> attackFromVillain(player, -50);
      std::cout << "You failed to dodge\n";
      } else {
      std::cout << "You dodged the sand\n";
      }
      counter++;
      delete sandStorm;
    } while (player -> checkDeath() == true
                       && counter < 3);
    if (player -> checkDeath() == false) {
      std::cout << "YOU DIED";
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


void SpaceColony::crackLock(MainCharacter* player) {
  if (getLocationComp(3) == false) {
    std::cout << "\nCRACK THE LOCK!!!\n" << std::endl;
    std::cout << "Hey, its your crewmate, remember, 3";
    std::cout << " is a magic number.\n";
    Interaction* inter = new Interaction();
    int guess;
    std::cout << player -> getName();
    std::cout << " currently has ";
    std::cout << player -> getHealth();
    std::cout << " health.\n";
    do {
    std::cout << "What is your guess for the first number? ";
    std::cin >> guess;
    if (guess != 3) {
      std::cout << "Wrong Answer!!!\n";
      inter -> attackFromVillain(player, -10);
    } else {
      std::cout << "Correct\n";
    }
    } while ( guess != 3 &&
           player -> checkDeath() != false);
    if (player->checkDeath() == false) {
      std::cout << "You died\n";
      abort();
    }
    do {
    std::cout << "What is your guess for the second number? ";
    std::cin >> guess;
    if (guess != 6) {
      std::cout << "Wrong Answer!!!\n";
      inter -> attackFromVillain(player, -10);
    } else {
      std::cout << "Correct\n";
    }
    } while ( guess != 6 &&
           player -> checkDeath() != false);
    if (player->checkDeath() == false) {
      std::cout << "You died\n";
      exit(1);
    }
    do {
    std::cout << "What is your guess for the third number? ";
    std::cin >> guess;
    if (guess != 9) {
      std::cout << "Wrong Answer!!!\n";
      inter -> attackFromVillain(player, -10);
    } else {
      std::cout << "Correct\n";
    }
    } while ( guess != 9 &&
            player -> checkDeath() != false);
    if (player->checkDeath() == false) {
      std::cout << "You died\n";
      exit(1);
    }
    setLocationComp(3);
    setEnvironmentComp();
    delete inter;
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void SpaceColony::playMission(MainCharacter* player, int c1) {
  if (c1 == 1) {
    guessGame();
  } else if (c1 == 2) {
    sandStorm(player);
  } else if (c1 == 3) {
    crackLock(player);
  } else {
    std::cout << "You are safe from danger here\n";
  }
}
