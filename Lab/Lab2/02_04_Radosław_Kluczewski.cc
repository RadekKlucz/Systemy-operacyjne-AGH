#include <unistd.h>
#include <iostream>
#include <csignal>

using namespace std;

void signalHandler( int signum ) {
    switch (signum)
    {
    case SIGABRT:
        cout << "Interrupt signal SIGABRT (" << signum << ") received.\n";
        break;
    case SIGFPE:
        cout << "Interrupt signal SIGFPE (" << signum << ") received.\n";
        break;
    case SIGILL:
        cout << "Interrupt signal SIGILL (" << signum << ") received.\n";
        break;
    case SIGINT:
        cout << "Interrupt signal SIGINT (" << signum << ") received.\n";
        break;
    case SIGSEGV:
        cout << "Interrupt signal SIGSEGV (" << signum << ") received.\n";
        break;
    case SIGTERM:
        cout << "Interrupt signal SIGTERM (" << signum << ") received.\n";
        break;
    default:
        break;
    }



   // cleanup and close up stuff here  
   // terminate program  

   exit(signum);  
}

int main () {
   int i = 0;
   // register signal SIGINT and signal handler  
   
//    signal(SIGINT, signalHandler); 
   signal(SIGFPE, signalHandler); 

   while(++i) {
      cout << "Going to sleep...." << endl;
      if( i == 3 ) {
        //  raise(SIGINT);
         raise(SIGFPE);
      }
      sleep(1);
   }

   return 0;
}