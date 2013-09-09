#ifndef GAME_H
#define GAME_H

#include <map>
#include "game_state.h"




using namespace std;





class Game
{
  public:
    Game();
    virtual ~Game();

    void init(); ///does nothing right now

    Game_state* get_state(string); // by name
    void change_state(Game_state*);
    void change_state(string); // by name

    void tick();
    void quit();

  protected:


  private:
    void add_state(string, Game_state*);

    map<string, Game_state*> game_states; //
    map<string, Game_state*>::iterator game_states_iter;
    Game_state* current_state;

};

#endif // GAME_H
