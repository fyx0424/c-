#include <iostream>
using namespace std;
#define max 1000

//�����ϵ�˽ṹ��
struct person
{
	string m_name;
	int m_sex;//�Ա�
	int m_age;
	string m_phone;
	string m_addr;
};
//���ͨѶ¼�ṹ��
struct addressbooks
{
	//������ϵ������
	struct person personarray[max];
	//ͨѶ¼�е�ǰ��¼�˸���
	int m_size;
};
//�˵�����
void showmenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}
//�����ϵ��
void addperson(addressbooks* abs)
{
	//��Ӿ�����ϵ��
	string name;
	cout << "����������:  " << endl;
	cin >> name;
	abs->personarray[abs->m_size].m_name = name;
	cout << "�������Ա�" << endl;    //����Ա�
	cout << "1----��" <<  endl;
	cout << "2----Ů" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personarray[abs->m_size].m_sex = sex;
			break;
		}
		cout << "����������������" << endl;
	}
	//����
	cout << "����������" << endl;
	int age = 0;
	cin >> age;
	abs->personarray[abs->m_size].m_age = age;
	//�绰
	cout << "������绰" << endl;
	string phone;
	cin >> phone;
	abs->personarray[abs->m_size].m_phone = phone;
	//סַ
	cout << "�������ͥסַ" << endl;
	string address;
	cin >> address;
	abs->personarray[abs->m_size].m_addr = address;
	//����ͨѶ¼����
	abs->m_size++;

	cout << "��ӳɹ�" << endl;

	system("pause");//�밴���������
	system("cls");//����
}
//��ʾ������ϵ��
void showperson(addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "����" << abs->personarray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personarray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "����" << abs->personarray[i].m_age << "\t";
			cout << "�绰" << abs->personarray[i].m_phone << "\t";
			cout << "סַ" << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");//�����������
	system("cls");//����
}
//�����ϵ���Ƿ����
int isexist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;//�ҵ���,���������
		}
	}
	return -1;
}
//3.ɾ��ָ����ϵ��
void deleteperson(addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//ret ==-1;δ�鵽
	//ret!=-1;�鵽��
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_size;i++)
		{
			//����ǰ��
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼��Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�����������
	system("cls");//����

}
void findperson(addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ������ͨѶ¼
	int ret = isexist(abs, name);
	if (ret != -1)//�ҵ�
	{
		cout << "����" << abs->personarray[ret].m_name << "\t";
		cout << "�Ա�" << (abs->personarray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "����" << abs->personarray[ret].m_age << "\t";
		cout << "�绰" << abs->personarray[ret].m_phone << "\t";
		cout << "סַ" << abs->personarray[ret].m_addr << endl;
	}
	else
	{
		cout << "δ�ҵ���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}
//5.�޸���ϵ��
void modifyperson(addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//�ҵ�
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;
		//�绰
		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//����ͨѶ¼�ṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼��ǰ��Ա����
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		//�˵�����
		showmenu();

		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addperson(&abs);//���õ�ַ��������ʵ��
			break;
		case 2:
			showperson(&abs);//��ʾ��ϵ��
			break;
		case 3://3.ɾ����ϵ��
		{
			cout << "������ɾ����ϵ������" << endl;
		string name;
		cin >> name;
		if (isexist(&abs, name) == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "�ҵ�����" << endl;
		}
		}
		deleteperson(&abs);
			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://�����ϵ��
			cleanperson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;

		}
	}
}