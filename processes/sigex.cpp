#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
using namespace std;

void someFunc(int sNum)
{
  int pidOfCompletedChild = waitpid( 0, nullptr, WNOHANG);

  cout << "Got here, snum=" << sNum << endl;

  if (pidOfCompletedChild !=0)
    {
      cout << "parent says: my completed child's PID = " << pidOfCompletedChild << endl;
    }
}

int main(int argc, char **argv)
{
  int pid = fork();
  if (pid!=0) // parent
  {
    signal (SIGCHLD, someFunc);


    cout << "Gimme an int:";
    int dummy; cin >> dummy;
    cout << "You gave me " << dummy << endl;


  }
  else // child
  {
    cout << "Child sleeping ..." << endl;
    cout.flush();
    sleep(5);
    cout << "Child is done napping. And is done. " << endl;
  }

  return 0;
}
