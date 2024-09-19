#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  FILE *fp = fopen(argv[1], "r");
  dup2(fileno(fp), fileno(stdin));

  int var;
  cin >> var;

  cout << var * var << endl;
  return 0;
}
