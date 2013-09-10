#include "character_manager.h"

#include <iostream>
using namespace std;






Character_manager::Character_manager()
{
  //ctor
}

Character_manager::~Character_manager()
{
  //dtor
}


void Character_manager::new_character()
{
  character_id_counter++;
  Character* c= new Character();
  glm::vec3 v(0,0,0);
  auto t = make_tuple (character_id_counter, c, v);

  character_list.push_back(t);
}


void Character_manager::list_characters()
{
  cout << "character_list contains:";
  for (auto& x: character_list)
    cout << get<0>(x);

}



void Character_manager::status(vector<string> s)
{

//  for (list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
//    cout << ' ' << *it;

}
