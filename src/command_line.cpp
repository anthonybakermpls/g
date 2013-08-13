/**
 * command_line.h
 */

#include "command_line.h"

#include <algorithm>

#include <iostream>
#include <iterator>
#include <limits>       // std::numeric_limits
#include <sstream>
#include <chrono>
#include <ctime>


using namespace std;








/// Brief description.
/** Detailed description. */
Command_line::Command_line()
{

}


Command_line::~Command_line(){}

void Command_line::set_quit(){}

void Command_line::prompt()
{
  thread t(&Command_line::p, this);
  t.detach();
}

void Command_line::p()
{

  while(!user_exit)
  {
    line.clear();
    name.clear();
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto time_point = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(time_point);
    struct tm * now = localtime( & now_c );

    char* t=asctime(now);
    timestamp=t;
    cout << timestamp.substr(0, timestamp.size()-1) << " g>";
    getline(cin, line);

    parse_line(line);
//    print_parsed_line();
    execute();
  }

}






vector<string> &Command_line::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> Command_line::split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void Command_line::parse_line(const string& s)
{
  arguments.clear();
  vector<string> args=split(s,' ');

  if (args.size() >0 ){
    for(int i=0; i<args.size();i++) //downcase it
      transform(args[i].begin(), args[i].end(), args[i].begin(), ::tolower);

    name=args.at(0);

    for(int i = 1; i < args.size(); i++) //exclude argument 0, the name
    {
        arguments.push_back(  args.at(i)  );
    }
  }
  else{
      return;
  }
}

void Command_line::print_parsed_line()
{
  vector<string>::iterator iter;

  cout << "name: \"" << name << "\"" << endl;
  cout << "args: " ;
  for (iter=arguments.begin(); iter< arguments.end(); iter++)
    cout <<  "\"" << *iter << "\"" << ", ";
  cout << endl;
}

void Command_line::execute()
{
  map<string,void(*)(vector<string>)>::iterator iter;
  iter=command_table.find(name);
  if( iter != command_table.end() )
    iter->second(arguments);


  map<string, function< void(vector<string>)>>::iterator iter2;
  iter2=command_table2.find(name);
  if( iter2 != command_table2.end() )
    iter2->second(arguments);

}


void Command_line::help(vector<string> s)
{

  if(s.size()>0){
    // help on  a specific command

  }
  else{
    cout << "commands: " << endl;
    cout << "free function commands: " << endl;
    for (auto it=command_table.begin(); it!=command_table.end(); ++it)
      cout << it->first << '\n';
    cout << endl;
    cout << "member function commands: " << endl;
    for (auto it=command_table2.begin(); it!=command_table2.end(); ++it)
      cout << it->first << '\n';
  }


}


void Command_line::quit(vector<string> v)
{
  user_exit=true;
  command_table["main_quit"](v);
}

void Command_line::show(vector<string> v)
{
//  cout << "user_exit_ptr: " << *user_exit_ptr << endl;
}




void Command_line::register_function(string s, void(*f)(vector<string>))
{
  command_table[s]=f; // insert name, function pointer into our table
}


void Command_line::register_function2(string s, function<void(vector<string>)> f)
{
  command_table2[s]=f;
}



//
//class Callback
//{
//  public:
//    void operator()() { call(); };
//    virtual void call() = 0;
//};
//
//
//class BasicCallback : public Callback
//{
//  // pointer to member function
//  void (*function)(void);
//
//  public:
//    BasicCallback(void(*_function)(void))
//        : function( _function ) { };
//    virtual void call()
//    {
//        (*function)();
//    };
//};
//
//
//template <class AnyClass>
//class ClassCallback : public Callback
//{
//
//  void (AnyClass::*function)(void);  // pointer to member function
//  AnyClass* object;   // pointer to object
//
//  public:
//    ClassCallback(AnyClass* _object, void(AnyClass::*_function)(void))
//        : object( _object ), function( _function ) { };
//    virtual void call()
//    {
//        (*object.*function)();
//    };
//};
//


