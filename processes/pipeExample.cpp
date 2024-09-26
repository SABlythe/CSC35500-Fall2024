#include <cstdio>
#include <cstring>   // for strlen
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{

  int pipefds[2];
  int status = pipe(pipefds);

  if (status != 0)
    {
      cerr << "pipe() call failed!" << endl;
      return 1;
    }
  

  int pid= fork();

  if (pid!=0) // parent
    {
      close (pipefds[1]); 
      dup2 ( pipefds[0], fileno(stdin) );
      

      char *args[2];

      int myLength;// = strlen("wc");
      string wc = "wc";
      myLength = wc.length();
      args[0] = new char [myLength+1];
      strcpy(args[0], wc.c_str() );
      args[1] = nullptr;

      cout << "do wc  (parent)" << endl;
      execvp("wc", args);


    }
  else //, so in child
    {

      
      char *args[3];

      close (pipefds[0]); 
      dup2 ( pipefds[1], fileno(stdout) );
      
      int myLength;// = strlen("ls");
      string str = "ls";
      myLength = str.length();
      args[0] = new char [myLength+1];
      strcpy(args[0], str.c_str() );

      str = "-l";
      myLength = str.length();
      args[1] = new char [myLength+1];
      strcpy(args[1], str.c_str() );
      
      args[2] = nullptr;

      cout << "do  ls -l   (child)" << endl;
      execvp(args[0], args);


    }
  
  return 0;
}
