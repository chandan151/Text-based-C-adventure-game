#include <string>

#include "Movements.h"
#include "Item.h"
#include "MainCharacter.h"
#include "Environment.h"
#include "BackPack.h"
#include "Mountain.h"

#include "gtest/gtest.h"

TEST(TestEnvironment, TestEnvironmentNaming) {
  std::string name =  "name";
  Environment* env = new Mountain();

  env -> setName(name);

  EXPECT_EQ(env -> getName(), name);

  delete env;
}

TEST(TestEnvironment, TestEnvironmentCOmpletionTrue) {
  Environment* env = new Mountain();

  env -> setLocationComp(1);
  env -> setLocationComp(2);
  env -> setLocationComp(3);

  env -> setEnvironmentComp();

  EXPECT_TRUE(env -> getEnvironmentComp());

  delete env;
}

TEST(TestEnvironment, TestEnvironmentCOmpletionFalse) {
  Environment* env = new Mountain();

  env -> setLocationComp(1);
  env -> setLocationComp(2);

  env -> setEnvironmentComp();

  EXPECT_FALSE(env -> getEnvironmentComp());

  delete env;
}
