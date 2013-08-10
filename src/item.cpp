#include "item.h"

#include "../lib/tinyxml2-master/tinyxml2.h"


Item::Item()
{
  //ctor
}

Item::~Item()
{
  //dtor
}



string Item::get_name(){}
string Item::get_type(){}
string Item::get_subtype(){}
int Item::get_bonus(string){}
void Item::equip(){}
void Item::unequip(){}
