#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

int main(int argc, char * argv[])
{
  char* args[3];

  args[0] = new char[10];
  strcpy(args[0], "ls");

  args[1] = new char[10];
  strcpy(args[1], "-la");

  args[2] = NULL;


  int pid = fork();

  if (pid==0)
    {
      cout << "in child!!" << endl;
      execvp (args[0], args);
    }
  else
    {
      cout << "in parent" << endl; 
    }



  
  cout << "If you see this, either execvp() failed or was not called!"
       << endl;

  return 0;
}
