#include "Book.h"

Book::Book() : Base("�����"), name("�� ������"), author("�� ������"), annotation("�� ������"), janr("�� ������"),
	yearReliase(0), volueme(0), price(0.0)
{
	cout << "������ ����������� Book" << endl;
}

Book::Book(string name, string author, string annotation, string janr, int yearReliase, int volueme, double price) :
	Base("�����"), name(name), author(author), annotation(annotation), janr(janr),
	yearReliase(yearReliase), volueme(volueme), price(price)
{
	cout << "������ ����������� Book" << endl;
}

Book::Book(const Book& book) :
	Base(book), name(book.name), author(book.author), annotation(book.annotation), janr(book.janr),
	yearReliase(book.yearReliase), volueme(book.volueme), price(book.price)
{
	cout << "������ ����������� ����������� Book" << endl;
}

void Book::inputFromConsole()
{
	cout << "������� ��������: ";
	getline(cin, name);
	cout << "������� ������: ";
	getline(cin, author);
	cout << "������� ���������: ";
	getline(cin, annotation);
	cout << "������� ����: ";
	getline(cin, janr);
	cout << "������� ��� �������: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "������� ����� �������: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "������� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Book::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "��������: " << name << endl;
	cout << "�����: " << author << endl;
	cout << "���������: " << annotation << endl;
	cout << "����: " << janr << endl;
	cout << "��� �������: " << yearReliase << endl;
	cout << "����� �������: " << volueme << endl;
	cout << "����: " << price << endl;
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
	cout << "������� ����� ��������: ";
	getline(cin, name);
	cout << "������� ������ ������: ";
	getline(cin, author);
	cout << "������� ����� ���������: ";
	getline(cin, annotation);
	cout << "������� ����� ����: ";
	getline(cin, janr);
	cout << "������� ����� ��� �������: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "������� ����� ����� �������: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "������� ����� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}