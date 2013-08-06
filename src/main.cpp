
#include <iostream>
#include <string>
#include <vector>

#include <chrono>
#include <ctime>
#include <ratio>




#include "command_line.h"
#include "character.h"



using namespace std;



bool user_exit=false;
void quit(vector<string>);







int main()
{
  user_exit=false;




  Command_line command_line;
  Character player;



  chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//  cout << "printing out 1000 stars...\n";
//  for (int i=0; i<1000; ++i) cout << "*";
//  cout << endl;
  chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
  chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
//  cout << "It took me " << time_span.count() << " seconds.";
//  cout << endl;








  // insert free functions into command table
  void(*fn)(vector<string>);
  fn = quit;
  command_line.register_function("quit",fn);
  command_line.register_function("exit",fn); // two commands do the same thing

  // insert member functions into command table 2
  function<void(vector<string>)> f = bind( &Command_line::help, &command_line, placeholders::_1);
  command_line.register_function2("help",f);

  f = bind( &Character::status, &player, placeholders::_1);
  command_line.register_function2("status",f);






  while(!user_exit)
  {


//  typedef std::chrono::high_resolution_clock clock;
//  typedef std::chrono::milliseconds milliseconds;
//
//  clock::time_point t0 = clock::now();
//   ... some operation to time estimate
//  clock::time_point t1 = clock::now();
//
//  milliseconds total_ms = std::chrono::duration_cast<milliseconds>(t1 - t0);




     command_line.prompt();
  }




  return 0;
}





void quit(vector<string> s)
{
  cout << "Quitting.\n";
  user_exit=true;
}









