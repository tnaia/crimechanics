/* StateManager.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

/*
 * The StateManager centralises the point of creation
 * of States and enforcing correct transitions from
 * one state to another.
 *
 * Note
 * It is probably the case that the specialized StateManager
 * on the client side will be a singleton.
 */

class StateManager 
{
public:
  StateManager();
  ~StateManager();

  virtual void SwitchToState( State * pState )
  {
    if( m_pCurrentState != 0 )
      {
	m_pCurrentState->onLeave();
      }

    m_pCurrentState = pState;
    m_pCurrentState->onEnter();
  }

private:
  State * m_pCurrentState;
};
