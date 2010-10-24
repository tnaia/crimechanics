/* SDLManager.hpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

#include "SDL/SDL.h"

class SDLManager
{
public:
  ~SDLManager();  
  static SDLManager & getInstance();
  bool isValid() const { return valid; };
  SDL_Surface * getScreen() const;
private:
  static SDLManager * me;
  SDLManager();
  bool valid; // Can the manager be used?
   int SCREEN_WIDTH;
   int SCREEN_HEIGHT;
   int SCREEN_BPP;
   SDL_Surface *screen;
   SDL_Event event;
};
