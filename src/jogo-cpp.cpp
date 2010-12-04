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
#include "MyStateManager.hpp"
#include "Renderer.hpp"

// Concrete states...

class Time {
 public:
  static Time GetTime()  {  return SDL_GetTicks(); };
 Time( Uint32 t ) : time( t );
 private:
  Uint32 time;
};

int main( int argc, char ** argv )
{

  // Start SDL
  if( init() == false )
    {
      std::cerr << "Erro: falha ao iniciar SDL." << std::endl;
      return 1;
    }

  Time t1 - Time::GetTime();
  Time dt = 0;
  bool quit = false;
  MyStateManager & stateM =
    MyStateManager::Instance();
  while( !quit )
    {


      State * pState = stateM.GetCurrentState();
      if( pState != 0 )
	{
	  pState->Updade( dt );
	  pState->Draw( pRenderer );
	}
      Timer t2 = Time::GetTime();
      dt = t2 - t1;
      t1 = t2;
    }

}
