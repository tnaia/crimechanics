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

  std::cout << "Hello from SDLNet.\n";

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
  printf("Waiting for connection...\n");
  do {
    new_tcpsock = SDLNet_TCP_Accept(tcpsock);
    SDL_Delay(1);
  }
  while (!new_tcpsock);

  // Once connected, I try to send some data                                                                                                             
  unsigned long data = 114;
  std::cout << "(C++): sending 114";
  printf (" (%lX).\n", data);
  SDLNet_TCP_Send(new_tcpsock, &data, sizeof(unsigned long));
  // Then I wait for a long int in response                                                                                                              
  SDLNet_TCP_Recv(new_tcpsock, &data, sizeof(unsigned long));
  // And I print the response:                                                                                                                           
  printf("(C++): Got a response: %lX\n", data);

  SDLNet_TCP_Close(tcpsock);
  SDLNet_TCP_Close(new_tcpsock);


  SDLNet_Quit ();
  return 0;
}
