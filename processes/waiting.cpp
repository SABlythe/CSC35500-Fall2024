#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char **argv)
{
  cout << "my pid = " << getpid() << endl;

  int cpid = fork();
  if (cpid!=0) //parent
    {
      waitpid(cpid, NULL, 0);
      cout << "The tantrum is done ... thank goodness!" << endl;
    }
  else  //child
    {
      for (int i=0; i<12; i++)
	{
	  cout << "Tantrum-ing !!!" << endl;
	  sleep(1);
	}
    }

  return 0;
}
