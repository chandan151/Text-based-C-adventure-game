#include <string>

#include "Movements.h"
#include "Item.h"
#include "MainCharacter.h"
#include "Mountain.h"
#include "SpaceShip.h"
#include "Environment.h"

#include "gtest/gtest.h"

TEST(TestMovements, TestMoveLeft) {
  Mountain* env1 = new Mountain();
  Movements* move1 = new Movements();

  env1 -> setPos(0);
  move1 -> moveLeft(env1);

  EXPECT_EQ(env1 -> getPos(), 1);

  delete move1;
  delete env1;
}

TEST(TestMovements, TestMoveForward) {
  Mountain* env2 = new Mountain();
  Movements* move2 = new Movements();

  env2 -> setPos(0);
  move2 -> moveForward(env2);

  EXPECT_EQ(env2 -> getPos(), 2);

  delete move2;
  delete env2;
}

TEST(TestMovements, TestMoveRight) {
  Environment* env3 = new Mountain();
  Movements* move3 = new Movements();

  env3 -> setPos(0);
  move3 -> moveRight(env3);

  EXPECT_EQ(env3 -> getPos(), 3);

  delete move3;
  delete env3;
}

TEST(TestMovements, TestMoveBackward) {
  Environment* env3 = new Mountain();
  Movements* move3 = new Movements();

  env3 -> setPos(2);
  move3 -> moveBackward(env3);

  EXPECT_EQ(env3 -> getPos(), 0);

  delete move3;
  delete env3;
}

TEST(TestMovements, TestMoveLeftInvalid) {
  Mountain* env1 = new Mountain();
  Movements* move1 = new Movements();

  env1 -> setPos(2);
  move1 -> moveLeft(env1);

  EXPECT_EQ(env1 -> getPos(), 2);

  delete move1;
  delete env1;
}

TEST(TestMovements, TestMoveForwardInvalid) {
  Mountain* env2 = new Mountain();
  Movements* move2 = new Movements();

  env2 -> setPos(1);
  move2 -> moveForward(env2);

  EXPECT_EQ(env2 -> getPos(), 1);

  delete move2;
  delete env2;
}

TEST(TestMovements, TestMoveRightInvalid) {
  Environment* env3 = new Mountain();
  Movements* move3 = new Movements();

  env3 -> setPos(2);
  move3 -> moveRight(env3);

  EXPECT_EQ(env3 -> getPos(), 2);

  delete move3;
  delete env3;
}

TEST(TestMovements, TestMoveBackwardInvalid) {
  Environment* env3 = new Mountain();
  Movements* move3 = new Movements();

  env3 -> setPos(3);
  move3 -> moveBackward(env3);

  EXPECT_EQ(env3 -> getPos(), 3);

  delete move3;
  delete env3;
}

TEST(TestMovements, TestMoveLeftFromRight) {
  Mountain* env1 = new Mountain();
  Movements* move1 = new Movements();

  env1 -> setPos(3);
  move1 -> moveLeft(env1);

  EXPECT_EQ(env1 -> getPos(), 0);

  delete move1;
  delete env1;
}

TEST(TestMovements, TestMoveRightFromLeft) {
  Environment* env3 = new Mountain();
  Movements* move3 = new Movements();

  env3 -> setPos(1);
  move3 -> moveRight(env3);

  EXPECT_EQ(env3 -> getPos(), 0);

  delete move3;
  delete env3;
}

TEST(TestMovements, TestEnvironmentMovement) {
  Environment* env1 = new Mountain();
  Environment* env2 = new SpaceShip();
  Environment* current;
  Movements* move = new Movements();

  current = env1;

  move -> moveEnvironment(current, env2);

  EXPECT_EQ(current, env2);

  delete move;
  delete env1;
  delete env2;
}
