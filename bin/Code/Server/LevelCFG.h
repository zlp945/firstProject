#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct LevelCFGData
{
	//境界等级
	int mLevel;
	//境界名称
	std::string mStateName;
	//突破所需修为
	int mUpExp;
};

class LevelCFG
{
public:
private:
	static std::auto_ptr<LevelCFG> msSingleton;
public:
	int GetCount();
	const LevelCFGData* GetData(int Level);
	boost::unordered_map<int, LevelCFGData>& GetMapData();
	void Reload();
	void Load(const std::string& path);
	void Load();
	static LevelCFG* GetSingleton();
private:
	boost::unordered_map<int, LevelCFGData> mMapData;
};
