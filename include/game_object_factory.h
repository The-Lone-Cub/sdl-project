#pragma once

#include <string>
#include <map>
#include <iostream>
#include "game_object.h"

// Base class for creating game objects
class BaseCreator {
    public:
        virtual GameObject *createGameObject() const = 0;
        virtual ~BaseCreator() {}
};

// Factory class for creating game objects
class GameObjectFactory {
    public:
        static GameObjectFactory* Instance() {
            if(!s_pInstance)
                s_pInstance = new GameObjectFactory();
            return s_pInstance;
        }

        bool registerType(std::string typeID, BaseCreator* pCreator) {
            std::map<std::string, BaseCreator *>::iterator it = m_creators.find(typeID);
            // if the type is already registered, do nothing
            if(it != m_creators.end()) {
                delete pCreator;
                return false;
            }

            m_creators[typeID] = pCreator;
            return true;
        }

        GameObject* create(std::string typeID) {
            std::map<std::string, BaseCreator *>::iterator it = m_creators.find(typeID);
            if(it == m_creators.end()) {
                std::cout << "could not find type: " << typeID << std::endl;
                return nullptr;
            }
            BaseCreator *pCreator = (*it).second;
            return pCreator->createGameObject();
        }
    private:
        GameObjectFactory() {}
        virtual ~GameObjectFactory() {}

        std::map<std::string, BaseCreator *> m_creators; // map of type IDs to creators
        static GameObjectFactory *s_pInstance; // singleton instance
};

using TheGameObjectFactory = GameObjectFactory;
