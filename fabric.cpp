#include "fabric.h"

Base* createObj(string name)
{
	if (name == "Канцелярия")
		return new Chancellery();
	if (name == "Учебник")
		return new Textbook();
	if (name == "Книга")
		return new Book();
	string err = "Тип объекта не распознан";
	throw err;
}