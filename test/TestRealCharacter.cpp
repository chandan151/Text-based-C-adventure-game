#include <string>

#include "Movements.h"
#include "Item.h"
#include "Character.h"
#include "RealCharacter.h"
#include "Environment.h"
#include "BackPack.h"

#include "gtest/gtest.h"

TEST(TestRealCharacter, TestRealCharacterHealth) {
  RealCharacter* ch = new RealCharacter();
  ch -> updateHealth(50);

  EXPECT_EQ(ch -> getHealth(), 150);
  delete ch;
}

TEST(TestRealCharacter, TestRealCharacterDeathFalse) {
  RealCharacter* ch = new RealCharacter();
  ch -> updateHealth(-150);

  EXPECT_FALSE(ch -> checkDeath());
  delete ch;
}

TEST(TestRealCharacter, TestRealCharacterAmmo) {
  RealCharacter* ch = new RealCharacter();

  EXPECT_EQ(ch -> getAmmo(), 10);
  delete ch;
}


