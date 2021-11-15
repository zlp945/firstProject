#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_LevelCFG.h"
std::auto_ptr<M_LevelCFG> M_LevelCFG::msSingleton(nullptr);

int M_LevelCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_LevelCFGData* M_LevelCFG::GetData(int Level)
{
	auto it = mMapData.find(Level);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_LevelCFGData>& M_LevelCFG::GetMapData()
{
	return mMapData;
}

void M_LevelCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_LevelCFG.xml");
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
		M_LevelCFGData data;
		data.mLevel = element->IntAttribute("Level");
		data.mNeedExp = element->Attribute("NeedExp");
		{
			const char* Award = element->Attribute("Award");
			std::vector<std::string> vecAward;
			boost::split(vecAward, Award, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAward.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAward[i].c_str(), &temp))
				{
					data.mAward.push_back(temp);
				}
			}
		}
		data.mLevelUpIcon = element->Attribute("LevelUpIcon");
		if (mMapData.find(data.mLevel) != mMapData.end())std::cout <<"data refind:" << data.mLevel << std::endl;
		CCASSERT(mMapData.find(data.mLevel) == mMapData.end(), "data.mLevel is exists");
		mMapData.insert(std::make_pair(data.mLevel, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_LevelCFG Loaded. Load Data:%u", mMapData.size());
}

void M_LevelCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_LevelCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_LevelCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_LevelCFGData data;
		LuaCfgHelper::readInt(L, "Level", data.mLevel);
		LuaCfgHelper::readString(L, "NeedExp", data.mNeedExp);
		LuaCfgHelper::readVectorInt(L, "Award", data.mAward);
		LuaCfgHelper::readString(L, "LevelUpIcon", data.mLevelUpIcon);
		if (mMapData.find(data.mLevel) != mMapData.end())std::cout <<"data refind:" << data.mLevel << std::endl;
		CCASSERT(mMapData.find(data.mLevel) == mMapData.end(), "data.mLevel is exists");
		mMapData.insert(std::make_pair(data.mLevel, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_LevelCFG Loaded. Load Data:%u", mMapData.size());
}

void M_LevelCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_LevelCFG* M_LevelCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_LevelCFG());
	}
	return msSingleton.get();
}

void M_LevelCFG::Release()
{
	msSingleton.reset(nullptr);
}
