#ifndef CHARACTER_H
#define CHARACTER_H



#include <functional>
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
    void update();
    void reset_turn();

    /// basic state functions
    void wait();
    void patrol_state();
    void attack_state();
    void sleep_state();
    void flee();

    /// behavior functions
    //movement
    void patrol();
    void follow_enemy();
    void stand_still();
    void wander();

    //action
    void look_for_enemy();
    void attack_enemy();
    void sleep();




  protected:
  private:

    map<string, int> attributes;
    vector<Item> inventory;
		unsigned int disposition; // mood tends toward this state
    bool turn_taken=false; // prevents character from performing infinite loops in its states/actions

    typedef void (Character::*Character_fn_ptr)(void); // http://www.parashift.com/c++-faq/typedef-for-ptr-to-memfn.html
    Character_fn_ptr current_state_fn_ptr = &Character::wander;//pointer to current state function

    bool enemy_seen=false;
    bool enemy_near=false;
    bool asleep=false;
};



#endif // CHARACTER_H
