#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

/* settings are not dynamic. All are known at compile time */
class Settings
{
	public:
//	  void load(const std::string &filename);
//	  void save(const std::string &filename);
	  /* use predefined file */
	  void load();
	  void save();	
	  
	protected:
	private:
		std::string cfg_file="cfg/cfg.xml";
		
		/* Game */
		std::string username;
		/* Graphics */
		bool vsync;
		int res_width;
		int res_height;
		bool fullscreen;
		bool bloom;
		/* sound */
		float master_vol;
		float music_vol;
		float sfx_vol;
		/* controls */
		std::string up;
		std::string down;
		std::string left;
		std::string right;
		std::string attack1;
		std::string attack2;
		std::string attack3;
		std::string attack4;
		std::string use;
		std::string info;
		
		
		
		
};
#endif

