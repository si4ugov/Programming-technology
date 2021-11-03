#include "Keeper.h"

Keeper::Keeper() : data(nullptr), size(0)
{
	cout << "Вызван конструктор Keeper" << endl;
}

Keeper::Keeper(Base** data, int size)
{
	this->data = new Base * [size];
	this->size = size;
	for (int i = 0; i < size; i++)
		this->data[i] = data[i];
	cout << "Вызван констукотр Keeper" << endl;
}

Keeper::Keeper(const Keeper& keeper)
{
	data = new Base * [keeper.size];
	size = keeper.size;
	for (int i = 0; i < size; i++)
		this->data[i] = keeper.data[i];
	cout << "Вызван констукотр копирования Keeper" << endl;
}

Keeper::~Keeper()
{
	size = 0;
	delete[] data;
	data = nullptr;
	cout << "Вызван деструктор Keeper" << endl;
}

void Keeper::add(Base* base)
{
	Base** tmp = data;
	size++;
	data = new Base * [size];
	for (int i = 0; i < size - 1; i++)
		data[i] = tmp[i];
	data[size - 1] = base;
}

void Keeper::del(int index)
{
	if (index < 0 || index >= size)
		throw index;

	Base** tmp = new Base * [size - 1];
	int k = 0;
	for (int i = 0; i < size; i++)
		if (i != index)
			tmp[k++] = data[i];
	size--;
	data = tmp;
}

Base* Keeper::operator[](int index)
{
	if (index < 0 || index >= size)
		throw index;
	return data[index];
}

void Keeper::inputFromFile()
{
	ifstream input("keeper.txt");
	if (input.is_open())
	{
		string tmpS;
		int countRecord;
		if (!getline(input, tmpS))
		{
			input.close();
			string err = "Файл не может быть прочитан";
			throw err;
		}
		countRecord = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
		try
		{
			for (int i = 0; i < countRecord; i++)
			{
				string err = "Файл не может быть корректно прочитан";
				if (!getline(input, tmpS))
					throw err;
				Base* obj = createObj(tmpS);
				obj->inputFromFile(input, tmpS);
				this->add(obj);
			}
		}
		catch (string err)
		{
			input.close();
			throw err;
		}
		input.close();
	}
	else
	{
		string err = "Файл keeper.txt не найден";
		throw err;
	}
}

void Keeper::printToFile()
{
	ofstream output("keeper.txt");
	output << size << endl;
	for (int i = 0; i < size; i++)
		data[i]->printToFile(output);
	output.close();
}

void Keeper::printToConsole()
{
	if (size == 0)
		cout << "Книжный магазин пуст" << endl;
	else
	{
		cout << "Содержимое книжного магазина: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". ";
			data[i]->printToConsole();
		}
	}
}

void Keeper::sort() {
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size - i; j++)
			if (*data[j] > *data[j + 1])
				std::swap(data[j], data[j + 1]);
}