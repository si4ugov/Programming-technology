#include "Textbook.h"

Textbook::Textbook() : Base("Учебник"), name("Не задано"), author("Не задано"), annotation("Не задано"), educationaInstitution("Не задано"),
	yearReliase(0), yearLearning(0), volueme(0), price(0.0)
{
	cout << "Вызван конструктор Textbook" << endl;
}

Textbook::Textbook(string name, string author, string annotation, string educationaInstitution,
	int yearReliase, int yearLearning, int volueme, double price) :
	Base("Учебник"), name(name), author(author), annotation(annotation), educationaInstitution(educationaInstitution), 
	yearReliase(yearReliase), yearLearning(yearLearning), volueme(volueme), price(price)
{
	cout << "Вызван конструктор Textbook" << endl;
}

Textbook::Textbook(const Textbook& textbook) :
	Base(textbook), name(textbook.name), author(textbook.author), annotation(textbook.annotation),
	educationaInstitution(textbook.educationaInstitution),
	yearReliase(textbook.yearReliase), yearLearning(textbook.yearLearning), volueme(textbook.volueme), price(textbook.price)
{
	cout << "Вызван конструктор копирования Textbook" << endl;
}

void Textbook::inputFromConsole()
{
	cout << "Введите название: ";
	getline(cin, name);
	cout << "Введите автора: ";
	getline(cin, author);
	cout << "Введите аннотацию: ";
	getline(cin, annotation);
	cout << "Введите образовательное учреждение: ";
	getline(cin, educationaInstitution);
	cout << "Введите год выпуска: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "Введите год обучения: ";
	yearLearning = safeInput(1, 11);
	cout << "Введите объем страниц: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "Введите цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Textbook::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	name = tmpS;
	if (!getline(file, tmpS))
		throw err;
	author = tmpS;
	if (!getline(file, tmpS))
		throw err;
	annotation = tmpS;
	if (!getline(file, tmpS))
		throw err;
	educationaInstitution = tmpS;
	if (!getline(file, tmpS))
		throw err;
	yearReliase = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	yearLearning = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	volueme = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	price = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Textbook::printToConsole()
{
	Base::printToConsole();
	cout << "Название: " << name << endl;
	cout << "Автор: " << author << endl;
	cout << "Аннотация: " << annotation << endl;
	cout << "Образовательное учреждение: " << educationaInstitution << endl;
	cout << "Год выпуска: " << yearReliase << endl;
	cout << "Год обучения: " << yearLearning << endl;
	cout << "Объем страниц: " << volueme << endl;
	cout << "Цена: " << price << endl;
}

void Textbook::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << name << endl;
	out << author << endl;
	out << annotation << endl;
	out << educationaInstitution << endl;
	out << yearReliase << endl;
	out << yearLearning << endl;
	out << volueme << endl;
	out << price << endl;
}

void Textbook::change()
{
	cout << "Введите новое название: ";
	getline(cin, name);
	cout << "Введите нового автора: ";
	getline(cin, author);
	cout << "Введите новую аннотацию: ";
	getline(cin, annotation);
	cout << "Введите новое образовательное учреждение: ";
	getline(cin, educationaInstitution);
	cout << "Введите новый год выпуска: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "Введите новый год обучения: ";
	yearLearning = safeInput(1, 11);
	cout << "Введите новый объем страниц: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "Введите новую цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}