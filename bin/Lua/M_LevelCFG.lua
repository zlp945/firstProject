M_LevelCFG = {}

function M_LevelCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_LevelCFG:init()
	self.datas = {}
	self.datas[1] = {Level = 1, NeedExp = "3000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[2] = {Level = 2, NeedExp = "6000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[3] = {Level = 3, NeedExp = "12000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[4] = {Level = 4, NeedExp = "24000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[5] = {Level = 5, NeedExp = "48000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[6] = {Level = 6, NeedExp = "96000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[7] = {Level = 7, NeedExp = "192000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[8] = {Level = 8, NeedExp = "384000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[9] = {Level = 9, NeedExp = "768000", Award = {2,1,5,5,8,5}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[10] = {Level = 10, NeedExp = "1536000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon1.png"}
	self.datas[11] = {Level = 11, NeedExp = "3072000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[12] = {Level = 12, NeedExp = "6144000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[13] = {Level = 13, NeedExp = "12288000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[14] = {Level = 14, NeedExp = "24576000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[15] = {Level = 15, NeedExp = "98304000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[16] = {Level = 16, NeedExp = "196608000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[17] = {Level = 17, NeedExp = "393216000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[18] = {Level = 18, NeedExp = "786432000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[19] = {Level = 19, NeedExp = "1572864000", Award = {2,3,5,10,8,10}, LevelUpIcon = "UI/Image/unlockIcon2.png"}
	self.datas[20] = {Level = 20, NeedExp = "3145728000", Award = {2,5,5,15,8,15}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[21] = {Level = 21, NeedExp = "6291456000", Award = {2,5,5,15,8,15}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[22] = {Level = 22, NeedExp = "12582912000", Award = {2,5,5,15,8,15}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[23] = {Level = 23, NeedExp = "25165824000", Award = {2,5,5,15,8,15}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[24] = {Level = 24, NeedExp = "50331648000", Award = {2,5,5,15,8,15}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[25] = {Level = 25, NeedExp = "75497472000", Award = {2,10,5,20,8,20}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[26] = {Level = 26, NeedExp = "150994944000", Award = {2,10,5,20,8,20}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[27] = {Level = 27, NeedExp = "301989888000", Award = {2,10,5,20,8,20}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[28] = {Level = 28, NeedExp = "603979776000", Award = {2,10,5,20,8,20}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[29] = {Level = 29, NeedExp = "1207959552000", Award = {2,10,5,20,8,20}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[30] = {Level = 30, NeedExp = "2415919104000", Award = {2,13,5,25,8,25}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[31] = {Level = 31, NeedExp = "4831838208000", Award = {2,13,5,25,8,25}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[32] = {Level = 32, NeedExp = "9663676416000", Award = {2,13,5,25,8,25}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[33] = {Level = 33, NeedExp = "19327352832000", Award = {2,13,5,25,8,25}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[34] = {Level = 34, NeedExp = "38654705664000", Award = {2,13,5,25,8,25}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[35] = {Level = 35, NeedExp = "77309411328000", Award = {2,15,5,30,8,30}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[36] = {Level = 36, NeedExp = "154618822656000", Award = {2,15,5,30,8,30}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[37] = {Level = 37, NeedExp = "309237645312000", Award = {2,15,5,30,8,30}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[38] = {Level = 38, NeedExp = "618475290624000", Award = {2,15,5,30,8,30}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[39] = {Level = 39, NeedExp = "1236950581248000", Award = {2,15,5,30,8,30}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[40] = {Level = 40, NeedExp = "1649267441664000", Award = {2,20,5,35,8,35}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[41] = {Level = 41, NeedExp = "3298534883328000", Award = {2,20,5,35,8,35}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[42] = {Level = 42, NeedExp = "6597069766656000", Award = {2,20,5,35,8,35}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[43] = {Level = 43, NeedExp = "13194139533312000", Award = {2,20,5,35,8,35}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[44] = {Level = 44, NeedExp = "26388279066624000", Award = {2,20,5,35,8,35}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[45] = {Level = 45, NeedExp = "52776558133248000", Award = {2,25,5,40,8,40}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[46] = {Level = 46, NeedExp = "105553116266496000", Award = {2,25,5,40,8,40}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[47] = {Level = 47, NeedExp = "211106232532992000", Award = {2,25,5,40,8,40}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[48] = {Level = 48, NeedExp = "422212465065984000", Award = {2,25,5,40,8,40}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
	self.datas[49] = {Level = 49, NeedExp = "", Award = {2,25,5,40,8,40}, LevelUpIcon = "UI/Image/unlockIcon3.png"}
end

M_LevelCFG:init()
