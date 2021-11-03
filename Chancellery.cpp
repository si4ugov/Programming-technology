#include "Chancellery.h"

Chancellery::Chancellery() : Base("����������"), type("�� ������"), color("�� ������"), specification("�� ������"), price(0.0)
{
	cout << "������ ����������� Chancellery" << endl;
}

Chancellery::Chancellery(string type, string color, string specification, double price) :
	Base("����������"), type(type), color(color), specification(specification), price(price)
{
	cout << "������ ����������� Chancellery" << endl;
}

Chancellery::Chancellery(const Chancellery& chancellery) :
	Base(chancellery), type(chancellery.type), color(chancellery.color), specification(chancellery.specification), price(chancellery.price)
{
	cout << "������ ����������� ����������� Chancellery" << endl;
}

void Chancellery::inputFromConsole()
{
	cout << "������� ���: ";
	getline(cin, type);
	cout << "������� ����: ";
	getline(cin, color);
	cout << "������� ����������: ";
	getline(cin, specification);
	cout << "������� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Chancellery::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	color = tmpS;
	if (!getline(file, tmpS))
		throw err;
	type = tmpS;
	if (!getline(file, tmpS))
		throw err;
	specification = tmpS;
	if (!getline(file, tmpS))
		throw err;
	price = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Chancellery::printToConsole()
{
	Base::printToConsole();
	cout << "���: " << type << endl;
	cout << "����: " << color << endl;
	cout << "����������: " << specification << endl;
	cout << "����: " << price << endl;
}

void Chancellery::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << type << endl;
	out << color << endl;
	out << specification << endl;
	out << price << endl;
}

void Chancellery::change()
{
	cout << "������� ���� ���: ";
	getline(cin, type);
	cout << "������� ����� ����: ";
	getline(cin, color);
	cout << "������� ����� ����������: ";
	getline(cin, specification);
	cout << "������� ����� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}