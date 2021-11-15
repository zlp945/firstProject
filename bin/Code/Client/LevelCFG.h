#pragma once
#include <map>
struct LevelCFGData
{
	//����ȼ�
	int mLevel;
	//��������
	std::string mStateName;
	//ͻ��������Ϊ
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
