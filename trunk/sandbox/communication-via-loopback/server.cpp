#include "SDL/SDL_net.h"
#include <iostream>

int main (int argc, char **argv)
{

  std::cout << "This is the server (C++).\n";

  if (SDLNet_Init() < 0)
    {
      std::cerr << "SDL_Init: " << SDL_GetError() << "\n";
      exit (1);
    }

  IPaddress ip;
  TCPsocket tcpsock, new_tcpsock;

  if(SDLNet_ResolveHost(&ip,NULL,9999)==-1) {
    printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
    exit(1);
  }

  tcpsock=SDLNet_TCP_Open(&ip);
  if(!tcpsock) {
    printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
    exit(2);
  }

  unsigned long data = 114;
  do {
  printf("Waiting for connection...\n");
  do {
    new_tcpsock = SDLNet_TCP_Accept(tcpsock);
    SDL_Delay(1);
  }
  while (!new_tcpsock);

  // Once connected, I try to send some data                                                                                                             
  std::cout << "(C++): sending "<< data;
  printf (" (hexa: %lX).\n", data);
  SDLNet_TCP_Send(new_tcpsock, &data, sizeof(unsigned long));
  // Then I wait for a long int in response                                                                                                              
  SDLNet_TCP_Recv(new_tcpsock, &data, sizeof(unsigned long));
  // And I print the response:                                                                                                                           
  /* Reflecting byte sequence */
  unsigned long ndata = 0;
  int aux = sizeof( unsigned long );
  unsigned long mask = 0xFF;
  //printf("(C++): Got a response: %lu (hexa %lX) <- antes de inverter\n", data, data );
  while( aux > 0 )
    {
      //printf( "mask = %lX\n", mask );
      //printf ( "%lX >> ( 8 * ( %d -1 ) ) = %lX\n", data, aux, data >> ( 8 * (aux -1)));
      //printf ( "mask & (%lX >> ( 8 * ( %d -1 ) )) = %lX\n",data, aux,  mask & (data >> ( 8 * (aux -1))));
      ndata |=  ( ( mask & ( data >> ( 8 * ( aux -1 ) ) ) ) << (8 * ( sizeof( unsigned long) -aux ) ) );
      --aux;
    }
  data = ndata >>32;
  printf("(C++): Got a response: %lu (hexa %lX)\n", data, data );
}while( data > 0 );
 
  SDLNet_TCP_Close(tcpsock);
  SDLNet_TCP_Close(new_tcpsock);


  SDLNet_Quit ();
  return 0;
}
