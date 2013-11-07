#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>




using namespace std;





class Game_state
{
  public :
    virtual void init()=0;
    virtual void quit()=0;
    virtual void tick()=0;
    virtual void escape()=0;
    virtual void enter()=0;
    virtual void leave()=0;

  protected :
    Game_state() {}

    // Local time which keeps track of time since the start of this state.
    unsigned long local_time_start;
    unsigned long local_time;

    string name; // unused
    int id;

  private :
};

#endif // GAME_STATE_H
