/* Renderer.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

#include "Renderer.hpp"
#include <vector>
#include <string>
#include <cassert>
#include <iostream> // for cerr
#include <algorithm>

/* Breakes the Strings in lines whose width exceeds w when rendered on 
 * the font f. Breaking occurs only on spaces. 
 * After the call, the vecotr lines has as many lines as can be rendered 
 * one below the other (with interline_space between them), using the font, 
 * without exceeding height h. The remainin lines are returned by the funcion,
 * which returns NULL in case.
*/

std::vector<std::string> 
shape_to_fit_rectangle( std::vector<std::string> & lines, 
			TTF_Font * f, 
			int w, 
			int h,
			int interline_space )
{
  using std::vector; using std::string;
  assert( f != NULL );


  // I'll make lines fit horizontally first
  int accumulated_height = 0;
  bool found_place_to_cut_vertically = false;
  int place_to_cut_vertically = 0;
  // For each line
  for( vector<string>::size_type i = 0; i < lines.size(); ++i )
    {
      std::cout<< "chopping line " << i << std::endl;
      string space = " ";
      /* I do a reverse search lines[ i ] for spaces (the only character 
       * a which I break lines.
       */
      string::size_type pos = (lines[ i ]).size() - 1; 
      int line_w;
      int line_h;
      string reduced_line = lines[ i ].substr( 0, pos );
      if( TTF_SizeUTF8( f, reduced_line.c_str(), & line_w, & line_h ) )
	{
	  std::cerr << "! Couldn't calculate the size of text:" 
		    << lines[ i ] << std::endl;
	}
      while( line_w > w )
	{
	  string::size_type new_pos = lines[ i ].find_last_of( space, pos );
	  std::cout << "posição "<< pos << std::endl;
	  if( new_pos == pos )
	    break;
	  pos = new_pos;
	  reduced_line = lines[ i ].substr( 0, pos );
	  if( TTF_SizeUTF8( f, reduced_line.c_str(), & line_w, &line_h ) )
	    {
	      std::cerr << "! Couldn't calculate the size of text:" 
			<< lines[ i ] << std::endl;
	    }
	}

      /* reduced line has the longest substring of lines[ i ] whose
       * rendering is smaller than w, or the longest substring of
       * lines[ i ] without spaces.
       */
      
      if( reduced_line.size() < lines[ i ].size() && reduced_line.size() > 0 )
	{
	  //Let me cut this line in two for ya!
	  string remainder_of_line = 
	    lines[ i ].substr( reduced_line.size() );
	  if( i < 
	  lines.insert( lines.begin() + i + 1, remainder_of_line ); // tirei um +1
	  lines[ i ] = reduced_line;
	  }
      lines[ i ] = reduced_line;

      accumulated_height += line_h;
      if( !found_place_to_cut_vertically 
	  && ( accumulated_height > h 
	       || accumulated_height + interline_space > h ) )
	{
	  found_place_to_cut_vertically = true;
	  place_to_cut_vertically = i;
	}
    }

  //Splits vector lines in two.
  vector<string> lines_to_return;
  if( found_place_to_cut_vertically )
    {
      copy( lines.begin() + place_to_cut_vertically, 
	    lines.end(), 
	    lines_to_return.begin() );

      lines.erase( lines.begin() + place_to_cut_vertically,
		   lines.end() );
    }

    return lines_to_return;
}

bool write_on_rectangle( const std::string texto, 
			 SDL_Surface * s, 
			 TTF_Font * f, 
			 SDL_Color textColor )
{
  assert( s != NULL );
  assert( f != NULL );


  SDL_Surface * message;
  message =  TTF_RenderUTF8_Solid( f, texto.c_str(), textColor );


  return true;
}

bool write_on_surface( SDL_Surface * s,
		       TTF_Font * f,
		       SDL_Color c,
		       const std::vector<std::string> lines, 
		       SDL_Rect rect, 
		       int interline_space )
{
  using std::vector; using std::string;
  assert( s != NULL );
  assert( f != NULL );

  bool ret = true; // Success or failuire of writing

  SDL_Surface * message = NULL;
  for( vector<string>::size_type i = 0; i < lines.size(); ++i )
    {
      message = TTF_RenderUTF8_Solid( f, lines[ i ].c_str(), c );
      SDL_BlitSurface( message, NULL, s, & rect );
      int line_h;
      if( TTF_SizeUTF8( f, lines[ i ].c_str(), NULL, & line_h ) )
	ret = false;
      rect.y += interline_space + line_h;
    }

  return ret;
}
