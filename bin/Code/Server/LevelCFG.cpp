#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include "tinyxml2.h"
#include "LevelCFG.h"
#include "FileEncrypt.h"
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

boost::unordered_map<int, LevelCFGData>& LevelCFG::GetMapData()
{
	return mMapData;
}

void LevelCFG::Reload()
{
	mMapData.clear();
	Load();
}

void LevelCFG::Load(const std::string& path)
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
		LevelCFGData data;
		data.mLevel = element->IntAttribute("Level");
		data.mStateName = element->Attribute("StateName");
		data.mUpExp = element->IntAttribute("UpExp");
		if (mMapData.find(data.mLevel) != mMapData.end())std::cout <<"data refind:" << data.mLevel << std::endl;
		assert(mMapData.find(data.mLevel) == mMapData.end());
		mMapData.insert(std::make_pair(data.mLevel, data));
		element = element->NextSiblingElement();
	}
}

void LevelCFG::Load()
{
	Load("../Config/LevelCFG.xml");
}

LevelCFG* LevelCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new LevelCFG());
	}
	return msSingleton.get();
}
