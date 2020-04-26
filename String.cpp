#include "String.h"

SString::SString() :init(0), size(0), length(0)
{

}

SString::SString(char b, int leng) {
	size = leng + 1;
	init = new char[size];
	length = leng;
	for (int i = 0; i < length; i++) init[i] = b;
	init[length] = 0;
}

SString::SString(const char* tstr) {
	if (strlen(tstr) > 0) {

		size = strlen(tstr) + 1;
		length = strlen(tstr);
		init = new char[strlen(tstr) + 1];
		for (size_t i = 0; i < strlen(tstr); i++)init[i] = tstr[i];
		init[strlen(tstr)] = 0;
	}

}

SString::SString(SString& a) {
	size = a.get_l() + 1;
	length = a.get_l();
	init = new char[size];
	for (int i = 0; i < length; i++)init[i] = a.get_s()[i];
	init[length] = 0;
}

SString::~SString() {
	delete[] init;
}

void SString::set_s(const char* s) {
	if (strlen(s) > 0) {
		size = strlen(s) + 1;
		length = strlen(s);
		init = new char[strlen(s) + 1];
		for (size_t i = 0; i < strlen(s); i++)init[i] = s[i];
		init[strlen(s)] = 0;
	}
}

SString operator +(SString& a, SString& b) {
	SString c(a);
	c.complete(a, b);
	return c;
}

SString& SString::operator =(const SString& a) {
	length = a.length;
	size = length + 1;
	init = new char[size];
	for (int i = 0; i < length; i++)init[i] = a.init[i];
	init[length] = 0;
	return *this;
}

bool operator == (SString& a, SString& b) {
	return(0 == strcmp(a.get_s(), b.get_s()));
}

bool operator <(SString& a, SString& b) {
	return(strcmp(a.get_s(), b.get_s()) < 0);
}

bool operator >(SString& a, SString& b) {
	return(strcmp(a.get_s(), b.get_s()) > 0);
}

char& SString::operator [](const int index) {
	return init[index];
}

ostream& operator <<(ostream& out, SString& a) {
	for (int i = 0; i < a.get_l(); i++) {
		out << a.get_s()[i];
	}

	return out;
}

istream& operator >> (istream& in, SString& b) 
{
	char t[256];
	in.getline(t, 256);
	SString e(t);
	b = e;
	return in;
}

char* SString::find(const char* e) 
{
	char* t = strstr(init, e);
	return t;
}

char* SString::find_c(char* c) 
{
	char* t = strstr(init, c);
	return t;
}

void SString::Tstrtok(char* c) {
	char* istr = strtok(init, c);


	while (istr != NULL)
	{

		cout << istr << endl;

		istr = strtok(NULL, c);
	}
}
