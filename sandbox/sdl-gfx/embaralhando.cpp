#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_gfxPrimitives.h"
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>

//Screen attributes
const int SCREEN_WIDTH = 480;//640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *screen = NULL;

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
  int x;
  int y;
public:
  Box( int x = 0, int y = 0 ) { this->x = x; this->y = y; }
  void drawMe() { boxRGBA ( screen, x, y, x + 10, y + 10, 0xFF, 0xFF, 0xFF, 0x88 ); }
  void setPosition( int x, int y ) { this->x = x; this->y = y; }
  int getX() { return x; }
  int getY() { return y; }
};
 
// rotationSpeed: degrees per second 
int roda_caixas( int i, int j, int numBoxes, Box *boxes[], const double rotationSpeed = 360 )
{
  double angle = 0;
  Uint32 startTicks = SDL_GetTicks();
  Box *a = ( ( boxes[ i ]->getX() <= boxes[ j ]->getX() ) ? boxes[ i ] : boxes[ j ]);
  Box *b = ( ( boxes[ i ]->getX() <= boxes[ j ]->getX() ) ? boxes[ j ] : boxes[ i ]);
  int BoxAX = a->getX();
  int BoxAY = a->getY();
  int BoxBX = b->getX();
  int BoxBY = b->getY();
  int centerOfRotationX = ( BoxAX + BoxBX ) / 2;
  int centerOfRotationY = ( BoxAY + BoxBY ) / 2;
  double radiusOfRotation = sqrt( ( BoxAX - BoxBX ) * ( BoxAX - BoxBX ) + ( BoxAY - BoxBY ) * ( BoxAY - BoxBY ) ) / 2;

  /*
  std::stringstream caption;
  caption << "dx: " << BoxAX - BoxBX << " dy: " << BoxAY - BoxBY << " r: " << radiusOfRotation;
  SDL_WM_SetCaption( caption.str().c_str(), NULL );

  for( int k = 0; k < numBoxes; ++k )
    boxes[ k ]->drawMe();
  */
  //  Uint32 tempo = 0;

  while( angle < 180 && angle > -180 )
    {
      while( SDL_PollEvent( &event ) )
	{
	  if (event.type == SDL_QUIT)
	    {
	      return -1;
	    }
	}
      
      a->setPosition( centerOfRotationX - int( cos( angle * M_PI / 180) * radiusOfRotation ),
		      centerOfRotationY + int( sin( angle * M_PI / 180) * radiusOfRotation ) );
      b->setPosition( centerOfRotationX + int( cos( angle * M_PI / 180) * radiusOfRotation ),
		      centerOfRotationY - int( sin( angle * M_PI / 180) * radiusOfRotation ) );

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

  return 0;
}

int main( int argc, char* argv[] )
{
  int numBoxes = 4;
  double rotationSpeed = 210;

  if( argc >= 2 )
    {
      numBoxes = atoi( argv[ 1 ] );
    }
  if( argc == 3 )
    {
      rotationSpeed = atoi( argv[ 2 ] );
    }


  //Initialize
  if( init() == false )
    {
      return 1;
    }

  //    Box *boxes[ 4 ];
   Box **boxes = new Box * [ numBoxes ];

   for( int i = 0; i < numBoxes; ++i )
     {
       boxes[ i ] = new Box( screen->w * (i + 1) / ( numBoxes + 1), screen->h / 2);
     }
      
   int increment = 1;
   bool quit = false;
   int i = 0;
   int j;
   while( !quit ) 
     {
       for( ; ( i < numBoxes ) && ( i >= 0 ) && ( !quit ); i += increment )
	 for( j = i + increment; ( j < numBoxes ) && ( j >= 0 ); j += increment )
	   {
	     std::stringstream caption;
	     caption << "(incremento = " << increment << ") rodando caixas " << i << " e " << j;
	     SDL_WM_SetCaption( caption.str().c_str(), NULL );
	     /*
	     while( !SDL_PollEvent( &event ) )
	       {
		 if( event.type == SDL_MOUSEBUTTONDOWN )
		   break;
	       }
	     */
	     if( roda_caixas( i, j, numBoxes, boxes, rotationSpeed * increment ) == -1 )
	       {
		 //		 std::cout << "vou sair" << std::endl;
		 quit = true;
		 break;
	       }
	   }
       increment = - increment;
       i += increment;
     }






  //  roda_caixas( 0, 1, numBoxes, boxes );
  delete [] boxes;

  //Clean up
  clean_up();

  return 0;

}
