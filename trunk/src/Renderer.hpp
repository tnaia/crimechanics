/* Renderer.hpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

std::vector<std::string> 
shape_to_fit_rectangle( std::vector<std::string> & lines, 
			TTF_Font * f, 
			int w, 
			int h,
			int interline_space = 0 );

bool write_on_surface( SDL_Surface * s,
		       TTF_Font * f,
		       SDL_Color c,
		       const std::vector<std::string> lines, 
		       SDL_Rect rect, 
		       int interline_space = 0 );
#endif /* not RENDERER_HPP */
