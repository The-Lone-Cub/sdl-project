#pragma once

#include <iostream>
#include <vector>
#include "tinyxml.h"

class GameObject;

// Class to parse state information from XML files
class StateParser {
    public:
        // Parse state information from an XML file
        bool parseState(const char *stateFile, std::string stateID,
                        std::vector<GameObject *> *pObjects, std::vector<std::string> *pTExtureIDs);
    private:
        // Parse game objects from the XML element
        void parseObjects(TiXmlElement *pStateRoot,
                          std::vector<GameObject *> *pObjects);
        
        // Parse texture IDs from the XML element
        void parseTextures(TiXmlElement *pStateRoot,
                           std::vector<std::string> *pTExtureIDs);
};