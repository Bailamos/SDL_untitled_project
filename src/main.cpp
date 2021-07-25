#include <stdio.h>
#include <vector>
#include "src/game.hpp"
#include <iostream>

int x = 0;

int main(int argc, char *args[])
{
  Game game;
  if (game.isGameRunning())
  {
    game.start();
  }

  return 0;
}