#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int pid;
  for (int i=0; i<4; i++)
  {
     pid = fork();
  }
  cout << "This line is printed!" << endl;         
    
  return 0;
}

