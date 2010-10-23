/* ConcreteState.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

/*
 * Client-domain concrete class derived from State.
 *
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
