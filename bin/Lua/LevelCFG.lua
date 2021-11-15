LevelCFG = {}

function LevelCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function LevelCFG:init()
	self.datas = {}
	self.datas[1] = {Level = 1, StateName = "练气一阶", UpExp = 1000}
	self.datas[2] = {Level = 2, StateName = "", UpExp = 1001}
	self.datas[3] = {Level = 3, StateName = "", UpExp = 1002}
	self.datas[4] = {Level = 4, StateName = "", UpExp = 1003}
	self.datas[5] = {Level = 5, StateName = "", UpExp = 1004}
	self.datas[6] = {Level = 6, StateName = "", UpExp = 1005}
	self.datas[7] = {Level = 7, StateName = "", UpExp = 1006}
	self.datas[8] = {Level = 8, StateName = "", UpExp = 1007}
	self.datas[9] = {Level = 9, StateName = "", UpExp = 1008}
	self.datas[10] = {Level = 10, StateName = "", UpExp = 1009}
	self.datas[11] = {Level = 11, StateName = "", UpExp = 1010}
	self.datas[12] = {Level = 12, StateName = "", UpExp = 1011}
	self.datas[13] = {Level = 13, StateName = "", UpExp = 1012}
	self.datas[14] = {Level = 14, StateName = "", UpExp = 1013}
	self.datas[15] = {Level = 15, StateName = "", UpExp = 1014}
	self.datas[16] = {Level = 16, StateName = "", UpExp = 1015}
	self.datas[17] = {Level = 17, StateName = "", UpExp = 1016}
	self.datas[18] = {Level = 18, StateName = "", UpExp = 1017}
	self.datas[19] = {Level = 19, StateName = "", UpExp = 1018}
	self.datas[20] = {Level = 20, StateName = "", UpExp = 1019}
	self.datas[21] = {Level = 21, StateName = "", UpExp = 1020}
	self.datas[22] = {Level = 22, StateName = "", UpExp = 1021}
	self.datas[23] = {Level = 23, StateName = "", UpExp = 1022}
	self.datas[24] = {Level = 24, StateName = "", UpExp = 1023}
	self.datas[25] = {Level = 25, StateName = "", UpExp = 1024}
	self.datas[26] = {Level = 26, StateName = "", UpExp = 1025}
	self.datas[27] = {Level = 27, StateName = "", UpExp = 1026}
	self.datas[28] = {Level = 28, StateName = "", UpExp = 1027}
	self.datas[29] = {Level = 29, StateName = "", UpExp = 1028}
	self.datas[30] = {Level = 30, StateName = "", UpExp = 1029}
	self.datas[31] = {Level = 31, StateName = "", UpExp = 1030}
	self.datas[32] = {Level = 32, StateName = "", UpExp = 1031}
	self.datas[33] = {Level = 33, StateName = "", UpExp = 1032}
	self.datas[34] = {Level = 34, StateName = "", UpExp = 1033}
	self.datas[35] = {Level = 35, StateName = "", UpExp = 1034}
end

LevelCFG:init()
