#pragma once
#include "fabric.h"

class Keeper
{
private:
	Base** data;
	int size;
public:
	Keeper();
	Keeper(Base** data, int size);
	Keeper(const Keeper& keeper);
	~Keeper();

	void add(Base* base);
	void del(int index);
	Base* operator[](int index);
	void inputFromFile();
	void printToFile();
	void printToConsole();
	void sort();

	int getSize() { return size; }
};

