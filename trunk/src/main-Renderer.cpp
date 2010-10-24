/* main-Renderer.cpp
 *
 * Author Tássio Naia dos Santos
 * This is free software.
 */

/* A ideia deste teste é desenhar um retângulo na tela que seja 
 * dimensionado pela posição do mouse. Um determinado texto é
 * escrito dentro do retângulo.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Renderer.hpp"
#include "SDLManager.hpp"

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

int main( int argc, char ** argv )
{
  using std::vector;
  using std::string;
  SDLManager sdlman = SDLManager::getInstance();

  vector<string> texto;
  texto.push_back( string( "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a." ) );
  texto.push_back( string( "Olê yayá!" ) );
  texto.push_back( string( "Um autor emblemático, que por sua atuação política, retrata bem a fusão etre os campos histórico e político, é o franês François G. Guisot, para quem as invações bárbaras teriam causado a decadência da civilização romana." ) );
  texto.push_back( string( "Cete manière de juger l'histoire d'Allemagne est conforme aux documents historiques des siècles passés." ) );
  texto.push_back( string( "Um louco, e com todo o direito de sê-lo!" ) );
  texto.push_back( string( "Põe um pouco de ti em tudo aquio que fazes." ) );

  vector<string> * copia_texto = NULL;
  copia_texto = new vector<string> ();
  copia_texto->resize( texto.size() );

  copy( texto.begin(), texto.end(), copia_texto->begin() );

  SDL_Surface * screen = sdlman.getScreen();
  SDL_FillRect( screen, 
		&screen->clip_rect, 
		SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

  SDL_Flip( screen );
  TTF_Font * font = 
    TTF_OpenFont( "../media/fonts/Cash_Font_by_despicablehero.ttf", 20 );
  //  TTF_Font * font = 
  //  TTF_OpenFont( "../media/fonts/newathu.ttf", 15 );
  if( font == NULL )
    {
      std::cerr << "! Couldn't open font." << std::endl;
      return 1;
    }

  std::cout << "o texto tem " << copia_texto->size() << " linhas" << std::endl;//return 0;
  vector<string> * next_texto = NULL;
  SDL_Rect rect = { 50, 100, 350, 6 * TTF_FontLineSkip( font ) };
  SDL_Rect fundo = rect;
  fundo.x = rect.x - 10;
  fundo.y = rect.y - 10;
  fundo.w = rect.w + 20;
  fundo.h = rect.h + 20;

  next_texto = shape_to_fit_rectangle( *copia_texto, font, rect.w, rect.h );
  SDL_Color color = { 89, 89, 109 }; 
  SDL_FillRect( screen, 
		&fundo, 
		SDL_MapRGB( screen->format, 0xF0, 0xF0, 0xF0 ) );
  write_on_surface( screen, font, color, *copia_texto, rect );
  SDL_Flip( screen );
  SDL_Delay( 2000 );
  while( next_texto != NULL )
    {
      //      SDL_Rect rect = { 10, 10, 250, 100 };
      std::cout << "o texto tem " << next_texto->size() << " linhas" << std::endl;//return 0;
      delete copia_texto;
      copia_texto = next_texto;
      next_texto = shape_to_fit_rectangle( *copia_texto, font, rect.w, rect.h );
      std::cout << "o texto tem " << copia_texto->size() << " linhas" << std::endl;//return 0;
      SDL_FillRect( screen, 
		    &screen->clip_rect, 
		    SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
      SDL_FillRect( screen, 
		    &fundo, 
		    SDL_MapRGB( screen->format, 0xF0, 0xF0, 0xF0 ) );
      write_on_surface( screen, font, color, *copia_texto, rect );
      SDL_Flip( screen );
      SDL_Delay( 2000 );
    }
  return 0;
}
