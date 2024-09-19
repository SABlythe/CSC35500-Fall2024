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

  execvp (args[0], args);

  cout << "should not see this message!" << endl;

  return 0;
}
