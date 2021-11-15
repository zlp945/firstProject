#pragma once
#include <map>
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
	const std::map<int, LevelCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static LevelCFG* GetSingleton();
	static void Release();
private:
	std::map<int, LevelCFGData> mMapData;
};
