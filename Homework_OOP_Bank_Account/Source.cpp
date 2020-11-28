#include <iostream>
#include <string>
#include<windows.h>
#include <ctime>

using namespace std;

//Написати клас "Банківський рахунок" (Account), який містить: 
//
//Перевірити пін - код(3 неправильних введення - блок рахунку)
//
//Властивості
//Номер рахунку   Заповняється випадковим числом від 00000000 до 99999999
//Розмір коштів на рахунку(Balance)
//Назва валюти рахунку(гривні, евро, BTC тощо)
//
//Забезпечити можливість :
//Знімати гроші з рахунку
//Докладати гроші на рахунок
//Показати баланс
//
//Перевірити коректність роботи класу.

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
	SetConsoleCP(1251);  //для того, що працювали українські букви
	SetConsoleOutputCP(1251); //для того, що працювали українські букви

	srand(time(NULL));
	Account firstaccount;
	firstaccount.account_number = (rand() % 99999999)+100000000;
	cout << "Ваш номер рахунку: " << firstaccount.account_number << endl;
	int number = 3;
	int pin_vvid = 0;
	bool flag = false; // булівська змінна для підтвердження введеного пароля

	for (int i = 0; i < number; i++)
	{
		cout << "Введіть свій пін-код!!! У Вас є " << number << " спроби!!! ->  ";
		cin >> pin_vvid;
		if (pin_vvid == firstaccount.GetPin())
		{
			cout << "Ви ввели вірно свій пін-код! Продовжуйте роботу!" << endl << endl;
			flag = true;
			bool vhid = true;
			while (vhid)
			{
				cout << "---   МЕНЮ   ---" << endl << endl;
				cout << "1.Поповнити рахунок." << endl;
				cout << "2.Зняти кошти з рахунку." << endl;
				cout << "3.Переглянути баланс." << endl;
				cout << "0.Вихід." << endl << endl;
				int action = 1;
				cout << "Оберіть потрібний пункт меню: ";
				cin >> action;
				switch (action)
				{
				case 1:
				{
					int choice;
					cout << "Бажаєте поповнити рахунок? (1 - так, 0 - ні): ";
					cin >> choice;
					if (choice == 1)
					{
						double popovn;
						cout << "Введіть суму поповнення: ";
						cin >> popovn;
						firstaccount.Balance += popovn;
						//cout << firstaccount.Balance << endl;
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					system("cls"); // очищає екран консолі (все що вище даної команди)
					break;
				}
				case 2:
				{
					int choice;
					cout << "Бажаєте зняти кошти з рахунку? (1 - так, 0 - ні): ";
					cin >> choice;
					if (choice == 1)
					{
						double znyaty;
						cout << "Введіть суму зняття: ";
						cin >> znyaty;
						firstaccount.Balance -= znyaty;
						//cout << firstaccount.Balance << endl;
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					system("cls"); // очищає екран консолі (все що вище даної команди)
					break;
				}
				case 3:
				{
					system("cls");
					cout << "\nСума балансу Вашого рахунку становить: " << firstaccount.Balance << " " << firstaccount.Uah << endl << endl;
					break;
				}
				case 0:
				{
					vhid = false;
					cout << "\nДякуємо. До побачення!" << endl << endl;
					break;
				}
				default:
					cout << "Ви обрали не вірний пункт меню. Зробіть ще раз свій вибір!" << endl;
				}
			}
			
			break;
		}
		//else
		//{
		//	cout << "УВАГА! Ви використали " << number << " спроби! Ваш рахунок заблоковано!!!" << endl << endl;
		//}
	}
	if (flag == false)
	{
		cout << endl;
		cout << "УВАГА! Ви використали " << number << " спроби! Ваш рахунок заблоковано!!!" << endl << endl;
	}

	

	return 0;
}