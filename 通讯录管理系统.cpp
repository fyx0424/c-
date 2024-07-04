#include <iostream>
using namespace std;
#define max 1000

//设计联系人结构体
struct person
{
	string m_name;
	int m_sex;//性别
	int m_age;
	string m_phone;
	string m_addr;
};
//设计通讯录结构体
struct addressbooks
{
	//保存联系人数组
	struct person personarray[max];
	//通讯录中当前记录人个数
	int m_size;
};
//菜单界面
void showmenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
//添加联系人
void addperson(addressbooks* abs)
{
	//添加具体联系人
	string name;
	cout << "请输入姓名:  " << endl;
	cin >> name;
	abs->personarray[abs->m_size].m_name = name;
	cout << "请输入性别" << endl;    //添加性别
	cout << "1----男" <<  endl;
	cout << "2----女" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personarray[abs->m_size].m_sex = sex;
			break;
		}
		cout << "输入有误，重新输入" << endl;
	}
	//年龄
	cout << "请输入年龄" << endl;
	int age = 0;
	cin >> age;
	abs->personarray[abs->m_size].m_age = age;
	//电话
	cout << "请输入电话" << endl;
	string phone;
	cin >> phone;
	abs->personarray[abs->m_size].m_phone = phone;
	//住址
	cout << "请输入家庭住址" << endl;
	string address;
	cin >> address;
	abs->personarray[abs->m_size].m_addr = address;
	//更新通讯录人数
	abs->m_size++;

	cout << "添加成功" << endl;

	system("pause");//请按任意键继续
	system("cls");//清屏
}
//显示所有联系人
void showperson(addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名" << abs->personarray[i].m_name << "\t";
			cout << "性别" << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄" << abs->personarray[i].m_age << "\t";
			cout << "电话" << abs->personarray[i].m_phone << "\t";
			cout << "住址" << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}
//检查联系人是否存在
int isexist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;//找到了,返回这个人
		}
	}
	return -1;
}
//3.删除指定联系人
void deleteperson(addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	//ret ==-1;未查到
	//ret!=-1;查到了
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (int i = ret; i < abs->m_size;i++)
		{
			//数据前移
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//更新通讯录人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清屏

}
void findperson(addressbooks* abs)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在于通讯录
	int ret = isexist(abs, name);
	if (ret != -1)//找到
	{
		cout << "姓名" << abs->personarray[ret].m_name << "\t";
		cout << "性别" << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄" << abs->personarray[ret].m_age << "\t";
		cout << "电话" << abs->personarray[ret].m_phone << "\t";
		cout << "住址" << abs->personarray[ret].m_addr << endl;
	}
	else
	{
		cout << "未找到联系人" << endl;
	}
	system("pause");
	system("cls");
}
//5.修改联系人
void modifyperson(addressbooks* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//找到
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1----男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;
		//电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		//家庭住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	addressbooks abs;
	//初始化通讯录当前人员个数
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		//菜单调用
		showmenu();

		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addperson(&abs);//利用地址传递修饰实参
			break;
		case 2:
			showperson(&abs);//显示联系人
			break;
		case 3://3.删除联系人
		{
			cout << "请输入删除联系人姓名" << endl;
		string name;
		cin >> name;
		if (isexist(&abs, name) == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "找到此人" << endl;
		}
		}
		deleteperson(&abs);
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyperson(&abs);
			break;
		case 6://清空联系人
			cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;

		}
	}
}