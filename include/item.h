#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

using namespace std;





class Item
{
  public:
    Item();
    virtual ~Item();

    string get_name();
    string get_type();
    string get_subtype();
    int get_bonus(string);
    void equip();
    void unequip();


  protected:
  private:
    string name; // e.g. sword of blazing testicles
    string type; // e.g. weapon
    string subtype; // e.g. sword, one hand
    map<string, int> attribute_bonus;  // e.g.   attributes["health"]=10;  // means +10 to health
    bool equipped; // bonus only applies if equipped for some items
};

#endif // ITEM_H
