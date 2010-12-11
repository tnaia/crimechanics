/* main.cpp
 *

 * Author: Tássio Naia dos Santos
 * This is free software.
 */

#include<iostream>

int main( int argc, char ** argv )
{
  pid_t pid = fork();
  if( pid == 0 ) // child
    execl( "jogo-cpp", 
	   "./jogo-cpp", 
	   ( char * ) NULL );
  else if( pid < 0 )
    std::cout << "Error: forking failed." << std::endl;
  else
    {
      execl( "/bin/sh", 
	     "sh", "-c", 
	     "java -jar Client.jar", 
	     (char *) NULL );
      std::cout << "Error: failed to run Client.jar" 
		<< std::endl;
    }
  return 0;
}
