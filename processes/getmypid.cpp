#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{
  cout << "my pid = " << getpid() << endl;

  if (fork()!=0)
    {
      cout << "good on fork!" << endl;
    }
  else
    {
      cout << "bad on fork!" << endl;
    }
  return 0;
}
