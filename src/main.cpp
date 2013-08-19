
#include <iostream>
#include <string>
#include <vector>

#include <chrono>
#include <ctime>
#include <memory>
#include <mutex>
#include <ratio>
#include <thread>

#include <unistd.h> //sleep


/// external libraries
#include "../lib/tinyxml2-master/tinyxml2.h"

#include "command_line.h"
#include "character.h"



using namespace std;









shared_ptr<bool> user_exit_ptr;


void test(){cout << "thread!" << endl;}
void quit(vector<string>s){cout << "quitting..." << endl; exit(0);}


int main()
{


  Command_line command_line;
  Character player;
  Character monster1;









  // insert free functions into command table
  void(*fn)(vector<string>);
  fn = quit;
  command_line.register_function("main_quit",fn);
//  command_line.register_function("exit",fn); // two commands do the same thing

  // insert member functions into command table 2
  function<void(vector<string>)> f;

  f= bind( &Command_line::help, &command_line, placeholders::_1);
  command_line.register_function2("help",f);

  f= bind( &Character::status, &player, placeholders::_1);
  command_line.register_function2("status",f);

  f= bind( &Command_line::quit, &command_line, placeholders::_1);
  command_line.register_function2("quit",f);

  f= bind( &Command_line::show, &command_line, placeholders::_1);
  command_line.register_function2("show",f);








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
//  chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
//
//  chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
//  cout << "It took " << time_span.count() << " seconds.";



//  auto t1 = chrono::system_clock::now();
//  auto dt = chrono::system_clock::now() - t1;
//
//  auto ms = chrono::duration_cast<chrono::milliseconds>(dt);
//  cout << "these few commands took:" << ms.count() << " milliseconds" << endl;

  command_line.prompt();

  bool user_exit=false;
  while(user_exit != true)
  {
    sleep(5);
    cout << "monster1 update: " << endl;
    monster1.update();
    monster1.reset_turn();
    cout << endl;
  }



  cout << "Done." << endl;

  return 0;
}











