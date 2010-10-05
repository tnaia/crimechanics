#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_rotozoom.h"
#include <string>
#include <sstream>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *player = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

SDL_Surface *load_image( std::string filename )
{
  //The image that's loated
  SDL_Surface *loadedImage = NULL;

  //The opimized surface that will be used
  SDL_Surface *optimizedImage = NULL;

  //Load the image
  loadedImage = IMG_Load( filename.c_str() );

  //If the image loaded
  if( loadedImage != NULL )
    {
      //Create an optimized surface
      optimizedImage = SDL_DisplayFormat( loadedImage );

      //Free the old surface
      SDL_FreeSurface( loadedImage );

      //If the surface was optimized
      if( optimizedImage != NULL )
	{
	  //Color key surface
	  SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF ) );
	}
    }

  //Return the optimized surface
  return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL )
{
  //Holds offsets
  SDL_Rect offset;

  //Get offsets
  offset.x = x;
  offset.y = y;

  //Blit
  SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
  //Initialize all SDL subsystems
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
      return false;
    }

  //Set up the screen
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

  //I there was an error in setting up the screen
  if( screen == NULL )
    {
      return false;
    }

  //Set the window caption
  SDL_WM_SetCaption( "Rodando", NULL );

  //If everything initialized fine
  return true;
}

bool load_files()
{
  //Load the backgroung image

  player = load_image( "../../media/boy.png" );

  if( player == NULL ) 
    {
      return false;
    }

  //If everything loaded fine
  return true;
}


void clean_up()
{
  //Free the surfaces
  SDL_FreeSurface( player );

  //Quit SDL
  SDL_Quit();
}

int main( int argc, char* argv[] )
{
  //Quit flag
  bool quit = false;
  bool rotate = true;
  double degrees = 0;
  double degreesIncrement = 0.5;

  SDL_Surface *playerRotated = NULL;
  SDL_Surface *playerResized = NULL;

  int xOffset = 0;
  int yOffset = 0;

  //Initialize
  if( init() == false )
    {
      return 1;
    }

  //Load the files
  if( load_files() == false )
    {
      return 1;
    }

  //Scale the image to half of its size.
  playerResized = rotozoomSurface( player, 0, .5, SMOOTHING_ON );

  //Free the original surface
  SDL_FreeSurface( player );

  player = playerResized;
  playerResized = NULL;

  //Color keying on the resized image
  SDL_SetColorKey( player, SDL_SRCCOLORKEY, SDL_MapRGB( player->format, 0xFF, 0xFF, 0xFF ) );

  //While the user hasn't quit
  while( quit == false )
    {

      //Assemble the caption
      std::stringstream caption;
      caption << "clique com qualquer botão do mouse. speed: " << degreesIncrement << " degrees/frame";
      //Set the window caption
      SDL_WM_SetCaption( caption.str().c_str(), NULL );

      //While there's an event to handle
      while( SDL_PollEvent( &event ) )
	{
	  //If a key was pressed
	  if( event.type == SDL_KEYDOWN )
	    {
	      rotate = ( !  rotate );
	    }
	  //If the user has Xed out the window
	  else if( event.type == SDL_QUIT )
	    {
	      //Quit the program
	      quit = true;
	    }
	  //If the mouse moved
	  else if( event.type == SDL_MOUSEMOTION )
	    {
	      xOffset = event.motion.x;
	      yOffset = event.motion.y;
	    }
	  //If a mouse button was pressed
	  else if( event.type == SDL_MOUSEBUTTONDOWN )
	    {
	      if( event.button.button == SDL_BUTTON_LEFT )
		{
		  degreesIncrement *= 2;
		}
	      else if( event.button.button == SDL_BUTTON_RIGHT )
		{
		  degreesIncrement /= 2;
		}
	    }
	}

      if( rotate )
	{
	  degrees += degreesIncrement;
	  while( degrees > 360 )
	    {
	      degrees -= 360;
	    }
	}

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

      playerRotated = rotozoomSurface( player, degrees, 1, SMOOTHING_ON );



      //Draw the player
      apply_surface( xOffset - player->w / 2 - ( playerRotated->w - player->w ) / 2, 
		     yOffset - player->h / 2- ( playerRotated->h - player->h ) / 2, 
		     playerRotated, screen );

      //Free the time surface
      SDL_FreeSurface( playerRotated );

      //Update the screen
      if( SDL_Flip( screen ) == -1 )
	{
	  return 1;
	}
    }

  //Clean up
  clean_up();

  return 0;
}
