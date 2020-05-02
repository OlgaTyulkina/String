#pragma once
#include <iostream>
using namespace std;

class SString {
public:
	SString();

	SString(char b, int leng);

	SString(SString& a);
	
	SString(const char* tstr);

	~SString();

	char* get_s() 
	{
		return init;
	}
	int get_l()
	{
		return length;
	}
	void set_s(const char* s);

	friend SString operator +(SString& a, SString& b);

	SString& operator =(const SString& a);

	void complete(SString& a, SString& b);

	friend bool operator == (SString& a, SString& b);

	friend bool operator <(SString& a, SString& b);

	friend bool operator >(SString& a, SString& b);

	char& operator [](const int index);

	friend ostream& operator <<(ostream& out, SString& a);

	friend istream& operator >> (istream& in, SString& b);

	char* find(const char* e);

	char* find_c(char* c);

	void Tstrtok(char* c);

private:
	char* init;
	int length;
	int size;
};
