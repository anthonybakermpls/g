#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H




#include <list>
#include <string>
#include <tuple>  // std::tuple, std::get, std::tie, std::ignore
#include <vector>

#include <glm.hpp>
#include "character.h"


using namespace std;




class Character_manager
{
  public:
    Character_manager();
    virtual ~Character_manager();

    void new_character();
    void delete_character(unsigned int);

    void list_characters();
    void status(vector<string>);

  protected:
  private:
    unsigned int character_id_counter=0;

      // unsigned int id, Character* character, glm::vec3 position
      list< tuple<unsigned int, Character*, glm::vec3> > character_list;
};

#endif // CHARACTER_MANAGER_H
