#include <string>

#include "Movements.h"
#include "Item.h"
#include "Character.h"
#include "Environment.h"
#include "BackPack.h"

#include "gtest/gtest.h"

TEST(TestCharacter, TestCharacterName) {
  std::string name =  "name";
  Character* character = new Character();

  character -> setName(name);

  EXPECT_EQ(character -> getName(), name);

  delete character;
}
