#pragma once
#include <map>
struct M_LevelCFGData
{
	//�ȼ�
	int mLevel;
	//��������ֵ
	std::string mNeedExp;
	//�������
	std::vector<int> mAward;
	//����ICON
	std::string mLevelUpIcon;
};

class M_LevelCFG
{
public:
private:
	static std::auto_ptr<M_LevelCFG> msSingleton;
public:
	int GetCount();
	const M_LevelCFGData* GetData(int Level);
	const std::map<int, M_LevelCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_LevelCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_LevelCFGData> mMapData;
};
