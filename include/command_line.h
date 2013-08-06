#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H


#include <functional>
#include <string>
#include <vector>
#include <map>

using namespace std;




class Command_line
{
  public:
    Command_line();
    virtual ~Command_line();
    void prompt();
    void register_function(string, void(*)(vector<string>)); // function name, function pointer
    void register_function2(string, function<void(vector<string>)> );

    void help(vector<string>);

  protected:
  private:

    vector<string> arguments;
    size_t num_args;
    string name;
    string line;
    bool user_exit;
    map<string, void(*)(vector<string>)> command_table; // free function pointers

    map<string, function< void(vector<string>)> > command_table2; // converted member function storage


    vector<string> &split(const string &, char, vector<string> &);
    vector<string> split(const string &, char);
    void parse_line(const string&);
    void execute();
    void print_parsed_line();

};

#endif // COMMAND_LINE_H





