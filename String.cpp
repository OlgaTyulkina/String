#include "String.h"
#pragma warning(disable:4996)

TString::TString() :nov(0), size(0), length(0)
{
}

TString::TString(char b, int leng) {
	size = leng + 1;
	nov = new char[size];
	length = leng;
	for (int i = 0; i < length; i++) nov[i] = b;
	nov[length] = 0;
}

TString::TString(const char* tstr) 
{
	if (strlen(tstr) > 0) {

		size = strlen(tstr) + 1;
		length = strlen(tstr);
		nov = new char[strlen(tstr) + 1];
		for (size_t i = 0; i < strlen(tstr); i++)nov[i] = tstr[i];
		nov[strlen(tstr)] = 0;
	}

}

TString::TString(TString& a) 
{
	size = a.get_l() + 1;
	length = a.get_l();
	nov = new char[size];
	for (int i = 0; i < length; i++)nov[i] = a.get_s()[i];
	nov[length] = 0;
}

TString::~TString() {
	if (nov != NULL)
		delete[] nov;
}

void TString::set_s(const char* s) {
	if (strlen(s) > 0) {
		size = strlen(s) + 1;
		length = strlen(s);
		nov = new char[strlen(s) + 1];
		for (size_t i = 0; i < strlen(s); i++)nov[i] = s[i];
		nov[strlen(s)] = 0;
	}
}

TString operator +(TString& a, TString& b) {
	TString c(a);
	c.complete(a, b);
	return c;
}

TString& TString::operator =(const TString& a) {
	if (&a == this)
		return *this;
	length = a.length;
	size = length + 1;
	nov = new char[size];
	for (int i = 0; i < length; i++)nov[i] = a.nov[i];
	nov[length] = 0;
	return *this;
}

bool operator == (TString& a, TString& b) {
	return(0 == strcmp(a.get_s(), b.get_s()));
}

bool operator <(TString& a, TString& b) {
	return(strcmp(a.get_s(), b.get_s()) < 0);
}

bool operator >(TString& a, TString& b) {
	return(strcmp(a.get_s(), b.get_s()) > 0);
}

char& TString::operator [](const int index) {
	if (index < 0 || index >= length)
		throw "yikes";
	else
		return nov[index];
}

ostream& operator <<(ostream& out, TString& a) 
{
	for (int i = 0; i < a.get_l(); i++)
	{
		out << a.get_s()[i];
	}
	return out;
}

istream& operator >> (istream& in, TString& b) {
	char t[256];
	in.getline(t, 256);
	TString e(t);
	b = e;
	return in;
}

char* TString::find(const char* e) {
	char* t = strstr(nov, e);
	if (t != NULL)
		return t;
	else
		return (char*)"Not found";
}

char* TString::find_c(const char* c) {
	char* t = strstr(nov, c);
	if (t != NULL)
		return t;
	else
		return (char*)"Not found";
}

TString* TString::Tstrtok(const char* c) {
	int count = 0;

	TString tmp = nov;

	char* istr = strtok(tmp.nov, c);
	while (istr != NULL)
	{
		count += 1;
		istr = strtok(NULL, c);
	}

	tmp = nov;

	TString* result = new TString[count];

	count = 0;

	istr = strtok(tmp.nov, c);
	while (istr != NULL)
	{
		result[count] = istr;
		count += 1;
		istr = strtok(NULL, c);
	}

	return result;
}

void TString::complete(TString& a, TString& b)
{

	nov = new char[a.get_l() + 1 + b.get_l()];
	length = a.get_l() + b.get_l();
	size = a.get_l() + 1 + b.get_l();
	for (int i = 0; i < a.get_l(); i++) nov[i] = a.get_s()[i];
	for (int i = 0; i < b.get_l(); i++) nov[i + a.get_l()] = b.get_s()[i];
	nov[a.get_l() + b.get_l()] = 0;
}

TString TString::repeater(TString& s, int k)
{
	if (s.get_l() == 0)
		throw "Length = 0";
	TString res(s);
	for (int i = 0; i < k - 1; i++)
	{
		res = res + s;
	}
	return res;
}
