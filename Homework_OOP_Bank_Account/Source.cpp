#include <iostream>
#include <string>
#include<windows.h>
#include <ctime>

using namespace std;

//�������� ���� "���������� �������" (Account), ���� ������: 
//
//��������� �� - ���(3 ������������ �������� - ���� �������)
//
//����������
//����� �������   ������������ ���������� ������ �� 00000000 �� 99999999
//����� ����� �� �������(Balance)
//����� ������ �������(�����, ����, BTC ����)
//
//����������� ��������� :
//������ ����� � �������
//��������� ����� �� �������
//�������� ������
//
//��������� ���������� ������ �����.

class Account
{
public:
	int account_number;
	double Balance = 0;
	string Uah = "Uah";
	string Usd = "Usd";
	string Euro = "Euro";
	string BTC = "BTC";

	int GetPin() {
		return Pin;
	}
private:
	int Pin = 1111;


};

int main()
{
	SetConsoleCP(1251);  //��� ����, �� ��������� �������� �����
	SetConsoleOutputCP(1251); //��� ����, �� ��������� �������� �����

	srand(time(NULL));
	Account firstaccount;
	firstaccount.account_number = (rand() % 99999999)+100000000;
	cout << "��� ����� �������: " << firstaccount.account_number << endl;
	int number = 3;
	int pin_vvid = 0;
	bool flag = false; // �������� ����� ��� ������������ ��������� ������

	for (int i = 0; i < number; i++)
	{
		cout << "������ ��� ��-���!!! � ��� � " << number << " ������!!! ->  ";
		cin >> pin_vvid;
		if (pin_vvid == firstaccount.GetPin())
		{
			cout << "�� ����� ���� ��� ��-���! ����������� ������!" << endl << endl;
			flag = true;
			bool vhid = true;
			while (vhid)
			{
				cout << "---   ����   ---" << endl << endl;
				cout << "1.��������� �������." << endl;
				cout << "2.����� ����� � �������." << endl;
				cout << "3.����������� ������." << endl;
				cout << "0.�����." << endl << endl;
				int action = 1;
				cout << "������ �������� ����� ����: ";
				cin >> action;
				switch (action)
				{
				case 1:
				{
					int choice;
					cout << "������ ��������� �������? (1 - ���, 0 - �): ";
					cin >> choice;
					if (choice == 1)
					{
						double popovn;
						cout << "������ ���� ����������: ";
						cin >> popovn;
						firstaccount.Balance += popovn;
						//cout << firstaccount.Balance << endl;
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
					break;
				}
				case 2:
				{
					int choice;
					cout << "������ ����� ����� � �������? (1 - ���, 0 - �): ";
					cin >> choice;
					if (choice == 1)
					{
						double znyaty;
						cout << "������ ���� ������: ";
						cin >> znyaty;
						firstaccount.Balance -= znyaty;
						//cout << firstaccount.Balance << endl;
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
					break;
				}
				case 3:
				{
					system("cls");
					cout << "\n���� ������� ������ ������� ���������: " << firstaccount.Balance << " " << firstaccount.Uah << endl << endl;
					break;
				}
				case 0:
				{
					vhid = false;
					cout << "\n������. �� ���������!" << endl << endl;
					break;
				}
				default:
					cout << "�� ������ �� ����� ����� ����. ������ �� ��� ��� ����!" << endl;
				}
			}
			
			break;
		}
		//else
		//{
		//	cout << "�����! �� ����������� " << number << " ������! ��� ������� �����������!!!" << endl << endl;
		//}
	}
	if (flag == false)
	{
		cout << endl;
		cout << "�����! �� ����������� " << number << " ������! ��� ������� �����������!!!" << endl << endl;
	}

	

	return 0;
}