#pragma once
#include "Base.h"
class Textbook :
    public Base
{
private:
	string name, author, annotation, educationaInstitution;
	int yearReliase, yearLearning, volueme;
	double price;
public:
	Textbook();
	Textbook(string name, string author, string annotation, string educationaInstitution,
		int yearReliase, int yearLearning, int volueme, double price);
	Textbook(const Textbook& textbook);
	~Textbook() { cout << "Вызван деструктор Textbook" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	string getAuthor() { return author; }
	void setAutho(string author) { this->author = author; }

	string getAnnotation() { return annotation; }
	void setAnnotation(string annotation) { this->annotation = annotation; }

	string getEducationaInstitution() { return educationaInstitution; }
	void setEducationaInstitution(string educationaInstitution) { this->educationaInstitution = educationaInstitution; }

	int getYearReliase() { return yearReliase; }
	void setYearReliase(int yearReliase) { this->yearReliase = yearReliase; }

	int getYearLearning() { return yearLearning; }
	void setYearLearning(int yearLearning) { this->yearLearning = yearLearning; }

	int geVolueme() { return volueme; }
	void setVolueme(int volueme) { this->volueme = volueme; }

	double gePrice() { return price; }
	void setPrice(double price) { this->price = price; }
};

