#include "Base.h"

Base::Base(string typeObj) : typeObj(typeObj)
{
	cout << "������ ����������� Base" << endl;
}

Base::Base(const Base& base) : typeObj(base.typeObj)
{
	cout << "������ ����������� ����������� Base" << endl;
}

void Base::printToConsole()
{
	cout << typeObj << endl;
}

void Base::printToFile(ostream& out)
{
	out << typeObj << endl;
}

bool Base::operator>(const Base& base) {
	return typeObj > base.typeObj;
}