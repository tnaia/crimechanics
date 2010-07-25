#include<iostream>

int main (int argc, char ** argv)
{
  pid_t pid = fork();
  if (pid == 0) // child
    execl("jogo", "./jogo", (char *) NULL);
  else if (pid < 0)
    std::cout << "forking failed!\n";
  else
    {
      execl ("Bdi.jar", "./Bdi.jar", (char *) NULL);
      std::cout << "não consegui ir pro java.\n";
    }

  return 0;
}
