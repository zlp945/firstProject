#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "LevelCFG.h"
std::auto_ptr<LevelCFG> LevelCFG::msSingleton(nullptr);

int LevelCFG::GetCount()
{
	return (int)mMapData.size();
}

const LevelCFGData* LevelCFG::GetData(int Level)
{
	auto it = mMapData.find(Level);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, LevelCFGData>& LevelCFG::GetMapData()
{
	return mMapData;
}

void LevelCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/LevelCFG.xml");
	auto result = xmlDoc.Parse(content.c_str(), content.length());
	if (result != tinyxml2::XML_SUCCESS)
	{
		CCLOGERROR("Result:%d", result);
		CCASSERT(false, "result != tinyxml2::XML_SUCCESS");
		return;
	}
	auto root = xmlDoc.RootElement();
	if (root == NULL)
	{
		CCASSERT(false, "root == NULL");
		return;
	}
	auto element = root->FirstChildElement("Data");
	while (element != NULL)
	{
		LevelCFGData data;
		data.mLevel = element->IntAttribute("Level");
		data.mStateName = element->Attribute("StateName");
		data.mUpExp = element->IntAttribute("UpExp");
		if (mMapData.find(data.mLevel) != mMapData.end())std::cout <<"data refind:" << data.mLevel << std::endl;
		CCASSERT(mMapData.find(data.mLevel) == mMapData.end(), "data.mLevel is exists");
		mMapData.insert(std::make_pair(data.mLevel, data));
		element = element->NextSiblingElement();
	}
	CCLOG("LevelCFG Loaded. Load Data:%u", mMapData.size());
}

void LevelCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/LevelCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "LevelCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		LevelCFGData data;
		LuaCfgHelper::readInt(L, "Level", data.mLevel);
		LuaCfgHelper::readString(L, "StateName", data.mStateName);
		LuaCfgHelper::readInt(L, "UpExp", data.mUpExp);
		if (mMapData.find(data.mLevel) != mMapData.end())std::cout <<"data refind:" << data.mLevel << std::endl;
		CCASSERT(mMapData.find(data.mLevel) == mMapData.end(), "data.mLevel is exists");
		mMapData.insert(std::make_pair(data.mLevel, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("LevelCFG Loaded. Load Data:%u", mMapData.size());
}

void LevelCFG::Reload()
{
	mMapData.clear();
	Load();
}

LevelCFG* LevelCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new LevelCFG());
	}
	return msSingleton.get();
}

void LevelCFG::Release()
{
	msSingleton.reset(nullptr);
}
