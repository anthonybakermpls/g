

#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <mutex>
#include <ratio>
#include <string>
#include <thread>
#include <vector>

#include <unistd.h> //sleep


/// external libraries
#include "tinyxml2-master/tinyxml2.h"



#include "command_line.h"
#include "character.h"
#include "character_manager.h"
#include "game.h"
#include "level.h"
#include "settings.h"



using namespace std;









std::shared_ptr<bool> user_exit_ptr;


void test(){std::cout << "thread!" << std::endl;}
void quit(std::vector<std::string>s){std::cout << "quitting..." << std::endl; exit(0);}


int main(int argc, char** argv)
{




  Command_line command_line;
  Character_manager cm;
  Level level_1;





  cm.new_character();
  
    try
    {
//        debug_settings ds;
//        ds.load("debug_settings.xml");
//        ds.save("debug_settings_out.xml");
		
		Settings settings;		
		settings.load();
		settings.save();
		
        std::cout << "Success\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }



  // insert free functions into command table
  void(*fn)(std::vector<std::string>);
  fn = quit;
  command_line.register_function("main_quit",fn);

  // insert member functions into command table 2
  function<void(vector<string>)> f;

  f= bind(&Command_line::help, &command_line, placeholders::_1);
  command_line.register_function2("help",f);

  f= bind(&Character_manager::status, &cm, placeholders::_1);
  command_line.register_function2("status",f);

  f= bind(&Command_line::quit, &command_line, placeholders::_1);
  command_line.register_function2("quit",f);

  f= bind(&Command_line::show, &command_line, placeholders::_1);
  command_line.register_function2("show",f);








//  tinyxml2::XMLDocument doc;
//  doc.LoadFile( "cfg/items.xml" ); // need absolute path?
//  if(doc.ErrorID() != 0)
//  {
//    doc.PrintError();
//    return 1; // we have to bail out because our items file is broken
//  }
//
//
//
//
//  const char* c;
//  string str;
//  tinyxml2::XMLElement *levelElement = doc.FirstChildElement(); // items   //cout << levelElement->Name();
//  for (tinyxml2::XMLElement* child = levelElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
//  {
//    c = child->FirstChildElement("name")->GetText();
//    str=c;
//    cout << "Item name: " << str << endl;
//  }


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








  command_line.prompt(); // launch own thread



  bool user_exit=false;
  while(user_exit != true)  // main loop here
  {
    
    
    
    
    
    
    
    
    
    usleep(1000000); //1,000,000 mu s = 1 second   // 32000 mu s = 32 microseconds
  }





  return 0;
}




