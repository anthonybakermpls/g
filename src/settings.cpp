
#include "settings.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <string>
#include <exception>


void Settings::load()
{

	
    using boost::property_tree::ptree;
    ptree pt;

    read_xml(cfg_file, pt);

    username = pt.get<std::string>("Options.Game.Username");
    vsync = pt.get<bool>("Options.Graphics.Vsync");


}

void Settings::save()
{

    // Create empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    // Put log filename in property tree
    pt.put("Options.Game.Username", username);

    // Put debug level in property tree
    pt.put("Options.Graphics.Vsync", vsync);


    
    // Write property tree to XML file (overwrites existing!)
    //write_xml(cfg_file, pt);

}
