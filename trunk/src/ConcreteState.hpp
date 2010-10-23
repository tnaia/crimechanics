/* ConcreteState.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

/*
 * Template for a client-domain concrete class 
 * derived from State.
 *
 * Pobable concrete classes from this template:
 * cutScene, MenuHierarchy, MainGame, Paused...
 */

#ifndef CONCRETESTATE_HPP
#define CONCRETESTATE_HPP

#include "mylibs/State.hpp"

class ConcreteState : public State
{
public:
  static ConcreteState & Instance();

  void Update( Time dt );
  void Draw( Renderer * pRenderer ) const;

private:
  //...
};

#endif /* not CONCRETESTATE_HPP */
