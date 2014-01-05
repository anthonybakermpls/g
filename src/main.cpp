
#include <iostream>

#include <vector>

#include <chrono>
#include <ctime>
#include <memory>
#include <mutex>
#include <ratio>
#include <string>
#include <thread>

#include <unistd.h> //sleep


/// external libraries
#include "tinyxml2-master/tinyxml2.h"
//#include <boost/log/trivial.hpp>


#include "command_line.h"
#include "character.h"
#include "character_manager.h"
#include "game.h"
#include "level.h"


using namespace std;





void getopts(int&, char** &);



shared_ptr<bool> user_exit_ptr;


void test(){cout << "thread!" << endl;}
void quit(vector<string>s){cout << "quitting..." << endl; exit(0);}


int main(int argc, char** argv)
{

  getopts(argc,argv);


  Command_line command_line;
  Character_manager cm;
  Level level_1;





  cm.new_character();



  // insert free functions into command table
  void(*fn)(vector<string>);
  fn = quit;
  command_line.register_function("main_quit",fn);
//  command_line.register_function("exit",fn); // two commands do the same thing

  // insert member functions into command table 2
  function<void(vector<string>)> f;

  f= bind(&Command_line::help, &command_line, placeholders::_1);
  command_line.register_function2("help",f);

//  f= bind(&Character::status, &player_1, placeholders::_1);
//  command_line.register_function2("status",f);

  f= bind(&Character_manager::status, &cm, placeholders::_1);
  command_line.register_function2("status",f);


  f= bind(&Command_line::quit, &command_line, placeholders::_1);
  command_line.register_function2("quit",f);

  f= bind(&Command_line::show, &command_line, placeholders::_1);
  command_line.register_function2("show",f);








  tinyxml2::XMLDocument doc;
  doc.LoadFile( "cfg/items.xml" ); // need absolute path?
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
//   //some op
//  chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
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

//    render_frame();
//    time_physics_curr = glfwGetTime()*1000; // This, like the rendering, ticks every time around.
//    physics_ptr->tick( ((float)(time_physics_curr - time_physics_prev))/1000.0, 10 );
//    time_physics_prev = time_physics_curr;
//    dt = (glfwGetTime()*1000) - t; // Game Clock ticks once every game_tick_ms milliseconds on average


//    while(dt >= game_tick_ms)
//    {
//        dt -= game_tick_ms;
//        time_gameclock += game_tick_ms;
//
//        controls.tick();
//        world_update();
//        game_tick();
//
          usleep(1000000); //1,000,000 mu s = 1 second   // 32000 mu s = 32 microseconds






//          cout << "monster1 update: " << endl;
//          monster_1.update();
//          monster_1.reset_turn();








//        fps=(renderer.get_frame())/glfwGetTime();
//    }
//

  }



  cout << "Done." << endl;

  return 0;
}






void getopts(int &a, char** &b)
{
  string t;
  vector<string> vargv;
  int i;
  for (i=1; i<a; i++)
  {
    t.assign(b[i]);
    vargv.push_back(t);

    // do something with vargv
    cout << "vargv contains:";
    for (vector<string>::iterator it = vargv.begin() ; it != vargv.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';
  }
}




