#include"boss.h"

Boss::Boss(int id, string name, int Did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_Did = Did;
}

//显示个人信息
void Boss::showInfo() {
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t职工岗位:" << this->getDeptName()
		<< "\t岗位职责--管理一切！" << endl;
}

//获取岗位名称
string Boss::getDeptName() {
	return string("老板");
}