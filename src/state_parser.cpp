#include "include/game.h"
#include "include/game_object_factory.h"
#include "include/game_object.h"
#include "include/state_parser.h"
#include "include/texture_manager.h"

using namespace std;

bool StateParser::parseState(const char *stateFile, string stateID, vector<GameObject *> *pObjects, vector<string> *pTextureIDs) {
    // Create the XML document
    TiXmlDocument xmlDoc;

    // Load the state file
    if(!xmlDoc.LoadFile(stateFile)) {
        cerr << xmlDoc.ErrorDesc() << "\n";
        return false;
    }

    // Get root element
    TiXmlElement *pRoot = xmlDoc.RootElement();

    // Pre-declare the state's root node
    TiXmlElement *pStateRoot = 0;
    // Get this state's root node and assign it to pStateRoot
    for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
        if(e->Value() == stateID)
            pStateRoot = e;
    
    // Pre-declare texture root
    TiXmlElement *pTextureRoot = 0;

    // Get root of texture elements
    for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
        if(e->Value() == string("TEXTURES"))
            pTextureRoot = e;
    
    // Now parse the textures
    parseTextures(pTextureRoot, pTextureIDs);

    // Pre-declare object root node and assign it to pObjectRoot
    TiXmlElement *pObjectRoot = 0;
    for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
        if(e->Value() == string("OBJECTS"))
            pObjectRoot = e;
    
    // Now parse the objects
    parseObjects(pObjectRoot, pObjects);
    return true;
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, vector<string> *pTextureIDs) {
    for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        string filenameAttribute = e->Attribute("filename");
        string idAttribute = e->Attribute("ID");
        pTextureIDs->push_back(idAttribute);    // Push into list

        TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer());
    }
}

void StateParser::parseObjects(TiXmlElement* pStateRoot, vector<GameObject*> *pObjects) {
    for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        int x, y, width, height, callbackID, animSpeed, numFrames;
        string textureID;

        e->Attribute("x", &x);
        e->Attribute("y", &y);
        e->Attribute("width", &width);
        e->Attribute("height", &height);
        e->Attribute("numFrames", &numFrames);
        e->Attribute("callbackID", &callbackID);
        e->Attribute("animSpeed", &animSpeed);

        textureID = e->Attribute("textureID");
        GameObject *pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
        pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
        pObjects->push_back(pGameObject);
    }
}