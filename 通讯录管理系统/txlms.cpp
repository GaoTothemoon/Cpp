#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

struct Person {
	string m_Name;
	//int m_Sex;    //男1，女2
	//int m_Age;
	string m_Phone;
	string m_Add;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

//菜单
void showMenu() {
	cout << "*********************" << endl;
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
	cout << "*********************" << endl;
}

void addPerson(Addressbooks * abs) {
	if (abs->m_Size == MAX)
	{
		cout << "空间已耗尽！" << endl;
	}
	else {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string add;
		cout << "请输入住址：" << endl;
		cin >> add;
		abs->personArray[abs->m_Size].m_Add = add;

		abs->m_Size++;
		cout << "添加成功。" << endl;
		system("pause");
		system("cls");
	}

}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录为空。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray->m_Name << "   电话：" << abs->personArray->m_Phone << "   住址：" << abs->personArray->m_Add << endl;
		}
		system("pause");
		system("cls");
	}
}

//检测联系人是否存在
int isExist(Addressbooks * abs,string name) {
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功!" << endl;
	}
	else {
		cout << "通讯录里无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "请输入你要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << abs->personArray[ret].m_Name << "\t";
		cout << abs->personArray[ret].m_Phone << "\t";
		cout << abs->personArray[ret].m_Add<< endl;
	}
	else {
		cout << "无此联系人！" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "请输入你要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "输入新电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		cout << "输入新地址：" << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_Add = add;
		cout << "修改成功！" << endl;
	}
	else {
		cout << "无此联系人！" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "empty!" << endl;
	system("pause");
	system("cls");
}

int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select;

	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:		//1、添加联系人
			addPerson(&abs);
			break;
		case 2:		//2、显示联系人
			showPerson(&abs);
			break;
		case 3:		//3、删除联系人
			deletePerson(&abs);
			break;
		case 4:		//4、查找联系人
			findPerson(&abs);
			break;
		case 5:		//5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:		//6、清空联系人
			cleanPerson(&abs);
			break; 
		case 0:		//0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}