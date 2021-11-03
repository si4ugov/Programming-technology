#include "Book.h"

Book::Book() : Base("Книга"), name("Не задано"), author("Не задано"), annotation("Не задано"), janr("Не задано"),
	yearReliase(0), volueme(0), price(0.0)
{
	cout << "Вызван конструктор Book" << endl;
}

Book::Book(string name, string author, string annotation, string janr, int yearReliase, int volueme, double price) :
	Base("Книга"), name(name), author(author), annotation(annotation), janr(janr),
	yearReliase(yearReliase), volueme(volueme), price(price)
{
	cout << "Вызван конструктор Book" << endl;
}

Book::Book(const Book& book) :
	Base(book), name(book.name), author(book.author), annotation(book.annotation), janr(book.janr),
	yearReliase(book.yearReliase), volueme(book.volueme), price(book.price)
{
	cout << "Вызван конструктор копирования Book" << endl;
}

void Book::inputFromConsole()
{
	cout << "Введите название: ";
	getline(cin, name);
	cout << "Введите автора: ";
	getline(cin, author);
	cout << "Введите аннотацию: ";
	getline(cin, annotation);
	cout << "Введите жанр: ";
	getline(cin, janr);
	cout << "Введите год выпуска: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "Введите объем страниц: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "Введите цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Book::inputFromFile(std::ifstream& file, std::string& tmpS)
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
	janr = tmpS;
	if (!getline(file, tmpS))
		throw err;
	yearReliase = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	volueme = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	price = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Book::printToConsole()
{
	Base::printToConsole();
	cout << "Название: " << name << endl;
	cout << "Автор: " << author << endl;
	cout << "Аннотация: " << annotation << endl;
	cout << "Жанр: " << janr << endl;
	cout << "Год выпуска: " << yearReliase << endl;
	cout << "Объем страниц: " << volueme << endl;
	cout << "Цена: " << price << endl;
}

void Book::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << name << endl;
	out << author << endl;
	out << annotation << endl;
	out << janr << endl;
	out << yearReliase << endl;
	out << volueme << endl;
	out << price << endl;
}

void Book::change()
{
	cout << "Введите новое название: ";
	getline(cin, name);
	cout << "Введите нового автора: ";
	getline(cin, author);
	cout << "Введите новую аннотацию: ";
	getline(cin, annotation);
	cout << "Введите новый жанр: ";
	getline(cin, janr);
	cout << "Введите новый год выпуска: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "Введите новый объем страниц: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "Введите новую цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}