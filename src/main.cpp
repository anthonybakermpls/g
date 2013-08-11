
#include <iostream>
#include <string>
#include <vector>

#include <chrono>
#include <ctime>
#include <ratio>
#include <thread>

#include <unistd.h> //sleep



/// external libraries
#include "../lib/tinyxml2-master/tinyxml2.h"

#include "command_line.h"
#include "character.h"



using namespace std;


bool user_exit=false;

void quit(vector<string>);
void test(){cout << "thread!" << endl;}




int main()
{




  Command_line command_line;
  command_line.set_quit(&user_exit);
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
//  void(*fn)(vector<string>);
//  fn = quit;
//  command_line.register_function("quit",fn);
//  command_line.register_function("exit",fn); // two commands do the same thing

  // insert member functions into command table 2
  function<void(vector<string>)> f;

  f= bind( &Command_line::help, &command_line, placeholders::_1);
  command_line.register_function2("help",f);

  f= bind( &Character::status, &player, placeholders::_1);
  command_line.register_function2("status",f);

  f= bind( &Command_line::quit, &command_line, placeholders::_1);
  command_line.register_function2("quit",f);









  tinyxml2::XMLDocument doc;
  doc.LoadFile( "cfg/items.xml" );
  if(doc.ErrorID() != 0)
  {
    doc.PrintError();
    return 1; // we have to bail out because our items file is broken
  }



  const char* c;
  string str;
  tinyxml2::XMLElement *levelElement = doc.FirstChildElement(); // items   //cout << levelElement->Name();
  for (tinyxml2::XMLElement* child = levelElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
  {
    c = child->FirstChildElement("name")->GetText();
    str=c;
    cout << "Item name: " << str << endl;
  }




//  chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//
//   //some op

//
//  chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
//
//  chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
//  cout << "It took " << time_span.count() << " seconds.";

  command_line.prompt();

  while(!user_exit)
  {
    sleep(5); // seconds
    cout << "main..." << endl;
  }




  return 0;
}





void quit(vector<string> s)
{
  cout << "Quitting.\n";
  user_exit=true;
}









