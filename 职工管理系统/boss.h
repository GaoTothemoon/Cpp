#pragma once
#include"worker.h"

class Boss :public Worker {

public:
	Boss(int id, string name, int Did);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();
	~Boss();

private:

};

