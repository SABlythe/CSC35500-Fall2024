#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int pid;
  for (int i=0; i<4; i++)
  {
  cout << "This line is printed!" << endl;         
     pid = fork();
  }
    
  return 0;
}

