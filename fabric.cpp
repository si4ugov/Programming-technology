#include "fabric.h"

Base* createObj(string name)
{
	if (name == "����������")
		return new Chancellery();
	if (name == "�������")
		return new Textbook();
	if (name == "�����")
		return new Book();
	string err = "��� ������� �� ���������";
	throw err;
}