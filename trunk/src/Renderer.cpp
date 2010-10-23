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
using std::vector; using std::string;
vector<string> 
shape_to_fit_rectangle( vector<string> lines, 
					  TTF_Font * f, 
					  int w, 
					  int h,
					  int interline_space )
{

  assert( f != NULL );


  // I'll make lines fit horizontally first
  int accumulated_height = 0;
  bool found_place_to_cut_vertically = false;
  int place_to_cut_vertically = 0;
  // For each line
  for( vector<string>::size_type i = 0; i < lines.size(); ++i )
    {
      const string space = " ";
      /* I do a reverse search lines[ i ] for spaces (the only character 
       * a which I break lines.
       */
      string::size_type pos = string::npos; 
      int line_w;
      int line_h;
      string reduced_line = lines[ i ].substr( 0, pos );
      if( ! TTF_SizeUTF8( f, reduced_line.c_str(), & line_w, & line_h ) )
	{
	  std::cerr << "! Couldn't calculate the size of text:" 
		    << lines[ i ] << std::endl;
	}
      while( line_w > w )
	{
	  pos = lines[ i ].find_last_of( space, pos );
	  if( pos == string::npos )
	    break;

	  reduced_line = lines[ i ].substr( 0, pos );
	  if( ! TTF_SizeUTF8( f, reduced_line.c_str(), & line_w, &line_h ) )
	    {
	      std::cerr << "! Couldn't calculate the size of text:" 
			<< lines[ i ] << std::endl;
	    }
	}

      /* reduced line has the longest substring of lines[ i ] whose
       * rendering is smaller than w, or the longest substring of
       * lines[ i ] without spaces.
       */
      if( reduced_line.size() < lines[ i ].size() )
	{
	  //Let me cut this line in two for ya!
	  string remainder_of_line = 
	    lines[ i ].substr( reduced_line.size() );
	  lines.insert( lines.begin() + i + 1, remainder_of_line );
	  lines[ i ] = reduced_line;
	}

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
  copy( lines.begin() + place_to_cut_vertically, 
	lines.end(), 
	lines_to_return.begin() );

  lines.erase( lines.begin() + place_to_cut_vertically,
	 lines.end() );

    return lines_to_return;
}

bool write_on_rectangle( const string texto, 
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
