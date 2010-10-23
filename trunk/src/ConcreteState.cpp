/* ConcreteState.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

/*
 *
 */

#include "ConcreteState.hpp"
#include "ConcreteStateManager.hpp"
#include "ConcreteStateFactory.hpp"

namespace
{
  State * createState()
  {
    return( & ConcreteState::Instance() );
  }

  bool registerState()
  {
    ConcreteStateManager & aSM = 
      ConcreteStateManager::Instance();
    StateFactory * pSF = aSM.GetFactory();

    return( pSF->register( "Concrete", createState ) );
  }
}

/* static */
ConcreteState & ConcreteState::Instance()
{
  static ConcreteState anInstance;

  return( anInstance );
}
