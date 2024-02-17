#include "SpaceGame.h"
#include <cstring>

const char* environments[] = {"mountain", "ship", "colony"};
const char* yesOrNo[] = {"yes", "no"};
const char* movement[] = {"left", "right", "up", "down"};
const char* decisions[] = {"move", "explore", "view"};
const char* bpAddRemove[] = {"add", "remove"};
const char* validItems[] = {"gun", "flashlight", "food"};

SpaceGame::SpaceGame() {
}

SpaceGame::~SpaceGame() {
}

void SpaceGame::playGame() {
  Environment* mountain = new Mountain();
  Environment* ship = new SpaceShip();
  Environment* colony = new SpaceColony();
  Environment* current;
  Interaction* inter = new Interaction();
  Movements* move = new Movements();
  MainCharacter* player = new MainCharacter();
  intro(player);
  introduceNPCs();
  Item* item1 = new Item();
  Item::ItemType gun = Item::Gun;
  Item* item2 = new Item();
  Item::ItemType flashlight = Item::Flashlight;
  Item* item3 = new Item();
  Item::ItemType food = Item::Food;
  item1 -> setItem(gun);
  item2 -> setItem(flashlight);
  item3 -> setItem(food);
  mountain -> setName("Mountain");
  ship -> setName("Space Ship");
  colony -> setName("Space Colony");
  current = ship;
  std::string decision;
  bool checkGame = false;
  do {
    std::cout << "You are currently on " << current->getName() << std::endl;
    std::cout << "Would you like to move, explore this environment, ";
    std::cout << "or view possible items";
    std::cout << "(add/drop from backpack)?" << std::endl;
    decision = getValidInput(decisions, 3);
    if (decision == "move") {
      moveOptions(current, mountain, ship, colony, move, player);
    } else if (decision == "explore") {
      current -> explore();
    } else {
      std::cout << "The possbile items here are ";
      std::cout << item1 -> itemToString(gun) << ", ";
      std::cout << item2 -> itemToString(flashlight) << ", and ";
      std::cout << item3 -> itemToString(food) << ". " << std::endl;
      player-> backpack -> displayItems();
      std::string bpDecision;
      std::cout << "Would you like to add or remove an item from BackPack?\n";
      bpDecision = getValidInput(bpAddRemove, 2);
      std::string itemInt;
      if (bpDecision == "add") {
        std::cout << "What item(gun, flashlight, food)?" << std::endl;
        itemInt = getValidInput(validItems, 3);
        if (itemInt == "gun") {
          inter -> addToBP(player, item1);
        } else if (itemInt == "flashlight") {
          inter -> addToBP(player, item2);
        } else if (itemInt == "food") {
            inter -> addToBP(player, item3);
  }
      } else {
        std::cout << "What item(gun, flashlight, food)?" << std::endl;
        itemInt = getValidInput(validItems, 6);
        if (itemInt == "gun") {
          inter -> removeFromBP(player, item1);
        } else if (itemInt == "flashlight") {
            inter -> removeFromBP(player, item2);
          } else if (itemInt == "food") {
            inter -> removeFromBP(player, item3);
  }
      }
    }
    checkGame = false;
    if ( mountain -> getEnvironmentComp() == true &&
      ship -> getEnvironmentComp() == true &&
      colony -> getEnvironmentComp() == true) {
      checkGame = true;
    }
  } while (checkGame == false);
}

void SpaceGame::moveOptions(Environment*& current, Environment* mountain,
                             Environment* ship, Environment* colony,
                             Movements* move, MainCharacter* player) {
  std::string moveEnv;
  std::string moveLoc;
  do {
    std::cout << "Would you like to switch environment?\n";
    moveEnv = getValidInput(yesOrNo, 2);
    if (moveEnv == "no") {
      std::cout << "You are not moving from " << current -> getName();
      std::cout << std::endl;
    } else if (moveEnv == "yes") {
      std::cout << "What environment would you like to visit?\n";
      std::string env = getValidInput(environments, 3);
      if (env == "mountain") {
        move -> moveEnvironment(current, mountain);
      } else if (env == "ship") {
        move -> moveEnvironment(current, ship);
      } else {
        move -> moveEnvironment(current, colony);
      }
    }
    std::cout << "Would you like to move in " << current -> getName();
    std::cout << "?\n";
    moveLoc = getValidInput(yesOrNo, 2);
    while (moveLoc == "yes") {
      std::cout << "What direction?\n";
      std::string location = getValidInput(movement, 4);
      if (location == "left") {
        move -> moveLeft(current);
      } else if (location == "right") {
          move -> moveRight(current);
      } else if (location == "up") {
          move -> moveForward(current);
      } else {
          move -> moveBackward(current);
      }
      viewOrPlayMission(player, current);
      checkEndGame(mountain, ship, colony);
      std::cout << "Would you like to move again?" << std::endl;
      moveLoc = getValidInput(yesOrNo, 2);
    }
  } while (moveEnv == "yes");
}

bool SpaceGame::checkValidInput(char input[],
        const char* possible[],
        int size) {
  for (int i = 0; i < size; i ++) {
    if (strcmp(input, possible[i]) == 0) {
      return true;
    }
  }
  return false;
}

std::string SpaceGame::getValidInput(const char* possible[],
                                     int size) {
  char* input = new char[100];
  do {
    std::cin >> input;
    if (checkValidInput(input, possible, size) == false) {
      std::cout << "INVALID INPUT, TRY AGAIN\n";
      std::cout << "Valid Inputs are: ";
      for (int i = 0; i < size - 1; i++) {
        std::cout << possible[i] << ", ";
      }
      std::cout << possible[size - 1] << std::endl;
    }
  } while (checkValidInput(input, possible, size) == false);
  std::string newInput(input);
  delete input;
  return newInput;
}

void SpaceGame::viewOrPlayMission(MainCharacter* player,
                             Environment* current) {
  int currentLocation = current -> getPos();
  bool currentComp = current -> getLocationComp(currentLocation);
  if (currentLocation != 0 &&
     currentComp == false) {
      std::cout << "There seems to be a mission here.\n";
      std::cout << "Would you like to view the mission?\n";
      std::string getUserResponse = getValidInput(yesOrNo, 2);
      if (getUserResponse == "yes") {
        current -> viewMission(currentLocation);
      }
      if (getUserResponse == "no") {
        std::cout << "I see... you are not the smartest\n";
      }
      std::cout << "Would you like to play this mission?\n";
      getUserResponse = getValidInput(yesOrNo, 2);
      if (getUserResponse == "yes") {
        current -> playMission(player, currentLocation);
      }
  } else if (currentLocation != 0) {
    std::cout << "This mission has been completed!\n";
  }
}

void SpaceGame::introduceNPCs() {
  NPC* helper = new RobotHelper();
  NPC* crew = new CrewMember();

  helper -> intro();
  helper -> helpMainCharacter();
  std::cout << "\n";
  crew -> intro();
  std::cout << "\n";
}

void SpaceGame::checkEndGame(Environment* mountain,
                            Environment* ship,
                            Environment* colony) {
  if ( mountain -> getEnvironmentComp() == true &&
      ship -> getEnvironmentComp() == true &&
      colony -> getEnvironmentComp() == true) {
    std::cout << "As you complete this mission, ";
    std::cout << "you notice something, a person.\n";
    std::cout << "Buried underneath a ton of rubble, ";
    std::cout << "a hand emerges.\n";
    std::cout << "You pull it out, and realize it's ";
    std::cout << "Your brother.\n";
    std::cout << "You cry, as you have found the most important ";
    std::cout << "person in your life. You can now safely make ";
    std::cout << "back to Earth, with him right beside you.\n";

    std::cout << "\nTHANK YOU FOR PLAYING, WE HOPE YOU ENJOYED\n";
    exit(1);
  }
}

void SpaceGame::intro(MainCharacter* player) {
  std::cout << "Welcome to SPACE GAME\n";
  std::string name;
  std::cout << "Pleaser Enter your name.\n";
  std::cin >> name;
  player -> setName(name);
  std::cout << " Hello " << name;
  std::cout << " welcome, to space, remember what your mission is.\n";
  std::cout << "You came to space to find your lost brother, remember?\n";
  std::cout << "If you have any questions refer to the user manual.\n\n";
}
