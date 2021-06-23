#pragma once
#include"worker.h"

class Boss :public Worker {

public:
	Boss(int id, string name, int Did);
	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
	~Boss();

private:

};

