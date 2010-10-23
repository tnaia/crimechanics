/* SDLManager.hpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

#include "SDL/SDL.h"

class SDLManager
{
public:
  static SDLManager & getInstance() { return me; };
  static bool valid; // Can the manager be used?
private:
  static SDLManager me;
  SDLManager();
  bool init();
  int SCREEN_WIDTH;
  int SCREEN_HEIGHT;
  int SCREEN_BPP;
  SDL_Surface *screen;
  SDL_Event event;
};
