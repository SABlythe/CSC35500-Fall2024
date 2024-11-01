#include "unistd.h"
#include <cstdio>  // for stdin, stdout, FILE, ...
#include <cstring> // for strcpy

using namespace std;

int main(int argc, char *argv[])
{
  int pipefd[2];
  pipe(pipefd); // for simplicity, assume this will work (ignore return value)

  int pid=fork();

  if (pid!=0) // have parent do    rsync origin dest
  {
    close (pipefd[0]); // this code will not read from pipe. 
    dup2  (pipefd[1], fileno(stdout)); // command output should go into pipe 

    char *args[4]; 
    for (int i=0; i< 3; i++) args[i]=new char[10]; // more than enough for each arg
    strcpy(args[0], "rsync");
    strcpy(args[1], "origin");
    strcpy(args[2], "dest");
    args[3] = nullptr;

    execvp(args[0], args);  
  }
  else // child does     tail -2     (and redirects output to results.txt)
  {
    close (pipefd[1]); // this code will not write to pipe. 
    dup2  (pipefd[0], fileno(stdin)); // command input should come from pipe 
    
    char *args[3];
    for (int i=0; i< 2; i++) args[i]=new char[10]; // more than enough for each arg
    strcpy(args[0], "tail");
    strcpy(args[1], "-2");
    args[2] = nullptr;

    // deal with    > results.txt    part
    FILE *fp = fopen("results.txt", "w"); 
    dup2(fileno(fp) , fileno(stdout)); 

    execvp(args[0], args);
  }

  // this cose should not be reached, but it keeps the compiler happy
  return 0;
}

