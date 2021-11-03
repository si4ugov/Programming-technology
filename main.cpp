#include "Keeper.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Keeper& keeper);
void changeObject(Keeper& keeper);
void deleteObject(Keeper& keeper);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper keeper;

	cout << "������ ����������� ������ �� �����?(1/0)" << endl;
	int method = safeInput(0, 1);
	try
	{
		if (method == 1)
			keeper.inputFromFile();
	}
	catch (string err)
	{
		cout << err << endl;
	}


	bool isExit = false;
	while (!isExit) {
		printMenu();
		method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(keeper);
			break;
		case 2:
			changeObject(keeper);
			break;
		case 3:
			deleteObject(keeper);
			break;
		case 4:
			keeper.printToConsole();
			break;
		case 5:
			keeper.printToFile();
			break;
		case 6:
			keeper.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void printMenu() {
	cout << "1. �������� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������ �� �����" << endl;
	cout << "5. ��������� � ����" << endl;
	cout << "6. ������������� ������� �� ����" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(Keeper& keeper)
{
	cout << "�������� ������ ��� ����������" << endl;
	cout << "1. �����" << endl;
	cout << "2. �������" << endl;
	cout << "3. ����������" << endl;
	int typeInt = safeInput(1, 3);
	string typeS;
	if (typeInt == 1)
		typeS = "�����";
	if (typeInt == 2)
		typeS = "�������";
	if (typeInt == 3)
		typeS = "����������";
	Base* object = createObj(typeS);
	object->inputFromConsole();
	keeper.add(object);
}

void changeObject(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "������� ������� ����. ������ ��������" << endl;
	else
	{
		keeper.printToConsole();
		cout << "�������� ����� ������� ��� ���������: ";
		int number = safeInput(1, keeper.getSize());
		keeper[number - 1]->change();
	}
}

void deleteObject(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "������� ������� ����. ������ �������" << endl;
	else
	{
		keeper.printToConsole();
		cout << "�������� ����� ������� ��� ��������: ";
		int number = safeInput(1, keeper.getSize());
		keeper.del(number - 1);
	}
}