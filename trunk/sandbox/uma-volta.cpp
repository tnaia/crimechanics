#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_gfxPrimitives.h"
#include <string>
#include <sstream>
#include <math.h>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *screen = NULL;

//THe event structure
SDL_Event event;

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
  SDL_WM_SetCaption( "Rodando caixas", NULL );

  //If everything initialized fine
  return true;
}

void clean_up()
{

  //Quit SDL
  SDL_Quit();
}

class Box
{
  int size;
  int x;
  int y;
public:
  Box( int x = 0, int y = 0, int size = 10 )
  {
    this->x = x;
    this->y = y;
    this->size = size;
  }
  void drawMe() 
  { 
    boxRGBA ( screen, x - size / 2, y - size / 2, x + size / 2, y + size / 2, 0xFF, 0xFF, 0xFF, 0x88 ); }
  void setPosition( int x, int y )
  {
    this->x = x;
    this->y = y;
  }
  void setSize( int size )
  {
    this->size = size;
  }
  int getX() { return x; }
  int getY() { return y; }
};
  
void roda_caixas( int i, int j, int numBoxes, Box *boxes[] )
{
  const double rotationSpeed = 20; // degrees per second
  double angle = 0;
  Uint32 startTicks = SDL_GetTicks();
  Box *a = ( boxes[ i ]->getX() <= boxes[ j ]->getX() ? boxes[ i ] : boxes[ j ]);
  Box *b = ( boxes[ i ]->getX() <= boxes[ j ]->getX() ? boxes[ j ] : boxes[ i ]);
  int BoxAX = a->getX();
  int BoxAY = a->getY();
  int BoxBX = b->getX();
  int BoxBY = b->getY();
  int centerOfRotationX = BoxAX + BoxBX / 2;
  int centerOfRotationY = BoxAY + BoxBY / 2;
  double radiusOfRotation = sqrt( ( BoxAX - BoxBX ) * ( BoxAX - BoxBX ) + ( BoxAY - BoxBY ) * ( BoxAY - BoxBY ) );

  //  Uint32 tempo = 0;
  while( angle < 180 )
    {

      a->setPosition( centerOfRotationX - cos( angle * M_PI / 180) * radiusOfRotation,
		      centerOfRotationY + sin( angle * M_PI / 180) * radiusOfRotation);
      b->setPosition( centerOfRotationX + cos( angle * M_PI / 180) * radiusOfRotation,
		      centerOfRotationY - sin( angle * M_PI / 180) * radiusOfRotation);

      SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x0F, 0x0F, 0x0F ) );

      for( int k = 0; k < numBoxes; ++k )
	boxes[ k ]->drawMe();

      //Update the screen
      SDL_Flip( screen );


      angle = ( double( SDL_GetTicks() - startTicks ) ) * rotationSpeed / 1000;
      //      angle = ( tempo++ ) * rotationSpeed / 1000;

      //      std::stringstream caption;
      //caption << "rodando - angulo: " << angle << "º";
      //SDL_WM_SetCaption( caption.str().c_str(), NULL );
    }

  a->setPosition( BoxAX, BoxAY );
  b->setPosition( BoxBX, BoxBY );
}

int main( int argc, char* argv[] )
{
  //Initialize
  if( init() == false )
    {
      return 1;
    }

  Box b( 0, 0, 4 );

  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x0F, 0x0F, 0x0F ) );
  int degree = 0;
  while( b.getX() >= 0 && b.getY() >= 0 
	 && b.getX() <= screen->w && b.getY() <= screen->h )
    {
            b.setPosition ( screen->w / 2 + ( 60 + degree ) / 6 * cos ( degree * M_PI / 180 ), screen->h / 2 + ( 60 + degree ) / 8 * sin ( degree * M_PI / 180 ) );
	    /*      b.setPosition ( int( degree) % int( screen->w ), 10 + 50 * int( degree / screen->w ) );
      int newSize =  50 * sin( degree / 30 );
      if( newSize < 0 )
	newSize = - newSize;
	b.setSize( newSize );*/
      b.drawMe();

      if( SDL_Flip( screen ) == -1 )
	{
	  return 1;
	}
      degree++;
    }

  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x0F, 0x0F, 0x0F ) );
  b.setSize( 2 );
  int amplitude = screen->h / 2;
  int maxAmplitude = screen->h / 2;
  for (int i = 0;; ++i)
    {
      while( SDL_PollEvent( &event ) )
	{
	  if( event.type == SDL_KEYDOWN )
	    {
	      if( event.key.keysym.sym == SDLK_UP )
		{
		  if ( amplitude < maxAmplitude )
		    amplitude += 1;
		  std::stringstream caption;
		  caption << "amplitude: " << amplitude;
		  SDL_WM_SetCaption( caption.str().c_str(), NULL );
		}
	      else if ( event.key.keysym.sym == SDLK_DOWN )
		{
		  if ( amplitude > -maxAmplitude )
		    amplitude -= 5;
		  std::stringstream caption;
		  caption << "amplitude: " << amplitude;
		  SDL_WM_SetCaption( caption.str().c_str(), NULL );
		}
	    }
	  else if( event.type == SDL_QUIT )
	    {
	      return 0;
	    }

	}

      b.setPosition( i % screen->w, screen->h / 2 + amplitude * sin( i * M_PI / 180 ) );
      b.drawMe();
      if( SDL_Flip( screen ) == -1 )
	{
	  return 1;
	}
    }



  //Clean up
  clean_up();

  return 0;

}
