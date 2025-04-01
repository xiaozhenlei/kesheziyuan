//菩提博客-大学生课设代码免费无偿分享 - 代码群 533683061
//作者：菩提科技
//官网：https://blog.wzl.icu
//时间：2025-3-31
//Tips: 1.本代码仅供学习和研究使用，不得用于任何商业用途
// 2.本代码仅供大学生课设代码免费无偿分享，未经许可，不得转载
// 3.本代码如有侵权，请联系作者删除
// 4.最新代码发布在菩提博客，大家可以去那里下载！
// 5.代码是作者辛苦劳动的成果，如果对您有所帮助，希望您能在博客下点赞！采集或者转载请保留代码的地址，谢谢合作
//如有疑问请联系：https://blog.wzl.icu

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};


//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	int m_Size;//通讯录中人员个数
};



void showMean() {
	cout << "****************************" << endl;
	cout << "*****   1 添加联系人   *****" << endl;
	cout << "*****   2 显示联系人   *****" << endl;
	cout << "*****   3 删除联系人   *****" << endl;
	cout << "*****   4 查找联系人   *****" << endl;
	cout << "*****   5 修改联系人   *****" << endl;
	cout << "*****   6 清空联系人   *****" << endl;
	cout << "*****   0 退出通讯录   *****" << endl;
	cout << "******菩提博客版权所有******" << endl;
}
using namespace std;
//添加联系人
void addPerson(Addressbooks* abs) {
	if (abs -> m_Size == MAX)
	{
		cout << "通讯录满了，无法添加" << endl;
	}
	else {
		//添加联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		int Sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;

		while (true) {
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = Sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
			
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(Addressbooks * abs) {
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{

			cout << "姓名：" << abs->personArray[i].m_Name << "\t" << endl;
			cout << "性别：" << (abs->personArray[i].m_Sex  == 1 ? "男":"女" )<< "\t" << endl;
			cout << "年龄：" << abs->personArray[i].m_Age << "\t" << endl;
			cout << "电话：" << abs->personArray[i].m_Phone << "\t" << endl;
			cout << "住址：" << abs->personArray[i].m_Addr << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
int DelExist(Addressbooks* abs) {
	cout << "请输入要删除的联系人" << endl;
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
			cout << "删除成功" << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "查无此人" << endl;
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
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != 1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t" << endl;
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t" << endl;
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t" << endl;
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t" << endl;
		cout << "地址：" << abs->personArray[ret].m_Addr << "\t" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
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
				cout << "输入有误，请重新输入" << endl;
			}
			
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMean();

		cin >> select;
		switch (select)
		{
		case 1://添加联系人	
			addPerson(&abs);//实参传递
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			DelExist(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}


	}
	//菜单的调用
	
	return 0;
}