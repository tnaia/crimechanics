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
  texto.push_back( string( "Olê yayá!" ) );
  texto.push_back( string( "Um autor emblemático, que por sua atuação política, retrata bem a fusão etre os campos histórico e político, é o franês François G. Guisot, para quem as invações bárbaras teriam causado a decadência da civilização romana." ) );
  texto.push_back( string( "Cete manière de juger l'histoire d'Allemagne est conforme aux documents historiques des siècles passés." ) );
  texto.push_back( string( "Um louco, e com todo o direito de sê-lo!" ) );

  vector<string> copia_texto;
  copia_texto.resize( texto.size() );

  copy( texto.begin(), texto.end(), copia_texto.begin() );

  /*
  for( vector<string>::size_type i = 0; i < copia_texto.size(); ++i )
    std::cout << copia_texto[ i ] << std::endl;

  SDL_Delay( 2000 );
  std::cout << "Agora, ciao!" << std::endl;
  */
  SDL_Surface * screen = sdlman.getScreen();
  SDL_FillRect( screen, 
		&screen->clip_rect, 
		SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
  SDL_Flip( screen );
  TTF_Font * font = 
    TTF_OpenFont( "../media/fonts/Cash_Font_by_despicablehero.ttf", 20 );
  if( font == NULL )
    {
      std::cerr << "! Couldn't open font." << std::endl;
      return 1;
    }

  /*
  std::cout << texto[ 0 ] << "." << std::endl <<
    texto[ 0 ].substr( 0, texto[ 0 ].find_last_of( string( " " ), texto[ 0 ].size() - 1 ) ) << "." << std::endl;
  return 0;
  */
  std::cout << "o texto tem " << copia_texto.size() << " linhas" << std::endl;//return 0;
  shape_to_fit_rectangle( copia_texto, font, 200, 200 );
  SDL_Rect rect = { 10, 10, 200, 200 };
  SDL_Color color = { 255, 0, 0 }; 
  write_on_surface( screen, font, color, copia_texto, rect );

  SDL_Flip( screen );
  SDL_Delay( 10000 );
  return 0;
}
