#include "SDL/SDL.h" // Talvez seja "SDL.h" no windows.


int main( int argc, char **argv )
{
  //The images
  SDL_Surface* hello = NULL;
  SDL_Surface* screen = NULL;

  //Start SDL
  SDL_Init( SDL_INIT_EVERYTHING );

  //Set up screen
  screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

  //Load image
  hello = SDL_LoadBMP( "../../media/hello.bmp" );

  //Apply image to screen
  SDL_BlitSurface( hello, NULL, screen, NULL );

  //Update screen
  SDL_Flip( screen );

  //Pause
  SDL_Delay( 2000 ); //2000 miliseconds


  //Free the loaded image
  SDL_FreeSurface( hello );

  //Quit SDL
  SDL_Quit();
  return 0;
}
