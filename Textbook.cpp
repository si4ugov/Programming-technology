#include "Textbook.h"

Textbook::Textbook() : Base("�������"), name("�� ������"), author("�� ������"), annotation("�� ������"), educationaInstitution("�� ������"),
	yearReliase(0), yearLearning(0), volueme(0), price(0.0)
{
	cout << "������ ����������� Textbook" << endl;
}

Textbook::Textbook(string name, string author, string annotation, string educationaInstitution,
	int yearReliase, int yearLearning, int volueme, double price) :
	Base("�������"), name(name), author(author), annotation(annotation), educationaInstitution(educationaInstitution), 
	yearReliase(yearReliase), yearLearning(yearLearning), volueme(volueme), price(price)
{
	cout << "������ ����������� Textbook" << endl;
}

Textbook::Textbook(const Textbook& textbook) :
	Base(textbook), name(textbook.name), author(textbook.author), annotation(textbook.annotation),
	educationaInstitution(textbook.educationaInstitution),
	yearReliase(textbook.yearReliase), yearLearning(textbook.yearLearning), volueme(textbook.volueme), price(textbook.price)
{
	cout << "������ ����������� ����������� Textbook" << endl;
}

void Textbook::inputFromConsole()
{
	cout << "������� ��������: ";
	getline(cin, name);
	cout << "������� ������: ";
	getline(cin, author);
	cout << "������� ���������: ";
	getline(cin, annotation);
	cout << "������� ��������������� ����������: ";
	getline(cin, educationaInstitution);
	cout << "������� ��� �������: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "������� ��� ��������: ";
	yearLearning = safeInput(1, 11);
	cout << "������� ����� �������: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "������� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Textbook::inputFromFile(std::ifstream& file, std::string& tmpS)
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
	cout << "��������: " << name << endl;
	cout << "�����: " << author << endl;
	cout << "���������: " << annotation << endl;
	cout << "��������������� ����������: " << educationaInstitution << endl;
	cout << "��� �������: " << yearReliase << endl;
	cout << "��� ��������: " << yearLearning << endl;
	cout << "����� �������: " << volueme << endl;
	cout << "����: " << price << endl;
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
	cout << "������� ����� ��������: ";
	getline(cin, name);
	cout << "������� ������ ������: ";
	getline(cin, author);
	cout << "������� ����� ���������: ";
	getline(cin, annotation);
	cout << "������� ����� ��������������� ����������: ";
	getline(cin, educationaInstitution);
	cout << "������� ����� ��� �������: ";
	yearReliase = safeInput(1, INT32_MAX);
	cout << "������� ����� ��� ��������: ";
	yearLearning = safeInput(1, 11);
	cout << "������� ����� ����� �������: ";
	volueme = safeInput(1, INT32_MAX);
	cout << "������� ����� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}