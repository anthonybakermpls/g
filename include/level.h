#ifndef LEVEL_H
#define LEVEL_H


#include <list>
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore

#include <glm.hpp>

#include "character.h"



using namespace std;




class Level
{
  public:
    Level();
    virtual ~Level();

    void reset();




  protected:
  private:


    list< tuple<Character*,glm::vec3> > character_positions;

};

#endif // LEVEL_H
