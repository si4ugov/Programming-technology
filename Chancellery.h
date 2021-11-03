#pragma once
#include "Base.h"

class Chancellery :
    public Base
{
private:
	string type, color, specification;
	double price;
public:
	Chancellery();
	Chancellery(string type, string color, string specification, double price);
	Chancellery(const Chancellery& chancellery);
	~Chancellery() { cout << "Вызван деструктор Chancellery" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getType() { return type; }
	void setType(string type) { this->type = type; }

	string getColor() { return color; }
	void setColor(string color) { this->color = color; }

	string getSpecification() { return specification; }
	void setSpecification(string specification) { this->specification = specification; }

	double gePrice() { return price; }
	void setPrice(double price) { this->price = price; }
};

