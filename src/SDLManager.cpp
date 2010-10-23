/* SDLManager.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string> // To handle window captions.
#include "SDLManager.hpp"

SDLManager::SDLManager() 
{
  SCREEN_WIDTH = 640;
  SCREEN_HEIGHT = 480;
  SCREEN_BPP = 32;
  screen = NULL;
  if( !init()) valid = false; 
}

bool SDLManager::init()
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    return false;

  screen = SDL_SetVideoMode( SCREEN_WIDTH, 
			     SCREEN_HEIGHT, 
			     SCREEN_BPP, 
			     SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
      {
	return false;
      }

    //Set the window caption
    SDL_WM_SetCaption( "Básico", NULL );

    return true;
}
