/* jogo-cpp.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */



/* SDL libraries for rendering, playing sounds,
 *  capturing input, etc.
 */
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_gfx.h"

/* Our libraries */
#include "ConcreteStateManager.hpp"
#include "ConcreteState.hpp"
#include "Renderer.hpp"

int main( int argc, char ** argv )
{
  Time t1 - GetTime();
  Time dt = 0;
  bool quit = false;
  while( !quit )
    {
      ConcreteStateManager & aSM =
	ConcreteStateManager::Instance();

      State * pState = aSM.GetCurrentState();
      if( pState != 0 )
	{
	  pState->Updade( dt );
	  pState->Draw( pRenderer );
	}
      Timer t2 = GetTime();
      dt = t2 - t1;
      t1 = t2;
    }

}
