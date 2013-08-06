#include "character.h"

#include <iostream>

using namespace std;







Character::Character()
{
  attributes["health"]=100;
  attributes["energy"]=100;
  attributes["mana"]=100;
  attributes["experience"]=0;
  attributes["level"]=1;

  attributes["strength"]=10;
  attributes["dexterity"]=10;
  attributes["constitution"]=10;
  attributes["intelligence"]=10;
  attributes["charisma"]=10;
  attributes["luck"]=10;
}


Character::~Character()
{
  //dtor
}


/// show content of attributes map
void Character::status(vector<string>s)
{

  map<string,int>::iterator it;

  if(s.size()>0){  /// actually size == 1
    it=attributes.find(s.at(0));
    if( it != attributes.end() )
      cout << it->first << " => " << it->second << '\n';
    else
      cout << "No such attribute." << endl;
  }
  else{ /// list all
    for (map<string,int>::iterator it=attributes.begin(); it!=attributes.end(); ++it)
      cout << it->first << " => " << it->second << '\n';
  }

}
