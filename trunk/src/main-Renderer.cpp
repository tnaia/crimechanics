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

int main( int argc, char ** argv )
{
  using std::vector;
  using std::string;
  SDLManager sdlman = SDLManager::getInstance();

  vector<string> texto;
  texto.push_back( string( "Um autor emblemático, que por sua atuação política, retrata bem a fusão etre os campos histórico e político, é o franês François G. Guisot, para quem as invações bárbaras teriam causado a decadência da civilização romana." ) );
  texto.push_back( string( "Cete manière de juger l'histoire d'Allemagne est conforme aux documents historiques des siècles passés." ) );
  texto.push_back( string( "Um louco, \ne com todo o direito de sê-lo!" ) );

  vector<string> copia_texto;
  copia_texto.resize( texto.size() );

  copy( texto.begin(), texto.end(), copia_texto.begin() );

  for( vector<string>::size_type i = 0; i < copia_texto.size(); ++i )
    std::cout << copia_texto[ i ] << std::endl;


  return 0;
}
