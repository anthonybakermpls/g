#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H


#include <functional>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;




class Command_line
{
  public:
    Command_line();
    virtual ~Command_line();
    void set_quit();
    void prompt();
    void register_function(string, void(*)(vector<string>)); // function name, function pointer
    void register_function2(string, function<void(vector<string>)> ); // used for class member functions

    void help(vector<string>);
    void quit(vector<string>);
    void show(vector<string>);

  protected:
  private:

    vector<string> arguments;
    size_t num_args;
    string name;
    string line;
    string timestamp;
    bool user_exit=false;

    map<string, void(*)(vector<string>)> command_table; // free function pointers
    map<string, function< void(vector<string>)> > command_table2; // converted member function storage

    vector<string> &split(const string &, char, vector<string> &);
    vector<string> split(const string &, char);

    void p();
    void parse_line(const string&);
    void execute();
    void print_parsed_line();

};

#endif // COMMAND_LINE_H





