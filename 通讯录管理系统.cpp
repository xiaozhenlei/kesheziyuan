//���Ჩ��-��ѧ�������������޳����� - ����Ⱥ 533683061
//���ߣ�����Ƽ�
//������https://blog.wzl.icu
//ʱ�䣺2025-3-31
//Tips: 1.���������ѧϰ���о�ʹ�ã����������κ���ҵ��;
// 2.�����������ѧ�������������޳�����δ����ɣ�����ת��
// 3.������������Ȩ������ϵ����ɾ��
// 4.���´��뷢�������Ჩ�ͣ���ҿ���ȥ�������أ�
// 5.���������������Ͷ��ĳɹ��������������������ϣ�������ڲ����µ��ޣ��ɼ�����ת���뱣������ĵ�ַ��лл����
//������������ϵ��https://blog.wzl.icu

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;
//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};


//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	int m_Size;//ͨѶ¼����Ա����
};



void showMean() {
	cout << "****************************" << endl;
	cout << "*****   1 �����ϵ��   *****" << endl;
	cout << "*****   2 ��ʾ��ϵ��   *****" << endl;
	cout << "*****   3 ɾ����ϵ��   *****" << endl;
	cout << "*****   4 ������ϵ��   *****" << endl;
	cout << "*****   5 �޸���ϵ��   *****" << endl;
	cout << "*****   6 �����ϵ��   *****" << endl;
	cout << "*****   0 �˳�ͨѶ¼   *****" << endl;
	cout << "******���Ჩ�Ͱ�Ȩ����******" << endl;
}
using namespace std;
//�����ϵ��
void addPerson(Addressbooks* abs) {
	if (abs -> m_Size == MAX)
	{
		cout << "ͨѶ¼���ˣ��޷����" << endl;
	}
	else {
		//�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		int Sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;

		while (true) {
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = Sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
			
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(Addressbooks * abs) {
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{

			cout << "������" << abs->personArray[i].m_Name << "\t" << endl;
			cout << "�Ա�" << (abs->personArray[i].m_Sex  == 1 ? "��":"Ů" )<< "\t" << endl;
			cout << "���䣺" << abs->personArray[i].m_Age << "\t" << endl;
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t" << endl;
			cout << "סַ��" << abs->personArray[i].m_Addr << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
int DelExist(Addressbooks* abs) {
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int flag = 0;
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			for (int j = i; j < abs->m_Size; j++)
			{
				abs->personArray[j] = abs->personArray[j + 1];
			}
			abs->m_Size--;
			cout << "ɾ���ɹ�" << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
	return 0;
}
int isExist(Addressbooks* abs,string name) {
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (name == abs->personArray[i].m_Name)
		{
			return i;
		}
		return -1;
	}
}
void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != 1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t" << endl;
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t" << endl;
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t" << endl;
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t" << endl;
		cout << "��ַ��" << abs->personArray[ret].m_Addr << "\t" << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
			
		}
		
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main() {
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMean();

		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��	
			addPerson(&abs);//ʵ�δ���
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			DelExist(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			break;
		default:
			cout << "������������������" << endl;
			break;
		}


	}
	//�˵��ĵ���
	
	return 0;
}