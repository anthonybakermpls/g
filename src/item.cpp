#include "item.h"




Item::Item()
{

}

Item::~Item()
{
  //dtor
}



string Item::get_name()
{
  return "";
}
string Item::get_type()
{
  return "";
}
string Item::get_subtype()
{
  return "";
}
int Item::get_bonus(string)
{
  return 0;
}
void Item::equip()
{}
void Item::unequip()
{}
