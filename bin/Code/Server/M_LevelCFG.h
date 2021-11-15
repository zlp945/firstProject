#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
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
	boost::unordered_map<int, M_LevelCFGData>& GetMapData();
	void Reload();
	void Load(const std::string& path);
	void Load();
	static M_LevelCFG* GetSingleton();
private:
	boost::unordered_map<int, M_LevelCFGData> mMapData;
};
