#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <string>
#include <vector>

#include "item.h"
using namespace std;




class Character
{
  public:
    Character();
    virtual ~Character();
    void status(vector<string>);

  protected:
  private:
    map<string, int> attributes;
    vector<Item> inventory;
		unsigned int mood; // 
		unsigned int disposition; // mood tends toward this state
};



#endif // CHARACTER_H
