/* State.cpp
 *
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

/*
 * A state is a single mode of behaviour that determines 
 * what the game is doing at any one time.
 *
 * Note
 * It is worth considering making a derived State a 
 * singleton.
 */



class State 
{
public:
  State();
  virtual ~State();

  virtual void Update( Time dt ) = 0;
  virtual void Draw( Renderer * pRenderer ) const = 0;
  virtual void OnEnter() { ; }
  virtual void OnLeave() { ; }
};  
