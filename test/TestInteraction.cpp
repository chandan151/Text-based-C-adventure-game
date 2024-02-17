#include <string>

#include "Movements.h"
#include "Item.h"
#include "MainCharacter.h"
#include "Environment.h"
#include "BackPack.h"

#include "gtest/gtest.h"

TEST(TestInteraction, TestAddToBP) {
  MainCharacter* c = new MainCharacter();
  Item::ItemType gun = Item::Gun;
  Item* i = new Item();
  Interaction* in = new Interaction();
  i -> setItem(gun);
  in -> addToBP(c, i);

  EXPECT_TRUE(c -> backpack -> checkBP(i));

  delete c;
  delete i;
  delete in;
}

TEST(TestInteraction, TestRemoveFromBP) {
  MainCharacter* c = new MainCharacter();
  Item::ItemType gun = Item::Gun;
  Item* i = new Item();
  Interaction* in = new Interaction();
  i -> setItem(gun);
  in -> addToBP(c, i);

  in -> removeFromBP(c, i);

  EXPECT_FALSE(c -> backpack -> checkBP(i));
  delete c;
  delete i;
  delete in;
}

TEST(TestInteraction, TestAttackFromPlayer) {
  RealCharacter* ch = new RealCharacter();
  Interaction* inter = new Interaction();

  inter -> attackFromPlayer(ch, -10);

  EXPECT_EQ(ch -> getHealth(), 90);

  delete ch;
  delete inter;
}

TEST(TestInteraction, TestAttackFromVillain) {
  MainCharacter* ch = new MainCharacter();
  Interaction* inter = new Interaction();

  inter -> attackFromVillain(ch, -10);

  EXPECT_EQ(ch -> getHealth(), 90);

  delete ch;
  delete inter;
}
