#pragma once
#include "Base.h"
class Book :
    public Base
{
private:
    string name, author, annotation, janr;
    int yearReliase, volueme;
	double price;
public:
	Book();
	Book(string name, string author, string annotation, string janr, int yearReliase, int volueme, double price);
	Book(const Book& book);
	~Book() { cout << "Вызван деструктор Book" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	string getAuthor() { return author; }
	void setAuthor(string author) { this->author = author; }

	string getAnnotation() { return annotation; }
	void setAnnotation(string annotation) { this->annotation = annotation; }

	string geJanr() { return janr; }
	void setJanr(string janr) { this->janr = janr; }

	int getYearReliase() { return yearReliase; }
	void setYearReliase(int yearReliase) { this->yearReliase = yearReliase; }

	int geVolueme() { return volueme; }
	void setVolueme(int volueme) { this->volueme = volueme; }

	double gePrice() { return price; }
	void setPrice(double price) { this->price = price; }

};

