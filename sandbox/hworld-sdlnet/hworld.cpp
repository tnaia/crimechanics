#include "SDL/SDL_net.h"
#include <iostream>

int main (int argc, char **argv)
{
  if (SDLNet_Init() < 0)
    {
      std::cerr << "SDL_Init: " << SDL_GetError() << "\n";
      exit (1);
    }

  std::cout << "Hello from SDLNet.\n";
  SDLNet_Quit ();
  return 0;
}
