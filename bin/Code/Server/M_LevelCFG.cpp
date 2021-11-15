#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include "tinyxml2.h"
#include "M_LevelCFG.h"
#include "FileEncrypt.h"
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

boost::unordered_map<int, M_LevelCFGData>& M_LevelCFG::GetMapData()
{
	return mMapData;
}

void M_LevelCFG::Reload()
{
	mMapData.clear();
	Load();
}

void M_LevelCFG::Load(const std::string& path)
{
	std::ifstream readStream(path, std::ios::binary);
	if (!readStream.is_open())
	{
		assert(false);
		return;
	}
	readStream.seekg(0, std::ios::end);
	int fileSize = readStream.tellg();
	boost::shared_array<char> buffer(new char[fileSize+1]);
	buffer.get()[fileSize] = '\0';
	readStream.seekg(0, std::ios::beg);
	readStream.read(buffer.get(), fileSize);
	readStream.close();
	FileEncrypt::decryptBuffer( buffer, fileSize );
	tinyxml2::XMLDocument xmlDoc;
	auto result = xmlDoc.Parse(buffer.get(), fileSize);
	if (result != tinyxml2::XML_SUCCESS)
	{
		assert(false);
		return;
	}
	auto root = xmlDoc.RootElement();
	if (root == NULL)
	{
		assert(false);
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
		assert(mMapData.find(data.mLevel) == mMapData.end());
		mMapData.insert(std::make_pair(data.mLevel, data));
		element = element->NextSiblingElement();
	}
}

void M_LevelCFG::Load()
{
	Load("../Config/M_LevelCFG.xml");
}

M_LevelCFG* M_LevelCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_LevelCFG());
	}
	return msSingleton.get();
}
