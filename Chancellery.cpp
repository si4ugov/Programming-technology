#include "Chancellery.h"

Chancellery::Chancellery() : Base("Канцелярия"), type("Не задано"), color("Не задано"), specification("Не задано"), price(0.0)
{
	cout << "Вызван конструктор Chancellery" << endl;
}

Chancellery::Chancellery(string type, string color, string specification, double price) :
	Base("Канцелярия"), type(type), color(color), specification(specification), price(price)
{
	cout << "Вызван конструктор Chancellery" << endl;
}

Chancellery::Chancellery(const Chancellery& chancellery) :
	Base(chancellery), type(chancellery.type), color(chancellery.color), specification(chancellery.specification), price(chancellery.price)
{
	cout << "Вызван конструктор копирования Chancellery" << endl;
}

void Chancellery::inputFromConsole()
{
	cout << "Введите тип: ";
	getline(cin, type);
	cout << "Введите цвет: ";
	getline(cin, color);
	cout << "Введите назначение: ";
	getline(cin, specification);
	cout << "Введите цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Chancellery::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
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
	cout << "Тип: " << type << endl;
	cout << "Цвет: " << color << endl;
	cout << "Назначение: " << specification << endl;
	cout << "Цена: " << price << endl;
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
	cout << "Введите ноый тип: ";
	getline(cin, type);
	cout << "Введите новый цвет: ";
	getline(cin, color);
	cout << "Введите новое назначение: ";
	getline(cin, specification);
	cout << "Введите новую цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}