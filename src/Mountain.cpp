#include "Mountain.h"

Mountain::Mountain() {
}

Mountain::~Mountain() {
}

void Mountain::viewMission(int c1) {
  if (c1 == 1) {
    std::cout << "For this level, your platoon gets" << std::endl;
    std::cout << " stuck going up a mountain. It seems" << std::endl;
    std::cout << " the engine has stalled, use your knowlegde" << std::endl;
    std::cout << " to fix it. Good Luck." << std::endl;
  } else if (c1 == 2) {
    std::cout << "For this level, your job is to " << std::endl;
    std::cout << "Kill the hardest boss, the mutant spider" << std::endl;
    std::cout << "by answering harder and harder math " << std::endl;
    std::cout << "questions. Good Luck." << std::endl;
  } else if (c1 == 3) {
    std::cout << "For this level, a riddle awaits" << std::endl;
    std::cout << " solve it to continue. Good Luck." << std::endl;
  } else {
    std::cout << "There are no missions at home base/n";
  }
}

void Mountain::explore() {
  std::cout << "This is the mountain" << std::endl;
  std::cout << "This is the most dangerous zone." << std::endl;
}

void Mountain::climbMountain() {\
  if (getLocationComp(1) == false) {
    std::cout << "\nYOU GOT STUCK ON THE MOUNTAIN\n" << std::endl;
    std::cout << "Hey it's your crewmate, let me give you a hint.\n";
    std::cout << "It is one letter\n";
    std::cout << "Remember this is not a normal engine\n";
    std::string answer;
    std::cout << "The engine can't be operated on unless ";
    std::cout << "the user solves the question. It  ";
    std::cout << "reads: What always ends everything?" << std::endl;
    std::cout << " (answer in lowercase)" << std::endl;
    do {
      std::cin >> answer;
      if (answer == "g") {
      std::cout << "Correct\n";
      std::cout << "Your group can now continue\n";
      } else {
      std::cout << "Incorrect, try again";
      }
    } while (answer != "g");
    setLocationComp(1);
    setEnvironmentComp();
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void Mountain::spiderAttack(MainCharacter* player) {
  if (getLocationComp(2) == false) {
    std::cout << "\nTHE MUTANT SPIDER IS ATTACKING!\n" << std::endl;
    std::cout << "Crew mate here, I'm sitting this one out.\n";
    std::cout << "Spiders scare the s#*& out of me.\n";
    RealCharacter* spider = new RealCharacter();
    spider -> setName("Spider");
    Interaction* inter = new Interaction();
    int counter = 1;
    int answer;
    std::cout << player -> getName();
    std::cout << " currently has ";
    std::cout << player -> getHealth();
    std::cout << " health.\n";
    do {
      std::cout << "What is the answer to:\n";
      std::cout << counter << " * " << 2 * counter << " = ";
      std::cin >> answer;
      if (answer == (counter * (2 * counter))) {
      std::cout << "Correct!\n";
      std::cout << "You fired at the spider\n";
      inter -> attackFromPlayer(spider, -10);
      } else {
      std::cout << "Incorrect!\n";
      std::cout << "The spider launched webbing at you\n";
      inter -> attackFromVillain(player, -50);
      }
      counter++;
    } while (player -> checkDeath() == true &&
                   spider -> checkDeath() == true);
    if (spider -> checkDeath() == false) {
      std::cout << "The spider was slain, you win.\n";
      setLocationComp(2);
      setEnvironmentComp();
    } else {
      std::cout << "YOU DIED!!!!! RIP!!!";
      std::cout << std::endl;
      exit(1);
    }
    delete inter;
    delete spider;
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void Mountain::puzzle() {
  if (getLocationComp(3) == false) {
    std::cout << "\nYOU MUST SOLVE THE RIDDLE\n" << std::endl;
    std::cout << "Crew mate here, here is your hint.";
    std::cout << " It goes on your hand.\n";
    std::string answer;
    std::cout << "What has four fingers and a thumb ";
    std::cout << ", but is not alive? (make sure answer ";
    std::cout << "is in lowercase)" << std::endl;
    do {
      std::cin >> answer;
      if (answer == "glove") {
      std::cout << "Correct\n";
      } else {
      std::cout << "Incorrect, try again\n";
      }
    } while (answer != "glove");
    setLocationComp(3);
    setEnvironmentComp();
  } else {
    std::cout << "MISSION ALREADY COMPLETED\n";
  }
}

void Mountain::playMission(MainCharacter* player, int c1) {
  if (c1 == 1) {
    climbMountain();
  } else if (c1 == 2) {
    spiderAttack(player);
  } else if (c1 == 3) {
    puzzle();
  } else {
    std::cout << "You are safe from danger here\n";
  }
}
