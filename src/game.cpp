#include "game.h"
#include "game_state.h"




using namespace std;






Game::Game()
{
  current_state=NULL;
}


Game::~Game()
{

}


void Game::init()
{

}


void Game::add_state(string s, Game_state* gs)
{
    game_states[s] = gs;
}


Game_state* Game::get_state(string s)
{
  if (game_states.count(s)>0)
    return game_states[s];
  else
  {
    return NULL;
  }
}


void Game::change_state(Game_state* es)
{
  current_state = es;
}


void Game::change_state(string s)
{

  if( current_state == NULL ) // upon start
  {
    current_state=get_state(s);
    current_state->enter();
  }
  else if( current_state != get_state(s) )
  {
    current_state->leave();
    current_state=get_state(s);
    current_state->enter();
  }
  else
  {
    return;
  }

}



void Game::tick()
{
  current_state->tick();
}


void Game::quit()
{

}

