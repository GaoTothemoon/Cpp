#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

struct Person {
	string m_Name;
	//int m_Sex;    //��1��Ů2
	//int m_Age;
	string m_Phone;
	string m_Add;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

//�˵�
void showMenu() {
	cout << "*********************" << endl;
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
	cout << "*********************" << endl;
}

void addPerson(Addressbooks * abs) {
	if (abs->m_Size == MAX)
	{
		cout << "�ռ��Ѻľ���" << endl;
	}
	else {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string add;
		cout << "������סַ��" << endl;
		cin >> add;
		abs->personArray[abs->m_Size].m_Add = add;

		abs->m_Size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}

}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ�ա�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray->m_Name << "   �绰��" << abs->personArray->m_Phone << "   סַ��" << abs->personArray->m_Add << endl;
		}
		system("pause");
		system("cls");
	}
}

//�����ϵ���Ƿ����
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
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�!" << endl;
	}
	else {
		cout << "ͨѶ¼���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << abs->personArray[ret].m_Name << "\t";
		cout << abs->personArray[ret].m_Phone << "\t";
		cout << abs->personArray[ret].m_Add<< endl;
	}
	else {
		cout << "�޴���ϵ�ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "�����µ绰���룺" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		cout << "�����µ�ַ��" << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_Add = add;
		cout << "�޸ĳɹ���" << endl;
	}
	else {
		cout << "�޴���ϵ�ˣ�" << endl;
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
		case 1:		//1�������ϵ��
			addPerson(&abs);
			break;
		case 2:		//2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:		//3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:		//4��������ϵ��
			findPerson(&abs);
			break;
		case 5:		//5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:		//6�������ϵ��
			cleanPerson(&abs);
			break; 
		case 0:		//0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}