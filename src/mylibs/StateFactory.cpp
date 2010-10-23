/* StateFactory.cpp
 * 
 * Author: Tássio Naia dos Santos
 * This is free software.
 */

/*
 * A state factory isolates the creation of concrete States
 * defined on the client side of the application.
 *
 */

class StateFactory
{
public:
  State * CreateState( const char * pName ) = 0;
};
