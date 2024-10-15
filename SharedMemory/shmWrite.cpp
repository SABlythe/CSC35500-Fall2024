#include <iostream>
#include <cerrno>
#include <cstdlib>

#include <sys/shm.h>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=3)
    {
      cerr << "USAGE: " << argv[0] << " <key number> <val to write>"
	   << endl;
      return 1;
    }

  int myKeyVal = atoi(argv[1]);
  int valToWrite =  atoi(argv[2]);

  int shm_id = shmget(myKeyVal, 1024 /*1 KB*/, 0);

  if (shm_id==-1)
    {
      cerr << "shmget() failed with errno = "
	   << errno << endl;
      return 2;
    }

  int *sharedArray = (int *) shmat(shm_id, NULL, 0);

  if (sharedArray == (int *) -1)
    {
      cerr << "shmat() failed " << endl;
      return 3;
    }
      
  sharedArray[0] = valToWrite;
  
  return 0;
}
