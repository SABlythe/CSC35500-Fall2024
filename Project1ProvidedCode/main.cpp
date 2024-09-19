#include <iostream>
#include <csignal>

#include <unistd.h>

#include "Command.hpp"

/*****************************************************
 *  Example usage of the Command class for project 1 *
 *****************************************************/

int main(void)
{
    Command com;
    int num=1; // keep track of number fo commands. 
    
    // prompt for and read in first command. 
    cout << ">>>> ";
    com.read();
    
    while(com.name() != "exit")
    {
        // print out current command
        cout << num++ << ")" << com << endl;
        
        // prompt for and read next command
	cout << ">>>> ";
        com.read();
    }
    
    cout << "Thank you for using mini-shell. We now return you to your regularly scheduled shell!" << endl;
}
