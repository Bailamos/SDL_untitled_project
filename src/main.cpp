#include <stdio.h>
#include <vector>
#include "headers/game.hpp"

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