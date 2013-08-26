#include "character.h"

#include <iostream>

using namespace std;







Character::Character()
{
  // These are defaults that will be over[written/ridden]
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

}


/// show content of attributes map
void Character::status(vector<string>s)
{

  cout << endl;

  /* list all attributes */
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

  cout << endl;

  /* list the current state */
}







void Character::update()
{
  (this->*current_state_fn_ptr)();  // Jaysus this is getting weird. I have a bad feeling about all of this.
  // possible alternate syntax ((*this).*(func))();
}

void Character::reset_turn()
{
  turn_taken=false;
}




// state functions call behavior functions

void Character::wait()
{
  /* how to get out of this state? */

  if(debug_lvl>0)
    cout << this << ": " << "wait(); " << endl;

  wander(); // or stand_still();
}

void Character::patrol_state()// do patrol behaviors
{

  if(debug_lvl>0)
    cout << this << ": " << "patrol_state(); " << endl;

  patrol(); // move back and forth
  look_for_enemy(); // locate enemy
}

void Character::attack_state() // do attack behaviors
{
  if(debug_lvl>0)
    cout << this << ": " << "attack_state(); " << endl;

  follow_enemy(); // if too far away
  attack_enemy(); // if close enough
  look_for_enemy(); // locate enemy
}

void Character::sleep_state() // do sleep behaviors
{

  if(debug_lvl>0)
    cout << this << ": " << "sleep_state(); " << endl;

  sleep(); // make snore noise
}









/* behavior functions can call state functions and other behavior functions */


/* on each game tick, the character can flow through one function before
   its turn_taken gets set to 1 and some other function is called that checks for turn_taken and returns.
*/






/// movement behaviors - don't change state

void Character::patrol()
{
  if(turn_taken)
    return;
  if(debug_lvl>0)
    cout << this << ": " << "patrol();" << endl;

 /* move back and forth */
 turn_taken=1;
}

void Character::follow_enemy()
{
  if(turn_taken)
    return;

  if(debug_lvl>0)
    cout << this << ": " << "follow_enemy();" << endl;

  /* move toward enemy */
  turn_taken=1;
}

void Character::wander()
{
  if(turn_taken)
    return;

  if(debug_lvl>0)
    cout << this << ": " << "wander();" << endl;

  /* move randomly */
  turn_taken=1;
}

void Character::stand_still()
{
  if(turn_taken)
    return;

  if(debug_lvl>0)
    cout << this << ": " << "stand_still();" << endl;


  /* don't move at all */
  turn_taken=1;
}


/// action behaviors - change state (but not necessarily)

void Character::look_for_enemy()
{
  if(turn_taken)
    return;


  if(debug_lvl>0)
    cout << this << ": " << "look_for_enemy();" << endl;

  /* if the enemy is seen we transition to attack state similar */
  if(enemy_seen)
    current_state_fn_ptr = &Character::attack_state;
  if(!enemy_seen)
    current_state_fn_ptr = &Character::patrol_state;

  turn_taken=1;
}

void Character::attack_enemy()
{
  if(turn_taken)
    return;

  // battle code

  if(debug_lvl>0)
    cout << this << ": " << "attack_enemy();" << endl;

  turn_taken=1;
}

void Character::sleep()
{
  if(turn_taken)
    return;

  if(enemy_near)
    attack_state();

  if(asleep)
  {

    if(debug_lvl>0)
      cout << this << ": " << "sleep();" << endl;

    // make snore noise
    /* set up a timer here and countdown to flipping bit of asleep */
    turn_taken=1;
    return;
  }

  /* made it out of sleep loop so change state and don't use up a turn*/
    patrol_state();
}



